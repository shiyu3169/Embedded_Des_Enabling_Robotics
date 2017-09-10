/**
 * Show lower 8 bits of integer value on LEDs
 *@param pBase	base address of userio
 *@param ledNr	the ID of individual LED.
 *@param state  either 0(off) or 1(on) to represent the state of selected LED
 */
void userio_ledSet(unsigned char *pBase, unsigned int ledNr, unsigned int state)
{
	/*Address distance between two LED offsets*/
	int distance = 4; 

	/*the offset of slected LED*/
	unsigned int ledOffset = pBase + LED1_OFFSET + ledNr * distance 
	
	REG_WRITE(pBase, ledOffset, state);
}
