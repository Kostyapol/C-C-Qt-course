#include <iostream>
#include <string>
#include <vector>
#include <iterator> 

#define Max_memory 10000 // размер доступной памяти (10000 КБ)


void add_block (std::vector <int> *sizes, std::vector <int*> *ptrs_of_blocks);
void del_block (std::vector <int> *sizes, std::vector <int*> *ptrs_of_blocks);
void comb_block (std::vector <int> *sizes, std::vector <int*> *ptrs_of_blocks); // функция объединения двух блоков
void show_memory (const std:: vector <int> &vec); // функция вычисления и отображения свободной памяти // передача вектора по константной ссылке
int get_memory_free (const std:: vector <int> &vec); // функция вычисления свободной памяти, по сути дублирует show_memory, но в них разные способы обращения к элементам vector (для тренировки)
void show_ptrs (const std:: vector <int*> &ptrs); // функция отображения существующих указателей на блоки

int main()
{
	std::vector <int> sizes_of_blocks; // вектор для хранения размеров блоков в байтах
	std::vector <int*> ptrs_of_blocks; // вектор указателей на блоки памяти
	int mod = 0;
	std::cout << "   Менеджер памяти" << std::endl;
	while (mod != 5)
	{
		std::cout << "1. Добавить блок" << std::endl;
		std::cout << "2. Удалить блок" << std::endl;
		std::cout << "3. Объединить блоки" << std::endl;
		std::cout << "4. Отобразить состояние памяти" << std::endl;
		std::cout << "5. Выход" << std::endl;
		std::cin >> mod;
		
		switch(mod)
		{
			case 1:
				add_block(&sizes_of_blocks,&ptrs_of_blocks);
				break;
			case 2:
				del_block(&sizes_of_blocks,&ptrs_of_blocks);
				break;
			case 3:
				comb_block(&sizes_of_blocks,&ptrs_of_blocks);
				break;
			case 4:
				show_memory (sizes_of_blocks);
				//std::cout << "Свободная память = "<< get_memory_free(sizes_of_blocks) << " КБ" << std::endl;
				std::cout << "Адреса блоков: ";
				show_ptrs (ptrs_of_blocks); 
				break;
			case 5:
				exit(1);
		}		
	}
	return 0;
	
}

void add_block (std::vector <int> *sizes, std::vector <int*> *ptrs_of_blocks)
{
	int size_block = 0;
	std::cout << "Введите размер блока в КБ: ";
	std::cin >> size_block;
	std::cout << std::endl;
	if (size_block > get_memory_free(*sizes))	
	{
		std::cout << "Ошибка!Недостаточно памяти!" << std::endl << std::endl;	
	} else 
	{
		int *ptr_block = new int [size_block/sizeof(int)*1000];
		ptrs_of_blocks -> push_back (ptr_block);
		sizes-> push_back (size_block);
		std::cout << "Блок размером " << size_block << " КБ добавлен" << std::endl <<std::endl;
	}
}

void del_block (std::vector <int> *sizes, std::vector <int*> *ptrs_of_blocks)
{
	int num_block = 0;
	std::cout << "Введите номер блока удаления: ";
	std::cin >> num_block;
	if (num_block > ptrs_of_blocks -> size() || num_block < 1)
	{
	std::cout << "Такого блока не существует";
	} else
	{
	delete ptrs_of_blocks -> at (num_block-1); // освобождаем память
	ptrs_of_blocks -> erase (ptrs_of_blocks -> begin () + num_block-1);   // удаляем элемент
	sizes -> erase (sizes -> begin () + num_block - 1);
	std::cout << "Блок " << num_block << " удален" << std::endl << std::endl;
	}
}

void comb_block (std::vector <int> *sizes, std::vector <int*> *ptrs_of_blocks)
{
	int num_block1 = 0;
	int num_block2 = 0;
	int sum_size = 0;
	std::cout << "Введите номер первого блока: ";
	std::cin >> num_block1;
	std::cout << "Введите номер второго блока: ";
	std::cin >> num_block2;
	if (num_block1 > ptrs_of_blocks -> size() || num_block1 < 1 || num_block2 > ptrs_of_blocks -> size() || num_block2 < 1)
	{
	std::cout << "Неверные номера блоков"<< std::endl;
	} else
	{
	delete ptrs_of_blocks -> at (num_block1-1); // освобождаем память 1 блока
	delete ptrs_of_blocks -> at (num_block2-1); // освобождаем память 2 блока
	sum_size = sizes -> at (num_block1-1) + sizes -> at (num_block2-1);
	
	int *ptr_block = new int [sum_size/sizeof(int)*1000]; // выделяем память для объединенного блока
	ptrs_of_blocks -> push_back (ptr_block);
	sizes -> push_back (sum_size);
	ptrs_of_blocks -> erase (ptrs_of_blocks -> begin () + num_block1 - 1);   // удаляем 1 блок
	sizes -> erase (sizes -> begin () + num_block1 - 1);
	ptrs_of_blocks -> erase (ptrs_of_blocks -> begin () + num_block2 - 1);   // удаляем 2 блок
	sizes -> erase (sizes -> begin () - 1 + num_block2 - 1);
	std::cout << "Объединение блоков " << num_block1 << " и " << num_block2 << " прошло успешно" << std::endl << std::endl;
	}
}


int get_memory_free (const std:: vector <int> &vec)
{
	int mem_free = Max_memory;
	auto begin {std::begin(vec)}; // доступ к элементам вектора с помощью иттератора
	auto end{std::end(vec)};	
	for (auto it {begin}; it != end; ++it)
	{
		mem_free-=*it;	
	}
	return mem_free;
}



void show_memory (const std::vector <int> &vec)
{
	int mem_free = Max_memory;
	std::cout << std::endl << "Размеры блоков: ";
	for(int i = 0; i < vec.size(); i++) // доступ к элементам вектора без иттератора
        {
		std::cout << vec[i] << ' ';
		mem_free-=vec[i];		
	}
	std::cout << std::endl;
	std::cout << "Свободная память = "<< mem_free << " КБ" << std::endl;
}
 
void show_ptrs (const std:: vector <int*> &ptrs)
{
		
	for(int i = 0; i < ptrs.size(); i++) // доступ к элементам вектора без иттератора
        {
		std::cout << ptrs[i] << " ";
	}
	std::cout << std::endl << std::endl;
	
}



