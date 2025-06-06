#include <stdint.h>

// Function to convert an integer to a uint64_t string representation
void intToStr(uint64_t num, char *buffer) {
    sprintf(buffer, "%u", num);
}

// Function to shift characters in a string to the right 
void shift_right(char *str, uint8_t shift_by, int buffer_size) {
    size_t len = strlen(str);

    // Protection against buffer overflow
    if (len + shift_by >= buffer_size) {
        shift_by = buffer_size - len - 1; // leave place for '\0'
    }

    // Shift characters from the end to avoid overwriting data
    for (int i = len; i >= 0; i--) {
        str[i + shift_by] = str[i];
    }

    // Set ('0') to start
    for (int i = 0; i < shift_by; i++) {
        str[i] = '0';
    }
}