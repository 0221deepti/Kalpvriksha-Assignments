//String rotation
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
void check_rotation(char *string1,char *string2){
    int len1=strlen(string1);
    int len2=strlen(string2);
    if(len1!=len2){
        printf("No strings are not rotation of each other\n");
        return;
    }
    char *check_string=(char *)malloc(len1*2+1);
    strcpy(check_string,string1);
    strcat(check_string,string1);
    
    char *pointer=strstr(check_string,string2);
    if(pointer==NULL){
        free(check_string);
         printf("No strings are not rotation of each other\n");
        return;
    }
    else{
        printf("Yes strings are rotation of each other\n");
    }
    free(check_string);
    return;
}
int main(){
    char string1[1000];
    char string2[1000];
    scanf("%[^\n]",string1);
    getchar();
    scanf("%[^\n]",string2);
    check_rotation(string1,string2);
}
