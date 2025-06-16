#include <stdint.h>
#include "functions.h"

// Function to convert an integer to a uint64_t string representation
void intToStr(uint64_t num, char *buffer) {
    sprintf(buffer, "%u", num);
}

// Function to convert a string representation of a number to a uint64_t integer (only positive digits)
void strToInt(const char *str, uint16_t strLen, uint64_t *num) {
    *num = 0;
    for(uint8_t i = 0; i < strLen; i++) {
        if(str[i] >= '0' && str[i] <= '9') {
            *num = *num * 10 + (str[i] - '0');
        } else {
            // Handle invalid character
            *num = 0;
            return;
        }
    }
}

// Function to shift characters in a string to the right 
void shift_right(char *str, uint8_t shift_by) {
    size_t len = strlen(str);

    // Shift characters from the end to avoid overwriting data
    for (int i = len; i >= 0; i--) {
        str[i + shift_by] = str[i];
    }

    // Set ('0') to start
    for (int i = 0; i < shift_by; i++) {
        str[i] = '0';
    }
}