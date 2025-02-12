#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "hex_conversion.h"

// Helper function to print binary data
void print_binary(const char* data, size_t len) {
    for (size_t i = 0; i < len; i++) {
        printf("%02x", (unsigned char)data[i]);
    }
    printf("\n");
}

// Test function
void run_test(const char* input, size_t input_len) {
    char hex[input_len * 2 + 1];
    char binary[input_len];

    printf("Original binary: ");
    print_binary(input, input_len);

    // Test binary_to_hex
    binary_to_hex(hex, input, input_len);
    printf("Hex: %s\n", hex);

    // Test hex_to_binary
    int result = hex_to_binary(binary, hex, strlen(hex));
    printf("Converted back to binary: ");
    print_binary(binary, input_len);

    // Verify results
    assert(result == 0);
    assert(memcmp(input, binary, input_len) == 0);
    printf("Test passed!\n\n");
}

int main() {
    // Test case 1: Simple byte sequence
    char test1[] = {0x12, 0x34, 0xAB, 0xCD};
    run_test(test1, sizeof(test1));

    // Test case 2: All zero bytes
    char test2[] = {0x00, 0x00, 0x00};
    run_test(test2, sizeof(test2));

    // Test case 3: All 0xFF bytes
    char test3[] = {0xFF, 0xFF, 0xFF};
    run_test(test3, sizeof(test3));

    // Test case 4: Mixed byte values
    char test4[] = {0x00, 0x7F, 0x80, 0xFF};
    run_test(test4, sizeof(test4));

    // Test case 5: Single byte
    char test5[] = {0xA5};
    run_test(test5, sizeof(test5));

    // Test error cases for hex_to_binary
    char error_output[10];
    assert(hex_to_binary(error_output, "1", 1) != 0);  // Odd length input
    assert(hex_to_binary(error_output, "1G", 2) != 0);  // Invalid hex character

    printf("All tests passed successfully!\n");

    return 0;
}

