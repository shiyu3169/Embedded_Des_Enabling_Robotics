/** 
* Template for Servo Control from FPGA with Software Controlled Speed 
* 
*/ 
#include <stdio.h> 
#include <stdlib.h> 
#include <fcntl.h> 
#include <sys/mman.h> 
#include <time.h> 
#include <unistd.h> 

#define BASE_ADDRESS 0x400D0000 

//Servo motor offsets 
#define Base_OFFSET 0x100 
#define Bicep_OFFSET 0x104 
#define Elbow_OFFSET 0x108 
#define Wrist_OFFSET 0x10C 
#define Gripper_OFFSET 0x110 
#define REG_WRITE(addr, off, val) (*(volatile int*)(addr+off)=(val)) 
#define REG_READ(addr, off) (*(volatile int*)(addr+off)) 

/** 
* data structure for servo instance 
*/ 
typedef struct { 
	unsigned char *test_base; /// base address of mapped virtual space 
	int fd; 				  /// file desrcriptor for memory map 
	int map_len; 			  /// size of mapping window 
} tServo; 

/** 
* global variable for all servos 
*/ 
tServo gServos; 

/** 
* Initialize servos 
* @return 0 upon success, 1 otherwise 
*/ 
int servo_init() { 
	//Open the file regarding memory mapped IO to write values for the FPGA 
	gServos.fd = open( "/dev/mem", O_RDWR); 
	
	unsigned long int PhysicalAddress = BASE_ADDRESS; 
	gServos.map_len= 0xFF; //size of mapping window 
	
	// map physical memory startin at BASE_ADDRESS into own virtual memory 
	gServos.test_base = (unsigned char*)mmap(NULL, gServos.map_len, PROT_READ | PROT_WRITE, MAP_SHARED, gServos.fd, (off_t)PhysicalAddress); 
	
	// did it work? 
	if(gServos.test_base == MAP_FAILED) { 
		perror("Mapping memory for absolute memory access failed -- Test Try\n"); 
		return 1; 
} 

	//Initialize all servo motors 
	// I assume this is the "sleep" position 
	REG_WRITE(gServos.test_base, Base_OFFSET, 150); 
	REG_WRITE(gServos.test_base, Bicep_OFFSET, 190); 
	REG_WRITE(gServos.test_base, Elbow_OFFSET, 190); 
	REG_WRITE(gServos.test_base, Wrist_OFFSET, 100); 
	REG_WRITE(gServos.test_base, Gripper_OFFSET, 150); 
	return 0; 
} 
/** 
* This function takes the servo number and the position, and writes the values in 
* appropriate address for the FPGA 
* @param test_base base pointer for servos 
* @param servo_number servo number to manipulate 
* @param position new postion 
*/ 
void servo_move(int servo_number, int position) { 
	switch (servo_number) { 
		case 1: //Base 
			REG_WRITE(gServos.test_base, Base_OFFSET, position); 
			break; 
		case 2: //Bicep 
			REG_WRITE(gServos.test_base, Bicep_OFFSET, position); 
			break; 
		case 3: //Elbow 
			REG_WRITE(gServos.test_base, Elbow_OFFSET, position); 
			break; 
		case 4: //Wrist 
			REG_WRITE(gServos.test_base, Wrist_OFFSET, position); 
			break; 
		case 5: //Gripper 
			REG_WRITE(gServos.test_base, Gripper_OFFSET, position); 
			break; 
	default: 
		break; 
	} 
} 

/** 
*Speed is in degrees per second 
*/ 
void servo_moveHelper(int servo_number, int end, int speed){ 
	int start = REG_READ(gServos.test_base, 0x96 + 0x4 * servo_number); 
	int pos; 
	if(end < start){ 
		speed *= -1; 
	} 
	for(pos = start; (pos - start) < 0 == (start - end) < 0; pos += speed / 5) { 
		servo_move(servo_number, pos); 
		usleep(200000); 
	} 
	servo_move(servo_number, end); 
} 

/** 
* Deinitialize Servos 
*/ 
void servo_release() { 
	// Releasing the mapping in memory 
	munmap((void *)gServos.test_base, gServos.map_len); 
	close(gServos.fd); 
} 

int main() 
{ 
	//Declarations and initialization 
	int servo_number = 0; 
	int position = 0; 
	int speed = 10; 

	printf("\n------------- Robot TESTING --------------------\n\n"); 
	/* initialize servos */ 
	if (servo_init() != 0) { 
		return -1; // exit if init fails 
	} 

	do { 
		printf("Enter servo number (1-5) or enter 0 to exit:\n"); 
		scanf("%d", &servo_number); //Take the servo number from user 
		if (servo_number != 0) { 
			printf("Enter position (60 - 240): Speed in degrees/s:\n"); 
			scanf("%d %d", &position, &speed); //Take the position from user 
			servo_moveHelper(servo_number, position, speed); //The selected servo will move to the desired position 
		} 
	} while( servo_number != 0 ); // repeat while valid servo number given 

	/* deinitialize servos */ 
	servo_release(); 
	return 0; 
}
