#include "leds.h"

//Constante para apagar todos los leds
#define ALL_OFF 0
//Constante para prender todos los leds
#define ALL_ON 0xFFFF
//Constante para prender un bit
#define BIT_ON 1
// Constante para convertir el numero de led en bit
#define LED_OFFSET 1


static uint16_t * leds;


 uint8_t Leds_Bits(uint8_t led){
	
	return(BIT_ON << (led - LED_OFFSET));
}

 void Leds_Create(uint16_t * puerto){
	leds = puerto;
	*puerto = ALL_OFF;
}

 void Led_On(uint8_t led){

	*leds |= Leds_Bits(led); /* OR */
}

 void Led_Off(uint8_t led){

	*leds &= ~Leds_Bits(led); /* AND con bits invertidos*/
}

 void All_Leds_On(void){

	*leds = ALL_ON;
}

 void All_Leds_Off(void){

	*leds = ALL_OFF;
}

void Led_State(uint8_t * ledState, uint8_t led){

	*ledState =  BIT_ON & (*leds >> (led - LED_OFFSET));
}




