#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_number (int min, int max);

int main ()
{
	int rand_num = 	random_number (0,100); // rand of 0-100
	// printf ("Random number:%d\n", rand_num);
	int num = 0;
	do
	{
		printf ("Enter number:");
		scanf ("%d", &num);
		if (num > rand_num) printf ("    less\n");
			 else if (num < rand_num) printf ("    more\n");		
	} while ( num != rand_num);
	printf ("You guessed it!\n");
	return 0;
}

int random_number (int min, int max)
{
	int rand_num;	
	srand (time(NULL));
	rand_num = min + rand()%(max - min + 1);
	return rand_num;
}
