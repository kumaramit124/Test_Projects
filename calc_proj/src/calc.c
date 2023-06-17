/** This is a sample test project for poc to implement the 
 *  Calculator using the Function pointer concept.
 *  This will be created as an library and api's exposed to
 *  third pary to utilize the calc funcanility.
 *
 *  Author: Amit K, Date:03-June-2023, Draft version- .01
 *
 */

#include "calc.h"

int add(int a, int b)
{
    return a + b;	
}

int sub(int a, int b) {
    return a - b;
}

int mul(int a, int b) {
    return a * b;
}

int div(int a, int b) {
    if (b != 0) {
        return a / b;
    }
    return 0;
}

