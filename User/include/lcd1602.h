 /*****************************************************************************
    *Ten Tep          :     lcd1602.h
    *Ngay             :     27/12/2016
    *Tac Gia          :     MCA team
    *Cong Ty          :     MCA
    *Webside          :     mca.vn
    *Phien Ban        :     V1.0
    *Tom Tat          :     
    ***************************************************************************/	
#ifndef __LCD1602_H
#define __LCD1602_H

#include <main.h>

#define LINE_1 0x80
#define LINE_2 0xC0
#define CLEAR_LCD 0x01

void lcd1602_enable(void);
void lcd1602_send_4bit_data ( unsigned char cX );
void lcd1602_send_command (unsigned char cX );
void lcd1602_init (void );
void lcd1602_gotoxy(unsigned char x, unsigned char y);
void lcd1602_clear(void);
void lcd1602_putchar ( unsigned int cX );
void lcd1602_puts (char *s);
//void lcd_putsf(char flash *s);

#endif
/*------------------------------KET THUC FILE-------------------------------
 _________________________________MCA Team__________________________________*/ 
