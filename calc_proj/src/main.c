#include <stdio.h>
#include "calc.h"

int main()
{
    int a = 10, b = 20;
    
    operation operations[] = {add, sub, mul, div};
    char *oprName[] = {"Addition", "Subtraction", "Multiply", "Divide"};

    for(int i; i < 4; i++)
    {
	int res = operations[i](a, b);
	
	printf("%s: %d\n", oprName[i], res);
    }

    return 0;
}
