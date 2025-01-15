//solution of question 8
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Compress_String(char *string){
    int store[26]={0};
    int len=strlen(string);
    char *new_String=(char*)malloc(20001);
    int k=0;
    int i=0;
    while(string[i]!='\0'){
        store[string[i]-'a']++;
        i++;
    }
    for(int i=0;i<26;i++){
        if(store[i]>0){
            new_String[k++]=i+'a';
            
            int freq=store[i];
            char char_freq[10];
            int temp=0;
            while(freq>0){
                char_freq[temp++]=freq%10+'0';
                freq/=10;
            }
            for(int j=temp-1;j>=0;j--){
                new_String[k++]=char_freq[j];
            }
           
        }
    }
    new_String[k]='\0';
    if(len>strlen(new_String)){
        printf("%s",new_String);
        free(string);
        free(new_String);
        return;
    }
    printf("%s",string);
    return;
}
int main(){
    char *string=(char*)malloc(20001);
    scanf("%s",string);
    Compress_String(string);
    return 0;
}
