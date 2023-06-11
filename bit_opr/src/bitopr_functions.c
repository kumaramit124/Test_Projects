#include "bitOpr_functions.h"

//This function reverse the bit of the given number
//Return the reverse bit
unsigned int reverse_bit(unsigned int num) {
    unsigned int rev_bit = 0;

    while(num > 0)
    {
	    rev_bit = rev_bit << 1;
	    if(num & 1 == 1)
	    {
		    rev_bit = rev_bit ^ 1;
	    }

	    // right shift num
	    num = num >> 1;
    }

    return num;
}



