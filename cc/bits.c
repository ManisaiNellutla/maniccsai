#include <stdio.h>

int main() {
    int a[20], b[30], i, j = 0, count = 0, n;

    // Get the frame length from the user
    printf("Enter frame length: ");
    scanf("%d", &n);

    // Get the input frame from the user (only 0's and 1's)
    printf("Enter input frame (0's & 1's only): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Perform bit stuffing
    for (i = 0; i < n; i++) {
        

        // If we encounter a 1, increase the count
        if (a[i] == 1) {
            count++;
        } else {
            count = 0;  // Reset count if it's 0
        }
        b[j] = a[i];
        j++;

        // If there are 5 consecutive 1's, add a 0 to avoid a sequence of 6
        if (count == 5) {
            b[j] = 0;
            j++;
            count = 0; // Reset count after adding 0
        }
    }

    // Output the stuffed frame
    printf("After stuffing, the frame is: ");
    for (i = 0; i < j; i++) {
        printf("%d", b[i]);
    }
    printf("\n");

    return 0;
}
