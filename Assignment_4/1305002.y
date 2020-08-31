%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//#include "new_SymbolTable.h"
#include "1305002_SymbolTable.h"
//#include "1305002_optimizer.cpp"
#define YYSTYPE symbolInfo*
//int yydebug;
int yyparse(void);
int yylex(void);
double var[26];
//symbolTable** table = (symbolTable**)malloc(2*sizeof(symbolTable*));
symbolTable* table1 = new symbolTable(13);
symbolTable* table2 = new symbolTable(31);
extern int line_count;
extern int error_count;


int labelCount=0;
int tempCount=0;


char *newLabel()
{
	char *lb= new char[4];
	strcpy(lb,"L");
	char b[3];
	sprintf(b,"%d", labelCount);
	labelCount++;
	strcat(lb,b);
	return lb;
}

char *newTemp()
{
	char *t= new char[4];
	strcpy(t,"t");
	char b[3];
	sprintf(b,"%d", tempCount);
	tempCount++;
	strcat(t,b);
	return t;
}


FILE *out;
FILE *code;
symbolInfo *sm = new symbolInfo();
symbolInfo *multiple = new symbolInfo();
symbolInfo *arr_ind = new symbolInfo();
symbolInfo *name_holder = new symbolInfo();
symbolInfo *pr_id = new symbolInfo();
symbolInfo *asgn = new symbolInfo();
int scope=1;
int index=-1;

void yyerror(const char *s)
{
	fprintf(stderr,"****error at line %d: %s\n",line_count,s);
	fprintf(out,"****error at line %d: %s\n",line_count,s);
	error_count++;
	return;
}

%}

%token WHITESPACE NEWLINE IF ELSE FOR WHILE DO BREAK INT CHAR FLOAT DOUBLE MAIN
%token VOID RETURN SWITCH CASE DEFAULT CONTINUE PRINTLN ADDOP MULOP INCOP DECOP
%token RELOP ASSIGNOP LOGICOP NOT LPAREN RPAREN LCURL RCURL LTHIRD RTHIRD COMMA
%token SEMICOLON CONST_INT CONST_FLOAT CONST_CHAR ID
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%error-verbose

%% 

Start : func_declaration global_var_declaration Program
		{fprintf(out, "\n\nStart : func_declaration global_var_declaration Program\n");}
      | global_var_declaration func_declaration Program
		{fprintf(out, "\n\nStart : global_var_declaration func_declaration Program\n");}
      | func_declaration Program
		{fprintf(out, "\n\nStart : func_declaration Program\n");}
      | global_var_declaration Program
		{fprintf(out, "\n\nStart : global_var_declaration Program\n");}
      | Program {
			fprintf(out, "\n\nStart : Program\n");
			if(error_count==0)fprintf(code, "\tEND MAIN\n");
		}
      ;

global_var_declaration : type_specifier global_dec_list SEMICOLON
				{fprintf(out, "\n\nglobal_var_declaration : type_specifier global_dec_list SEMICOLON\n");
					scope = 2;
				}
		       | global_var_declaration type_specifier global_dec_list SEMICOLON
				{fprintf(out, "\n\nglobal_var_declaration : global_var_declaration type_specifier global_dec_list SEMICOLON\n");
					scope = 2;
				}
		       ;
global_dec_list : global_dec_list COMMA ID
			{fprintf(out, "\n\nglobal_dec_list : global_dec_list COMMA ID\n");
				fprintf(out,"%s\n",$3->name.c_str());
				multiple = table1->lookSymbol($3->name);
				if(multiple==NULL)
				{
					if(strcmp(sm->name.c_str(),"int")==0)
					{
						$3->dataType = 0;
						$3->v.i = -99999;
					}
					else if(strcmp(sm->name.c_str(),"float")==0)
					{
						$3->dataType = 1;
						$3->v.f = -99999.000000;
					}
					else if(strcmp(sm->name.c_str(),"char")==0)
					{
						$3->dataType = 2;
						$3->v.c = '0';
					}
					table1->insertSymbol($3);
				}
				else
				{
					char msg[30] = "Multiple Declaration For ID: ";
					strcat(msg,$3->name.c_str());
					yyerror(msg);
				}
			}
		| global_dec_list COMMA ID LTHIRD CONST_INT RTHIRD
			{fprintf(out, "\n\nglobal_dec_list : global_dec_list COMMA ID LTHIRD CONST_INT RTHIRD\n");
				fprintf(out,"%s\n",$3->name.c_str());
				multiple = table1->lookSymbol($3->name);
				if(multiple==NULL)
				{
					if(strcmp(sm->name.c_str(),"int")==0)
					{
						$3->dataType = 0;
						$3->sz = $5->v.i;
						$3->v.i_Arr = (int*)malloc(($3->sz)*sizeof(int));
						for(int k = 0; k<$3->sz; k++) $3->v.i_Arr[k] = -1;
					}
					else if(strcmp(sm->name.c_str(),"float")==0)
					{
						$3->dataType = 1;
						$3->sz = $5->v.i;
						$3->v.f_Arr = (float*)malloc(($3->sz)*sizeof(float));
						for(int k = 0; k<$3->sz; k++) $3->v.f_Arr[k] = -1.00000;
					}
					else if(strcmp(sm->name.c_str(),"char")==0)
					{
						$3->dataType = 2;
						$3->sz = $5->v.i;
						$3->v.c_Arr = (char*)malloc(($3->sz)*sizeof(char));
						for(int k = 0; k<$3->sz; k++) $3->v.c_Arr[k] = '0';
					}
					table1->insertSymbol($3);
				}
				else
				{
					char msg[30] = "Multiple Declaration For ID: ";
					strcat(msg,$3->name.c_str());
					yyerror(msg);
				}
			}
		| global_dec_list COMMA ID LTHIRD error RTHIRD
		| ID	{fprintf(out, "\n\nglobal_dec_list : ID\n");
				fprintf(out,"%s\n",$1->name.c_str());
				multiple = table1->lookSymbol($1->name);
				if(multiple==NULL)
				{
					if(strcmp(sm->name.c_str(),"int")==0)
					{
						$1->dataType = 0;
						$1->v.i = -99999;
					}
					else if(strcmp(sm->name.c_str(),"float")==0)
					{
						$1->dataType = 1;
						$1->v.f = -99999.000000;
					}
					else if(strcmp(sm->name.c_str(),"char")==0)
					{
						$1->dataType = 2;
						$1->v.c = '0';
					}
					table1->insertSymbol($1);
				}
				else
				{
					char msg[30] = "Multiple Declaration For ID: ";
					strcat(msg,$1->name.c_str());
					yyerror(msg);
				}
			}
		| ID LTHIRD CONST_INT RTHIRD
			{fprintf(out, "\n\nglobal_dec_list : ID LTHIRD CONST_INT RTHIRD\n");
				fprintf(out,"%s\n",$1->name.c_str());
				multiple = table1->lookSymbol($1->name);
				if(multiple==NULL)
				{
					if(strcmp(sm->name.c_str(),"int")==0)
					{
						$1->dataType = 0;
						$1->sz = $3->v.i;
						$1->v.i_Arr = (int*)malloc(($1->sz)*sizeof(int));
						for(int k = 0; k<$1->sz; k++) $1->v.i_Arr[k] = -1; 
					}
					else if(strcmp(sm->name.c_str(),"float")==0)
					{
						$1->dataType = 1;
						$1->sz = $3->v.i;
						$1->v.f_Arr = (float*)malloc(($1->sz)*sizeof(float));
						for(int k = 0; k<$1->sz; k++) $1->v.f_Arr[k] = -1.000000;
					}
					else if(strcmp(sm->name.c_str(),"char")==0)
					{
						$1->dataType = 2;
						$1->sz = $3->v.i;
						$1->v.c_Arr = (char*)malloc(($1->sz)*sizeof(char));
						for(int k = 0; k<$1->sz; k++) $1->v.c_Arr[k] = '0';
					}
					table1->insertSymbol($1);
				}
				else
				{
					char msg[30] = "Multiple Declaration For ID: ";
					strcat(msg,$1->name.c_str());
					yyerror(msg);
				}
			}
		| ID LTHIRD error RTHIRD
		;
func_declaration : type_specifier ID LPAREN Parameter_List RPAREN SEMICOLON
			{fprintf(out, "\n\nfunc_declaration : type_specifier ID LPAREN Parameter_List RPAREN SEMICOLON\n");}
		 | VOID ID LPAREN Parameter_List RPAREN SEMICOLON
			{fprintf(out, "\n\nfunc_declaration : VOID ID LPAREN Parameter_List RPAREN SEMICOLON\n");}
		 | type_specifier error LPAREN error RPAREN error SEMICOLON
		 | VOID error LPAREN error RPAREN error SEMICOLON
		 ;

Parameter_List : Parameter_List COMMA Parameter
			{fprintf(out, "\n\nParameter_List : Parameter_List COMMA Parameter\n");}
	       | Parameter  {fprintf(out, "\n\nParameter_List : Parameter\n");}
	       ;
Parameter : type_specifier ID {fprintf(out, "\n\nParameter : type_specifier ID\n");}
	  | type_specifier ID LTHIRD RTHIRD
			{fprintf(out, "\n\nParameter : type_specifier ID LTHIRD CONST_INT RTHIRD\n");}
	  | type_specifier error LTHIRD error RTHIRD
	  | VOID	{fprintf(out, "\n\nParameter : VOID\n");}
	  ;

Program : INT MAIN LPAREN RPAREN compound_statement
		{
			fprintf(out, "\n\nProgram: INT MAIN LPAREN RPAREN compound_statement\n");
			//$$ = $5;
			if(error_count==0)
			{
				fprintf(code, "TITLE: CODE GENERATION\n");
				fprintf(code, ".MODEL SMALL\n");
				fprintf(code, ".STACK 100H\n");		
				fprintf(code, ".DATA\n");
				fprintf(code, "\tCR EQU 0DH\n");		
				fprintf(code, "\tLF EQU 0AH\n");
				for(int i = 0; i<tempCount; i++)
					fprintf(code, "t%d DW ?\n",i);
				$$ = $5;
				$$->code += "MAIN ENDP\n\n";
				$$->code +="OUTDEC PROC\nPUSH AX\nPUSH BX\nPUSH CX\nPUSH DX\nOR AX,AX\nJGE @END_IF1\nPUSH AX\n";
				$$->code +="MOV DL,'-'\nMOV AH,2\nINT 21H\nPOP AX\nNEG AX\n\n @END_IF1:\nXOR CX,CX\nMOV BX,10D\n";
				$$->code +="@REPEAT1:\nXOR DX,DX\nDIV BX\nPUSH DX\nINC CX\nOR AX,AX\nJNE @REPEAT1\n\nMOV AH,2\n";
				$$->code +="@PRINT_LOOP:\n\nPOP DX\nOR DL,30H\nINT 21H\nLOOP @PRINT_LOOP\n\nMOV DX, CR\nINT 21H\n";
				$$->code +="MOV DX, LF\nINT 21H\nPOP DX\nPOP CX\nPOP BX\nPOP AX\nRET\nOUTDEC ENDP\n\n";
				fprintf(code,"%s",$$->code.c_str());
			}
		}
	;


compound_statement : LCURL var_declaration statements RCURL
				{
					fprintf(out, "\n\ncompound_statement: LCURL var_declaration statements RCURL\n");
					$$=$3;
					$$->code=$2->code+".CODE\nMAIN PROC\nMOV AX, @DATA\nMOV DS, AX\n"+$3->code;	
				}
		   | LCURL statements RCURL
				{fprintf(out, "\n\ncompound_statement: LCURL statements RCURL\n");
					$$=$2;
				}
		   | LCURL RCURL	{fprintf(out, "\n\ncompound_statement: LCURL RCURL\n");
					}
		   ;

			 
var_declaration	: type_specifier declaration_list SEMICOLON
			{
				fprintf(out, "\n\nvar_declaration: type_specifier declaration_list SEMICOLON\n");
				$$=$2;
				delete $1;
			}
		|  var_declaration type_specifier declaration_list SEMICOLON
			{
				fprintf(out, "\n\nvar_declaration: var_declaration type_specifier declaration_list SEMICOLON\n");
				$$=$1;
				$$->code+=$3->code;
				delete $2;
			}
		;

type_specifier	: INT		{fprintf(out, "\n\ntype_specifier: INT\n");
					sm->name = "int";
				}
		| FLOAT		{fprintf(out, "\n\ntype_specifier: FLOAT\n");
					sm->name = "float";
				}
		| CHAR		{fprintf(out, "\n\ntype_specifier: CHAR\n");
					sm->name = "char";
				}
		;
			
declaration_list : declaration_list COMMA ID	{fprintf(out, "\n\ndeclaration_list: declaration_list COMMA ID\n");
							fprintf(out,"%s\n",$3->name.c_str());
							multiple = table2->lookSymbol($3->name);
							if(multiple==NULL)
							{
								$$=$1;
								if(strcmp(sm->name.c_str(),"int")==0)
								{
									$3->dataType = 0;
									$3->v.i = -99999;
									$$->code+=$3->name+" DW " + "?\n";
								}
								else if(strcmp(sm->name.c_str(),"float")==0)
								{
									$3->dataType = 1;
									$3->v.f = -99999.000000;
									$$->code+=$3->name+" DW " + "?\n";
								}
								else if(strcmp(sm->name.c_str(),"char")==0)
								{
									$3->dataType = 2;
									$3->v.c = '0';
									$$->code+=$3->name+" DW " + "?,\'$\'\n";
								}
								table2->insertSymbol($3);
							}
							else
							{
								char msg[30] = "Multiple Declaration For ID: ";
								strcat(msg,$3->name.c_str());
								yyerror(msg);
							}
						}
		 | declaration_list COMMA ID LTHIRD CONST_INT RTHIRD
			{fprintf(out, "\n\ndeclaration_list: declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n");
				fprintf(out,"%s\n",$3->name.c_str());
				multiple = table2->lookSymbol($3->name);
				if(multiple==NULL)
				{
					$$=$1;
					if(strcmp(sm->name.c_str(),"int")==0)
					{
						$3->dataType = 0;
						$3->sz = $5->v.i;
						$3->v.i_Arr = (int*)malloc(($3->sz)*sizeof(int));
						for(int k = 0; k<$3->sz; k++) $3->v.i_Arr[k] = -1;
						int length = $5->v.i;
						$$->code+=$3->name+" DW ";
						for(int i=0;i<length-1;i++){
							$$->code += "?, " ;
						}
						$$->code+="?\n";
					}
					else if(strcmp(sm->name.c_str(),"float")==0)
					{
						$3->dataType = 1;
						$3->sz = $5->v.i;
						$3->v.f_Arr = (float*)malloc(($3->sz)*sizeof(float));
						for(int k = 0; k<$3->sz; k++) $3->v.f_Arr[k] = -1.00000;
						int length = $5->v.i;
						$$->code+=$3->name+" DW ";
						for(int i=0;i<length-1;i++){
							$$->code += "?, " ;
						}
						$$->code+="?\n";
					}
					else if(strcmp(sm->name.c_str(),"char")==0)
					{
						$3->dataType = 2;
						$3->sz = $5->v.i;
						$3->v.c_Arr = (char*)malloc(($3->sz)*sizeof(char));
						for(int k = 0; k<$3->sz; k++) $3->v.c_Arr[k] = '0';
						int length = $5->v.i;
						$$->code+=$3->name+" DW ";
						for(int i=0;i<length-1;i++){
							$$->code += "?, " ;
						}
						$$->code+="?,\'$\'\n";;
					}
					table2->insertSymbol($3);
				}
				else
				{
					char msg[30] = "Multiple Declaration For ID: ";
					strcat(msg,$3->name.c_str());
					yyerror(msg);
				}
			}
		 | ID   {fprintf(out, "\n\ndeclaration_list: ID\n");
				fprintf(out,"%s\n",$1->name.c_str());
				multiple = table2->lookSymbol($1->name);
				if(multiple==NULL)
				{
					$$=new symbolInfo($1);
					if(strcmp(sm->name.c_str(),"int")==0)
					{
						$1->dataType = 0;
						$1->v.i = -99999;
						$$->code=$1->name+" DW " + "?\n";
					}
					else if(strcmp(sm->name.c_str(),"float")==0)
					{
						$1->dataType = 1;
						$1->v.f = -99999.000000;
						$$->code=$1->name+" DW " + "?\n";
					}
					else if(strcmp(sm->name.c_str(),"char")==0)
					{
						$1->dataType = 2;
						$1->v.c = '0';
						$$->code=$1->name+" DW " + "?, \'$\'\n";
					}
					table2->insertSymbol($1);
				}
				else
				{
					char msg[30] = "Multiple Declaration For ID: ";
					strcat(msg,$1->name.c_str());
					yyerror(msg);
				}
				
			}
		 | ID LTHIRD CONST_INT RTHIRD
			{fprintf(out, "\n\ndeclaration_list: ID LTHIRD CONST_INT RTHIRD\n");
				fprintf(out,"%s\n",$1->name.c_str());
				multiple = table2->lookSymbol($1->name);
				if(multiple==NULL)
				{
					$$=new symbolInfo($1);
					if(strcmp(sm->name.c_str(),"int")==0)
					{
						$1->dataType = 0;
						$1->sz = $3->v.i;
						$1->v.i_Arr = (int*)malloc(($1->sz)*sizeof(int));
						for(int k = 0; k<$1->sz; k++) $1->v.i_Arr[k] = -1;
						int length = $3->v.i;
						$$->code=$1->name+" DW ";
						for(int i=0;i<length-1;i++){
							$$->code += "?, " ;
						}
						$$->code+="?\n";
					}
					else if(strcmp(sm->name.c_str(),"float")==0)
					{
						$1->dataType = 1;
						$1->sz = $3->v.i;
						$1->v.f_Arr = (float*)malloc(($1->sz)*sizeof(float));
						for(int k = 0; k<$1->sz; k++) $1->v.f_Arr[k] = -1.000000;
						int length = $3->v.i;
						$$->code=$1->name+" DW ";
						for(int i=0;i<length-1;i++){
							$$->code += "?, " ;
						}
						$$->code+="?\n";
					}
					else if(strcmp(sm->name.c_str(),"char")==0)
					{
						$1->dataType = 2;
						$1->sz = $3->v.i;
						$1->v.c_Arr = (char*)malloc(($1->sz)*sizeof(char));
						for(int k = 0; k<$1->sz; k++) $1->v.c_Arr[k] = '0';
						int length = $3->v.i;
						$$->code=$1->name+" DW ";
						for(int i=0;i<length-1;i++){
							$$->code += "?, " ;
						}
						$$->code+="?, \'$\'\n";
					}
					table2->insertSymbol($1);
				}
				else
				{
					char msg[30] = "Multiple Declaration For ID: ";
					strcat(msg,$1->name.c_str());
					yyerror(msg);
				}
			}
		 | declaration_list COMMA ID error LTHIRD error RTHIRD
		 | ID error LTHIRD error RTHIRD
		 ;

statements : statement		{fprintf(out, "\n\nstatements: statement\n");
					$$=$1;
				}
	   | statements statement	{fprintf(out, "\n\nstatements: statements statement\n");
						$$=$1;
						$$->code += $2->code;
						delete $2;
					}
	   ;


statement  : expression_statement	{fprintf(out, "\n\nstatement: expression_statement\n");
						$$=$1;
					}
	   | compound_statement		{fprintf(out, "\n\nstatement: compound_statement\n");
						$$=$1;
					}
	   | FOR LPAREN expression_statement expression_statement expression RPAREN statement
		{
			fprintf(out, "\n\nstatement: FOR LPAREN expression_statement expression_statement expression RPAREN statement\n");
			$$ = $3;

			char *label1=newLabel();
			char *label2=newLabel();
			$$->code+=string(label1)+":\n";
			$$->code+=$4->code;
			$$->code+="CMP "+$4->name+", 0\n";
			$$->code+="JLE "+string(label2)+"\n";
			$$->code+=$7->code;
			$$->code+=$5->code;
			$$->code+="JMP "+string(label1)+"\n";
			$$->code+=string(label2)+":\n";
		}
	   | FOR error LPAREN expression_statement expression_statement error RPAREN statement
	   | IF LPAREN expression RPAREN statement
		{
			fprintf(out,"\n\nstatement: IF LPAREN expression RPAREN statement\n");
			$$=$3;
					
			char *label=newLabel();
			$$->code+="MOV AX, "+ $3->name +"\n";
			$$->code+="CMP AX, 0\n";
			$$->code+="JLE "+string(label)+"\n";
			$$->code+=$5->code;
			$$->code+=string(label)+":\n";
					
		}	%prec LOWER_THAN_ELSE
	   | IF error LPAREN error RPAREN statement						%prec LOWER_THAN_ELSE
	   | IF LPAREN expression RPAREN statement ELSE statement
		{	
			fprintf(out,"\n\nstatement: IF LPAREN expression RPAREN statement ELSE statement\n");
			$$ = $3;

			char *label1=newLabel();
			char *label2=newLabel();
			$$->code+="MOV AX, "+ $3->name +"\n";
			$$->code+="CMP AX, 0\n";
			$$->code+="JLE "+string(label1)+"\n";
			$$->code+=$5->code;
			$$->code+="JMP "+string(label2)+"\n";
			$$->code+=string(label1)+":\n";
			$$->code+=$7->code;
			$$->code+=string(label2)+":\n";
		}
	   | IF error LPAREN error RPAREN statement ELSE statement
	   | WHILE LPAREN expression RPAREN statement 
		{
			fprintf(out,"\n\nstatement: WHILE LPAREN expression RPAREN statement\n");
			$$ = new symbolInfo();
			char *label1=newLabel();
			char *label2=newLabel();
			$$->code=string(label1)+":\n";
			$$->code+=$3->code;
			$$->code+="MOV AX, "+ $3->name +"\n";
			$$->code+="CMP AX, 0\n";
			$$->code+="JLE "+string(label2)+"\n";
			$$->code+=$5->code;
			$$->code+="JMP "+string(label1)+"\n";
			$$->code+=string(label2)+":\n";
			
		}
	   | WHILE error LPAREN error RPAREN statement
	   | PRINTLN LPAREN ID RPAREN SEMICOLON 
		{fprintf(out,"\n\nstatement: PRINTLN LPAREN ID RPAREN SEMICOLON\n");
			pr_id = table2->lookSymbol($3->name);
			if(pr_id!=NULL)
			{
				$$=$3;
				if(pr_id->dataType==0)
				{
					if(pr_id->sz==0)
					{
						printf("%d\n",pr_id->v.i);
						$$->code+="MOV AX, "+$3->name+"\n";
						$$->code+="CALL OUTDEC\n";
					}
					else
					{
						
						int i = pr_id->sz;
						char buffer[20];
						itoa(i,buffer,10);
						char* label1 = newLabel();
						char* label2 = newLabel();
						$$->code += "MOV BX, " + string(buffer) +"\n";
						$$->code += "MOV CX, 0\n";
						$$->code += string(label1) +":\n";
						$$->code += "CMP CX, BX\nJGE ";
						$$->code += string(label2)+"\n";
						$$->code += "LEA DI, "+ $$->name+"\n";
						$$->code += "ADD DI, CX\nADD DI, CX\nMOV AX, [DI]\n";
						$$->code += "CALL OUTDEC\nINC CX\nJMP "+ string(label1)+"\n";
						$$->code += string(label2)+ ":\n";

					}
				}
				else if(pr_id->dataType==1)printf("%f\n",pr_id->v.f);
				else if(pr_id->dataType==2)
				{
					printf("%c\n",pr_id->v.c);
					$$->code+="LEA DX, "+$3->name+"\n";
					$$->code+="MOV AH, 9\nINT 21H\n";
					$$->code+="MOV AH, 2\nMOV DX, CR\nINT 21H\nMOV DX, LF\nINT 21H\n";
				}
			}
			else
			{
				char msg[30] = "Undeclared Identifier: ";
				strcat(msg,$3->name.c_str());
				yyerror(msg);
			}
		
		}
	   | RETURN expression SEMICOLON 
		{	
			fprintf(out,"\n\nstatement: RETURN expression SEMICOLON\n");
			$$ = $2;
			$$->code += "MOV AH, 4CH\nINT 21H\n";
		}
	   | RETURN error SEMICOLON 
	   ;
		
expression_statement	: SEMICOLON	{
						fprintf(out, "\n\nexpression_statement: SEMICOLON\n");
						$$=new symbolInfo(";","SEMICOLON");
						$$->code="";
					}
			| expression SEMICOLON  {
							fprintf(out, "\n\nexpression_statement: expression SEMICOLON\n");
							$$=$1;
						}
			| error SEMICOLON
			;
						
variable : ID 				{fprintf(out, "\n\nvariable: ID\n"); fprintf(out,"%s\n",$1->name.c_str());
						asgn = table2->lookSymbol($1->name);
						if(asgn!=NULL)
						{
							if(asgn->sz!=0) yyerror("identifier to an array");
							else $$ = new symbolInfo(table2->lookSymbol($1->name));
							printf("in var: ID  %s\n",$$->name.c_str());
						}
						else 
						{
							char msg[30] = "Undeclared Identifier: ";
							strcat(msg,$1->name.c_str());
							yyerror(msg);
						}
					}
	 | ID LTHIRD expression RTHIRD  {fprintf(out, "\n\nvariable: ID LTHIRD expression RTHIRD\n");
						fprintf(out,"%s\n",$1->name.c_str());
						asgn = table2->lookSymbol($1->name);
						if(asgn!=NULL)
						{
							if(asgn->sz>0)
							{
								arr_ind = $3;
								name_holder->name = $3->name;
								index = $3->v.i;
								printf("var %s\n",name_holder->name.c_str());
								if(($3->dataType==0||$3->dataType==2)&&(($3->v.i>=0&&$3->v.i<asgn->sz)||($3->v.c>=0&&$3->v.c<asgn->sz)))
								{
									$$ = new symbolInfo(table2->lookSymbol($1->name));
									$$->code = $3->code;
									$$->index = arr_ind->v.i;
									printf("**in var: ID[exp] -> %d\n",$$->index);
								}
								else if($3->dataType==1)yyerror("index can not be a float");
								else yyerror("array index out-of-bound");
							}
							else
							{
								yyerror("not an array");
							}
						}
						else 
						{
							char msg[30] = "Undeclared Identifier: ";
							strcat(msg,$1->name.c_str());
							yyerror(msg);
						}
						delete $3;
					}
	 | ID error LTHIRD error RTHIRD
	 ;
			
expression : logic_expression		{fprintf(out,"\n\nexpression: logic_expression\n");
						$$=$1;
						printf("exp %s\n",$$->name.c_str());
					}
	   | variable ASSIGNOP logic_expression
		{fprintf(out,"\n\nexpression: variable ASSIGNOP logic_expression\n");
			
			if($3->dataType == 3) {}
			else if(!(($1->dataType==0||$1->dataType==2)&&$3->dataType==1))
			{
				//$1->index == -1 was in condition
				if($1->sz == 0)
				{
					if($1->dataType == 0 && $3->dataType == 0)
						$1->v.i=$3->v.i;
					else if($1->dataType == 0 && $3->dataType == 2)
						$1->v.i=$3->v.c;
					else if($1->dataType == 1 && $3->dataType == 0)
						$1->v.f=$3->v.i;
					else if($1->dataType == 1 && $3->dataType == 1)
						$1->v.f=$3->v.f;
					else if($1->dataType == 1 && $3->dataType == 2)
						$1->v.f=$3->v.c;
					else if($1->dataType == 2 && $3->dataType == 0)
						$1->v.c=$3->v.i;
					else if($1->dataType == 2 && $3->dataType == 2)
						$1->v.c=$3->v.c;
				}
				else
				{
					
					if($1->dataType == 0 && $3->dataType == 0)
						$1->v.i_Arr[index]=$3->v.i;
					else if($1->dataType == 0 && $3->dataType == 2)
						$1->v.i_Arr[index]=$3->v.c;
					else if($1->dataType == 1 && $3->dataType == 0)
						$1->v.f_Arr[index]=$3->v.i;
					else if($1->dataType == 1 && $3->dataType == 1)
						$1->v.f_Arr[index]=$3->v.f;
					else if($1->dataType == 1 && $3->dataType == 2)
						$1->v.f_Arr[index]=$3->v.c;
					else if($1->dataType == 2 && $3->dataType == 0)
						$1->v.c_Arr[index]=$3->v.i;
					else if($1->dataType == 2 && $3->dataType == 2)
						$1->v.c_Arr[index]=$3->v.c;
				}
				printf("in assignop -> index value %d\n",$1->index);
				$$=$1;
				printf("in assign  %d\n",index);
				printf("in assign  %s\n",$1->name.c_str());
				$$->code=$3->code+$1->code;
				$$->code+="MOV AX, "+$3->name+"\n";
				//$$->index==-1 was in condition
				if($$->sz==0)
				{
					$$->code+= "MOV "+$1->name+", AX\n";
				}
				
				else
				{
					$$->code+="LEA DI, " + $1->name+"\n";
					char buffer[20];
					itoa($$->index,buffer,10);
					printf("**in assignop -> %d\n",$$->index);
					for(int i=0;i<2;i++){
						$$->code += "ADD DI, " + string(buffer) +"\n";
						//$$->code += "ADD DI, " + name_holder->name +"\n";
						//printf("%s\n",buffer);
					}
					$$->code+= "MOV [DI], AX\n";
					$$->index = -1;
				}
				delete $3;
				//table2->deleteSymbol($1->name);
				//table2->insertSymbol($$);
				table2->printTable(out);
			}
			else yyerror("Type Mismatch");
		}
	   ;
			
logic_expression : rel_expression 	{
						fprintf(out,"\n\nlogic_expression: rel_expression\n");
						$$=$1;
						printf("log_exp %s\n",$$->name.c_str());
					}
		 | rel_expression LOGICOP rel_expression 	
			{fprintf(out,"\n\nlogic_expression: rel_expression LOGICOP rel_expression\n");
				$$ = $1;
				$$->code+=$3->code;
				$$->code+="MOV AX, " + $1->name+"\n";
				$$->code+="MOV BX, " + $3->name+"\n";
				char *temp=newTemp();
				char *label1=newLabel();
				char *label2=newLabel();
				$$->dataType = 0;
				if(strcmp($2->name.c_str(),"&&")==0)
				{
					if($1->dataType == 0 && $3->dataType == 0)
						$$->v.i = $1->v.i&&$3->v.i;
					else if($1->dataType == 0 && $3->dataType == 1)
						$$->v.i = $1->v.i&&$3->v.f;
					else if($1->dataType == 0 && $3->dataType == 2)
						$$->v.i = $1->v.i&&$3->v.c;
					else if($1->dataType == 1 && $3->dataType == 0)
						$$->v.i = $1->v.f&&$3->v.i;
					else if($1->dataType == 1 && $3->dataType == 1)
						$$->v.i = $1->v.f&&$3->v.f;
					else if($1->dataType == 1 && $3->dataType == 2)
						$$->v.i = $1->v.f&&$3->v.c;
					else if($1->dataType == 2 && $3->dataType == 0)
						$$->v.i = $1->v.c&&$3->v.i;
					else if($1->dataType == 2 && $3->dataType == 1)
						$$->v.i = $1->v.c&&$3->v.f;
					else if($1->dataType == 2 && $3->dataType == 2)
						$$->v.i = $1->v.c&&$3->v.c;
					$$->code+="CMP AX, 0\n";
					$$->code+="JLE "+string(label1)+"\n";
					$$->code+="CMP BX, 0\n";
					$$->code+="JLE "+string(label1)+"\n";
					$$->code+="MOV "+string(temp)+", 1\n";
					$$->code+="JMP "+string(label2)+"\n";
					$$->code+=string(label1)+":\nMOV "+string(temp)+", 0\n";

				}
				else if(strcmp($2->name.c_str(),"||")==0)
				{
					if($1->dataType == 0 && $3->dataType == 0)
						$$->v.i = $1->v.i||$3->v.i;
					else if($1->dataType == 0 && $3->dataType == 1)
						$$->v.i = $1->v.i||$3->v.f;
					else if($1->dataType == 0 && $3->dataType == 2)
						$$->v.i = $1->v.i||$3->v.c;
					else if($1->dataType == 1 && $3->dataType == 0)
						$$->v.i = $1->v.f||$3->v.i;
					else if($1->dataType == 1 && $3->dataType == 1)
						$$->v.i = $1->v.f||$3->v.f;
					else if($1->dataType == 1 && $3->dataType == 2)
						$$->v.i = $1->v.f||$3->v.c;
					else if($1->dataType == 2 && $3->dataType == 0)
						$$->v.i = $1->v.c||$3->v.i;
					else if($1->dataType == 2 && $3->dataType == 1)
						$$->v.i = $1->v.c||$3->v.f;
					else if($1->dataType == 2 && $3->dataType == 2)
						$$->v.i = $1->v.c||$3->v.c;
					$$->code+="CMP AX, 0\n";
					$$->code+="JG "+string(label1)+"\n";
					$$->code+="CMP BX, 0\n";
					$$->code+="JG "+string(label1)+"\n";
					$$->code+="MOV "+string(temp)+", 0\n";
					$$->code+="JMP "+string(label2)+"\n";
					$$->code+=string(label1)+":\nMOV "+string(temp)+", 1\n";
				}
				$$->code+=string(label2)+":\n";
				$$->name=temp;
				printf("%s\n",$$->name.c_str());
				delete $3;
			}
		 ;
			
rel_expression	: simple_expression	{fprintf(out,"\n\nrel_expression: simple_expression\n");
						$$=$1;
						printf("rel_exp %s\n",$$->name.c_str());
					}
		| simple_expression RELOP simple_expression
			{fprintf(out,"\n\nrel_expression: simple_expression RELOP simple_expression\n");
				$$ = $1;
				$$->dataType = 0;
				$$->code+=$3->code;
				$$->code+="MOV AX, " + $1->name+"\n";
				$$->code+="CMP AX, " + $3->name+"\n";
				char *temp=newTemp();
				char *label1=newLabel();
				char *label2=newLabel();
				if(strcmp($2->name.c_str(),"<")==0)
				{
					if($1->dataType == 0 && $3->dataType == 0)
						$$->v.i = $1->v.i<$3->v.i;
					else if($1->dataType == 0 && $3->dataType == 1)
						$$->v.i = $1->v.i<$3->v.f;
					else if($1->dataType == 0 && $3->dataType == 2)
						$$->v.i = $1->v.i<$3->v.c;
					else if($1->dataType == 1 && $3->dataType == 0)
						$$->v.i = $1->v.f<$3->v.i;
					else if($1->dataType == 1 && $3->dataType == 1)
						$$->v.i = $1->v.f<$3->v.f;
					else if($1->dataType == 1 && $3->dataType == 2)
						$$->v.i = $1->v.f<$3->v.c;
					else if($1->dataType == 2 && $3->dataType == 0)
						$$->v.i = $1->v.c<$3->v.i;
					else if($1->dataType == 2 && $3->dataType == 1)
						$$->v.i = $1->v.c<$3->v.f;
					else if($1->dataType == 2 && $3->dataType == 2)
						$$->v.i = $1->v.c<$3->v.c;
					$$->code+="JL " + string(label1)+"\n";
				}
				else if(strcmp($2->name.c_str(),">")==0)
				{
					if($1->dataType == 0 && $3->dataType == 0)
						$$->v.i = $1->v.i>$3->v.i;
					else if($1->dataType == 0 && $3->dataType == 1)
						$$->v.i = $1->v.i>$3->v.f;
					else if($1->dataType == 0 && $3->dataType == 2)
						$$->v.i = $1->v.i>$3->v.c;
					else if($1->dataType == 1 && $3->dataType == 0)
						$$->v.i = $1->v.f>$3->v.i;
					else if($1->dataType == 1 && $3->dataType == 1)
						$$->v.i = $1->v.f>$3->v.f;
					else if($1->dataType == 1 && $3->dataType == 2)
						$$->v.i = $1->v.f>$3->v.c;
					else if($1->dataType == 2 && $3->dataType == 0)
						$$->v.i = $1->v.c>$3->v.i;
					else if($1->dataType == 2 && $3->dataType == 1)
						$$->v.i = $1->v.c>$3->v.f;
					else if($1->dataType == 2 && $3->dataType == 2)
						$$->v.i = $1->v.c>$3->v.c;
					$$->code+="JG " + string(label1)+"\n";
				}
				else if(strcmp($2->name.c_str(),"<=")==0)
				{
					if($1->dataType == 0 && $3->dataType == 0)
						$$->v.i = $1->v.i<=$3->v.i;
					else if($1->dataType == 0 && $3->dataType == 1)
						$$->v.i = $1->v.i<=$3->v.f;
					else if($1->dataType == 0 && $3->dataType == 2)
						$$->v.i = $1->v.i<=$3->v.c;
					else if($1->dataType == 1 && $3->dataType == 0)
						$$->v.i = $1->v.f<=$3->v.i;
					else if($1->dataType == 1 && $3->dataType == 1)
						$$->v.i = $1->v.f<=$3->v.f;
					else if($1->dataType == 1 && $3->dataType == 2)
						$$->v.i = $1->v.f<=$3->v.c;
					else if($1->dataType == 2 && $3->dataType == 0)
						$$->v.i = $1->v.c<=$3->v.i;
					else if($1->dataType == 2 && $3->dataType == 1)
						$$->v.i = $1->v.c<=$3->v.f;
					else if($1->dataType == 2 && $3->dataType == 2)
						$$->v.i = $1->v.c<=$3->v.c;
					$$->code+="JLE " + string(label1)+"\n";
				}
				else if(strcmp($2->name.c_str(),">=")==0)
				{
					if($1->dataType == 0 && $3->dataType == 0)
						$$->v.i = $1->v.i>=$3->v.i;
					else if($1->dataType == 0 && $3->dataType == 1)
						$$->v.i = $1->v.i>=$3->v.f;
					else if($1->dataType == 0 && $3->dataType == 2)
						$$->v.i = $1->v.i>=$3->v.c;
					else if($1->dataType == 1 && $3->dataType == 0)
						$$->v.i = $1->v.f>=$3->v.i;
					else if($1->dataType == 1 && $3->dataType == 1)
						$$->v.i = $1->v.f>=$3->v.f;
					else if($1->dataType == 1 && $3->dataType == 2)
						$$->v.i = $1->v.f>=$3->v.c;
					else if($1->dataType == 2 && $3->dataType == 0)
						$$->v.i = $1->v.c>=$3->v.i;
					else if($1->dataType == 2 && $3->dataType == 1)
						$$->v.i = $1->v.c>=$3->v.f;
					else if($1->dataType == 2 && $3->dataType == 2)
						$$->v.i = $1->v.c>=$3->v.c;
					$$->code+="JGE " + string(label1)+"\n";
				}
				else if(strcmp($2->name.c_str(),"==")==0)
				{
					if($1->dataType == 0 && $3->dataType == 0)
						$$->v.i = $1->v.i==$3->v.i;
					else if($1->dataType == 0 && $3->dataType == 1)
						$$->v.i = $1->v.i==$3->v.f;
					else if($1->dataType == 0 && $3->dataType == 2)
						$$->v.i = $1->v.i==$3->v.c;
					else if($1->dataType == 1 && $3->dataType == 0)
						$$->v.i = $1->v.f==$3->v.i;
					else if($1->dataType == 1 && $3->dataType == 1)
						$$->v.i = $1->v.f==$3->v.f;
					else if($1->dataType == 1 && $3->dataType == 2)
						$$->v.i = $1->v.f==$3->v.c;
					else if($1->dataType == 2 && $3->dataType == 0)
						$$->v.i = $1->v.c==$3->v.i;
					else if($1->dataType == 2 && $3->dataType == 1)
						$$->v.i = $1->v.c==$3->v.f;
					else if($1->dataType == 2 && $3->dataType == 2)
						$$->v.i = $1->v.c==$3->v.c;
					$$->code+="JE " + string(label1)+"\n";
				}
				else if(strcmp($2->name.c_str(),"!=")==0)
				{
					if($1->dataType == 0 && $3->dataType == 0)
						$$->v.i = $1->v.i!=$3->v.i;
					else if($1->dataType == 0 && $3->dataType == 1)
						$$->v.i = $1->v.i!=$3->v.f;
					else if($1->dataType == 0 && $3->dataType == 2)
						$$->v.i = $1->v.i!=$3->v.c;
					else if($1->dataType == 1 && $3->dataType == 0)
						$$->v.i = $1->v.f!=$3->v.i;
					else if($1->dataType == 1 && $3->dataType == 1)
						$$->v.i = $1->v.f!=$3->v.f;
					else if($1->dataType == 1 && $3->dataType == 2)
						$$->v.i = $1->v.f!=$3->v.c;
					else if($1->dataType == 2 && $3->dataType == 0)
						$$->v.i = $1->v.c!=$3->v.i;
					else if($1->dataType == 2 && $3->dataType == 1)
						$$->v.i = $1->v.c!=$3->v.f;
					else if($1->dataType == 2 && $3->dataType == 2)
						$$->v.i = $1->v.c!=$3->v.c;
					$$->code+="JNE " + string(label1)+"\n";
				}
				$$->code+="MOV "+string(temp) +", 0\n";
				$$->code+="JMP "+string(label2) +"\n";
				$$->code+=string(label1)+":\nMOV "+string(temp)+", 1\n";
				$$->code+=string(label2)+":\n";
				$$->name = temp;
				printf("%s\n",$$->name.c_str());
				delete $3;
			}
		;
				
simple_expression : term		{fprintf(out,"\n\nsimple_expression: term\n");
						$$=$1;
						printf("simple_exp %s\n",$$->name.c_str());
					}
		  | simple_expression ADDOP term {fprintf(out,"\n\nsimple_expression: simple_expression ADDOP term\n");
							$$=$1;
							$$->code+=$3->code;
							$$->code+="MOV AX, "+$1->name+"\n";
							if(strcmp($2->name.c_str(),"+")==0)
							{
								if($1->dataType == 0 && $3->dataType == 0)
									{$$->dataType = 0;$$->v.i = $1->v.i+$3->v.i;}
								else if($1->dataType == 0 && $3->dataType == 1)
									{$$->dataType = 1;$$->v.f = $1->v.i+$3->v.f;}
								else if($1->dataType == 0 && $3->dataType == 2)
									{$$->dataType = 0;$$->v.i = $1->v.i+$3->v.c;}
								else if($1->dataType == 1 && $3->dataType == 0)
									{$$->dataType = 1;$$->v.f = $1->v.f+$3->v.i;}
								else if($1->dataType == 1 && $3->dataType == 1)
									{$$->dataType = 1;$$->v.f = $1->v.f+$3->v.f;}
								else if($1->dataType == 1 && $3->dataType == 2)
									{$$->dataType = 1;$$->v.f = $1->v.f+$3->v.c;}
								else if($1->dataType == 2 && $3->dataType == 0)
									{$$->dataType = 0;$$->v.i = $1->v.c+$3->v.i;}
								else if($1->dataType == 2 && $3->dataType == 1)
									{$$->dataType = 1;$$->v.f = $1->v.c+$3->v.f;}
								else if($1->dataType == 2 && $3->dataType == 2)
									{$$->dataType = 0;$$->v.i = $1->v.c+$3->v.c;}
								$$->code+="ADD AX, "+$3->name+"\n";
							}
							else if(strcmp($2->name.c_str(),"-")==0)
							{
								if($1->dataType == 0 && $3->dataType == 0)
									{$$->dataType = 0;$$->v.i = $1->v.i-$3->v.i;}
								else if($1->dataType == 0 && $3->dataType == 1)
									{$$->dataType = 1;$$->v.f = $1->v.i-$3->v.f;}
								else if($1->dataType == 0 && $3->dataType == 2)
									{$$->dataType = 0;$$->v.i = $1->v.i-$3->v.c;}
								else if($1->dataType == 1 && $3->dataType == 0)
									{$$->dataType = 1;$$->v.f = $1->v.f-$3->v.i;}
								else if($1->dataType == 1 && $3->dataType == 1)
									{$$->dataType = 1;$$->v.f = $1->v.f-$3->v.f;}
								else if($1->dataType == 1 && $3->dataType == 2)
									{$$->dataType = 1;$$->v.f = $1->v.f-$3->v.c;}
								else if($1->dataType == 2 && $3->dataType == 0)
									{$$->dataType = 0;$$->v.i = $1->v.c-$3->v.i;}
								else if($1->dataType == 2 && $3->dataType == 1)
									{$$->dataType = 1;$$->v.f = $1->v.c-$3->v.f;}
								else if($1->dataType == 2 && $3->dataType == 2)
									{$$->dataType = 0;$$->v.i = $1->v.c-$3->v.c;}
								$$->code+="SUB AX, "+$3->name+"\n";
							}
							char *temp = newTemp();
							$$->code+="MOV "+string(temp)+", AX\n";
							$$->name = temp;
							printf("%s\n",$$->name.c_str());
							delete $3;
						}
		  ;
					
term :	unary_expression		{fprintf(out,"\n\nterm: unary_expression\n");
						$$=$1;
						printf("%s\n",$$->name.c_str());
					}
     |  term MULOP unary_expression	{fprintf(out,"\n\nterm: term MULOP unary_expression\n");
						$$=$1;
						$$->code += $3->code;
						$$->code += "MOV AX, "+ $1->name+"\n";
						$$->code += "MOV BX, "+ $3->name+"\n";
						char *temp=newTemp();
						if(strcmp($2->name.c_str(),"*")==0)
						{
							if($1->dataType == 0 && $3->dataType == 0)
								{$$->dataType = 0; $$->v.i = $1->v.i*$3->v.i;}
							else if($1->dataType == 0 && $3->dataType == 1)
								{$$->dataType = 1; $$->v.f = $1->v.i*$3->v.f;}
							else if($1->dataType == 0 && $3->dataType == 2)
								{$$->dataType = 0; $$->v.i = $1->v.i*$3->v.c;}
							else if($1->dataType == 1 && $3->dataType == 0)
								{$$->dataType = 1; $$->v.f = $1->v.f*$3->v.i;}
							else if($1->dataType == 1 && $3->dataType == 1)
								{$$->dataType = 1; $$->v.f = $1->v.f*$3->v.f;}
							else if($1->dataType == 1 && $3->dataType == 2)
								{$$->dataType = 1; $$->v.f = $1->v.f*$3->v.c;}
							else if($1->dataType == 2 && $3->dataType == 0)
								{$$->dataType = 0; $$->v.i = $1->v.c*$3->v.i;}
							else if($1->dataType == 2 && $3->dataType == 1)
								{$$->dataType = 1; $$->v.f = $1->v.c*$3->v.f;}
							else if($1->dataType == 2 && $3->dataType == 2)
								{$$->dataType = 0; $$->v.i = $1->v.c*$3->v.c;}
							$$->code += "MUL BX\n";
							$$->code += "MOV "+ string(temp) + ", AX\n";
							$$->name = temp;
							printf("mulop  %s\n",$$->name.c_str());
						}
						else if(strcmp($2->name.c_str(),"/")==0)
						{
							if($1->dataType == 0 && $3->dataType == 0)
								{$$->dataType = 0; $$->v.i = $1->v.i/$3->v.i;}
							else if($1->dataType == 0 && $3->dataType == 1)
								{$$->dataType = 1; $$->v.f = $1->v.i/$3->v.f;}
							else if($1->dataType == 0 && $3->dataType == 2)
								{$$->dataType = 0; $$->v.i = $1->v.i/$3->v.c;}
							else if($1->dataType == 1 && $3->dataType == 0)
								{$$->dataType = 1; $$->v.f = $1->v.f/$3->v.i;}
							else if($1->dataType == 1 && $3->dataType == 1)
								{$$->dataType = 1; $$->v.f = $1->v.f/$3->v.f;}
							else if($1->dataType == 1 && $3->dataType == 2)
								{$$->dataType = 1; $$->v.f = $1->v.f/$3->v.c;}
							else if($1->dataType == 2 && $3->dataType == 0)
								{$$->dataType = 0; $$->v.i = $1->v.c/$3->v.i;}
							else if($1->dataType == 2 && $3->dataType == 1)
								{$$->dataType = 1; $$->v.f = $1->v.c/$3->v.f;}
							else if($1->dataType == 2 && $3->dataType == 2)
								{$$->dataType = 0; $$->v.i = $1->v.c/$3->v.c;}
							$$->code += "XOR DX, DX\n";
							$$->code += "DIV BX\n";
							$$->code += "MOV "+ string(temp) + ", AX\n";
							$$->name = temp;
							printf("%s\n",$$->name.c_str());
						}
						else 
						{
							if(!($1->dataType==1 || $3->dataType==1))
							{
								if($1->dataType == 0 && $3->dataType == 0)
									{$$->dataType = 0; $$->v.i = $1->v.i%$3->v.i;}
								else if($1->dataType == 0 && $3->dataType == 2)
									{$$->dataType = 0; $$->v.i = $1->v.i%$3->v.c;}
								else if($1->dataType == 2 && $3->dataType == 0)
									{$$->dataType = 0; $$->v.i = $1->v.c%$3->v.i;}
								else if($1->dataType == 2 && $3->dataType == 2)
									{$$->dataType = 0; $$->v.i = $1->v.c%$3->v.c;}
								$$->code += "XOR DX, DX\n";
								$$->code += "DIV BX\n";
								$$->code += "MOV "+ string(temp) + ", DX\n";
								$$->name = temp;
								printf("%s\n",$$->name.c_str());
							}
							else
							{
								$$->dataType = 3;
								yyerror("invalid operands for modulo operation");
							}
						}
						delete $3;
					}
     ;

unary_expression : ADDOP unary_expression {fprintf(out,"\n\nunary_expression: ADDOP unary_expression\n");
						if(strcmp($1->name.c_str(),"+")==0)
						{
							$$=$2;
						}
						else if(strcmp($1->name.c_str(),"-")==0)
						{
							if($1->dataType == 0) {$2->v.i=-$2->v.i;}
							else if($1->dataType == 1) {$2->v.f=-$2->v.f;}
							else if($1->dataType == 2) {$2->v.c=-$2->v.c;}
							$$=$2;
							char *temp=newTemp();
							//$$->code="MOV AX, " + $2->name + "\n"; was here
							$$->code+="MOV AX, " + $2->name + "\n";
							$$->code+="NEG AX\n";
							$$->code+="MOV "+string(temp)+", AX\n";
							$$->name = temp;
						}
					  }  
		 | NOT unary_expression   {fprintf(out,"\n\nunary_expression: NOT unary_expression\n");
						if($1->dataType == 0) {$2->v.i=!$2->v.i;}
						else if($1->dataType == 1) {$2->v.f=!$2->v.f;}
						else if($1->dataType == 2) {$2->v.c=!$2->v.c;}
						$$=$2;
						char *temp=newTemp();
						//$$->code="MOV AX, " + $2->name + "\n"; was here
						$$->code+="MOV AX, " + $2->name + "\n";
						$$->code+="NOT AX\n";
						$$->code+="MOV "+string(temp)+", AX\n";
						$$->name = temp;
					} 
		 | factor {fprintf(out,"\n\nunary_expression: factor\n");
				$$ = new symbolInfo();
				$$->name = $1->name;
				$$->type = $1->type;
				$$->dataType = $1->dataType;
				$$->index = $1->index;
				//$$->pos = $1->pos;
				$$->sz = $1->sz;
				$$->code = $1->code;
				if($1->sz == 0)
				{
					if($1->dataType==0)$$->v.i = $1->v.i;
					else if($1->dataType==1)$$->v.f = $1->v.f;
					else if($1->dataType==2)$$->v.c = $1->v.c;
				}
				else
				{
					printf("*** index: %d\n",index);
					if($1->dataType==0){$$->v.i = $1->v.i_Arr[index];
					printf("ekhane achi....9.b.1\n");}
					else if($1->dataType==1){$$->v.f = $1->v.f_Arr[index];
					printf("ekhane achi....9.b.2\n");}
					else if($1->dataType==2){$$->v.c = $1->v.c_Arr[index];
					printf("ekhane achi....9.b.3\n");}
					index = -1;
				}
				printf("%s\n",$$->name.c_str());
			}
		 ;
	
factor	: variable {fprintf(out,"\n\nfactor: variable\n");
			$$=$1;
			printf("factor %s\n",$$->name.c_str());
			printf("factor %s\n",name_holder->name.c_str());
			if($$->sz>0)
			{
				$$->code+="LEA DI, " + $1->name+"\n";
				printf("**in factor: var -> %d\n",arr_ind->v.i);
				string s1 = name_holder->name;
				for(int i=0;i<2;i++)
				{
					$$->code += "ADD DI, " + s1 +"\n";
					printf("%s\n",name_holder->name.c_str());
				}
				char *temp= newTemp();
				$$->code+= "MOV AX, [DI]\n";
				$$->code+= "MOV " + string(temp) + ", AX\n";
				$$->name = temp;
				$$->index = -1;
				name_holder->name = "";
			}
			printf("%s\n",$$->name.c_str());
		   }
	| LPAREN expression RPAREN   {fprintf(out,"\nfactor: LPAREN expression RPAREN\n"); $$=$2;}
	| CONST_INT    {fprintf(out,"\n\nfactor: CONST_INT\n");
				fprintf(out,"%d\n",$1->v.i);
			} 
	| CONST_FLOAT  {fprintf(out,"\n\nfactor: CONST_FLOAT\n");
				fprintf(out,"%f\n",$1->v.f);
			}
	| CONST_CHAR   {fprintf(out,"\n\nfactor: CONST_CHAR\n");
				fprintf(out,"%c\n",$1->v.c);
			}
	| variable INCOP {fprintf(out,"\n\nfactor: variable INCOP\n");
				$$=$1;
				//index==-1 was in condition
				if($$->sz==0)
				{
					if($1->dataType == 0) {$1->v.i++;}
					else if($1->dataType == 1) {$1->v.f++;}
					else if($1->dataType == 2) {$1->v.c++;}
					$$->code += "INC " + $1->name + "\n";
				}
				else
				{
					if($1->dataType==0){$1->v.i_Arr[index]++;}
					else if($1->dataType==1){$1->v.f_Arr[index]++;}
					else if($1->dataType==2){$1->v.c_Arr[index]++;}	
					$$->code+="LEA DI, " + $1->name+"\n";
					string s1 = name_holder->name;
					for(int i=0;i<2;i++)
					{
						$$->code += "ADD DI, " + s1 +"\n";
						printf("%s\n",name_holder->name.c_str());
					}
					$$->code+= "MOV AX, [DI]\n";
					$$->code += "INC AX\n";
					$$->code+= "MOV [DI], AX\n";
					$$->index = -1;
					name_holder->name = "";
				}
				
				printf("%s\n",$$->name.c_str());
			}
	| variable DECOP {fprintf(out,"\n\nfactor: variable DECOP\n");
				$$=$1;
				//index==-1 was in condition
				if($$->sz==0)
				{
					if($1->dataType == 0) {$1->v.i--;}
					else if($1->dataType == 1) {$1->v.f--;}
					else if($1->dataType == 2) {$1->v.c--;}
					$$->code += "DEC " + $1->name + "\n";
				}
				else
				{
					if($1->dataType==0){$1->v.i_Arr[arr_ind->v.i]--;}
					else if($1->dataType==1){$1->v.f_Arr[arr_ind->v.i]--;}
					else if($1->dataType==2){$1->v.c_Arr[arr_ind->v.i]--;}
					$$->code+="LEA DI, " + $1->name+"\n";
					string s1 = name_holder->name;
					for(int i=0;i<2;i++)
					{
						$$->code += "ADD DI, " + s1 +"\n";
						printf("%s\n",name_holder->name.c_str());
					}
					$$->code+= "MOV AX, [DI]\n";
					$$->code += "DEC AX\n";
					$$->code+= "MOV [DI], AX\n";
					$$->index = -1;
					name_holder->name = "";
				}
				printf("%s\n",$$->name.c_str());
			}
	;


%%
int main(int argc,char *argv[]){
	
	extern FILE *yyin;
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	
	out= fopen("1305002_log.txt","w");
	code= fopen("1305002_code.asm","w");


	yyin= fin;
	/*yydebug=1;*/
	yyparse();
	fprintf(out,"\n*******global symbol table******\n");
	table1->printTable(out);
	fprintf(out,"\n*******local symbol table******\n");
	table2->printTable(out);
	fprintf(out,"\nTotal Lines: %d\n",line_count);
	fprintf(out,"\nTotal Errors: %d\n",error_count);
	fclose(yyin);
	fclose(out);
	fclose(code);
	//optimize("1305002_code.asm");
	return 0;
}
