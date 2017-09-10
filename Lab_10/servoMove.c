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
//transfer degree to PMW signal
int degreeToOnDelay(double degree) {
	return degree * 10 + 600;
}

/**
* Move servo given a speed.
* @param servoNr selected servo number
* @param from start position (0-180)
* @param to end position (0-180)
* @param speed speed (degree/sec) >0
*/
void servoMove(unsigned int servoNr, int from, int to, int speed) {
	
	//transfer from and to
	int start = degreeToOnDelay(from);
	int end = degreeToOnDelay(to);

	//move to start position
	PWM_gen(20000, start, 200, servoNr);

	//move to end position periodly
	int n = end - start;
	int next;
        if(n >0) {
		next = speed / 50;
        while (n > 0) {
        	PWM_gen(20000, start + next, 50, servoNr);
			next = next + speed /50;
			n = n -speed /50;
		}
	} 
	if (n < 0) {
		next = -(speed / 50);
		while (n <0) {
			PWM_gen(20000, start + next, 50, servoNr);
            next = next - speed /50;
            n = n - speed /50;
        }
    }
    else {
		//do nothing;
	}

	//stay for 4 sec at end position
	PWM_gen(20000, end, 200, servoNr);

}

