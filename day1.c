#include<stdio.h> 
#include<ctype.h> 
#include<string.h> 
void main(){
	FILE *fptr; 
	fptr=fopen("file.txt","r"); 
	int s=0;
	char c,w[100]="";
	while(1){
		X:c=fgetc(fptr);
		if(c==EOF)
			break; 
		s=0;
		Y:switch(s)
		{
			R:case 0:if(c=='<')
						s=1;
					else if(c=='>')
						s=4;
					else if(c=='!')
						s=7;
					else if(c=='=')
						s=9;
					else if(isalpha(c)!=0){ 
							strcpy(w,"");
							s=11; 
						}
					else if(isdigit(c)!=0){ 
							strcpy(w,"");
							s=13; 
						}
					else
						goto T;
					goto Y;
			case 1:c=fgetc(fptr);
					if(c=='=')
						s=2;
					else
						s=3;
					goto Y;
			case 2:printf("<= - LESS THAN OR EQUAL TO\n"); 
					s = 0;
					goto Y;
			case 3:printf("< - LESS THAN\n");
					s=0;
					goto Y;
			case 4:c=fgetc(fptr);
					if(c=='=')
						s=5;
					else
						s=6; 
					goto Y;
			case 5:printf(">= - GREATER THAN OR EQUAL TO\n"); 
					goto X;
			case 6:printf("> - GREATER THAN\n"); 
					s=0;
					goto Y;
			case 7:c=fgetc(fptr);
					if(c=='=')
						s=8; 
					goto Y;
			case 8:printf("!= - NOT EQUAL TO\n"); 
					goto X;
			case 9:c=fgetc(fptr);
					if(c=='=')
						s=10; 
					else
					{
						printf("= - EQUAL TO\n");
						s=0;
						goto Y;
					}
					goto Y;
			case 10:printf("== - EQUAL TO EQUAL TO\n");
					goto X;
			case 11:strncat(w,&c,1);
					c=getc(fptr); 
					if(isalpha(c)||isdigit(c))
						s=11; 
					else
						s=17; 
					goto Y;
			case 12:printf("%s - Identifier\n",w); 
					goto R;
			case 13:strncat(w,&c,1); 
					c=getc(fptr);
					if(isdigit(c))
						s=13;
					else if(c=='.')
						s=14;
					else
						s=16;
					goto Y;
			case 14:strncat(w,&c,1);
					c=getc(fptr);
					if(isdigit(c))
						s=14; 
					else
						s=15; 
					goto Y;
			case 15:printf("%s - Floating number\n",w); 
					s=0;
					goto Y;
			case 16:printf("%s - Integer\n",w);
					s=0;
					goto Y; 
			case 17:if(strcmp(w,"void")==0 || strcmp(w,"float")==0||strcmp(w,"int")==0||strcmp(w, "if")==0||strcmp(w,"else")==0 || strcmp(w,"main")==0)
					{
						printf("%s - Keyword\n",w);
						goto R;
					} 
					else{
						printf("%s- Identifier\n",w);
						goto R; 
					}
					goto Y; 
			T:default:if(c=='+'||c=='-'||c=='*'||c=='/')
						printf("%c - Arithmetic operator\n",c); 
					else if(c==';')
						printf("%c - Delimter\n",c); 
					else if(c!=' '&&c!='\n')
						printf("%c - Special character\n",c);
		}
	}
}