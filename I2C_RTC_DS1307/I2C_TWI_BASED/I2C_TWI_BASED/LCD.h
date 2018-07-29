/*
 * LCD.h
 *
 * Created: 6/24/2018 5:17:47 PM
 *  Author: Ram
 */ 


#ifndef LCD_H_
#define LCD_H_

void LCD_init(void);

void LCD_cmd(uint8_t command);

void LCD_data(uint8_t data);

void LCD_print(int line_no, char *info);

#endif /* LCD_H_ */