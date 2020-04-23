#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>  //for strcmp and strcpy

#define Max_numbers 3

struct Telbook
{
	char name[20];
	unsigned long int number;
}Items [Max_numbers];


void print_menu ();
int get_number (int total);
void add_item_book(struct Telbook* curSt, int cur_num);	
void view_item(struct Telbook curSt);
void find (struct Telbook curSt, char*name_f, int n_user);
void save_to_file(struct Telbook curSt);

int main ()
{
	int cur_number = 0; 
	int number_item_menu = 0; 
	char name_find [20];	
	print_menu ();
	number_item_menu = get_number(5);
	switch (number_item_menu)
	{
		case 1:
			printf ("Объем справочника = %d абонента\n", Max_numbers);			
			do 
			{
 		 		add_item_book(&Items[cur_number], cur_number);
		   		printf("  name = %s ;   number= %lu\n", Items[cur_number].name, Items[cur_number].number);					
				++cur_number;
			}
			while (cur_number < Max_numbers);
			printf ("Справочник заполнен!\n");
			sleep(1);
			main();
		case 2:
			for (int i = 0;	i <  Max_numbers ;	++i)
			{	
				save_to_file (Items[i]);
			}
			printf ("Сохранение успешно выполнено\n");
			sleep(1);
			main();

		case 3:
			for (int i = 0;	i <  Max_numbers ;	++i)
			{	
				view_item (Items[i]);
			}
			sleep(2);
			main();
		case 4:
			printf ("Введите имя для поиска:\n");
			scanf ("%s", name_find);			
			for (int i = 0;	i <  Max_numbers ; ++i)
			{	
				find (Items[i], name_find, i+1);
			}
			
			main();
			
		case 5:
			exit(1);
	}
	return 0;
}

int get_number (int total)
{ 
int number;
    char str[100];
    scanf("%s", str); 
    while (sscanf(str, "%d", &number) != 1 || number < 1 || number > total) 
	{
        printf("Некорректный ввод! Попробуйте еще: "); 
        scanf("%s", str); 
	}
	return number;
}


void add_item_book(struct Telbook* curSt, int cur_num) // функция добавления записей с аргументом итем по указателю, и текущий номер
{  
	
	char name_user[20];
	unsigned long int number_user;
	printf ("Введи имя %d-го абонента и телефон:\n", cur_num+1);
	scanf ("%s %lu", name_user, &number_user);
	strcpy (curSt->name,name_user); // копирование строк
	curSt->number = number_user;
}


void view_item(struct Telbook curSt)
{

printf("name = %s ; number= %lu\n", curSt.name, curSt.number);	

}

void find (struct Telbook curSt, char* name_f, int n_user)
{
	if (strcmp (curSt.name, name_f) == 0) 
	{ 
		printf ("АБОНЕНТ НАЙДЕН! Его порядковый №%d! Номер телефона:%lu\n", n_user, curSt.number);
		sleep(5);
	} 
}

void save_to_file(struct Telbook curSt)
{
	FILE* fp;
	fp = fopen ("File.txt", "a+");
	if ((fp = fopen ("File.txt", "a+")) == NULL)
	{
		printf("Файл не создан\n");
	}
	
	fprintf (fp, " Name:%s Number:%lu\n", curSt.name, curSt.number);
	fclose(fp);
}




void print_menu ()
{
	system ("clear"); 
	printf ("   Телефонный справочник\n");
	printf ("    1 - Добавить запись\n    2 - Сохранить в файл\n    3 - Вывести данные\n    4 - Поиск\n    5 - Выход\n\nВыберите пункт меню: ");
}




