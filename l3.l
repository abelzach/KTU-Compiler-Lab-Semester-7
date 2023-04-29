%{
	#include<stdio.h>
	
%}
%%
[a-zA-Z \n]* {
		for(int i=0;i<yyleng;i++){
			if(yytext[i]=='a'&&yytext[i+1]=='b'&&yytext[i+2]=='c'){
				yytext[i]='A';
				yytext[i+1]='B';
				yytext[i+2]='C';
			}
		}
		printf("%s",yytext);
	     }
%%
int main(){
	printf("Enter string : ");
	yyin = stdin;
	yylex();
}
int yywrap(){
	return 1;
}
