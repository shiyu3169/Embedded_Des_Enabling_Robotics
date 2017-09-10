#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

// physical base address of GPIO
#define GPIO_ADDRESS	0x400D0000
// length of MEM Mapped IO window
#define GPIO_MAP_LEN 0xFF

#define LED1_OFFSET	0x12C  /* Offset for LED1 */
#define LED2_OFFSET	0x130  /* Offset for LED2 */
#define LED3_OFFSET	0x134  /* Offset for LED3 */
#define LED4_OFFSET	0x138  /* Offset for LED4 */
#define LED5_OFFSET	0x13C  /* Offset for LED5 */
#define LED6_OFFSET	0x140  /* Offset for LED6 */
#define LED7_OFFSET	0x144  /* Offset for LED7 */
#define LED8_OFFSET	0x148  /* Offset for LED8 */

#define SW1_OFFSET	0x14C  /* Offset for Switch 1 */
#define SW2_OFFSET	0x150  /* Offset for Switch 2 */
#define SW3_OFFSET	0x154  /* Offset for Switch 3 */
#define SW4_OFFSET	0x158  /* Offset for Switch 4 */
#define SW5_OFFSET	0x15C  /* Offset for Switch 5 */
#define SW6_OFFSET	0x160  /* Offset for Switch 6 */
#define SW7_OFFSET	0x164  /* Offset for Switch 7 */
#define SW8_OFFSET	0x168  /* Offset for Switch 8 */

#define PBTNL_OFFSET	0x16C  /* Offset for left push button */
#define PBTNR_OFFSET	0x170  /* Offset for right push button */
#define PBTNU_OFFSET	0x174  /* Offset for up push button */
#define PBTND_OFFSET	0x178  /* Offset for down push button */
#define PBTNC_OFFSET	0x17C  /* Offset for center push button */

#define REG_WRITE(addr, off, val) (*(volatile int*)(addr+off)=(val))
#define REG_READ(addr,off) (*(volatile int*)(addr+off))

/**
 * Initialize userio module.
 *  - opens access to physical memory /dev/mem
 *  - mapps memory at offset 'PhysicalAddress' into virtual address space
 *
 *@param  fd	pointer to file descriptor (needed for later)
 *@return  address to virtual memory which is mapped to physical,
 *          or MAP_FAILED on error.
 */
unsigned char *userio_init(int *fd)
{
	unsigned long int PhysicalAddress = GPIO_ADDRESS;
	int map_len = GPIO_MAP_LEN;
	unsigned char *pBase;

	*fd = open( "/dev/mem", O_RDWR);

	pBase = (unsigned char*)mmap(NULL, map_len, PROT_READ |
				PROT_WRITE, MAP_SHARED, *fd, (off_t)PhysicalAddress);

	return pBase;
}

/**
 * Show lower 8 bits of integer value on LEDs
 *@param pBase	base address of userio
 *@param value	value to show on LEDs
 */
void userio_ledSetAll(unsigned char *pBase, int value)
{
	REG_WRITE(pBase, LED1_OFFSET, value%2);
	REG_WRITE(pBase, LED2_OFFSET, (value/2)%2);
	REG_WRITE(pBase, LED3_OFFSET, (value/4)%2);
	REG_WRITE(pBase, LED4_OFFSET, (value/8)%2);
	REG_WRITE(pBase, LED5_OFFSET, (value/16)%2);
	REG_WRITE(pBase, LED6_OFFSET, (value/32)%2);
	REG_WRITE(pBase, LED7_OFFSET, (value/64)%2);
	REG_WRITE(pBase, LED8_OFFSET, (value/128)%2);
}


/**
 * Control the single led with the corresponding state
 *@param pBase base address of userio
 *@param ledNr the number of led to control
 *@param state the state of the led
 */
void userio_ledSet(unsigned char *pBase, unsigned int ledNr, unsigned int state)
{
	//the offset address of first led
	unsigned int ledOffset = LED1_OFFSET;
	// calculate the given led's offest address
	unsigned int led = ledOffset + ledNr * 4;
	// write to the led
	REG_WRITE(pBase, led, state);
}

/**
 * Return the state of a led by reading from the switch
 *@param pBase base address of userio
 *@param SwNr the number of switch to read from
 */
unsigned int userio_switchGet(unsigned char *pBase, unsigned int SwNr)
{
	// the offset address of first switch
	unsigned int switchOffset = SW1_OFFSET;
	// calculate the given Sw's offset
	unsigned int Aswitch = switchOffset + SwNr * 4;
	// read from the switch and return the state of the corresponding led
	return (unsigned int)REG_READ(pBase, Aswitch);
}


/**
 * Return the value if any button is pushed
 *@param pBase base address of userio
 */
unsigned int userio_pushButtonGet(unsigned char *pBase)
{
	if (REG_READ(pBase, PBTNU_OFFSET) == 1)
	    return 1;
	else if (REG_READ(pBase, PBTNR_OFFSET) == 1)
	    return 2;
        else if (REG_READ(pBase, PBTND_OFFSET) == 1)
            return 4;
        else if (REG_READ(pBase, PBTNL_OFFSET) == 1)
            return 8;
        else if (REG_READ(pBase, PBTNC_OFFSET) == 1)
            return 16;
        else 
            return 0;
}


/**
 * close userio module and free resources
 * -  Unmap the address mapping at 'pBase' and close the file descriptor fd
 *@param pBase	base address
 *@param fd     file descriptor to close
 */
void userio_deinit(unsigned char *pBase, int fd)
{
	int map_len = GPIO_MAP_LEN;
	munmap((void *)pBase, map_len);
	close(fd);
}


/**
 * Load the current value of the switch
 *@param pBase	base address
 *@param counter the current value of the switch
 */
void load(unsigned char *pBase, int *counter)
{
    int i;
    *counter = 0;
    // start from sw7 loop through all the switch and keep the value
    for(i =7; i> -1; i--){
	unsigned int state = userio_switchGet(pBase, i);
	// we shift the digits to left since we start from the highest digits
        *counter = *counter << 1;
	// if the state is 1 we will have 1, otherwise 0;
        *counter = *counter | state;
    }
}


int main()
{
	int fd;
	
	// open userio module
	unsigned char *pMemBase = userio_init(&fd);
	
	if(pMemBase == MAP_FAILED)
	{
		perror("Mapping memory for absolute memory access failed -- Test Try\n");
		return -1;
	}	
	

		
	// a counter to track the value of switch	
	int counter;
	
	// initialize the direction and the speed	
	int direction = 1, speed = 1000000;

	// an accumulator to track whether a button has been pushed
        int up_pressed = 0, down_pressed = 0, center_pressed = 0,
	    left_pressed = 0, right_pressed = 0;
	// initialize the leds	
	load(pMemBase, &counter);	

	// using the up and down button to control the direction
	// using the left and right button to decrease  and increase the speed
	// the counter will change automaticly by the given speed and direction
	// having the accumulator to make sure the value only change once with push 
	// but not changing by holding any button.
	while(1){
	    unsigned int button_val = userio_pushButtonGet(pMemBase);
	    if ((button_val == 1) && (button_val != up_pressed)) {
		up_pressed = button_val;
		direction = 1;
	    }
	    else if (button_val != 1) {
		up_pressed = 0;
	    }
	    if ((button_val == 2) && (button_val != right_pressed)) {
		right_pressed = button_val;
		speed += 500000;
	    }
	    else if (button_val != 2) {
		right_pressed = 0;
	    }
	    if ((button_val == 8) && (button_val != left_pressed)) {
		left_pressed = button_val;
		speed -= 500000;
	    }
	    else if (button_val != 8) {
		left_pressed = 0;
	    }
	    if ((button_val == 4) && (button_val != down_pressed)) {
		down_pressed = button_val;
		direction = -1;
	    }
	    else if (button_val != 4) {
		down_pressed = 0;
	    }
	    if ((button_val == 16) && (button_val != center_pressed)) {
		center_pressed = button_val;
	    }
	    else if (button_val != 16) {
		center_pressed = 0;
	    }
	    usleep(speed);
	    if (direction == 1) {
		counter++;
	    }
	    else {
		counter--;
	    }
	    userio_ledSetAll(pMemBase, counter);
	}
	// close userio module
	userio_deinit(pMemBase, fd);

	return 0;
}

