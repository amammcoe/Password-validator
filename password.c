#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 20

// Function to merge multiple spaces into a single space
void mergeSpaces(const char *input, char *output) {
    int j = 0; // Index for the output string
    int length = strlen(input);

    for (int i = 0; i < length; i++) {
        // Only add non-space characters or a single space if it's not already there
        if (input[i] != ' ' || (j > 0 && output[j - 1] != ' ')) {
            output[j++] = input[i];
        }
    }
    output[j] = '\0'; // Null-terminate the new string
}

// Function to remove all whitespace from the string
void removeWhitespace(const char *input, char *output) {
    int j = 0; // Index for the output string
    int length = strlen(input);

    for (int i = 0; i < length; i++) {
        // Only add non-space characters
        if (input[i] != ' ') {
            output[j++] = input[i];
        }
    }
    output[j] = '\0'; // Null-terminate the new string
}

int isValidPassword(const char *password) {
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;
    int length = strlen(password);

    // Check character types
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) hasUpper = 1;
        else if (islower(password[i])) hasLower = 1;
        else if (isdigit(password[i])) hasDigit = 1;
        else if (ispunct(password[i])) hasSpecial = 1;
    }

    // Provide feedback on missing criteria
    if (!hasUpper) {
        printf("Password must contain at least one uppercase letter.\n");
    }
    if (!hasLower) {
        printf("Password must contain at least one lowercase letter.\n");
    }
    if (!hasDigit) {
        printf("Password must contain at least one digit.\n");
    }
    if (!hasSpecial) {
        printf("Password must contain at least one special character (e.g., @, #, $, %).\n");
    }

    // Return validity status
    return hasUpper && hasLower && hasDigit && hasSpecial;
}

int main() {
    char input[MAX_PASSWORD_LENGTH];
    char processedPassword[MAX_PASSWORD_LENGTH];
    char finalPassword[MAX_PASSWORD_LENGTH];

    while (1) { // Loop until a valid password is entered
        printf("Enter a password (at least 8 characters, with uppercase, lowercase, digit, and special character): ");
        scanf(" %[^\n]", input); // Read password including spaces

        // Merge spaces
        mergeSpaces(input, processedPassword);

        // Remove all whitespace
        removeWhitespace(processedPassword, finalPassword);

        // Display the processed password without spaces
        printf("Processed password (without spaces): '%s'\n", finalPassword);

        // Check length first
        if (strlen(finalPassword) < 8) {
            printf("Password must be at least 8 characters long. Please try again.\n");
            continue; // Redirect to start of the loop
        }

        // Check if the password is valid
        if (isValidPassword(finalPassword)) {
            printf("Password is valid.\n");
            break; // Exit the loop if the password is valid
        } else {
            printf("Password is not valid. Please try again.\n");
        }
    }

    return 0;
}
