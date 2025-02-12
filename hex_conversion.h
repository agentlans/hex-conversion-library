#ifndef HEX_CONVERSION_H
#define HEX_CONVERSION_H

#include <stddef.h> // For size_t

/**
 * @brief Converts binary data to a hexadecimal string representation.
 *
 * This function takes an array of binary data and converts it into a null-terminated
 * string of hexadecimal characters (lowercase). Each byte of binary data is represented
 * by two hexadecimal characters.
 *
 * @param[out] output    A pointer to the output buffer where the hexadecimal string will be stored.
 *                       The buffer must have enough space to store `2 * input_len + 1` characters
 *                       (including the null terminator).
 * @param[in]  input     A pointer to the input buffer containing binary data.
 * @param[in]  input_len The length of the input buffer in bytes.
 *
 * @note The output buffer must be pre-allocated by the caller.
 */
void binary_to_hex(char* output, const char* input, size_t input_len);

/**
 * @brief Converts a hexadecimal string back into binary data.
 *
 * This function takes a null-terminated string of hexadecimal characters and converts
 * it back into its corresponding binary representation. Each pair of hexadecimal characters
 * represents one byte of binary data. The function returns an error code if the input string
 * contains invalid characters or has an odd length.
 *
 * @param[out] output    A pointer to the output buffer where the binary data will be stored.
 *                       The buffer must have enough space to store `input_len / 2` bytes.
 * @param[in]  input     A pointer to the null-terminated input string containing hexadecimal characters.
 * @param[in]  input_len The length of the input string in characters (excluding the null terminator).
 *
 * @return int           Returns 0 on success. Returns a non-zero value if:
 *                       - The input length is odd (not divisible by 2).
 *                       - The input contains invalid hexadecimal characters.
 *
 * @note The output buffer must be pre-allocated by the caller.
 */
int hex_to_binary(char* output, const char* input, size_t input_len);

#endif // HEX_CONVERSION_H

