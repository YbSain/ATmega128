#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	unsigned char rx_data;
	
	DDRA = 0xFF;
	PORTE = 0xFF;
	
	UBRR0H = 103 >> 8;
	UBRR0L = 103;
	UCSR0A = 0x00;
	UCSR0B = 0x18;
	UCSR0C = 0x06;
	
	rx_data = UDR0;
	
    while (1)
	{		
		while( !(UCSR0A & 0x80 ));
		rx_data = UDR0;
		
		while(!(UCSR0A & 0x20));
		UDR0 = rx_data;
		
		PORTA = 0xFF;
		_delay_ms(10);
		PORTA = 0x00;
	}
	return 0;
}

