%{
#include<stdio.h>
int nl=0,nw=0,nc=0;
%}

%%
\n nl++;
[^ \t\n]+ {nw++;nc+=yyleng;}
%%
int yywrap(){
	return 1;
}
int main(){
	yylex();
	printf("\nNo of lines: %d",nl);
	printf("\nNo of words: %d",nw);
	printf("\nNo of characters: %d\n",nc);
}
