#include <stdio.h>
#include <string.h>

void encrypt(char plain[], char key[], char cipher[]) {
    int i, keyLength = strlen(key);
    for (i = 0; plain[i] != '\0'; i++) {
        cipher[i] = plain[i] ^ key[i % keyLength]; // XOR encryption
    }
    cipher[i] = '\0'; // Null-terminate the string
}
void decrypt(char cipher[], char key[], char plain[]) {
    int i, keyLength = strlen(key);
    for (i = 0; cipher[i] != '\0'; i++) {
        plain[i] = cipher[i] ^ key[i % keyLength]; // XOR decryption
    }
    plain[i] = '\0'; // Null-terminate the string
}
int main() {
    int choice;
    char plain[50], cipher[50] = "", key[50];

    while (1) {
        printf("\n----- MENU -----\n");
    	printf("1: Data Encryption\n");
    	printf("2: Data Decryption\n");
    	printf("3: Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume leftover newline

        switch (choice) {
            case 1:
                // Encrypt
                printf("Enter the plain text: ");
                scanf("%s", plain); // Simple input
                printf("Enter the encryption key: ");
                scanf("%s", key);

                encrypt(plain, key, cipher);
                printf("The encrypted text is: %s\n", cipher);
                break;

            case 2:
                // Decrypt
                if (strlen(cipher) == 0) {
                    printf("No encrypted text found! Please encrypt first.\n");
                } else {
                    decrypt(cipher, key, plain);
                    printf("The decrypted text is: %s\n", plain);
                }
                break;

            case 3:
                // Exit
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}

// Function to display menu