#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>                      // для strlen

void create_file (FILE* name_fp, int N); // функция заполнения файла N случайными символами
int random_number (int min, int max); //  функция генерации случайного целого числа в промежутке от мин до макс
int find_ch (FILE* name_fp, char ch); //  функция поиска символа ch из файла

int main()
{
	FILE *fp;
	fp = fopen ("File.txt", "w+");
	if ((fp = fopen ("File.txt", "w+")) == NULL)
		{
			printf("Файл не создан\n");
		}
	int n = 0;
	char ch_use;	
	printf ("Введите общее количество символов в создаваемом файле и cимвол для поиска:");
	scanf ("%d %c", &n, &ch_use); 
	create_file (fp, n);
	fseek (fp,0,SEEK_SET);//   установка каретки в начало
	printf ("Частота использования '%c' = %d\n", ch_use, find_ch (fp, ch_use));
    fclose (fp);
    return 0;
}

void create_file (FILE* name_fp, int N)
{
	int i = 1;
	while (i <= N)
		{
			srand (time(NULL)+i);
			fprintf (name_fp, "%c", (char) random_number(65,127));// печать в файл случайных символов
			++i;
		}
	printf ("Файл заполнен\n");
}

int random_number (int min, int max)
{
	int rand_num;	
	rand_num = min + rand()%(max - min + 1);
	return rand_num;
}

int find_ch (FILE* name_fp, char ch)
{
	//int i = 0;
	char ch_f = '0';
	int N_ch = 0; //  количество использований символа ch в файле

	    do 
	    {
	    	//printf ("karetka: %d",ftell (name_fp));
	    	//i++;
	    	ch_f = fgetc (name_fp);//  считать символ из файла
	    	if (ch_f == ch) 
	    	{
	    	    
	    	    N_ch++;
	  	    }	
	  	    //printf ("i:%d\nN:%d\n""char:%c\n", i, N_ch, ch_f);
	    }
	    while (ch_f != EOF ); // пока не конец файла
	
	return N_ch;

}


