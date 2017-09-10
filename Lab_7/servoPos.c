/*****************************************
 Filename:  PWM_thru_GPIO.c
 Author:   James Massucco
 Date:      11/03/2014
 Purpose:   Produce PWM signal which is on
            for 2000usec with a period of
            20000usec.
 
            IMPORTANT NOTE:
            The GPIO initialization script,
            GPIO_Init.sh, MUST be run as root
            BEFORE running this program.
 *****************************************/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>

/**
 * open GPIO and return file handle
 * @param gpio_num  	GPIO number
 * @return   			file handle 
 */
int open_GPIO(int gpio_num);

/**
 * Generate numPerods periods of PWM signal.
 * Note function blocks while generating the signal. 
 *
 * @param period  	    PWM period [micro seconds]
 * @param onDuration  	on duration [micro seconds]
 * @param numPerods  	how many periods to generate?
 * @param fd            file descriptor of GPIO device file
 */
void PWM_gen(int period, int onDuration, int numPeriods, int fd);

int main()
{

    printf("\n-----------  Generate PWM Signal:  -------------\n\n");

	// file descriptor for 13
        int fdNum;
	printf("Enter a servo number:\n");
	scanf("%d", &fdNum);
	printf("Enter a position between 600 and 2400\n");
	int pos;
	scanf("%d", &pos);
	int fd;
	// open device file on Linux file system
	fd = open_GPIO(fdNum);   

	// generate PWM signal with 20ms period and 1.5ms on time
	// generate 400 periods, this will take 20ms * 400 iterations = 8s
    PWM_gen(20000, pos, 400, fd);
    
	sleep(1); // wait for an additional second
	
	close(fd);    //Close Linux GPIO interface file before exiting

	return 0;
}


/* User should create unique fd in main 
 for each opening of a GPIO port.
 Suggested naming scheme is "fd#" where
 # is the GPIO port number being opened */
int open_GPIO(int gpio_num) {

	// local var for device name
	char deviceName[128];
	
	// local var for file handle
	int fileHandle;
	
	/// GPIO device files will follow the format
	///   /sys/class/gpio/gpio<NR>/value
	/// <NR> has to be replaced with the actual number
	sprintf(deviceName, "/sys/class/gpio/gpio%d/value",gpio_num); 
	
	// open file in file system and get file pointer
    fileHandle = open(deviceName, O_WRONLY);

	// return file pointer 
    return fileHandle;
}

/**
 * Generate numPerods periods of PWM signal.
 * Note function blocks while generating the signal. 
 *
 * @param period  	    PWM period [micro seconds]
 * @param onDuration  	on duration [micro seconds]
 * @param numPerods  	how many periods to generate?
 * @param fd            file descriptor of GPIO device file
 */
void PWM_gen(int period, int onDuration, int numPeriods, int fd) {
    
    int i; // period counter
	
	// generate numPeriods periods of the PWM signal
    for (i = 0; i < numPeriods; i++) {
        write(fd, "1", 1 );     // write 1 to raise pin to 1, starting the "on" cycle
        usleep(onDuration);      // wait for duration of on portion of cycle

        write(fd, "0", 1 );          // write 0 to start off portion
        usleep(period - onDuration);  // wait for duration of off portion of cycle
        
    }
    return;
}
