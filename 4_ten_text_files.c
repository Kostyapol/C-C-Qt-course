#include <stdio.h>
#include <stdlib.h>
#include <time.h>
# define N 1000

void fprintf_random (); // function of writing N random numbers to flow 

int main ()
{
	FILE *file;
	char name_file [7];
	srand (time(NULL));
       	for (int i = 1; i <= 10; ++i)
		{
		sprintf (name_file, "%s%d", "File ", i);
		file = fopen (name_file, "w");
		fprintf_random (file);
		printf ("Write %s\n", name_file);
			if ((file = fopen (name_file, "w")) == NULL)
			{
			printf("Cannot open file.\n");
			return 1;
			}
		}
return 0;
}

void fprintf_random (FILE *fp) 
{
	for (int j = 1; j <= N; ++j)
	{
	fprintf (fp, "%d", rand()%10);
	}
}
