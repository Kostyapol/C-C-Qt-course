#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep(sec.)
#define total_item 4

void print_menu ();
int get_number (int total);
void window_1 ();
void window_2 ();
void help ();


int main ()
{
	int number_item = 0; // item number of menu
	do
	{
	print_menu();
	number_item = get_number (total_item);
	switch (number_item)
		{
		case 1:
			window_1 ();	
			break;
		case 2:
			window_2 ();	
			break;
		case 3:
			help ();	
			break;
		}
	if (number_item != 4)
		{
		sleep(1);
		}
	} while (number_item != 4);
	
return 0;
}

void print_menu ()
{
	system ("clear"); // clear
	printf ("        МЕНЮ   \n");
	printf ("    1 - окно 1\n    2 - окно 2\n    3 - помощь\n    4 - выход\nВыберите пункт меню: ");
}

int get_number (int total)
{
    int number;
    char str[100];
    scanf("%s", str); 
    while (sscanf(str, "%d", &number) != 1 || number < 1 || number > total) 
	{
        printf("Incorrect input. Try again: "); 
        scanf("%s", str); 
	}
	return number;
}

void window_1 ()
{
	system ("clear"); // clear
	printf ("        Окно 1   \n");
}
void window_2 ()
{
	system ("clear"); // clear
	printf ("        Окно 2   \n");
}
void help ()
{
	system ("clear"); // clear
	printf ("        Помощь   \n");
}
