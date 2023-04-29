#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void main(){
    FILE *fptr;
    int s=0;
    char c,w[100]="";
    fptr = fopen("file.txt","r");
    while(1){
    c=getc(fptr);
    s = 0;
    if(c==EOF){
        break;
    }
    Y:switch(s){
        R:case 0:if(c=='>')
                s=1;
                else if(isalpha(c)){
                    strcpy(w," ");
                    s=11;
                }
                else if(isdigit(c)){
                    strcpy(w," ");
                    s=13;
                }
                else goto T;
                goto Y;
        case 1:c=getc(fptr);
                if(c=='=')
                     s=2;
                else s = 3;
                goto Y;
        case 2:printf("\nGreater than or equal to");
                s=0;
                goto Y;
        case 3:printf("\nGreater than");
                s=0;
                goto Y;
        case 11:strncat(w,&c,1);
                c=getc(fptr);
                if(isalpha(c)||isdigit(c))
                    s=11;
                else s=12;
                goto Y;
        case 12:if(strcmp(w,"void")||strcmp(w,"main")||strcmp(w,"int")){
                printf("\nKeyword %s",w);
                goto R;
                }      
                else {   
                printf("\nIdentifier %s",w);
                    goto R;
                }
                goto Y;
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
        case 15:printf("\nFloating %s",w);
                s=0;
                goto Y;
        case 16:printf("\nInteger %s",w);
                s=0;
                goto Y;
  

        T:default:if(c=='+'||c=='-'||c=='*'||c=='/')
						printf("\n%c - Arithmetic operator\n",c); 
					else if(c==';')
						printf("\n%c - Delimter\n",c); 
					else if(c!=' '&&c!='\n')
						printf("\n%c - Special character\n",c);
    }
    }

}