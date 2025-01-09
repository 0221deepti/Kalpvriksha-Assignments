#include<stdio.h>

int string_length(char string[101]){
    int i=0;
    int count=0;
    while(string[i]!='\0'){
        count++;
        i++;
    }
    return count;
}

int main(){
    char string[101];
    printf("Enter string: ");
    scanf("%s",string);
    int count_store[26]={0};
    char ans[202]={0};
    int length=string_length(string);
    for(int i=0;i<length;i++){
        char ch=string[i];
        count_store[ch-'a']++;
    }
    int k=0;
    for(int i=0;i<26;i++){
        if(count_store[i]>0){
            ans[k++]=i+'a';

            int freq=count_store[i];
            char char_freq[10];
            int temp=0;
            while(freq>0){
                char_freq[temp++]=freq%10+'0';
                freq/=10;
            }
            for(int j=temp-1;j>=0;j--){
                ans[k++]=char_freq[j];
            }

        }
    }
    ans[k]='\0';
    printf("%s",ans);
}
