#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int n;
struct expr {
    char op1[5],op2[5],op[2],result[5];
    int flag;
}arr[10];

void change(int p, char *res){
    for(int i=p+1;i<n;i++){
        if(strcmp(arr[i].op1,arr[p].result)==0)
            strcpy(arr[i].op1,res);
        else if(strcmp(arr[i].op2,arr[p].result)==0)
            strcpy(arr[i].op2,res);
    }
}


void constant(){
    int op1,op2,res;
    char op,res1[5];
    for(int i=0;i<n;i++){
        if((isdigit(arr[i].op1[0])&&isdigit(arr[i].op2[0]))||strcmp(arr[i].op,"=")==0){
            
            op1 = atoi(arr[i].op1);
            op2 = atoi(arr[i].op2);
            op = arr[i].op[0];
            switch(op){
                case '+':res = op1+op2;
                        break;
                case '-':res = op1-op2;
                        break;
                case '/':res = op1/op2;
                        break;
                case '*':res = op1*op2;
                        break;
                case '=':res = op1;
                        break;
            }
            sprintf(res1,"%d",res);
            snprintf(arr[i].op1,"%d",res1);
            strcpy(arr[i].op2,"-");
            strcpy(arr[i].op,"=");
            change(i,res1);
            arr[i].flag = 1;
        }
        
    }
}

int main(){
    printf("Enter number of experssions : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter expression %d ",i+1);
        scanf("%s",arr[i].op);
        scanf("%s",arr[i].op1);
        scanf("%s",arr[i].op2);
        scanf("%s",arr[i].result);
        arr[i].flag = 0;
    }
    constant();
    for(int i=0;i<n;i++){
        printf("\n %s %s %s =  %s",arr[i].op2,arr[i].op,arr[i].op1,arr[i].result);
    }
}