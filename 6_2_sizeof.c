#include <stdio.h>
#include <string.h> // для sprintf

int size_file (FILE* name_fp);

int main()
{
	char name_file [15] = {'0'};
	printf ("Введите название файла:");
	scanf ("%s", name_file);
	sprintf (name_file, "%s%s", name_file, ".txt");
	FILE *fp;
	fp = fopen (name_file, "r");
	if ((fp = fopen (name_file, "r")) == NULL)
		{
			printf("Файл не доступен\n");
			return 1;
		}
	printf ("Размер считанных данных = %d\n", size_file(fp));
	fclose (fp);
    return 0;
}

int size_file (FILE* name_fp)
{
	int size = 0;
	
	while (fgetc (name_fp) != EOF ) // пока не конец файла
	{
	    	 size++;
	}   	    
	return size;
}


