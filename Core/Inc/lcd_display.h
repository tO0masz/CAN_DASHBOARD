#include <stdint.h>

#define MAX_RPM 10000

void init_lcd();

void draw_static_components();

void draw_rpm_max_line(uint64_t rpm);

void draw_rpm(uint64_t rpm);