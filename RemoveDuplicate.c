//Solution of Question 1:
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
void removeDuplicate(char *string){
    int store[256]={0};
    char ans[101];
    int len=strlen(string);
    for(int i=0;i<len;i++){
        store[string[i]]=1;
    }
    int k=0;
    for(int i=0;i<len;i++){
        if(store[string[i]]==1){
        ans[k++]=string[i];
        store[string[i]]=0;
        }
    }
    ans[k]='\0';
    printf("%s",ans);
}

int main() {
    char *string;
    string=(char*)malloc(sizeof(char)*100);
    scanf("%s",string);
    
    if(*string=='\0') {
        free(string);
        return 0;
        
    }
    removeDuplicate(string);
    free(string);
    return 0;
}
