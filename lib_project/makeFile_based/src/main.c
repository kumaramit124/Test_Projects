#include <stdio.h>
#include "math_functions.h"
#include "string_functions.h"

int main() {
    int result = add(5, 3);
    printf("Result of addition: %d\n", result);

    result = subtract(5, 3);
    printf("Result of subtraction: %d\n", result);

    const char* str = "Hello, World!";
    int length = string_length(str);
    printf("Length of the string: %d\n", length);

    return 0;
}

