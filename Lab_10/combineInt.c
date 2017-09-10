//combines two unsigned char values (valLow, valHigh) into one unsigned integer (value)
unsigned int combine(unsigned char valLow, unsigned char valHigh, unsigned int value) {
	unsigned int result = valHigh << 24 | valLow << 16 | value;
	return result;
}