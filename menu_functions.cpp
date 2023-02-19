#include "menu_functions.h"

std::tuple <std::string, int> openFileMenu(void) {
	int size{ 1 };
	int choice{ 0 };
	std::string fileName{ "--" };
	std::cout << "Добро пожаловать!" << std::endl << "Вариант №2 Контрольной работы №1 был выполнен Ореховым Даниилом" << std::endl;
	std::cout << "====================================================================================" << std::endl;
	std::cout << "Задание: Необходимо разработать класс для указанной предметной области."<<std::endl<<
		"Доступ к данным реализовать с помощью методов Set, Get, Show." << std::endl<<
		"Абитуриент: фамилия, имя, отчество, адрес, баллы. Создать массив объектов. Реализовать возможность получения: " << std::endl <<
		"– отсортированного списка всех абитуриентов, " << std::endl <<
		"– списка абитуриентов, сумма баллов у которых не меньше заданной," << std::endl <<
		"– списка N абитуриентов, имеющих самую высокую сумму баллов." << std::endl;
	std::cout << "====================================================================================" << std::endl;
	std::cout << "1. Загрузить шаблон" << std::endl << "2. Загрузить пользовательский файл" << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case FileChoice::templateFile:
		fileName = "template";
		size = TEMPLATE_SIZE;
		break;
	case FileChoice::customFile:
		std::cout << "Введите название файла, который нужно создать/изменить: ";
		std::cin >> fileName;
		std::cout << "Введите количество абитуриентов: ";
		std::cin >> size;
		break;
	case FileChoice::leaveFile:
		std::cout << "Выход...";
		std::exit(0);
	default:
		std::cout << "Ошибка";
		break;
	}
	fileName = fileName + ".txt";
	openFile(fileName);
	return std::make_tuple(fileName, size);
}

void editOptions(enrollee* source, int srcSize) {
	int action_choice{ 0 };
	int size = srcSize;

	bool exitEdit = false;
		enrollee* people = new enrollee[size];
	for (int i = 0; i < size; i++) {
		people[i].setAddress(source[i].getAddress());
		people[i].setFirstName(source[i].getFirstName());
		people[i].setLastName(source[i].getLastName());
		people[i].setMiddleName(source[i].getMiddleName());
		people[i].setGrade(source[i].getGrade());
	}
	do
	{
		printAll(people, size);
		std::cout << "Для редактирования:" << std::endl <<
			"1.Отсортировать список по параметрам" << std::endl <<
			"2.Список абитуриентов, сумма баллов которых не меньше заданой" << std::endl <<
			"3.Список N абитуриентов имеющих наибольшее количество баллов" << std::endl <<
			"4.Вернуться к исходному файлу" << std::endl <<
			"5.Выход." << std::endl;
		std::cout << "====================================================================================" << std::endl;
		std::cin >> action_choice;
		switch (action_choice) {
		case ActionChoice::sortArray:
			sortEnrollee(people, size);						//Сортировка массива по возрастающей, по разным параметрам 
			break;
		case ActionChoice::moreThan:
			size = showLimited(&people, size);				//Фильтр массива и возвращение нового размера
			break;
		case ActionChoice::top:
			std::sort(&people[0], &people[size], gradeCmp); //Сортировка массива по возрастающей, по баллам
			size = topN(&people, size);						//Вывод первых N элементов отсортированного массива
 			break;
		case ActionChoice::returnToSrc:						//Сброс массива к исходному
			delete[] people;
			size = srcSize;
			people = new enrollee[size];
			for (int i = 0; i < size; i++) {
				people[i].setAddress(source[i].getAddress());
				people[i].setFirstName(source[i].getFirstName());
				people[i].setLastName(source[i].getLastName());
				people[i].setMiddleName(source[i].getMiddleName());
				people[i].setGrade(source[i].getGrade());
			}
			break;
		case ActionChoice::leaveEditMenu:
			std::cout << "Выход...";
			exitEdit = true;
			break;
		default:
			std::cout << "Ошибка";
			break;
		}
	} while (!exitEdit);
	delete[] people;
	people = NULL;
}
