#include <stdio.h>
#include <string.h>

int main() {
    char input[50], stuffed[100], ch;
    int i = 0, j = 0, n, pos;

    // Get the input string
    printf("Enter string: ");
    scanf("%s", input);

    // Calculate the length of the input string
    n = strlen(input);

    // Get the position to insert the character
    printf("Enter position (1-based index): ");
    scanf("%d", &pos);

    // Validate the position
    while (pos < 1 || pos > n + 1) {
        printf("Invalid position. Enter again: ");
        scanf("%d", &pos);
    }

    // Get the character to insert
    printf("Enter the character: ");
    scanf(" %c", &ch); // Notice the space before %c to consume any leftover newline

    // Start the stuffed frame with "dle stx"
    stuffed[j++] = 'd';
    stuffed[j++] = 'l';
    stuffed[j++] = 'e';
    stuffed[j++] = 's';
    stuffed[j++] = 't';
    stuffed[j++] = 'x';

    // Perform stuffing
    while (i < n) {
        // Insert the character at the specified position
        if (i == pos - 1) {
            stuffed[j++] = 'd';
            stuffed[j++] = 'l';
            stuffed[j++] = 'e';
            stuffed[j++] = ch;
            stuffed[j++] = 'd';
            stuffed[j++] = 'l';
            stuffed[j++] = 'e';
        }

        // If "dle" sequence is found in input, add an extra "dle" for stuffing
        if (input[i] == 'd' && input[i + 1] == 'l' && input[i + 2] == 'e') {
            stuffed[j++] = 'd';
            stuffed[j++] = 'l';
            stuffed[j++] = 'e';
        }

        // Copy the character from input to stuffed array
        stuffed[j++] = input[i++];
    }

    // Insert at the end if position is after the last character
    if (pos == n + 1) {
        stuffed[j++] = 'd';
        stuffed[j++] = 'l';
        stuffed[j++] = 'e';
        stuffed[j++] = ch;
        stuffed[j++] = 'd';
        stuffed[j++] = 'l';
        stuffed[j++] = 'e';
    }

    // End the stuffed frame with "dle etx"
    stuffed[j++] = 'd';
    stuffed[j++] = 'l';
    stuffed[j++] = 'e';
    stuffed[j++] = 'e';
    stuffed[j++] = 't';
    stuffed[j++] = 'x';
    stuffed[j] = '\0'; // Null-terminate the stuffed string

    // Display the stuffed frame
    printf("\nFrame after stuffing:\n%s\n", stuffed);

    return 0;
}
