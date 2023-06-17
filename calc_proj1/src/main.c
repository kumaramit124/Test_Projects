#include <stdio.h>
#include "calc.h"

/*
int calAdd(int a, int b)
{
    return a + b;
}

int calSub(int a, int b) {
    return a - b;
}

int calMul(int a, int b) {
    return a * b;
}

int calDiv(int a, int b) {
    if (b != 0) {
        return a / b;
    }
    return 0;
}
*/

int main()
{
    int a = 20, b = 10;

    //create an instance of calc operation structure
    struct calc_operation calcOps;
    calcOps.add = calAdd;
    calcOps.sub = calSub;
    calcOps.mul = calMul;
    calcOps.div = calDiv;


    operation operations[] = {calcOps.add, calcOps.sub, calcOps.mul, calcOps.div};
    char *oprName[] = {"Addition", "Subtraction", "Multiply", "Divide"};

    for(int i; i < 4; i++)
    {
	int res = operations[i](a, b);
	
	printf("%s: %d\n", oprName[i], res);
    }

    return 0;
}
