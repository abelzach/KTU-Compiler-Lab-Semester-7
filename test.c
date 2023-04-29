#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int i=1,j=0,tempch=90;
char str[100],left[15],right[15];
struct exp{
    int pos;
    char op;
}k[20];
void findopr(){
    for(i=0;str[i]!='\0';i++){
        if(str[i] == ':')
        {
            k[j].pos = i;
            k[j].op = ':';
            j++;
        }
    }
    for(i=0;str[i]!='\0';i++){
        if(str[i] == '*')
        {
            k[j].pos = i;
            k[j].op = '*';
            j++;
        }
    }
    for(i=0;str[i]!='\0';i++){
        if(str[i] == '/')
        {
            k[j].pos = i;
            k[j].op = '/';
            j++;
        }
    }
    for(i=0;str[i]!='\0';i++){
        if(str[i] == '+')
        {
            k[j].pos = i;
            k[j].op = '+';
            j++;
        }
    }
    for(i=0;str[i]!='\0';i++){
        if(str[i] == '-')
        {
            k[j].pos = i;
            k[j].op = '-';
            j++;
        }
    }
}

void fleft(int x){
    x--;
    int w=0,flag=0;
    while(x!=-1&&str[x]!='+'&&str[x]!='-'&&str[x]!='/'&&str[x]!='*'&&str[x]!=':'&&str[x]!='\0'){
        if(str[x]!='$' && flag == 0){
            left[w] = str[x];
            left[w+1] = '\0';
            str[x] = '$';
            flag = 1;
        }
        x--;
    }
}
void fright(int x){
    x++;
    int w=0,flag=0;
    while(x!=-1&&str[x]!='+'&&str[x]!='-'&&str[x]!='/'&&str[x]!='*'&&str[x]!=':'&&str[x]!='\0'){
        if(str[x]!='$' && flag == 0){
            right[w] = str[x];
            right[w+1] = '\0';
            str[x] = '$';
            flag = 1;
        }
        x++;
    }
}
void explore(){
    i=1;
    while(k[i].op != '\0'){
        fleft(k[i].pos);
        fright(k[i].pos);
        str[k[i].pos] = tempch--;
        printf("\n%c:=%s %c %s",str[k[i].pos],left,k[i].op,right);
        i++;
    }
    fright(-1);
    fleft(strlen(str));
    printf("\n%s:=%s",right,left);
}
void main() {
    printf(" INTERMEDIATE CODE GENERATION");
    printf("\n Enter the Expression : "); 
    scanf("%s", str);
    printf(" The Intermediate code:\n"); 
    findopr();
    explore();
    printf("\n"); 
}