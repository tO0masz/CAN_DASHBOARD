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
    uint16_t max_rpm_index = (rpm * ILI9341_WIDTH) / MAX_RPM;
    uint8_t max_rpm_color_red = 0.85 * ILI9341_WIDTH;
    uint8_t max_rpm_color_yellow = 0.7 * ILI9341_WIDTH;
    for(uint16_t i = 0; i < max_rpm_index; i++) {
        if(i > max_rpm_color_red) {
            ILI9341_FillRectangle(i, 3, 1, 5, ILI9341_RED);
        } else if(i > max_rpm_color_yellow) {
            ILI9341_FillRectangle(i, 3, 1, 5, ILI9341_YELLOW);
        }
        else {
            ILI9341_FillRectangle(i, 3, 1, 5, ILI9341_BLUE);
        }
    }

    for(uint16_t i = max_rpm_index; i < ILI9341_WIDTH; i++) {
        ILI9341_FillRectangle(i, 3, 1, 5, ILI9341_BLACK);

    }
}

void draw_rpm(uint64_t rpm) {
    char rpm_str[6];
    intToStr(rpm, rpm_str);
    if(rpm < 10000){
        shift_right(rpm_str, 6 - strlen(rpm_str), 6);
    }
    ILI9341_WriteString(ILI9341_WIDTH/6, ILI9341_HEIGHT/3, rpm_str, Font_16x26, ILI9341_WHITE, ILI9341_BLACK);
}