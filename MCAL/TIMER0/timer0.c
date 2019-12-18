#include "timer0.h"


void TMR0_delay_normal_ms(U16 t){
	TCNT0 = 0; 
	F32 counts  = (t * 0.001 /(1/F_CPU))-1;
	if(counts < 255)
		SET_BIT(TCCR0, 0);
	else 
		TCCR0 |= (1 << 2) | (1 << 0);
	while (1){
		if(TCNT0 >= counts){
			break;
			TCNT0 = 0;
		}
	}
}

ISR(TIMER0_OVF_vect)
{
	// keep a track of number of overflows
	n_overflows++;
}

void TMR0_delay_INT_ms(U16 t){
	TCNT0 = 0;
	TCCR0 |= (1 << 2) | (1 << 0);
	F32 req_flows = t * 0.001 / (255 + 1) * 1024 / F_CPU;
	
	n_overflows = 0;                 // initialize n_overflow instead of garbage value
	TIMSK |= (1 << TOIE0);            // enable overflow interrupt
	sei();                            // enable global interrupt
	while (1)
	{
		if (n_overflows >= (int)req_flows)
		{
			if (TCNT0 >= (req_flows - (int)req_flows) * (255 + 1))
			{
				TCNT0 = 0;
				n_overflows = 0;    // RESET overflows to begin from 0
				break;
			}
		}
	} 
}
