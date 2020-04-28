#include <stdio.h>
#include <stdlib.h>
#include <time.h> // для clock ()


#define Size_arr 5000 // количество символов в массиве
#define Total_arr 100 // количество различных массивов для сортировки
#define Total_methods 3 // количество сравниваемых методов сортировки


void random_arr (int arr [Size_arr], int size); // функция формирование массива размера Size_arr случайных целых по указателю
float bubble_sort (int arr [], int size); // функция расчета времени работы сортирровки пузырьком
float find_min_sort (int arr [], int size); 
void quick_sort (int arr [], int first, int last);
float time_quick_sort (int arr [], int size);
float medium (float t [], int size);
float minimum (float t [], int size);
float maximum (float t [], int size);


int main ()
{
	int arr_int [Size_arr] = {0};
	float t_bubble [Total_arr] = {0};
	float t_min_sort [Total_arr] = {0};
	float t_quick_sort [Total_arr] = {0};
	float t_med_bubble = 0; //
	float t_med_min_sort = 0;
	float t_med_quick_sort = 0;
	float t_min_bubble = 0;
	float t_min_min_sort = 0;
	float t_min_quick_sort = 0;
	float t_max_bubble = 0;
	float t_max_min_sort = 0;
	float t_max_quick_sort = 0;
	
	
		/*for (int i = 0; i <  Size_arr; i++)
		{	
				printf ("%d", arr_int [i]);
		}*/
	printf ("Рассчет запущен,ждите... \n  Ход выполнения:\n"); 
	printf ("   0 %% \n");
	for (int i = 0; i <  Total_arr; i++)
		{
		random_arr (arr_int, Size_arr); 
		t_bubble [i] = bubble_sort (arr_int, Size_arr);
		t_min_sort [i] = find_min_sort (arr_int, Size_arr);
		t_quick_sort [i] = time_quick_sort (arr_int, Size_arr);
		printf ("  %d %% \n", (i+1)*100/Total_arr);
		//sleep (1);
		} 
	
	for (int i = 0; i <  Total_arr; i++)
	{	
	
		printf ("Время выполнения: пузырьком: %f сек. | поиском минимума: %f сек. | быстрой сортировкой: %f сек.\n", t_bubble [i], t_min_sort [i],t_quick_sort [i]);
	}	
	

	t_med_bubble = medium (t_bubble, Total_arr);
	t_med_min_sort = medium (t_min_sort, Total_arr);
	t_med_quick_sort = medium (t_quick_sort, Total_arr);
	printf ("\n   СРЕДНЕЕ время\n 1) пузырьком = %f сек. 2) поиском минимума: %f сек. 3) быстрой сортировкой: %f сек.\n", t_med_bubble, t_med_min_sort, t_med_quick_sort);
	t_min_bubble = minimum (t_bubble, Total_arr);
	t_min_min_sort = minimum (t_min_sort, Total_arr);
	t_min_quick_sort = minimum (t_quick_sort, Total_arr);
	printf ("\n   МИНИМАЛЬНОЕ время\n 1) пузырьком = %f сек. 2) поиском минимума: %f сек. 3) быстрой сортировкой: %f сек.\n", t_min_bubble, t_min_min_sort, t_min_quick_sort);
	t_max_bubble = maximum (t_bubble, Total_arr);
	t_max_min_sort = maximum (t_min_sort, Total_arr);
	t_max_quick_sort = maximum (t_quick_sort, Total_arr);
	printf ("\n   МАКСИМАЛЬНОЕ время\n 1) пузырьком = %f сек. 2) поиском минимума: %f сек. 3) быстрой сортировкой: %f сек.\n", t_max_bubble, t_max_min_sort, t_max_quick_sort);
	return 0;



}




void random_arr (int * arr, int size)
{
	//printf ("\n---------\n");
	srand (time(NULL));
	for (int i = 0; i <  size; i++)
	{	
		arr[i] = rand()%(10);
		//printf ("%d",arr[i]);
	}

}


float bubble_sort (int arr [], int size) 
{
	float t = 0;
	clock_t start, stop;
	start = clock ();
	for (int i = 0; i <  Size_arr - 1; i++)
	{	
		for (int j = 0; j <  Size_arr - 1 - i; j++)
		{
			if (arr [j] > arr [j+1])
			{
				int tmp = arr [j];
				arr [j] = arr [j+1];
				arr [j+1] = tmp;
			}
		}
	}
	stop = clock();
	t = (float)(stop - start) / CLOCKS_PER_SEC;
	return t;
}

float find_min_sort (int arr [], int size)
{	
	int x_arr [size];
	long k, i, j;
	float t = 0;
	clock_t start, stop;
	start = clock ();
	for (int i = 0; i <  Size_arr - 1; i++)
	{	
		x_arr [i] = arr [i];
		k = i;
		for (int j = i + 1; j <  Size_arr - 1; j++)
		{
			if (x_arr [i] > arr [j])
			{
				x_arr [i] = arr [j];
				k = j; // минимальный элемент
			}
			arr [k] = arr [i];
			arr [i] = x_arr [i]; 
		}
	}
	stop = clock();
	t = (float)(stop - start) / CLOCKS_PER_SEC;
	return t;
}

float time_quick_sort (int arr [], int size)
{
	int q_arr [size];
	for (int i = 0; i <  size; i++)
	{	
		q_arr [i] = arr [i];		
	}
	int first = arr [0];
	int last = arr [size-1];
	
	float t = 0;
	clock_t start, stop;
	start = clock ();
	quick_sort (q_arr, first, last);
	stop = clock();
	t = (float)(stop - start) / CLOCKS_PER_SEC;
	return t;
}


void quick_sort (int arr [], int first, int last)
{	

	if (last > first) 
	{
		int left = first;
		int middle = arr [(last-first)/2];
		int right = last;
		do
		{         
			while (arr [left] < arr [middle])
				{
					left++;
				}
				 while (arr [right] > arr [middle])
				{
					right--;
				}
				if (left <= right)
					{
				        int tmp = arr[left];
				        arr[left] = arr[right];
				        arr[right] = tmp;
				        left++;
				        right--;
				    }

		} while (left <= right);
		quick_sort (arr, first, right);
		quick_sort (arr, left, last);
	}
}

float medium (float arr [], int size)
{
	float Sum = 0;
	for (int i = 0; i < size; i++)
	{
		Sum += arr[i];
	}
	return Sum/size;
}

float minimum (float arr [], int size)
{
	float min = arr [0];
	
	for (int i = 1; i < size; i++)
	{
		if (min > arr[i])
		{
			min = arr[i];
		}
	}
	return min;
}

float maximum (float arr [], int size)
{
	float max = arr [0];
	for (int i = 1; i < size; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	return max;
}


