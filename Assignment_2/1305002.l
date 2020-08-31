%option noyywrap

%x STRSTATE
%x COMSTATE
%x SCOMMENT

%{
#include<stdio.h>
#include<stdlib.h>
#include"1305002_SymbolTable.h"

int line_count=1;
int error_count=0;
int com_line, str_line;
int i = 0, j = 0;
char ch[1000];
symbolTable table(31);

FILE *logout;
FILE *tokenout;

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

"if"	{
			fprintf(tokenout,"<IF>");
			fprintf(logout,"\nLine no %d: TOKEN <IF> Lexeme %s found\n",line_count,yytext);
		}
		
"else"	{
			fprintf(tokenout,"<ELSE>");
			fprintf(logout,"\nLine no %d: TOKEN <ELSE> Lexeme %s found\n",line_count,yytext);
		}

"for"	{
			fprintf(tokenout,"<FOR>");
			fprintf(logout,"\nLine no %d: TOKEN <FOR> Lexeme %s found\n",line_count,yytext);
		}
"while"	{
			fprintf(tokenout,"<WHILE>");
			fprintf(logout,"\nLine no %d: TOKEN <WHILE> Lexeme %s found\n",line_count,yytext);
		}
"do"	{
			fprintf(tokenout,"<DO>");
			fprintf(logout,"\nLine no %d: TOKEN <DO> Lexeme %s found\n",line_count,yytext);
		}
"break"	{
			fprintf(tokenout,"<BREAK>");
			fprintf(logout,"\nLine no %d: TOKEN <BREAK> Lexeme %s found\n",line_count,yytext);
		}
"int"	{
			fprintf(tokenout,"<INT>");
			fprintf(logout,"\nLine no %d: TOKEN <INT> Lexeme %s found\n",line_count,yytext);
		}
"char"	{
			fprintf(tokenout,"<CHAR>");
			fprintf(logout,"\nLine no %d: TOKEN <CHAR> Lexeme %s found\n",line_count,yytext);
		}
"float"	{
			fprintf(tokenout,"<FLOAT>");
			fprintf(logout,"\nLine no %d: TOKEN <FLOAT> Lexeme %s found\n",line_count,yytext);
		}
"double"	{
			fprintf(tokenout,"<DOUBLE>");
			fprintf(logout,"\nLine no %d: TOKEN <DOUBLE> Lexeme %s found\n",line_count,yytext);
		}
"void"	{
			fprintf(tokenout,"<VOID>");
			fprintf(logout,"\nLine no %d: TOKEN <VOID> Lexeme %s found\n",line_count,yytext);
		}
"return"	{
			fprintf(tokenout,"<RETURN>");
			fprintf(logout,"\nLine no %d: TOKEN <RETURN> Lexeme %s found\n",line_count,yytext);
		}
"switch"	{
			fprintf(tokenout,"<SWITCH>");
			fprintf(logout,"\nLine no %d: TOKEN <SWITCH> Lexeme %s found\n",line_count,yytext);
		}
"case"	{
			fprintf(tokenout,"<CASE>");
			fprintf(logout,"\nLine no %d: TOKEN <CASE> Lexeme %s found\n",line_count,yytext);
		}
"default"	{
			fprintf(tokenout,"<DEFAULT>");
			fprintf(logout,"\nLine no %d: TOKEN <DEFAULT> Lexeme %s found\n",line_count,yytext);
		}
"continue"	{
			fprintf(tokenout,"<CONTINUE>");
			fprintf(logout,"\nLine no %d: TOKEN <CONTINUE> Lexeme %s found\n",line_count,yytext);
		}

[+-]		{
			fprintf(tokenout,"<ADDOP,%s>",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <ADDOP> Lexeme %s found\n",line_count,yytext);
			table.insertSymbol(logout,yytext,"ADDOP");
			table.printTable(logout);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}
[*/%]	{
			fprintf(tokenout,"<MULOP,%s>",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <MULOP> Lexeme %s found\n",line_count,yytext);
			table.insertSymbol(logout,yytext,"MULOP");
			table.printTable(logout);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}
"++"|"--"		{
			fprintf(tokenout,"<INCOP,%s>",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <INCOP> Lexeme %s found\n",line_count,yytext);
			table.insertSymbol(logout,yytext,"INCOP");
			table.printTable(logout);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}
"<"|"<="|">"|">="|"=="|"!="		{
			fprintf(tokenout,"<RELOP,%s>",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <RELOP> Lexeme %s found\n",line_count,yytext);
			table.insertSymbol(logout,yytext,"RELOP");
			table.printTable(logout);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}
"="		{
			fprintf(tokenout,"<ASSIGNOP,%s>",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <ASSIGNOP> Lexeme %s found\n",line_count,yytext);
			table.insertSymbol(logout,yytext,"ASSIGNOP");
			table.printTable(logout);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}
"&&"|"||"|"!"		{
			fprintf(tokenout,"<LOGICOP,%s>",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <LOGICOP> Lexeme %s found\n",line_count,yytext);
			table.insertSymbol(logout,yytext,"LOGICOP");
			table.printTable(logout);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}
"("		{
			fprintf(tokenout,"<LPAREN,%s>",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <LPAREN> Lexeme %s found\n",line_count,yytext);
			table.insertSymbol(logout,yytext,"LPAREN");
			table.printTable(logout);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}
")"		{
			fprintf(tokenout,"<RPAREN,%s>",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <RPAREN> Lexeme %s found\n",line_count,yytext);
			table.insertSymbol(logout,yytext,"RPAREN");
			table.printTable(logout);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}
"{"		{
			fprintf(tokenout,"<LCURL,%s>",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <LCURL> Lexeme %s found\n",line_count,yytext);
			table.insertSymbol(logout,yytext,"LCURL");
			table.printTable(logout);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}
"}"		{
			fprintf(tokenout,"<RCURL,%s>",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <RCURL> Lexeme %s found\n",line_count,yytext);
			table.insertSymbol(logout,yytext,"RCURL");
			table.printTable(logout);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}
"["		{
			fprintf(tokenout,"<LTHIRD,%s>",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <LTHIRD> Lexeme %s found\n",line_count,yytext);
			table.insertSymbol(logout,yytext,"LTHIRD");
			table.printTable(logout);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}
"]"		{
			fprintf(tokenout,"<RTHIRD,%s>",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <RTHIRD> Lexeme %s found\n",line_count,yytext);
			table.insertSymbol(logout,yytext,"RTHIRD");
			table.printTable(logout);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}
","		{
			fprintf(tokenout,"<COMMA,%s>",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <COMMA> Lexeme %s found\n",line_count,yytext);
			table.insertSymbol(logout,yytext,"COMMA");
			table.printTable(logout);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}
";"		{
			fprintf(tokenout,"<SEMICOLON,%s>",yytext);
			fprintf(logout,"\nLine no %d: TOKEN <SEMICOLON> Lexeme %s found\n",line_count,yytext);
			table.insertSymbol(logout,yytext,"SEMICOLON");
			table.printTable(logout);
			//insert in symbol table and print symbol table content(only non empty buckets)
			// There is a '|' in "+"'s rule, this means match execute the action for following rule
		}
		
{DIGIT}+ 	{
				fprintf(tokenout,"<CONST_INT,%s>",yytext);
				fprintf(logout,"\nLine no %d: TOKEN <CONST_INT> Lexeme %s found\n",line_count,yytext);
				table.insertSymbol(logout,yytext,"CONST_INT");
				table.printTable(logout);
				//insert in symbol table and print symbol table content(only non empty buckets)
			}
{DIGIT}*(\.{DIGIT}+)?(E[+-]?{DIGIT}+)? 	{
				fprintf(tokenout,"<CONST_FLOAT,%s>",yytext);
				fprintf(logout,"\nLine no %d: TOKEN <CONST_FLOAT> Lexeme %s found\n",line_count,yytext);
				table.insertSymbol(logout,yytext,"CONST_FLOAT");
				table.printTable(logout);
				//insert in symbol table and print symbol table content(only non empty buckets)
			}
\'{AlphaNumeric}\' 	{
				fprintf(tokenout,"<CONST_CHAR,%s>",yytext);
				fprintf(logout,"\nLine no %d: TOKEN <CONST_CHAR> Lexeme %s found\n",line_count,yytext);
				table.insertSymbol(logout,yytext,"CONST_CHAR");
				table.printTable(logout);
				//insert in symbol table and print symbol table content(only non empty buckets)
			}
\'\\[n|t|a|f|r|b|v|0|\\|\"]\' {
				fprintf(tokenout,"<CONST_CHAR,%s>",yytext);
				fprintf(logout,"\nLine no %d: TOKEN <CONST_CHAR> Lexeme %s found\n",line_count,yytext);
				table.insertSymbol(logout,yytext,"CONST_CHAR");
				table.printTable(logout);
				//insert in symbol table and print symbol table content(only non empty buckets)
			}
			
({LETTER}|{UNDERSCORE})({LETTER}|{UNDERSCORE}|{DIGIT})* 	{
				fprintf(tokenout,"<ID,%s>",yytext);
				fprintf(logout,"\nLine no %d: TOKEN <ID> Lexeme %s found\n",line_count,yytext);
				table.insertSymbol(logout,yytext,"ID");
				table.printTable(logout);
				//insert in symbol table and print symbol table content(only non empty buckets)
			}
({DIGIT}+)({LETTER}|{UNDERSCORE})+ 	{
				error_count++;
				fprintf(logout,"\nError at line %d: Invalid prefix on ID or invalid suffix on Number %s\n",line_count,yytext);
			}
\'{AlphaNumeric}{AlphaNumeric}+\'	{
				error_count++;
				fprintf(logout,"\nError at line %d: Ill formed character %s\n",line_count,yytext);
			}
\'{AlphaNumeric}*$	{
				error_count++;
				fprintf(logout,"\nError at line %d: Unterminated character %s\n",line_count,yytext);
			}
{DIGIT}*(\.{DIGIT}*)?(E[+-]?{DIGIT}*)((\.{DIGIT}*)(E[+-]?{DIGIT}+)?)*	{
				error_count++;
				fprintf(logout,"\nError at line %d: Ill formed number %s\n",line_count,yytext);
			}

{DIGIT}*(\.{DIGIT}*)(\.{DIGIT}*)+	{
				error_count++;
				fprintf(logout,"\nError at line %d: Too many decimal point %s\n",line_count,yytext);
			}



\".*\" 	{
				fprintf(tokenout,"<STRING,%s>",yytext);
				fprintf(logout,"\nLine no %d: TOKEN <STRING> Lexeme %s found\n",line_count,yytext);
				//insert in symbol table and print symbol table content(only non empty buckets)
			}
"//" 	{
				BEGIN SCOMMENT;
				fprintf(logout,"\nLine no %d: TOKEN <COMMENT> Lexeme %s",line_count,yytext);
				//insert in symbol table and print symbol table content(only non empty buckets)
			}
<SCOMMENT>\n	{
		BEGIN INITIAL;
		line_count++;
		fprintf(logout," found\n");
	}
<SCOMMENT>.	{
		fprintf(logout,"%s",yytext);
	}

\"	{
		BEGIN STRSTATE;
		str_line = line_count;
		//fprintf(logout,"\nLine no %d: TOKEN <STRING> Lexeme %s",str_line,yytext);
		ch[i++] = '\"';
			}
<STRSTATE>\" {
		BEGIN INITIAL;
		ch[i++] = '\"';
		fprintf(tokenout,"<STRING,%s>",ch);
		fprintf(logout,"\nLine no %d: TOKEN <STRING> Lexeme %s found\n",str_line,ch);
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
		//fprintf(logout,"%s is found\n",yytext);
		//fprintf(logout,"Unterminated string\n",yytext);
		fprintf(logout,"\nError at line %d: Unterminated string %s\n",str_line,ch);
		while(i!=0)
			ch[i--] = 0;
		BEGIN INITIAL;
	}
<STRSTATE>.		{
		//fprintf(logout,"%s",yytext);
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
		//fprintf(logout,"Line no %d: TOKEN <COMMENT> Lexeme %s",com_line,yytext);
	}
<COMSTATE>"*/"	{
		BEGIN INITIAL;
		while(yytext[j]!='\0')
			ch[i++] = yytext[j++];
		j=0;
		fprintf(logout,"\nLine no %d: TOKEN <COMMENT> Lexeme %s found\n",com_line,ch);
		while(i!=0)
			ch[i--] = 0;
		//fprintf(logout,"%s is found\n",yytext);
	}
<COMSTATE>\n	{
		line_count++;
		ch[i++] = '\n';
	}
<COMSTATE><<EOF>>	{
		error_count++;
		//fprintf(logout,"%s is found\n",yytext);
		//fprintf(logout,"Unterminated string\n",yytext);
		fprintf(logout,"\nError at line %d: Unterminated comment %s\n",com_line,ch);
		while(i!=0)
			ch[i--] = 0;
		yyterminate();
	}
<COMSTATE>.		{
		//fprintf(logout,"%s",yytext);
		while(yytext[j]!='\0')
			ch[i++] = yytext[j++];
		j=0;
	}

.	{
				error_count++;
				fprintf(logout,"\nError at line %d: Unrecognized character %s\n",line_count,yytext);
			}

%%

int main(int argc,char *argv[]){
	
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	
	logout= fopen("log.txt","w");
	tokenout= fopen("token.txt","w");

	yyin= fin;
	yylex();
	fprintf(logout,"\nTotal Lines: %d\n",line_count);
	fprintf(logout,"\nTotal Errors: %d\n",error_count);
	fclose(yyin);
	fclose(tokenout);
	fclose(logout);
	return 0;
}
