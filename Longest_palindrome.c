/*
Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome.
Example 1:
Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:
Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
 Constraints:

1 <= s.length <= 2000
s consists of lowercase and/or uppercase English letters only.
*/
//solution
int longestPalindrome(char* s) {
    int lower_store[26]={0};
    int upper_store[26]={0};
    int count=0;
    int odd=0;
    for(int i=0;i<s[i]!='\0';i++){
        if(islower(s[i])){
           lower_store[s[i]-'a']++;
        }
        else{
            upper_store[s[i]-'A']++;
        }
    }

    for(int i=0;i<26;i++){
    if(lower_store[i]%2==0){
        count+=lower_store[i];}
    else{
         count+=lower_store[i]-1;
         odd=1;
        }

    if(upper_store[i]%2==0){
        count+=upper_store[i];
     }
    else{
         count+=upper_store[i]-1;
         odd=1;
        }
       }
    return count+odd;
    }
int main(){
char *input=(char*)malloc(2001*sizeof(char));
scanf("%s",input);
int res=longestPalindrome(input);
printf("Longest palindrome possible is:%d\n",res);
}
