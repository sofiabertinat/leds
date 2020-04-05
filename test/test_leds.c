/*
Desarrollar un controlador de led utilizando la técnica de TDD. Se deben completar las siguientes pruebas:
> Después de la inicialización todos los LEDs deben quedar apagados.
> Se puede prender un LED individual.
> Se puede apagar un LED individual.
> Se pueden prender y apagar múltiples LED’s.
> Se pueden prender todos los LEDs de una vez.
> Se pueden apagar todos los LEDs de una vez.
> Se puede consultar el estado de un LED.
*/

#include "unity.h"
#include "leds.h"

//Constante para apagar todos los leds
#define ALL_OFF 0
//Constante para prender todos los leds
#define ALL_ON 0xFFFF
//Constante para prender un bit
#define BIT_ON 1
// Constante para convertir el numero de led en bit
#define LED_OFFSET 1

/*Se define variable donde se va a emular el puerto de E/S */
static uint16_t ledsVirtuales;

void setUp(void){

	Leds_Create(&ledsVirtuales);/*precondicion de estado de los leds*/
}

void tearDown(void){

}

// Después de la inicialización todos los LEDs deben quedar apagados.
void test_LedsOffAfterCreat(void){

	
	uint16_t ledsVirtuales= 0xFFFF;/*Inicializamos los leds en 1 para ver si hubo un cambio*/ 

	Leds_Create(&ledsVirtuales);

	TEST_ASSERT_EQUAL_HEX16(ALL_OFF, ledsVirtuales); /*Asegura que la comparacion se va a hacer en 16 bits*/

	/*llamada siempre falla, se corta en test en ese lugar e imprime el mensaje*/
	//TEST_FAIL_MESSAGE("Empezamos"); 
}

// Se puede prender un LED individual.
void test_IndividualLedOn(void){
	
	const uint8_t led = 3;

	Led_On(led);	

	/*vemos que el bit 3 este en uno, 1 << 3 */
	TEST_ASSERT_EQUAL(BIT_ON << (led - LED_OFFSET), ledsVirtuales);
}

// Se puede apagar un LED individual.
void test_IndividualLedOff(void){
	
	const uint8_t led = 3;

	Led_On(led);

	Led_Off(led);	

	TEST_ASSERT_EQUAL(ALL_OFF , ledsVirtuales);
}

// Se pueden prender y apagar múltiples LED’s.
void test_MultipleLedOnAndOff(void){

	Led_On(2);
	Led_On(5);
	Led_Off(2);
	TEST_ASSERT_EQUAL(BIT_ON << (5 - LED_OFFSET), ledsVirtuales);
}

// Se pueden prender todos los LEDs de una vez.
void test_AllLedsOn(void){

	All_Leds_On();

	TEST_ASSERT_EQUAL(ALL_ON , ledsVirtuales);
}

// Se pueden apagar todos los LEDs de una vez.
void test_AllLedsOff(void){

	All_Leds_On();

	All_Leds_Off();

	TEST_ASSERT_EQUAL(ALL_OFF , ledsVirtuales);
}

//Se puede consultar el estado de un LED.
void test_LedState(void){

	const uint8_t led = 3;
	uint8_t ledState = 0;

	Led_On(led);

	Led_State(&ledState, led);

	TEST_ASSERT_EQUAL(BIT_ON , ledState);
}





