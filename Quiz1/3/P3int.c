#include <stdio.h>
void main()
{
char x[64]; 

for (int i=0;i<64;i=i+4)
{	
	int *temp = (int*) (&x[i]);
	int k = 2147483647;
	*temp= k;
}
for (int i=0;i<64;i=i+4)
{	int *temp = (int*) (&x[i]);
	printf("%d\n",*temp );
}

}