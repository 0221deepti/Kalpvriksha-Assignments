//question longest palindrome
#include <stdio.h>
#include <string.h>
char* longest_palindrome(char *s) {
    int len = strlen(s);
    if (len == 0) return "";  

    int start = 0, end = 0;
    void expand_around_center(int left, int right) {
        while (left >= 0 && right < len && s[left] == s[right]) {
            left--;
            right++;
        }
        left++;
        right--;
        if (right - left > end - start) {
            start = left;
            end = right;
        }
    }

    for (int i = 0; i < len; i++) {
        expand_around_center(i, i);
        expand_around_center(i, i + 1);
    }
    static char result[1000];  
    strncpy(result, s + start, end - start + 1);
    result[end - start + 1] = '\0'; 
    return result;
}

int main() {
    char input[1000];
    scanf("%[^\n]", input);

    char *longest = longest_palindrome(input);
    printf("%s\n", longest);

    return 0;
}
