#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

<<<<<<< HEAD
#include "user.h"

=======
>>>>>>> origin/main
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define FILENAME "password.txt"

// Function prototypes
void createAccount();
void login();

int main() {
    int choice;

    // Main menu
    printf("Welcome to the Movie booking application\n");
    printf("1. Login\n");
    printf("2. Create Account\n");
<<<<<<< HEAD
    printf("3. Exit\n");
=======
>>>>>>> origin/main
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            login();
            break;
        case 2:
            createAccount();
            break;
<<<<<<< HEAD
        case 3:
        	exit(0);
        	break;
=======
>>>>>>> origin/main
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}

// Function to create a new account
void createAccount() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int fd;

    // Get username and password from user
    printf("Enter username (max %d characters): ", MAX_USERNAME_LENGTH);
    scanf("%s", username);
    printf("Enter password (max %d characters): ", MAX_PASSWORD_LENGTH);
    scanf("%s", password);

    // Open password file in append mode
    fd = open(FILENAME, O_WRONLY | O_APPEND | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Write username and password to file
    dprintf(fd, "%s %s\n", username, password);
    close(fd);

    printf("Account created successfully\n");
}

// Function to authenticate login
void login() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char fileUsername[MAX_USERNAME_LENGTH];
    char filePassword[MAX_PASSWORD_LENGTH];
    FILE *file;

    // Get username and password from user
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Open password file in read mode
    file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Read usernames and passwords from file and check for match
    while (fscanf(file, "%s %s", fileUsername, filePassword) != EOF) {
        if (strcmp(username, fileUsername) == 0 && strcmp(password, filePassword) == 0) {
            fclose(file);
            printf("Login successful\n");
<<<<<<< HEAD
            //return;
            //main1();
        }
    }
	main1();
	//insert_details();
=======
            return;
        }
    }

>>>>>>> origin/main
    fclose(file);
    printf("Login failed. Incorrect username or password\n");
}
