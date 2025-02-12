#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "hex_conversion.h"

// Converts the input binary data to a string of hexadecimal characters like [0-9a-f]
// output must have length = 2*input_len + 1 for the trailing null
void binary_to_hex(char* output, const char* input, size_t input_len) {
    static const char hex_chars[] = "0123456789abcdef";
    
    for (size_t i = 0; i < input_len; i++) {
        output[i*2] = hex_chars[(input[i] >> 4) & 0xF];
        output[i*2 + 1] = hex_chars[input[i] & 0xF];
    }
    output[input_len * 2] = '\0';
}

// Converts a string of hexadecimal characters back to binary data
// Returns non-zero if there's any error in input string
int hex_to_binary(char* output, const char* input, size_t input_len) {
    if (input_len % 2 != 0) {
        return 1;  // Error: input length must be even
    }

    for (size_t i = 0; i < input_len; i += 2) {
        char high = tolower(input[i]);
        char low = tolower(input[i+1]);

        if (!isxdigit(high) || !isxdigit(low)) {
            return 1;  // Error: invalid hexadecimal character
        }

        int high_val = (high >= 'a') ? (high - 'a' + 10) : (high - '0');
        int low_val = (low >= 'a') ? (low - 'a' + 10) : (low - '0');

        output[i/2] = (high_val << 4) | low_val;
    }

    return 0;  // Success
}

