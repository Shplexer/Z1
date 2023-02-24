#include "menu_functions.h"

int openFileMenu(void){
	int size{ 1 };
	int choice{ 0 };
	std::string fileName{ "--" };
	std::cout << "Welcome!" << std::endl << "Var #2 by Daniil Orekhov" << std::endl;
	std::cout << "====================================================================================" << std::endl;
	std::cout << "Task: Develop a class for a given subject area" << std::endl <<
		"Access to the data must be implemented through the Set, Get and Show methods" << std::endl <<
		"Enrollee: last name, first name, middle name, address, grades. Create an array of objects." << std::endl <<
		"Implement the ability to output: " << std::endl <<
		"- A sorted list of enrollees, " << std::endl <<
		"- A list of enrollees with grades higher than the input number, " << std::endl <<
		"- A list of N enrollees with the highest grades." << std::endl;
	std::cout << "====================================================================================" << std::endl;
	std::cout << "1. Load a template file" << std::endl << "2. Load a custom file" << std::endl;
	choice = CheckInt();
	switch (choice)
	{
	case FileChoice::templateFile:
		fileName = "template";
		break;
	case FileChoice::customFile:
		std::cout << "Enter the name of a file you'd like to open: ";
		fileName = makeLineGood();
		break;
	case FileChoice::leaveFileMenu:
		std::cout << "Exiting the programm...";
		std::exit(0);
	default:
		std::cout << "ERR. Wrong input.";
		break;
	}
	fileName = fileName + ".txt";
	openFile(fileName);
	size = calculateSize(fileName);
	return size;
}

bool editOptions(enrollee* source, int srcSize) {
	int action_choice{ 0 };
	int size = srcSize;
	bool exitEdit = false;
	bool exitAll = false;
	enrollee* people = new enrollee[size];
	for (int i = 0; i < size; i++) {
		people[i].setAddress(source[i].getAddress());
		people[i].setFirstName(source[i].getFirstName());
		people[i].setLastName(source[i].getLastName());
		people[i].setMiddleName(source[i].getMiddleName());
		people[i].setGrade(source[i].getGrade());
		people[i].setNumber(i + 1);
	}
	do
	{
		printAll(people, size);
		std::cout << "Edit options:" << std::endl <<
			"1.Add an enrollee to the list" << std::endl <<
			"2.Sort the list" << std::endl <<
			"3.Show enrollees with grades higher than the input number" << std::endl <<
			"4.Show N enrollees with the highest grades" << std::endl <<
			"5.Reset the list" << std::endl <<
			"6.Save info to a file" << std::endl <<
			"7.Exit to main menu" << std::endl <<
			"8.Exit the programm." << std::endl;
		std::cout << "====================================================================================" << std::endl;
		action_choice = CheckInt();
		switch (action_choice) {
		case ActionChoice::add:
			size = AddToArray(&people, size);
			break;
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
		case ActionChoice::save:
			saveToFile(people, size);
			break;
		case ActionChoice::returnToMain:
			std::cout << "Returning to main menu..." << std::endl;
			exitEdit = true;
			exitAll = false;
			break;
		case ActionChoice::leaveEditMenu:
			std::cout << "Exiting...";
			exitEdit = true;
			exitAll = true; 
			break;
		default:
			std::cout << "ERR. Wrong input.";
			break;
		}
	} while (!exitEdit);
	delete[] people;
	people = NULL;
	return exitAll;
}
