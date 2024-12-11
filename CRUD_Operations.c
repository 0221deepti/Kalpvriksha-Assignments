#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "users.txt"

typedef struct {
    int id;
    char name[50];
    int age;
} User;

//for adding new users
void create_user(){
     User user;
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter User ID: ");
    scanf("%d", &user.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", user.name);  // we can use this for taking string with spaces
    printf("Enter Age: ");
    scanf("%d", &user.age);
    // adding data to our file
    fprintf(file, "%d,%s,%d\n", user.id, user.name, user.age);
    fclose(file);

    printf("Successfully Added\n");
}

// for just viewing the data
void read_users(){
     FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("Error opening file.\n");
        return;
    }

    User user;
    printf("\n**** User Data ****\n");
    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF) {
        printf("ID: %d, Name: %s, Age: %d\n", user.id, user.name, user.age);
    }
    fclose(file);
}
// to change user's data
void update_user(){
     int target_id, found = 0;
    User user;
    FILE *file = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!file || !temp) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter the User ID to update: ");
    scanf("%d", &target_id);

    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF) {
        if (user.id == target_id) {
            found = 1;
            printf("Enter new Name: ");
            scanf(" %[^\n]", user.name);
            printf("Enter new Age: ");
            scanf("%d", &user.age);
        }
        fprintf(temp, "%d,%s,%d\n", user.id, user.name, user.age);
    }

    fclose(file);
    fclose(temp);

    if (found) {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("Successfully Updated\n");
    } else {
        remove("temp.txt");
        printf("User ID %d not found.\n", target_id);
    }
}

// to delete data
void delete_user(){
     int target_id, found = 0;
    User user;
    FILE *file = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (!file || !temp) {
        printf("Error opening file.\n");
        return;
    }

    printf("Enter the User ID to delete: ");
    scanf("%d", &target_id);

    while (fscanf(file, "%d,%49[^,],%d\n", &user.id, user.name, &user.age) != EOF) {
        if (user.id == target_id) {
            found = 1;
            continue;  // Skip writing this record to the temp file
        }
        fprintf(temp, "%d,%s,%d\n", user.id, user.name, user.age);
    }

    fclose(file);
    fclose(temp);

    if (found) {
        remove(FILE_NAME);
        rename("temp.txt", FILE_NAME);
        printf("successfully Deleted \n");
    } else {
        remove("temp.txt");
        printf("User ID %d not found.\n", target_id);
    }
}

// to check file is there or not
void ensure_file_exists(){
      FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        printf("Error creating/opening the file.\n");
        exit(1);
    }
    fclose(file);
}

int main() {
    int ch;
    ensure_file_exists();

    while (1) {
        printf("\n**** USERS DATA ****\n");
        printf("1. Add User\n");
        printf("2. View Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Close Program\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                create_user();
                break;
            case 2:
                read_users();
                break;
            case 3:
                update_user();
                break;
            case 4:
                delete_user();
                break;
            case 5:
                printf("closing..\n");
                exit(0);
            default:
                printf("Enter only valid choice (1-5)\n");
        }
    }

    return 0;
}

