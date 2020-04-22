#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_number (int min, int max); //  функция генерации случайного целого числа в промежутке от мин до макс


int main ()
{
	char str[1000] = {0};
	char ch_ran = 0;
	int i = 0;
	while (i < 1000)
		{
			srand (time(NULL)+i);	// для разного результата в реализациях и запусках программы
			ch_ran = (char) random_number(65 ,122); 
			str[i] = ch_ran;
			i++;
		}
	printf ("%s\n", str);
return 0;
}




int random_number (int min, int max)
{
	int rand_num;	
	rand_num = min + rand()%(max - min + 1);
	return rand_num;
}
