//Solution of question 4
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
bool check_substring(char *check_String,char *string2){
  int len1=strlen(check_String);
  int len2=strlen(string2);
  for(int i=0;i<len1-len2+1;i++){
    bool is_Substring=true;
    for(int j=0;j<len2;j++){
        if(check_String[i+j]!=string2[j]){
            is_Substring=false;
            break;
        }
    }
    if(is_Substring) return true;
    
}
return false;
}
void check_rotation(char *string1,char *string2){
    int len1=strlen(string1);
    int len2=strlen(string2);
    if(len1!=len2){
        printf("Not a rotation\n");
        return;
    }
    char *check_string=(char*)malloc(2*len1+1);
    strcpy(check_string,string1);
    strcat(check_string,string1);
    if(check_substring(check_string,string2)){
        printf("Yes string2 is rotation of string1\n");
        return;
    }
     printf("Not a rotation\n");
}

int main(){
    char string1[256];
    char string2[256];
    scanf("%[^\n]",string1);
    getchar();
    scanf("%[^\n]",string2);
    check_rotation(string1,string2);
}
