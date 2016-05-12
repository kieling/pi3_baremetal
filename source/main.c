
#include <string.h>
#include <stdlib.h>

#include "rpi_gpio.h"

/** GPIO Register set */
volatile unsigned int* gpio = (unsigned int*)GPIO_BASE;

/** Main function - we'll never return from here */
void kernel_main( unsigned int r0, unsigned int r1, unsigned int atags )
{
    int loop;

    unsigned int * counters;

    counters = malloc(1024* sizeof(unsigned int));

    if (counters == NULL)
        while(1) {
          gpio[LED_GPSET] = (1 << LED_GPIO_BIT);
        }

    for (loop = 0; loop < 1024; loop++)
      counters[loop] = 0;

    /* Write 1 to the GPIO16 init nibble in the Function Select 1 GPIO
       peripheral register to enable GPIO16 as an output */
    gpio[LED_GPFSEL] |= (1 << LED_GPFBIT);

    /* Never exit as there is no OS to exit to! */
    while(1)
    {
        for(counters[0] = 0; counters[0] < 500000; counters[0]++)
            ;

        /* Set the LED GPIO pin low ( Turn OK LED on for original Pi, and off
           for plus models )*/
        gpio[LED_GPCLR] = (1 << LED_GPIO_BIT);

        for(counters[1] = 0; counters[1] < 500000; counters[1]++)
            ;

        /* Set the LED GPIO pin high ( Turn OK LED off for original Pi, and on
           for plus models )*/
        gpio[LED_GPSET] = (1 << LED_GPIO_BIT);
    }
}
