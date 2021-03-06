%x STRSTATE
%x COMSTATE
%x SCOMMENT

%{
#include<stdio.h>
#include<stdlib.h>
//#include "new_SymbolTable.h"
#include "1305002_SymbolTable.h"
#include "y.tab.h"


extern YYSTYPE yylval;
extern symbolTable* table1;
extern symbolTable* table2;
extern int scope;
extern FILE *out;
void yyerror(const char *);

int line_count=1;
int error_count=0;
int com_line, str_line;
int i = 0, j = 0;
char ch[1000];


%}

WHITESPACE [ \t\f\r\v]+ 
LETTER [a-zA-Z]
DIGIT [0-9]
AlphaNumeric [a-zA-Z0-9]
NEWLINE \n
UNDERSCORE _

%%
{WHITESPACE} {}

{NEWLINE} {line_count++;}

"if"		{
			return IF;
		}
		
"else"		{
			return ELSE;
		}

"for"		{
			return FOR;
		}
"while"		{
			return WHILE;
		}
"do"		{
			return DO;
		}
"break"		{
			return BREAK;
		}
"int"		{
			return INT;
		}
"char"		{
			return CHAR;
		}
"float"		{
			return FLOAT;
		}
"double"	{
			return DOUBLE;
		}
"void"		{
			return VOID;
		}
"main"		{
			return MAIN;
		}
"return"	{
			return RETURN;
		}
"switch"	{
			return SWITCH;
		}
"case"		{
			return CASE;
		}
"default"	{
			return DEFAULT;
		}
"continue"	{
			return CONTINUE;
		}
"println"	{
			return PRINTLN;
		}

[+-]		{
			symbolInfo *s= new  symbolInfo(yytext, "ADDOP");
			yylval = (YYSTYPE)s;
			//yylval.sym = s;
			return ADDOP;			
		}
[*/%]		{
			symbolInfo *s= new  symbolInfo(yytext, "MULOP");
			yylval = (YYSTYPE)s;
			//yylval.sym = s;
			return MULOP;
		}
"++"		{
			return INCOP;
		}
"--"		{
			return DECOP;
		}

"<"|"<="|">"|">="|"=="|"!="		{
			symbolInfo *s= new  symbolInfo(yytext, "RELOP");
			yylval = (YYSTYPE)s;
			//yylval.sym = s;
			return RELOP;
		}
"="		{
			return ASSIGNOP;
		}
"&&"|"||"	{
			symbolInfo *s= new  symbolInfo(yytext, "LOGICOP");
			yylval = (YYSTYPE)s;
			//yylval.sym = s;
			return LOGICOP;
		}
"!"		{
			return NOT;
		}

"("		{
			return LPAREN;
		}
")"		{
			return RPAREN;
		}
"{"		{
			return LCURL;
		}
"}"		{
			return RCURL;
		}
"["		{
			return LTHIRD;
		}
"]"		{
			return RTHIRD;
		}
","		{
			return COMMA;
		}
";"		{
			return SEMICOLON;
		}
		
{DIGIT}+ 	{
				symbolInfo *s= new  symbolInfo(yytext, "CONST_INT");
				s->dataType = 0;
				s->v.i = atoi(yytext);
				yylval = (YYSTYPE)s;
				return CONST_INT;
			}
{DIGIT}*(\.{DIGIT}+)?(E[+-]?{DIGIT}+)? 	{
				symbolInfo *s= new  symbolInfo(yytext, "CONST_FLOAT");
				s->dataType = 1;
				s->v.f = atof(yytext);
				yylval = (YYSTYPE)s;
				return CONST_FLOAT;
			}
\'{AlphaNumeric}\' 	{
				symbolInfo *s= new  symbolInfo(yytext, "CONST_CHAR");
				s->dataType = 2;
				s->v.c = yytext[1];
				yylval = (YYSTYPE)s;
				return CONST_CHAR;
			}
\'\\[n|t|a|f|r|b|v|0|\\|\"]\' {
				symbolInfo *s= new  symbolInfo(yytext, "CONST_CHAR");
				//s->v.c = yytext;
				yylval = (YYSTYPE)s;
				return CONST_CHAR;
			}
			
({LETTER}|{UNDERSCORE})({LETTER}|{UNDERSCORE}|{DIGIT})* 	{
				symbolInfo *s;
				if(scope==1)
				s = table1->lookSymbol(yytext);
				else s = table2->lookSymbol(yytext);
				if(s==NULL)
				{					
					s= new symbolInfo(yytext, "ID");
				}
				yylval = (YYSTYPE)s;
				
				return ID;
			}
({DIGIT}+)({LETTER}|{UNDERSCORE})+ 	{
				error_count++;
				fprintf(out,"\nError at line %d: Invalid prefix on ID or invalid suffix on Number %s\n",line_count,yytext);
			}
\'{AlphaNumeric}{AlphaNumeric}+\'	{
				error_count++;
				fprintf(out,"\nError at line %d: Ill formed character %s\n",line_count,yytext);
			}
\'{AlphaNumeric}*$	{
				error_count++;
				fprintf(out,"\nError at line %d: Unterminated character %s\n",line_count,yytext);
			}
{DIGIT}*(\.{DIGIT}*)?(E[+-]?{DIGIT}*)((\.{DIGIT}*)(E[+-]?{DIGIT}+)?)*	{
				error_count++;
				fprintf(out,"\nError at line %d: Ill formed number %s\n",line_count,yytext);
			}

{DIGIT}*(\.{DIGIT}*)(\.{DIGIT}*)+	{
				error_count++;
				fprintf(out,"\nError at line %d: Too many decimal point %s\n",line_count,yytext);
			}



\".*\" 	{
				//fprintf(out,"\nLine no %d: TOKEN <STRING> Lexeme %s found\n",line_count,yytext);
			}
"//" 	{
				BEGIN SCOMMENT;
				//fprintf(logout,"\nLine no %d: TOKEN <COMMENT> Lexeme %s",line_count,yytext);
			}
<SCOMMENT>\n	{
		BEGIN INITIAL;
		line_count++;
		//fprintf(logout," found\n");
	}
<SCOMMENT>.	{
		//fprintf(logout,"%s",yytext);
	}

\"	{
		BEGIN STRSTATE;
		str_line = line_count;
		ch[i++] = '\"';
			}
<STRSTATE>\" {
		BEGIN INITIAL;
		ch[i++] = '\"';
		//fprintf(tokenout,"<STRING,%s>",ch);
		//fprintf(logout,"\nLine no %d: TOKEN <STRING> Lexeme %s found\n",str_line,ch);
		while(i!=0)
			ch[i--] = 0;
	
	}
<STRSTATE>\\\n	{
		line_count++;
		ch[i++] = ' ';
	}
<STRSTATE>\n	{
		line_count++;
		error_count++;
		fprintf(out,"\nError at line %d: Unterminated string %s\n",str_line,ch);
		while(i!=0)
			ch[i--] = 0;
		BEGIN INITIAL;
	}
<STRSTATE>.		{
		while(yytext[j]!='\0')
			ch[i++] = yytext[j++];
		j=0;
	}
"/*"	{
		BEGIN COMSTATE;
		com_line = line_count;
		while(yytext[j]!='\0')
			ch[i++] = yytext[j++];
		j=0;
	}
<COMSTATE>"*/"	{
		BEGIN INITIAL;
		while(yytext[j]!='\0')
			ch[i++] = yytext[j++];
		j=0;
		while(i!=0)
			ch[i--] = 0;
	}
<COMSTATE>\n	{
		line_count++;
		ch[i++] = '\n';
	}
<COMSTATE><<EOF>>	{
		error_count++;
		fprintf(out,"\nError at line %d: Unterminated comment %s\n",com_line,ch);
		while(i!=0)
			ch[i--] = 0;
		yyterminate();
	}
<COMSTATE>.		{
		while(yytext[j]!='\0')
			ch[i++] = yytext[j++];
		j=0;
	}

.	{
		error_count++;
		fprintf(out,"\nError at line %d: Unrecognized character %s\n",line_count,yytext);
		char msg[25];
		sprintf(msg,"%s <%s>","invalid character",yytext);
		yyerror(msg);
	}

%%

int yywrap(void)
{
	return 1;
}
