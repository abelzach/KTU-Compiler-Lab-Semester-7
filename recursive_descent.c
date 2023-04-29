#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int i,error=0;
char input[20];
void Aprime(){
    if(input[i]=='b'){
        i++;
        if(input[i]=='c'){
            i++;
            Aprime();
        }
    }
}
void A(){
    if(input[i]=='b'){
        i++;
        Aprime();
    }
}
void B(){
    if(input[i] == 'd')
        i++;
    else
        error = 1;
}
void S(){
    if(input[i]=='a'){
        i++;
        A();
        B();
        if(input[i] == 'e')
            i++;
    }
}

void main(){
    printf("G : S -> aABe \n A -> bA'\nA' -> bcA'|$ \nB -> d\n");
    printf("Enter input : ");
    scanf("%s",input);
    S();
    if(error == 0 && i == strlen(input))
        printf("\nString accepted");
    else
        printf("\nString Rejected");
    
}