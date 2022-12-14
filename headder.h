/************************************************************************/
/* headder.h: Inneh?ller makron och funktionsdefinitioner f?r 
              implementering av blinkning av lysdioder p? Arduino UNO.  */
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

#define LED_1_ON PORTB |= (1 << LED_1)                                  //T?nder lydiod ansluten till pin 8
#define LED_2_ON PORTB |= (1 << LED_2)                                  //T?nder lydiod ansluten till pin 9
#define LED_3_ON PORTB |= (1 << LED_3)                                  //T?nder lydiod ansluten till pin 10
#define LEDS_ON PORTB |= ((1 << LED_1) | (1 << LED_2) | (1 << LED_3))   //T?nder alla lysdider

#define LED_1_OFF PORTB &= ~(1 << LED_1)                                  //Sl?cker lydiod ansluten till pin 8
#define LED_2_OFF PORTB &= ~(1 << LED_2)                                  //Sl?cker lydiod ansluten till pin 9
#define LED_3_OFF PORTB &= ~(1 << LED_3)                                  //Sl?cker lydiod ansluten till pin 10
#define LEDS_OFF PORTB &= ~((1 << LED_1) | (1 << LED_2) | (1 << LED_3))   //Sl?cker alla lysdider

#define BUTTON_1_IS_PRESSED (PINB &(1 << BUTTON_1))   //Kollar om tryckknappen asnluten till pin 13 ?r nedtryckt
	
typedef enum { false, true }bool;   //Implementering av datatypen bool


/* Funktionsdefinitioner */

/************************************************************************/
/* setup: Initierar I/O-portar och aktiverar avbrott.                   */
/************************************************************************/
void setup(void);

/************************************************************************/
/* led_toggle: Togglar lysdioder mellan att blinka och vara sl?ckta.    */
/************************************************************************/
void led_toggle(void);

/************************************************************************/
/* led_blink_sequence: Blinkar lysdioderna i ordning "LED_1 till LED_3.
                       
					   -blink_speed_ms: Best?mmer hastigheten som
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