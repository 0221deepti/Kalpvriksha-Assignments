#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 10
#define MAX_COLS 101
#define MAX_NAME_LENGTH 50

int isVowel(char ch) {
    ch = tolower(ch); 
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

int isValidName(char name[]) {
    for (int i = 0; i < strlen(name); i++) {
        if (!isalpha(name[i])) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    int rows, cols, vowel_count = 0;
    char names[MAX_ROWS][MAX_COLS][MAX_NAME_LENGTH];
    char longest_name[MAX_NAME_LENGTH] = "";

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    while (rows < 1 || rows > 10) { 
        printf("Rows should be between 1-10 only\n");
        printf("Enter number of rows: ");
        scanf("%d", &rows);
    }
    printf("Enter number of columns: ");
    scanf("%d", &cols);
    while (cols < 1 || cols > 101) {
        printf("Columns should be between 1-101 only\n");
        printf("Enter number of columns: ");
        scanf("%d", &cols);
    }
    printf("Enter the names:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
           while (1) {
                printf("Name at (%d,%d): ", i, j);
                scanf("%s", names[i][j]);

                if (isValidName(names[i][j])) {
                    break; 
                } else {
                    printf("Names should only contain alphabets.\n");
                }
            }
            if (isVowel(names[i][j][0])) {
                vowel_count++;
            }
            if (strlen(names[i][j]) > strlen(longest_name)) {
                strcpy(longest_name, names[i][j]);
            }
        }
    }
    printf("\nThe 2D array of names is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s ", names[i][j]);
        }
        printf("\n");
    }
    printf("\nNumber of names starting with a vowel: %d\n", vowel_count);
    printf("The longest name: %s\n", longest_name);
    return 0;
}
