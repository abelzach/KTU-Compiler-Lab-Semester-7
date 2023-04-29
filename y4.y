%{
	#include<stdlib.h>
	#include<stdio.h>
%}
%token NUMBER ID
%left '+' '-' '/' '*'
%%
T : T'+'T
  | T'-'T
  | T'/'T
  | T'*'T
  | ID
  |'('T')'
  |NUMBER
  ;

%%
int main(){
	printf("\nEnter statment ");
	yyparse();
	printf("\nValid\n");
	exit(0);
}
int yyerror(char *s){
	printf("\nInvalid\n");
	exit(0);
}
