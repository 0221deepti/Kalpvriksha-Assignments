//solution of question 5
#include<stdio.h>
#include<stdlib.h>
int get_number(char *string){
    int num=0;
    int negflg=0;
    int i=0;
    int temp=0;
    if(string[0]=='-'){
            negflg=1;
            i=1;
        }
    while(string[i]!='\0'){
        
        temp=string[i]-'0';
        num=num*10+temp;  
        i++;
    }
    if(negflg) return -num;
    return num;
}
int main(){
    char *string=(char*)malloc(200001);
    scanf("%s",string);
    int num=get_number(string);
    printf("%d",num);
    free(string);
    return 0;
}
