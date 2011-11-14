#include <pic18f4550.h>
#include "fuses.h"
#include "main.h"

void main() {
    int8_t i = 0;
    char c = 'A';
    char custom_chars[] = {
        0x00, 0x00, 0x00, 0x04,
        0x00, 0x00, 0x00, 0x00,
        
        0x00, 0x00, 0x0e, 0x0a,
        0x0e, 0x00, 0x00, 0x00,
        
        0x00, 0x1f, 0x11, 0x11,
        0x11, 0x1f, 0x00, 0x00
    };
    _asm bcf _WDTCON, 0 _endasm;
    init_io();
    
    lcd_init();
    
    lcd_custom_char_create(custom_chars, 0, 3);
    delay_ms(500);
    lcd_command(LCD_CMD_DISPLAY_CONTROL | LCD_CMD_DISPLAY_CONTROL_ON);
    //lcd_test_do();
    while(1) {
        lcd_position(0, 0);
        lcd_write(i++ % 3, LCD_RS_DATA, 2);
        delay_ms(150);
        PORTEbits.RE1 ^= 1;
    }
}
