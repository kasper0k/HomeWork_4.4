/*Тема: Алгоритмы и структуры данных. Динамический массив.
Задача 2. Добавление в изменяемый динамический массив
В этом задании вам нужно реализовать функцию добавления нового элемента в конец динамического массива целых чисел append_to_dynamic_array.
Добавление элемента будет происходить по алгоритму: если логический размер массива меньше фактического, 
то вы добавляете новый элемент в запас вашего массива и увеличиваете его логический размер на 1.
Если логический размер массива равен его фактическому размеру, тогда создаётся новый массив размером в 2 раза больше. 
В него перекладываются элементы из старого массива вместе с новым элементом в конце. 
Фактический и логический размеры массива изменяют своё значение. 
Логический размер увеличивается на единицу, фактический размер увеличивается в два раза, старый массив уничтожается. 
Далее программа должна работать уже с новым массивом.
Организуйте интерактивное взаимодействие с пользователем. Ваша программа будет работать по алгоритму:
	1 Пользователь вводит фактический размер массива.
	2 Пользователь вводит логический размер массива.
	3 Пользователь вводит элементы для заполнения массива. Их количество будет равно логическому размеру массива.
	4 Программа выводит введённый массив на консоль с помощью функции print_dynamic_array из прошлого задания.
	5 Пользователь вводит новый элемент для добавления в конец. Ввод элементов заканчивается, если пользователь введёт специальное значение (например, 0).
	6 Программа выводит массив с добавленным элементом.
Пункты 5 и 6 повторяются до тех пор, пока пользователь не введёт специальное значение (например, 0).
Программа прощается, выводит окончательное состояние динамического массива и завершает свою работу.
Подумайте над тем, какая сигнатура будет у вашей функции и как вы будете хранить фактический и логический размеры вашего массива.*/

#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
	std::cout << "Динамический массив: ";
	for (int i = 0; i < actual_size; i++)
	{
		if (i < logical_size)
		{
			std::cout << arr[i] << " ";
		}
		else
		{
			std::cout << "_" << " ";
		}
	}
}

int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int new_arr_element)
{
	if (actual_size == logical_size)
	{
		actual_size = actual_size * 2;
		int* arr_temp = new int(actual_size);
		for (int i = 0; i < logical_size; i++)
		{
			arr_temp[i] = arr[i];
		}
		arr_temp[logical_size] = new_arr_element;
		logical_size = logical_size + 1;
		return arr_temp;
	}
	else
	{
		arr[logical_size] = new_arr_element;
		logical_size = logical_size + 1;
		return arr;
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	int actual_size = 0, logical_size=0, stop_marker=0, new_arr_element=0;
	std::cout << "Введите фактический размер массива: ";
	std::cin >> actual_size;
	std::cout << "Введите логический размер массива: ";
	std::cin >> logical_size;

	if (logical_size > actual_size)
	{
		std::cout << "Ошибка. Логический размер массива не может превышать фактический!" << std::endl;
	}
	else
	{
		int* arr = new int[actual_size];
		for (int i = 0; i < logical_size; i++)
		{
			std::cout << "  Введите элемент " << i << ": ";
			std::cin >> arr[i];
		}
		print_dynamic_array(arr, logical_size, actual_size);

		while (stop_marker == 0)
		{
			std::cout <<std::endl<< "Введите элемент для добавления в массив или '0' для вывода массива на экран: ";
			std::cin >> new_arr_element;
			if (new_arr_element == 0)
			{
				stop_marker = 1;
			}
			else
			{
				arr=append_to_dynamic_array (arr, logical_size, actual_size, new_arr_element);
				print_dynamic_array(arr, logical_size, actual_size);
			}
			std::cout << std::endl;
		}		
		delete[] arr;
	}
	return 0;
}