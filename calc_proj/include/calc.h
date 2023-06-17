#ifndef CALC_H
#define CALC_H

/* Function pointer declaration for any operation */
typedef int (*operation)(int x, int y);

/* Addition function */
int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);

#endif
