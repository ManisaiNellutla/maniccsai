#include <stdio.h>
#include <string.h>

// Length of the generator polynomial
#define GEN_POLY_LENGTH strlen(gen_poly)

// Data to be transmitted and received
char data[28];

// CRC value (used for intermediate and final calculations)
char crc_value[28];

// Generator polynomial
char gen_poly[10];

// Variables for data length and loop indices
int data_length, i, j;

// Function to perform XOR operation
void performXOR() {
    for (j = 0; j < GEN_POLY_LENGTH; j++) {
        crc_value[j] = (crc_value[j] == gen_poly[j]) ? '0' : '1';
    }
}

// Function to calculate the CRC
void calculateCRC() {
    // Initialize the CRC value with the first bits of data
    for (i = 0; i < GEN_POLY_LENGTH; i++) {
        crc_value[i] = data[i];
    }

    do {
        // If the first bit is '1', perform XOR
        if (crc_value[0] == '1') {
            performXOR();
        }

        // Shift the bits to the left by 1 position
        for (j = 0; j < GEN_POLY_LENGTH - 1; j++) {
            crc_value[j] = crc_value[j + 1];
        }

        // Append the next bit from the data
        crc_value[j] = data[i++];
    } while (i <= data_length + GEN_POLY_LENGTH - 1);
}

// Function to simulate the receiver checking for errors
void receiverCheck() {
    printf("Enter the received data: ");
    scanf("%s", data);

    printf("\nData received: %s\n", data);

    // Calculate the CRC for the received data
    calculateCRC();
   
    int i;
    int errorDetected = 0;  // Flag to track error detection

    // Loop through the first GEN_POLY_LENGTH - 1 bits of the crc_value array
    for (i = 0; i < GEN_POLY_LENGTH - 1; i++) {
        if (crc_value[i] == '1') {
            errorDetected = 1;  // If '1' is found, mark error as detected
            break;  // Exit loop early since we found an error
        }
    }

    // After checking all bits, evaluate the result
    if (errorDetected) {
        printf("\nError detected in received data.\n\n");
    } else {
        printf("\nNo error detected in received data.\n\n");
    }
}

// Main function
int main() {
    // Get the data to be transmitted
    printf("Enter data to be transmitted: ");
    scanf("%s", data);

    // Get the generator polynomial
    printf("Enter the generator polynomial: ");
    scanf("%s", gen_poly);

    // Find the length of the input data
    data_length = strlen(data);

    // Pad the data with (length of generator polynomial - 1) zeros
    for (i = data_length; i < data_length + GEN_POLY_LENGTH - 1; i++) {
        data[i] = '0';
    }
    data[i] = '\0'; // Null-terminate the data string

    printf("\nData padded with zeros: %s\n", data);

    // Calculate the CRC
    calculateCRC();

    // Print the calculated CRC value
    printf("CRC (Check Value): %s\n", crc_value);

    // Append the CRC value to the data
    for (i = data_length; i < data_length + GEN_POLY_LENGTH - 1; i++) {
        data[i] = crc_value[i - data_length];
    }
    data[i] = '\0'; // Null-terminate the final data string

    printf("Final data to be sent: %s\n", data);

    // Simulate the receiver checking for errors
    receiverCheck();

    return 0;
}
