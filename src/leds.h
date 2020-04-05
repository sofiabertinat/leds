#include <stdint.h>

/*A la funcion se le pasa como parámetro un puntero que apunta a la dirección de memoria que va a emular un puerto de entradas/salidas, donde  unos y ceros representan los leds*/
 void Leds_Create(uint16_t * puerto);

 void Led_On(uint8_t led);

 void Led_Off(uint8_t led);

 void All_Leds_On(void);

 void All_Leds_Off(void);

 void Led_State(uint8_t * ledState, uint8_t led);
