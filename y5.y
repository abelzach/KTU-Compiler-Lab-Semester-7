%{
	#include<stdio.h>
	#include<stdlib.h>
%}
%token NUMBER
%left '+' '-' '/' '%'
%%
E : T {printf("\nResult : %d\n",$$);
	return 0;}
T : T '+' T {$$ = $1+$3;}
  | T '-' T {$$ = $1-$3;}
  | T'/'T {$$ = $1/$3;}
  | T'%'T {$$ = $1%$3;}
  | NUMBER {$$ = $1;}
  | '('T')' {$$ = $2;}
  ;
%%
int main(){
	printf("Enter expression ");
	yyparse();
	exit(0);
}
int yyerror(char *s){
	printf("\nInvalid\n");
	exit(0);
}
