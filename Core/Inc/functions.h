#include <stdint.h>

// Function to convert an integer to a uint64_t string representation
void intToStr(uint64_t num, char *buffer);

void strToInt(const char *str, uint16_t strLen, uint64_t *num);

// Function to shift characters in a string to the right 
void shift_right(char *str, uint8_t shift_by);