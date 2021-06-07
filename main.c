/*
 * Projekt-Name:
 *
 * Created (Datum): 
 *  Author: Nathanael
 */ 


#include <avr/io.h>
#define F_CPU 1200000UL  // 1,2 MHz (für ATtiny13, ansonsten verwendete Frequenz einfügen (für die "delay"-Funktion))
#include <util/delay.h>
// hier die benötigten Bibliotheken einfügen und wiederkehrende Befehle mit
// #define deklarieren

void Port_Init(void)
{
    // PB0 als Ausgang, der Port ist auch zu PWM fähig
    DDRB |= (1<<DDB0);
    // alle LEDs aus
    PORTB = 0;
}
void ADC_Init(void)
{
	// Vcc als Referenzspannugn wählen
	ADMUX = (0<<REFS0);

	// Frequenzvorverteiler: 8 --> 1,2 MHz / 8 = 150 kHz (Takt)
	ADCSRA = (1<<ADPS1) | (1<<ADPS0);

	// "Free-running"-Modus
	ADCSRA |= (1<<ADATE);

	// ADC aktivieren
	ADCSRA |= (1<<ADEN);

	// "Dummy-Readout" oder kompletter Start des Wandlers (weil free-running)
	ADCSRA |= (1<<ADSC);
	while(ADCSRA & (1<<ADSC))	// aud Abschluss der Konverstierung warten
	{

	}
	// Ergebnis auslesen, da sonst die nächste Messung nicht eingetragen wird
	(void) ADCW;
}

int main(void)
{
    Port_Init();
    ADC_Init();
    while(1)
    {

    }
    return 0;
}
