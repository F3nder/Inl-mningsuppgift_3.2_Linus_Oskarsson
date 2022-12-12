/************************************************************************/
/* headder.h: Innehåller makron och funktionsdefinitioner för 
              implementering av blinkning av lysdioder på Arduino UNO.  */
/************************************************************************/
#ifndef HEADDER_H_
#define HEADDER_H_


/* Klockfrekvens */
#define F_CPU 16000000UL


/* Inkluderingsdirektiv */
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


/* Makron */
#define LED_1 0   //Lysdiod ansluten till pin 8
#define LED_2 1   //Lysdiod ansluten till pin 9
#define LED_3 2   //Lysdiod ansluten till pin 10

#define BUTTON_1 5   //Tryckknapp ansluten till pin 13

#define LED_1_ON PORTB |= (1 << LED_1)                                  //Tänder lydiod ansluten till pin 8
#define LED_2_ON PORTB |= (1 << LED_2)                                  //Tänder lydiod ansluten till pin 9
#define LED_3_ON PORTB |= (1 << LED_3)                                  //Tänder lydiod ansluten till pin 10
#define LEDS_ON PORTB |= ((1 << LED_1) | (1 << LED_2) | (1 << LED_3))   //Tänder alla lysdider

#define LED_1_OFF PORTB &= ~(1 << LED_1)                                  //Släcker lydiod ansluten till pin 8
#define LED_2_OFF PORTB &= ~(1 << LED_2)                                  //Släcker lydiod ansluten till pin 9
#define LED_3_OFF PORTB &= ~(1 << LED_3)                                  //Släcker lydiod ansluten till pin 10
#define LEDS_OFF PORTB &= ~((1 << LED_1) | (1 << LED_2) | (1 << LED_3))   //Släcker alla lysdider

#define BUTTON_1_IS_PRESSED (PINB &(1 << BUTTON_1))   //Kollar om tryckknappen asnluten till pin 13 är nedtryckt
	
typedef enum { false, true }bool;   //Implementering av datatypen bool


/* Funktionsdefinitioner */

/************************************************************************/
/* setup: Initierar I/O-portar och aktiverar avbrott.                   */
/************************************************************************/
void setup(void);

/************************************************************************/
/* led_toggle: Togglar lysdioder mellan att blinka och vara släckta.    */
/************************************************************************/
void led_toggle(void);

/************************************************************************/
/* led_blink_sequence: Blinkar lysdioderna i ordning "LED_1 till LED_3.
                       
					   -blink_speed_ms: Bestämmer hastigheten som
					                    lysdioderna blinkar med i
										millisekunder.                  */
/************************************************************************/
void led_blink_sequenc(uint16_t blink_speed_ms);

/************************************************************************/
/* ms_delay: Genererar delay i millisekunder.
            
			 -blik_speed_ms: Angiven delay i millisekunder.             */
/************************************************************************/
void ms_delay(uint16_t blink_speed_ms);

#endif /* HEADDER_H_ */