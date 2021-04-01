#include <stdio.h>
void main()
{
char x[64]; 

for (int i=0;i<64;i=i+8)
{	
	long int * temp = (long int*) (&x[i]);
	long  k =2147483648;
	*temp= k;
}
for (int i=0;i<64;i=i+8)
{	long int  *temp = (long int *) (&x[i]);
	printf("%ld\n",*temp );
}
}