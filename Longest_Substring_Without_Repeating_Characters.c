/*
Longest Substring Without Repeating Characters

Given a string s, find the length of the longest 
substring without repeating characters.
Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 
Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.
*/
// solution
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int lengthOfLongestSubstring(char* s) {
    int hash[256];
    memset(hash,-1,sizeof(hash));
    int len=0;
    int max_len=0;
    int first=0;

    for(int second=0;s[second]!='\0';second++){
       if(hash[s[second]]!=-1 && hash[s[second]]>=first){
        first=hash[s[second]]+1;
       }
        hash[s[second]]=second;
        len=second-first+1;
        max_len=max_len>len ? max_len:len;
    }
    return max_len;
}

int main(){
    char* input=(char*)malloc(100*(sizeof(char)));
    scanf("%s",input);
    int res=0;
    res=lengthOfLongestSubstring(input);
    printf("Longest substring without repeating character is:%d\n",res);
    return 0;
}
