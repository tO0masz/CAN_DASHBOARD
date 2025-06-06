#include "lcd_display.h"
#include "ili9341.c"
#include "fonts.c"
#include "testimg.h"
#include "functions.c"

void init_lcd() {
    HAL_GPIO_WritePin(LCD_BL_GPIO_Port, LCD_BL_Pin, GPIO_PIN_SET);
    ILI9341_Unselect();
    ILI9341_Init();
}

void draw_static_components() {
    ILI9341_FillScreen(ILI9341_BLACK);
    ILI9341_WriteString(ILI9341_WIDTH/5, 2*ILI9341_HEIGHT/3, "RPM", Font_16x26, ILI9341_WHITE, ILI9341_BLACK);
    ILI9341_WriteString(3*ILI9341_WIDTH/5, 2*ILI9341_HEIGHT/3, "Speed", Font_16x26, ILI9341_WHITE, ILI9341_BLACK);
}

void draw_rpm_max_line(uint64_t rpm){
    // TODO: Implement this function if needed
    // This function can be used to draw a line for max RPM
}

void draw_rpm(uint64_t rpm) {
    char rpm_str[6];
    intToStr(rpm, rpm_str);
    if(rpm < 10000){
        shift_right(rpm_str, 6 - strlen(rpm_str), 6);
    }
    ILI9341_WriteString(ILI9341_WIDTH/6, ILI9341_HEIGHT/3, rpm_str, Font_16x26, ILI9341_WHITE, ILI9341_BLACK);
}