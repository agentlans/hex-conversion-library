# Hexadecimal Conversion Library

A lightweight C library for converting binary data to hexadecimal strings and vice versa. This library provides two core functions: `binary_to_hex` and `hex_to_binary`, which are efficient and easy to use.

## Features

- Convert binary data to a null-terminated hexadecimal string.
- Convert a hexadecimal string back into binary data.
- Handles invalid input gracefully with error codes.
- Lightweight and dependency-free (only uses standard C libraries).

## Functions

### `void binary_to_hex(char* output, const char* input, size_t input_len)`

Converts binary data into a string of hexadecimal characters.

#### Parameters:
- **`output`**: Pointer to the pre-allocated output buffer. Must have enough space for `2 * input_len + 1` characters (including the null terminator).
- **`input`**: Pointer to the binary data to be converted.
- **`input_len`**: Length of the input binary data in bytes.

#### Example:
```c
char binary_data[] = {0x12, 0x34, 0xAB, 0xCD};
char hex_output; // 2 * 4 bytes + 1 for null terminator

binary_to_hex(hex_output, binary_data, sizeof(binary_data));
printf("Hexadecimal: %s\n", hex_output); // Output: "1234abcd"
```

### `int hex_to_binary(char* output, const char* input, size_t input_len)`

Converts a hexadecimal string back into binary data.

#### Parameters:
- **`output`**: Pointer to the pre-allocated output buffer. Must have enough space for `input_len / 2` bytes.
- **`input`**: Pointer to the null-terminated hexadecimal string.
- **`input_len`**: Length of the input string in characters (excluding the null terminator).

#### Returns:
- `0`: Success.
- Non-zero: Error (e.g., invalid hex character or odd-length input).

#### Example:
```c
const char hex_input[] = "1234abcd";
char binary_output;

if (hex_to_binary(binary_output, hex_input, strlen(hex_input)) == 0) {
    printf("Binary data converted successfully.\n");
} else {
    printf("Error: Invalid hexadecimal string.\n");
}
```

## Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/agentlans/hex-conversion-library.git
   cd hex-conversion-library
   ```

2. Include the library in your project:
   - Add `hex_conversion.h` to your include path.
   - Add the implementation file (`hex_conversion.c`) to your build system.

3. Compile your project with the library:
   ```bash
   gcc -o my_program my_program.c hex_conversion.c
   ```

## Testing

A test program for validation is included in the repository (`test_hex_conversion.c`).

### Run Tests:
Compile and execute the test program:
```bash
gcc -o test_hex_conversion test_hex_conversion.c hex_conversion.c
./test_hex_conversion
```

If all tests pass successfully, you'll see:
```
All tests passed successfully!
```

## Example Use Cases

1. **Data Serialization**: Convert binary data into a human-readable hexadecimal format for logging or storage.
2. **Networking**: Encode and decode binary payloads in hexadecimal format for transmission over text-based protocols.
3. **Cryptography**: Represent hash values or encryption keys as hexadecimal strings.

## License

Copyright :copyright: 2025 Alan Tseng

MIT Licence
