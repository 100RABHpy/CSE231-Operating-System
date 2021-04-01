/*
 * A small program that illustrates how to call the maxofthree function we wrote in
 * assembly language.
 */

#include <stdio.h>

int64_t add(int64_t, int64_t);

int main()
{
    printf("%ld\n", add(1, -4));
    printf("%ld\n", add(2, 6));
}