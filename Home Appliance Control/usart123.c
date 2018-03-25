#include<avr/io.h>
#include<compat/deprecated.h>
#include"uart.h"
#include"uart.c"
#include<avr/interrupt.h>
#include<util/delay.h>
void main()
{
	uart_init(UART_BAUD_SELECT(9600,F_CPU));
	sei();
					uart_puts("HOME APPLIANCE CONTROL SYSTEM\n\r");
					

	char c;
	int i=0;
	sbi(DDRC,4); //DIGITAL SWITCH1
	sbi(DDRC,5); //DIGITAL SWITCH2
	while(1)
	{
		if(i==7)
		{
			uart_puts("\n\r");
			uart_puts("          HOME APPLIANCE CONTROL SYSTEM              \n\r");
			
			
			uart_puts("*******************************************");
			uart_puts("\n\r");
			uart_puts("\n\r");
			uart_puts("SYSTEM COMMAND");
			uart_puts("\n\r");
			uart_puts("press w = SYSTEM1 ON");
			uart_puts("\n\r");
			
			uart_puts("press s = SYSTEM1 OFF");
			uart_puts("\n\r");
			uart_puts("press a = SYSTEM2 ON");
			uart_puts("\n\r");
			uart_puts("press d = SYSTEM2 OFF");
			uart_puts("\n\r");
			uart_puts("press z = ALL SYSTEM ON");
			uart_puts("\n\r");
			uart_puts("press x = ALL SYSTEM OFF");
			uart_puts("\n\r");
			uart_puts("\n\r");
			uart_puts("*******************************************");
			uart_puts("\n\r");
			i=0;
		}
		
		
		c=uart_getc();
		
		i++;

						
							if(!(c & UART_NO_DATA))
							{
							
						
								
								if(c=='w')
								{
									sbi(PORTC,4);
									uart_puts("***********--------- ");
									uart_puts("SYETEM1 IS ON");
									uart_puts(" ---------***********");

									uart_puts("\n\r");
								}
								if(c=='s')
								{
									cbi(PORTC,4);
									uart_puts("***********--------- ");
									uart_puts("SYSTEM1 IS OFF");
									uart_puts(" ---------***********");
									
									uart_puts("\n\r");
								}
								if(c=='a')
								{
									sbi(PORTC,5);
									uart_puts("***********--------- ");
									uart_puts("SYETEM2 IS ON");
									uart_puts(" ---------***********");
									
									uart_puts("\n\r");
								}
								if(c=='d')
								{
									cbi(PORTC,5);
									uart_puts("***********--------- ");
									uart_puts("SYSTEM2 IS OFF");
									uart_puts(" ---------***********");
									uart_puts("\n\r");
								}
								if(c=='z')
								{
									sbi(PORTC,4);
									sbi(PORTC,4);
									
									uart_puts("***********--------- ");
									uart_puts("ALL SYSTEMS ARE ON");
									uart_puts(" ---------***********");
									
									uart_puts("\n\r");

								}
								if(c=='x')
								{
									cbi(PORTC,4);
									cbi(PORTC,5);
									uart_puts("***********--------- ");
									
									uart_puts("ALL SYSTEMS ARE OFF");
									uart_puts(" ---------***********");
									
									uart_puts("\n\r");
								}
								
								
							}
							
							
							
							_delay_ms(500);
	}
}

