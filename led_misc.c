/************************************************************************/
/* led_misc.c: Innehåller funktioer för toggling och blinkning 
               av lysdioder. 
			   Samt funktion för att generera delay i millisekunder.    */
/************************************************************************/
#include "headder.h"

static bool leds_enabled;

/************************************************************************/
/* led_toggle: Togglar lysdioder mellan att blinka och vara släckta.    */
/************************************************************************/
void led_toggle(void)
{
	leds_enabled = !leds_enabled;
	if (!leds_enabled) LEDS_OFF;
	return;
}

/************************************************************************/
/* led_blink_sequence: Blinkar lysdioderna i ordning "LED_1 till LED_3.
                       
					   -blink_speed_ms: Bestämmer hastigheten som
					                    lysdioderna blinkar med i
										millisekunder.                  */
/************************************************************************/
void led_blink_sequenc(uint16_t blink_speed_ms)
{
	if (!leds_enabled) return;
	
	else
	{
    LED_1_ON;
	LED_2_OFF;
	LED_3_OFF;
	ms_delay(blink_speed_ms);
	
	LED_1_OFF;
    LED_2_ON;
	LED_3_OFF;
	ms_delay(blink_speed_ms);
	 
	LED_1_OFF;
	LED_2_OFF;
	LED_3_ON;
	ms_delay(blink_speed_ms);
	
	LEDS_OFF;
	}
	
	return;
}

/************************************************************************/
/* ms_delay: Genererar delay i millisekunder.
            
			 -blik_speed_ms: Angiven delay i millisekunder.             */
/************************************************************************/
void ms_delay(uint16_t blink_speed_ms)
{
	for (int i = 0; i < blink_speed_ms; i++)
	{
		_delay_ms(1);
	}
	return;
}
