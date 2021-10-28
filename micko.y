%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "defs.h"
  #include "symtab.h"
  #include "codegen.h"

  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  int out_lin = 0;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0; //broj promenljivih u fji
  int fun_idx = -1;
  int fcall_idx = -1;
  int lab_num = -1;
  FILE *output;
  int type; //tip promenljive
  int returned=0; // da li je naredba return upotrebljena
  //int assigned=1;
    int whenId = -1;

int konstanta = 5;
int parameter_cnt=0;
int reg=-1;
int args_cnt = 0;
int arg_value = 0;
%}

%union {
  int i;
  char *s;
}

%token <i> _TYPE
%token _IF
%token _ELSE
%token _RETURN
%token <s> _ID
%token <s> _INT_NUMBER
%token <s> _UINT_NUMBER
%token _LPAREN
%token _RPAREN
%token _LBRACKET
%token _RBRACKET
%token _ASSIGN
%token _SEMICOLON
%token <i> _AROP
%token <i> _RELOP

%token _COLON
%token _COMMA
%token _POSTINC
%token _CHECK
%token _WHEN
%token _DEFAULT
%token _BREAK
%token _LOOP
%token _QMARK

%type <i> num_exp exp literal
%type <i> function_call argument argument_list rel_exp if_part postincrement when when_list conditional_operator

%nonassoc ONLY_IF
%nonassoc _ELSE

%%

program
  : global_variable_list function_list
      {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
      }
  ;

global_variable_list
  : /*empty*/
  | global_variable_list global_variable
  ;

global_variable
  : _TYPE _ID _SEMICOLON
  {
    if(lookup_symbol($2, GVAR) == NO_INDEX)
      insert_symbol($2, GVAR, $1, NO_ATR, NO_ATR);
    else 
      err("redefinition of '%s'", $2);
    
    code("\n%s:", $2);
    code("\n\tWORD 1");
  }
  ;
function_list
  : function
  | function_list function
  ;

function
  : _TYPE _ID
      {
        fun_idx = lookup_symbol($2, FUN);
        if(fun_idx == NO_INDEX)
          fun_idx = insert_symbol($2, FUN, $1, NO_ATR, NO_ATR);
        else 
          err("redefinition of function '%s'", $2);

        code("\n%s:", $2);
        code("\n\t\tPUSH\t%%14");
        code("\n\t\tMOV \t%%15,%%14");
        parameter_cnt = 0;
      }
    _LPAREN parameter _RPAREN body
      {
        clear_symbols(fun_idx + 1);
        var_num = 0;
        
        code("\n@%s_exit:", $2);
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
       	returned = 0;
      }
  ;

parameters
  : _TYPE _ID
  {
     int idx = insert_symbol($2, PAR, $1, ++parameter_cnt, NO_ATR);
        set_atr1(fun_idx, parameter_cnt);
        set_atr2(fun_idx, get_atr2(fun_idx) * 10 + $1);
  }
  | parameters _COMMA _TYPE _ID
  {
    int idx = lookup_symbol($4, PAR);
    if(idx != NO_INDEX)
      err("param alredy defined");
    
        idx = insert_symbol($4, PAR, $3, ++parameter_cnt, NO_ATR);
   set_atr1(fun_idx, parameter_cnt);
      set_atr2(fun_idx, get_atr2(fun_idx) * 10 + $3);
  }
 ;

parameter
  : /* empty */
      { set_atr1(fun_idx, 0); } //ako nema parametara ide 0 na atr1

  | parameters
  ;
body
  : _LBRACKET variable_list
      {
        if(var_num)
          code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
        code("\n@%s_body:", get_name(fun_idx));
      }
    statement_list _RBRACKET
  ;

variable_list
  : /* empty */
  | variable_list var_row
  ;

variables
  : _TYPE _ID 
    {
      
        if(lookup_symbol($2, VAR|PAR) == NO_INDEX)
           insert_symbol($2, VAR, $1, ++var_num, NO_ATR);
        else 
           err("redefinition of '%s'", $2);
	
	if( $1 == VOID)
	   err("Variable type can't be void");

        type = $1; //cuvamo tip promenljive da bismo u nekoj od sledecih promenljivih u tom redu mogli da pristupimo tom tipu

    }

  | _TYPE _ID _ASSIGN num_exp
   	{
	if(lookup_symbol($2, VAR|PAR) == NO_INDEX)
           insert_symbol($2, VAR, $1, ++var_num, NO_ATR);
        else 
           err("redefinition of '%s'", $2);
	
	if( $1 == VOID)
	   err("Variable type can't be void");
       
	if($1!=get_type($4))
	  err("Incompatible variable types in assignment");

	int idx = lookup_symbol($2, VAR|PAR);
        gen_mov($4, idx);   //smesta literal u promenljivu,generise mov naredbu
	
        int temp = lookup_symbol($2,VAR|PAR);
	set_atr2(temp,5);

	}
  | variables _COMMA _ID  // npr int a,b ... mora da zavrsi imenom prom
	{
        if(lookup_symbol($3, VAR|PAR) == NO_INDEX)
           insert_symbol($3, VAR, type, ++var_num, NO_ATR);
        else 
           err("redefinition of '%s'", $3);
      }               
  ;

var_row
  : variables _SEMICOLON
  ;
statement_list
  : /* empty */
  | statement_list statement
  ;

statement
  : compound_statement
  | assignment_statement
  | if_statement
  | postincrement_statement
  | return_statement
  | loop_statement
  | check_statement
  ;

compound_statement
  : _LBRACKET statement_list _RBRACKET
  ;

assignment_statement
  : _ID _ASSIGN num_exp _SEMICOLON
      {
        int idx = lookup_symbol($1, VAR|PAR);
        if(idx == NO_INDEX)
          err("invalid lvalue '%s' in assignment", $1);
        else
          if(get_type(idx) != get_type($3))
            err("incompatible types in assignment");
        gen_mov($3, idx);
      }
  | _ID _ASSIGN conditional_operator _SEMICOLON
  
  ;

postincrement_statement
  : postincrement _SEMICOLON
  ;

postincrement
  : _ID _POSTINC
{
    	  int idx = lookup_symbol($1, VAR|PAR|FUN);

    if(idx == NO_INDEX)
      err("operand '%s' not defined in increment", $1);

    if(get_kind(idx) == FUN)
    {
		  err("increment can't be called on function");
    }

    int registar = take_reg();

    gen_mov(idx, registar);

    if(get_type(idx) == INT) //za int ide sufiks s
      code("\n\t\tADDS\t");
    else
      code("\n\t\tADDU\t");
    
    gen_sym_name(idx);

    code(", $1, ");
    gen_sym_name(idx);

	  $$=registar;
  }
  ;

loop_statement
  : _LOOP _LPAREN _ID _COMMA  literal _COMMA literal _COMMA literal _COMMA literal  _RPAREN statement
  {
    int idx = lookup_symbol($3, VAR|PAR);
      if(idx == NO_INDEX)
        err("invalid value '%s' in loop", $3);

    
    
    if(get_type(idx) != get_type($5))
      err("incompatible types in loop statement ");
    
    if(get_type(idx) != get_type($7))
      err("incompatible types in loop statement");

   if(get_type(idx) != get_type($9))
      err("incompatible types in loop statement");

     if(get_type(idx) != get_type($11))
      err("incompatible types in loop statement");

    code("\n@loop_statement%d: ", ++lab_num);
      //$<i>$ = lab_num;
       
      gen_mov($5, idx);   //smesta literal u promenljivu
      code("\n@loop_cmp%d: ", lab_num);
      gen_cmp(idx, $7);
      code("\n\t\tJLES @loop_exit%d", lab_num);
      code("\n@loop_statement%d: ", lab_num);

    
    if(get_type(idx) == INT)
      code("\n\t\tSUBS\t");
    else
      code("\n\t\tSUBU\t");
    
    gen_sym_name(idx);
    code(", $%d, ", $11);
    gen_sym_name(idx);


    code("\n\t\tJMP\t@loop_cmp%d", lab_num);
    code("\n@loop_exit%d: ", lab_num);	
  }
  | _LOOP _LPAREN _ID _COMMA  literal _COMMA literal _COMMA literal   _RPAREN statement
  {
    int idx = lookup_symbol($3, VAR|PAR);
      if(idx == NO_INDEX)
        err("invalid value '%s' in loop", $3);
    
    if(get_type(idx) != get_type($5))
      err("incompatible types in loop statement ");
    
    if(get_type(idx) != get_type($7))
      err("incompatible types in loop statement");

   if(get_type(idx) != get_type($9))
      err("incompatible types in loop statement");

  gen_mov($5, idx);   //smesta literal u promenljivu
      code("\n@loop_cmp%d: ", lab_num);
      gen_cmp(idx, $7);
      code("\n\t\tJLES @loop_exit%d", lab_num);
      code("\n@loop_statement%d: ", lab_num);

    
    if(get_type(idx) == INT)
      code("\n\t\tADDS\t");
    else
      code("\n\t\tADDU\t");
    
    gen_sym_name(idx);
    code(", $%d, ", $9);
    gen_sym_name(idx);


    code("\n\t\tJMP\t@loop_cmp%d", lab_num);
    code("\n@loop_exit%d: ", lab_num);
	
  }
  ;

break
  :
  | _BREAK _SEMICOLON
  ;

check_statement
  : _CHECK _LPAREN _ID 
  {
    int idx = lookup_symbol($3, VAR|PAR);
    if(idx == NO_INDEX)
      err("invalid lvalue '%s' in check statement", $3);
    
    whenId = idx;
        code("\n@checkStart%d:", whenId);
  }
  _RPAREN _LBRACKET when_list default _RBRACKET

 {
    code("\n@checkEnd%d:", whenId);
  }
  ;

when_list
  : when break
  {
    $$ = $1;
  }
  | when_list when break
  {
    int lit1 = atoi(get_name($1));


    int lit2 = atoi(get_name($2));

    if(lit1 == lit2)
      err("repeated literal in check ");
  }
  ;

when
  : _WHEN literal _COLON  
  {
    if(get_type(whenId) != get_type($2))
      err("invalid expresion in when");
    
    int lit1 = atoi(get_name($2));
    code("\n@check%d_when%d:", whenId, lit1);
    gen_cmp(whenId, $2);
    code("\n\t\tJEQ\t@check%d_statement%d", whenId, lit1);
code("\n\t\tJMP\t@check%d_statement%d_exit", whenId, lit1);
    code("\n@check%d_statement%d:", whenId, lit1);
    
 }statement{
	    int lit1 = atoi(get_name($2));

    code("\n@check%d_statement%d_exit:", whenId, lit1);
    code("\n\t\tJMP\t@checkEnd%d", whenId);
    $$ = $2;
  }
  ;

default
  : /* empty */
  | _DEFAULT _COLON statement
  ;

num_exp
  : exp

  | num_exp _AROP exp
      {
        if(get_type($1) != get_type($3))
          err("invalid operands: arithmetic operation");
        int t1 = get_type($1);    
        code("\n\t\t%s\t", ar_instructions[$2 + (t1 - 1) * AROP_NUMBER]);
        gen_sym_name($1);
        code(",");
        gen_sym_name($3);
        code(",");
        free_if_reg($3);
        free_if_reg($1);
        $$ = take_reg();
        gen_sym_name($$);
        set_type($$, t1);
      }
  ;

exp
  : literal

  | _ID
      {
        $$ = lookup_symbol($1, VAR|PAR);
        if($$ == NO_INDEX)
          err("'%s' undeclared", $1);
      }

  | function_call
      {
        $$ = take_reg();
        gen_mov(FUN_REG, $$);
      }
  
  | _LPAREN num_exp _RPAREN
      { $$ = $2; }

  | postincrement
  {
    $$ = $1;
  }

  
  ;

literal
  : _INT_NUMBER
      { $$ = insert_literal($1, INT); }

  | _UINT_NUMBER
      { $$ = insert_literal($1, UINT); }
  ;

function_call
  : _ID 
      {
        fcall_idx = lookup_symbol($1, FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", $1);
      }
    _LPAREN argument_list _RPAREN
      {
        if(get_atr1(fcall_idx) != args_cnt)
          err("wrong number of arguments");
           if(get_atr2(fcall_idx) != arg_value)
          err("wrong types of arguments");


        code("\n\t\t\tCALL\t%s", get_name(fcall_idx));
          if(args_cnt > 0)
          code("\n\t\t\tADDS\t%%15,$%d,%%15", args_cnt * 4);
        set_type(FUN_REG, get_type(fcall_idx));
        $$ = FUN_REG;
         args_cnt = 0;
        arg_value = 0;
      }
  ;

argument
  : /* empty */
    { $$ = 0; }

  | num_exp
    { 
     // if(get_atr2(fcall_idx) != get_type($1))
      //  err("incompatible type for argument");
      free_if_reg($1);
      code("\n\t\t\tPUSH\t");
        gen_sym_name($1);
       arg_value = arg_value * 10 + get_type($1);
      args_cnt++;
    
      $$ = 1;
    }
  ;

argument_list
  : argument
  {
    $$ = $1;
  }
  | argument_list _COMMA argument
  {
    $$ = $3;
  }
  ;
if_statement
  : if_part %prec ONLY_IF
      { code("\n@exit%d:", $1); }

  | if_part _ELSE statement
      { code("\n@exit%d:", $1); }
  ;

if_part
  : _IF _LPAREN
      {
        $<i>$ = ++lab_num;
        code("\n@if%d:", lab_num);
      }
    rel_exp
      {
        code("\n\t\t%s\t@false%d", opp_jumps[$4], $<i>3);
        code("\n@true%d:", $<i>3);
      }
    _RPAREN statement
      {
        code("\n\t\tJMP \t@exit%d", $<i>3);
        code("\n@false%d:", $<i>3);
        $$ = $<i>3;
      }
  ;


conditional_operator
  : _LPAREN rel_exp _RPAREN _QMARK
  {
    int label = ++lab_num;
    int reg = take_reg();
    code("\n\t\t%s\t@false%d", opp_jumps[$2], lab_num); 
    code("\n@true%d:", lab_num);
  }
  exp
  {
    gen_mov($6, reg);
    code("\nJMP\t\t@exit%d",lab_num);
    code("\n@false%d:", lab_num);
  }
  _COLON exp
  {
    gen_mov($9, reg);
    code("\n@exit%d:", lab_num);
    $$ = reg;
  }
  ;

rel_exp
  : num_exp _RELOP num_exp
      {
        if(get_type($1) != get_type($3))
          err("invalid operands: relational operator");
        $$ = $2 + ((get_type($1) - 1) * RELOP_NUMBER);
        gen_cmp($1, $3);
      }
  ;

return_statement
  : _RETURN num_exp _SEMICOLON
      {
        if(get_type(fun_idx) != get_type($2))
          err("incompatible types in return");
	if(get_type(fun_idx) == VOID)
      		err("function of type void should not return value");
        returned=1;
        gen_mov($2, FUN_REG);
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));        
      }
 | _RETURN _SEMICOLON
    {
	if(get_type(fun_idx)!=VOID )
      		err("function of that type must have return value");
       returned=1;
      }	
  ;

%%

int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s", yylineno, s);
  error_count++;
  return 0;
}

void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s", yylineno, s);
  warning_count++;
}

int main() {
  int synerr;
  init_symtab();
  output = fopen("output.asm", "w+");

  synerr = yyparse();

  clear_symtab();
  fclose(output);
  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count) {
    remove("output.asm");
    printf("\n%d error(s).\n", error_count);
  }

  if(synerr)
    return -1;  //syntax error
  else if(error_count)
    return error_count & 127; //semantic errors
  else if(warning_count)
    return (warning_count & 127) + 127; //warnings
  else
    return 0; //OK
}

