#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char stack[10],input[10],start[2];
int stack_top=0,count;
char production[10][10];
int can_reduce(){
    if(strlen(stack)==0)
        return -1;
    for(int i=stack_top;i>=0;i--){
        for(int j=0;j<count;j++){
            if(strcmp(production[j]+2, stack+i)==0)
                return j;
        }
    }
    return -1;
}

void main(){
    printf("Enter number of productions : ");
    scanf("%d",&count);
    for(int i=0;i<count;i++){
        scanf("%s",production[i]);
    }
    start[0] = production[0][0];
    start[1] = '\0';
    int itr = 0;
    printf("\nEnter input : ");
    scanf("%s",input);
    for(int i=0;i<=strlen(input);itr++){
        printf("\n Iteration %d",itr);
        printf("\n Stack %s",stack);
        printf("\n Input %s",input+i);

        if(strcmp(start,stack)==0 && i==strlen(input)){
            printf("String accepted");
            exit(0);
        }
        int reduce = 0;
        reduce = can_reduce();
        if(reduce >= 0){
            printf("\nReduction");
            stack_top -= strlen(production[reduce]+2);
            stack[stack_top++] = production[reduce][0];
            stack[stack_top] = '\0';
        }
        else{
            printf("\nShift ");
            stack[stack_top++] = input[i];
            stack[stack_top] = '\0';
            i++;
        }
    }
    printf("\nString rejected");
}