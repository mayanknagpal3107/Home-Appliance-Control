#include<avr/io.h>
#include<compat/deprecated.h>
#include"uart.h"
#include"uart.c"
#include<avr/interrupt.h>
void main()
{
	uart_init(UART_BAUD_SELECT(9600,F_CPU));
	sei();
					uart_puts("welcome\n\r");
					uart_putc('d');

	char c;
	sbi(DDRC,2);  //led
	sbi(DDRC,3);  //led
	sbi(DDRD,5);  //en2
	sbi(PORTD,5); //high
	sbi(DDRD,7);
	sbi(DDRD,6);
	while(1)
	{
		c=uart_getc();
						//	if(c!=0)
							if(!(c & UART_NO_DATA))
							{
								if(c=='F')
								{
									cbi(PORTD,6);
									sbi(PORTD,7);
									uart_puts("CLOCKWISE\n");
								}
								if(c=='R')
								{
									sbi(PORTD,6);
									cbi(PORTD,7);
									uart_puts("ANTICLOCKWISE\n");
								}
								
							}
	}
}

