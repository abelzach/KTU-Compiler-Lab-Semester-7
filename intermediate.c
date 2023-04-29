#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){    
    int i = 0;
    char icode[10][30],opr[30],op;
    printf("Enter :\n");
    do{
        scanf("%s",icode[i]);
    }while(strcmp(icode[i++],"exit")!=0);
    i=0;
    do{
        op = icode[i][3];
        switch(op){
            case '+': strcpy(opr,"ADD");
                        break;
            case '-': strcpy(opr,"SUB");
                        break;
            case '*': strcpy(opr,"MUL");
                        break;
            case '/': strcpy(opr,"DIV");
                        break;
        }
        printf("\nMOV %c,R%d",icode[i][2],i);
        printf("\n%s %c,R%d",opr,icode[i][4],i);
        printf("\nMOV R%d,%c",i,icode[i][0]);
    }while(strcmp(icode[++i],"exit")!=0);
}