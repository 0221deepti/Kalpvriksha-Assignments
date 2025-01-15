//solution of question 6
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
bool check_anagrams(char *string1,char *string2){
    int store1[26]={0};
    int store2[26]={0};
    int len1=strlen(string1);
    int len2=strlen(string2);
    if(len1!=len2) return false;
    for(int i=0;i<len1;i++){
        store1[tolower(string1[i])]++;
        store2[tolower(string2[i])]++;
    }
    for(int i=0;i<26;i++){
        if(store1[i]!=store2[i]) return false;
    }
    return true;
}
int main(){
    char string1[400];
    char string2[400];
    scanf("%[^\n]",string1);
    getchar();
    scanf("%[^\n]",string2);
    if(check_anagrams(string1,string2)){
        printf("Yes, strings are anagrams\n");
        return 0;
    }
    printf("No strings are not anagrams\n");
}
