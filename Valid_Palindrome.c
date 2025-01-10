/* VALID PALINDROME
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. 
Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.
Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
Constraints:
1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.
************************************************ */
// Soltuion

#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<stdbool.h>

bool check_pallindrome(char *new_string){
    int s=0;
    int e=strlen(new_string)-1;
    while(s<e){
        if(*(new_string+s)!=*(new_string+e)) return 0;
        s++;
        e--;
    }
    
    return 1;
}

bool isPalindrome(char* s) {
    int length=strlen(s);
    char *new_string=(char*)malloc(length+1*sizeof(char));
    char *p=new_string;
    if(new_string==NULL) return 0;
    while(*s!='\0'){
        if(isupper(*s)){
            *s=tolower(*s); 
        }
        if(isalnum(*s)){
            *new_string=*s;
            new_string++;
        }
        else{
            s++;
            continue;
        }
        s++;
    }
    *new_string='\0';
    new_string=p;
    bool res=check_pallindrome(new_string);
    free(new_string);
   return res;
}

int main() {
  char input[2000001];
  printf("enter a string:\n");
  fgets(input,sizeof(input),stdin);
  if(isPalindrome(input)){
      printf("String is palindrome\n");
  }
  else
   printf("String is not palindrome\n");

    return 0;
}
