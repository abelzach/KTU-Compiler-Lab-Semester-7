%{
int vowels=0,consonants=0;
%}
%%
[aeiouAEIOU] {vowels++;}
[^aeiouAEIOU \t\n] {consonants++;}
%%
int main(){
	printf("Enter string : ");
	yyin = stdin;
	yylex();
	printf("\n vowels: %d \n consonants: %d\n",vowels, consonants);
}
int yywrap(){
	return 1;
}

