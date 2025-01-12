//solution of question 3
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
void check_substring(char *string1,char *string2){
    int len1=strlen(string1);
    int len2=strlen(string2);
    int end=len1-len2+1;
    if(len1<len2){
        printf("NO, Starting index:-1\\n");
        return;}
    for(int i=0;i<end;i++){
         bool isstring=true;
        for(int j=0;j<len2;j++){
            if(string1[i+j]!=string2[j]){
                isstring=false;
                break;
            }
        }
     if(isstring){
        
         printf("YES, Starting index: %d\n", i);
         return ;
     }
    }
    printf("NO, Starting index:-1\n");
     return;
}
int main(){
    char string1[256];
    char string2[256];
     scanf("%[^\n]", string1);
    getchar(); //for newline character
    scanf("%[^\n]", string2);
    // fgets(string1,256,stdin);
    //  fgets(string2,256,stdin);
    check_substring(string1,string2);
}
