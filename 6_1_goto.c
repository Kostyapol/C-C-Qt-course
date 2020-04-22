#include <stdio.h>

int main ()
{
	int i = 1;
	printf ("%d ", i);
	Again:
	i++;
	printf ("%d ", i);
	if (i < 100) goto Again;
	return 0;
}

