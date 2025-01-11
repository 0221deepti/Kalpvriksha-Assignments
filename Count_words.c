//Soltuion of Question 2: 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void count_words(char *string){
    int count=0;
    int flag=0;
    int len=strlen(string);
    if (string[len - 1] == '\n') {
        string[len - 1] = '\0';
        len--; 
    }
    for(int i=0;i<len;i++){
        if(isalpha(string[i])){
            if(flag==0){
                count++;
                flag=1;
            }
        }
        else{
            flag=0;
        }
    }
    printf("%d ",count);
}
int main(){
    char *string;
    string=(char *)malloc(sizeof(char)*200001);
    fgets(string,200001,stdin);
    count_words(string);
}
