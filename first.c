#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int numProductions;
char productions[10][10];
void addToResult(char Result[], char val){
    int i;
    for(i=0;Result[i]!='\0';i++)
        if(Result[i] == val)
            return;
    Result[i] = val;
    Result[i+1] = '\0';
}
void FIRST(char *Result,char c){
    char subResult[10];
    Result[0] = '\0';
    subResult[0] = '\0';
    int found;
    if(!isupper(c)){
        addToResult(Result,c);
        return;
    }
    else{
        for(int i=0;i<numProductions;i++){
            if(productions[i][0]==c){
                if(productions[i][2] == '$')
                {
                    addToResult(Result,'$');
                }
                else{
                    for(int j=2;productions[i][j]!='\0';j++){
                        FIRST(subResult,productions[i][j]);
                        found = 0;
                        for(int k=0;subResult[k]!='\0';k++)
                            addToResult(Result,subResult[k]);
                        for(int k=0;subResult[k]!='\0';k++){
                            if(subResult[k] =='$'){
                                found=1;
                                break;
                            }
                        }
                        if(!found)
                            break;
                    }   
                }
            }
        }
    }
    return;
    
}
void main(){
    char c,Result[20],y;
    printf("Enter number of productions ");
    scanf("%d",&numProductions);
    for(int i=0;i<numProductions;i++){
        scanf("%s",productions[i]);
    }
    do{
        printf("\nFind first of : ");
        scanf(" %c",&c);
        FIRST(Result,c);
        printf("\nFirst(%c) = %s",c,Result);
        printf("\nContinue ? ");
        scanf(" %c",&y);
    }while(y=='y');
}