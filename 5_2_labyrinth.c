#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for sleep(sec.)

void print_menu ();
int get_number (int total);
void green_room ();
void impasse ();
void red_room (int f); 
void blue_room (int d);

//  игра в лабиринт с учетом того, из какой комнаты заходит игрок в другую комнату (его ориентации относительно дверей). Присутствуют тупики (из них можно выйти) и мина (игрок проиграл).
int main () 
{
	int number_item = 0; // item number of menu
	
		print_menu();
		number_item = get_number(2);
		if (number_item == 1) 
		{
			green_room (1);
		} else if (number_item == 2)
			{
				exit(1);
			}
	
return 0;
}


void print_menu ()
{
	system ("clear"); // clear
	printf ("        ЛАБИРИНТ  \n");
	printf ("    1 - Войти\n    2 - Выйти\n\nВыберите пункт меню: ");
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

void green_room (int g)
{
	int number_item_green = 0;
	system ("clear");
	printf ("\e[32m        Зеленая комната   \e[0m\n");
	printf ("    1 - вперед \n    2 - повернуть вправо\n    3 - повернуть влево\n    4 - развернуться\n\nВыберите маршрут: ");
	number_item_green = get_number(4);
	if (number_item_green != 4)
	{
		sleep(1);
	}
	switch (g)
	{
		case 1: // in green room from enter		
			switch (number_item_green)
			{
				case 1:
					impasse ();
					green_room (1);
				case 2:
					red_room (1);
					green_room (2);
				case 3:
					blue_room (1);
					green_room (3);
				case 4:
					main();
			}	
		case 2: // in green room from red room	
			switch (number_item_green)
			{
				case 1:
					blue_room (1);
					green_room (3);
				case 2:
					impasse ();
					green_room (2);
				case 3:
					main();
				case 4:
					red_room (1);
			}	
		case 3: // in green room from blue room	
			switch (number_item_green)
			{
				case 1:
					red_room (1);
				case 2:
					main();					
				case 3:
					impasse ();
					green_room (3);
				case 4:
					blue_room (1);
			}


	}

}


void impasse ()
{
	int number_item_impasse = 0;
	do
	{
		system ("clear"); 
		printf ("        Тупик  \n");
		printf ("    1 - Вернуться\n\nВыберите маршрут: ");
		number_item_impasse = get_number(1);
	}
	while (number_item_impasse != 1);

}

void red_room (int f)
{
	int number_item_red = 0;
	system ("clear"); 
	printf ("\e[31m        Красная комната   \e[0m\n");
	printf ("    1 - вперед \n    2 - повернуть вправо\n    3 - повернуть влево\n    4 - развернуться\n\nВыберите маршрут: ");
	number_item_red = get_number(4);
	if (number_item_red != 4)
	{
		sleep(1);
	}
	if (f == 1) // in red room from green room 
	{	
		switch (number_item_red)
		{
			case 1:
				printf ("        ПОБЕДА!\n");
				sleep(2);
				main();
			case 2:
				blue_room (2);	
			case 3:
				impasse ();
				red_room (1);	
			case 4:
				break;
			} 
	} else if (f == 2) // in red room from blue room 
			{
				switch (number_item_red)
				{
					case 1:
						impasse ();
						red_room (2);
					case 2:
						printf ("        ПОБЕДА!\n");
						sleep(2);
						main();	
					case 3:
						green_room (2);	
					case 4:
						break;
				} 
			}
}


void blue_room (int d)
{
int number_item_blue = 0;
	system ("clear"); 
	printf ("\e[34m        Синяя комната   \e[0m\n");
	printf ("    1 - вперед \n    2 - повернуть вправо\n    3 - повернуть влево\n    4 - развернуться\n\nВыберите маршрут: ");
	number_item_blue = get_number(4);
	if (number_item_blue != 4)
	{
		sleep(1);
	}
	if (d == 1) // in blue room from green room
	{
		switch (number_item_blue)
		{
			case 1:
				printf ("        Мина! Вы проиграли!\n");
				sleep(2);
				main();	
			case 2:
				impasse ();
				blue_room (2);	
			case 3:
				red_room (2);	
			case 4:
				break;
		} 
	} else if (d == 2) // in blue room from red room
		{
			switch (number_item_blue)
			{
				case 1:
					impasse ();
					blue_room (2);
				case 2:
					green_room (3);	
				case 3:
					printf ("        Мина! Вы проиграли!\n");
					sleep(2);
					main();	
				case 4:
					red_room(2);
			} 
		}
}


