// Blinking Led example 

// Arm physical addr if no MMU, if MMU then use virtual addr

// Physical addresses range from   0x20000000-0x20FFFFFF  
// Peripheral  advertised  at  bus  address  0x7Ennnnnn has physical address 0x20nnnnnn.
// 0x7E0->0x200 

/*The raspberry pi 3 is Cortex A8 based, 64 bit
And they moved the LED (the leds) to an i2c gpio expander.
*/
// Pi3 uses same base addr as Pi2 
#define GPIO_BASE_ADDR 0x3F200000UL

#define LED_GPFSEL      GPIO_GPFSEL4
#define LED_GPFBIT      21
#define LED_GPSET       GPIO_GPSET1
#define LED_GPCLR       GPIO_GPCLR1
#define LED_GPIO_BIT    15

#define GPIO_GPFSEL0    0
#define GPIO_GPFSEL1    1
#define GPIO_GPFSEL2    2
#define GPIO_GPFSEL3    3
#define GPIO_GPFSEL4    4
#define GPIO_GPFSEL5    5

#define GPIO_GPSET0     7
#define GPIO_GPSET1     8

#define GPIO_GPCLR0     10
#define GPIO_GPCLR1     11

#define GPIO_GPLEV0     13
#define GPIO_GPLEV1     14

#define GPIO_GPEDS0     16
#define GPIO_GPEDS1     17

#define GPIO_GPREN0     19
#define GPIO_GPREN1     20

#define GPIO_GPFEN0     22
#define GPIO_GPFEN1     23

#define GPIO_GPHEN0     25
#define GPIO_GPHEN1     26

#define GPIO_GPLEN0     28
#define GPIO_GPLEN1     29

#define GPIO_GPAREN0    31
#define GPIO_GPAREN1    32

#define GPIO_GPAFEN0    34
#define GPIO_GPAFEN1    35

#define GPIO_GPPUD      37
#define GPIO_GPPUDCLK0  38
#define GPIO_GPPUDCLK1  39

// Register set
volatile unsigned int* gpio;

// loop var
volatile unsigned int i; 

int main(){

	gpio = (unsigned int*)(GPIO_BASE_ADDR); 
	
	gpio[LED_GPFSEL] |= (1<<LED_GPFBIT); // Write 1 to the function select GPIO register to enable output 
	
	while(1){

		for(i=0;i<500000;i++) ; //stupid loop

		gpio[LED_GPCLR] = (1<<LED_GPIO_BIT); // set reg to 0 - 1 shifted x times
		
		for(i=0;i<500000;i++) ; //stupid loop

		gpio[LED_GPSET] = (1<<LED_GPIO_BIT); // set reg to 1 - 1 shifted x times
	
	}
	return 0; 
}



void exit(int code){
	while(1);
};
