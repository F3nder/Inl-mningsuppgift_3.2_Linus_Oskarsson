/************************************************************************/
/* main.c: Program för att toggla mellan lysdioder. 
           Antingen av eller blinka sekventiellt.                       */
/************************************************************************/
#include "headder.h"

int main(void)
{
    setup();
	
    while (1) 
    {
	   led_blink_sequenc(100);
    }
}

