//solution for question 9
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void remove_char(char *string,char ch){
    char *ans=(char*)malloc(20001);
    int k=0;
    for(int i=0;string[i]!='\0';i++){
        if(string[i]!=ch){
            ans[k++]=string[i];
    }
}
ans[k] = '\0';
printf("%s",ans);
free(ans);
}
int main(){
    char *string=(char*)malloc(20001);
    char ch;
    scanf("%[^\n]",string);
    getchar();
    scanf("%c",&ch);
    remove_char(string,ch);
    free(string);
    return 0;
}

