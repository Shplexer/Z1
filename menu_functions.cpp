#include "menu_functions.h"

std::string openFileMenu(){
	int size{ 1 };
	int choice{ 0 };
	std::string fileName{ "--" };
	bool exit = true;
	std::cout << "Welcome!" << std::endl << "Var #2 by Daniil Orekhov" << std::endl;
	std::cout << "==============================================================================================" << std::endl;
	std::cout << "Task: Develop a class for a given subject area" << std::endl <<
		"Access to the data must be implemented through the Set, Get and Show methods" << std::endl <<
		"Enrollee: last name, first name, middle name, address, grades. Create an array of objects." << std::endl <<
		"Implement the ability to output: " << std::endl <<
		"- A sorted list of enrollees, " << std::endl <<
		"- A list of enrollees with grades higher than or equal to the input number, " << std::endl <<
		"- A list of N enrollees with the highest grades." << std::endl;
	std::cout << "==============================================================================================" << std::endl;
	std::cout
		<< "1. Test" << std::endl
		<< "2. Load a file" << std::endl
		<< "3. New file" << std::endl
		<< "4. Exit" << std::endl;
	std::cout << "==============================================================================================" << std::endl;
	do {
		choice = checkInt();
		switch (choice)
		{
		case FileChoice::test:
			fileName = "Test";
			exit = true;
			break;
		case FileChoice::customFile:
			std::cout << "Enter the name of a source file: ";
			fileName = makeLineGood();
			exit = true;
			break;
		case FileChoice::emptyStart:
			exit = true;
			break;
		case FileChoice::leaveFileMenu:
			std::cout << "Exiting the programm...";
			std::exit(0);
		default:
			std::cout << "ERR. Wrong input, try again" <<std::endl;
			exit = false;
			break;
		}
	} while (!exit);
		fileName = fileNameCheck(fileName);
	if (fileName != "Test.txt") {
		openFile(fileName);
	}
	return fileName;
}

bool editOptions(enrollee* source, int srcSize) {
	int action_choice{ 0 };
	int size = srcSize;
	bool exitEdit = false;
	bool exitAll = false;
	int prevSize = size;
	enrollee* people = new enrollee[size];
	enrollee* prevArr = new enrollee[prevSize];

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
			"3.Show enrollees with grades equal or higher than the input number" << std::endl <<
			"4.Show N enrollees with the highest grades" << std::endl <<
			"5.Save info to a file" << std::endl <<
			"6.Return to main menu" << std::endl <<
			"7.Exit the programm." << std::endl;
		std::cout << "==============================================================================================" << std::endl;
		action_choice = checkInt();
		switch (action_choice) {
		case ActionChoice::add:
			resizeArr(&prevArr, prevSize, size);
			size = addToArray(&people, size);
			break;
		case ActionChoice::sortArray:
			sortEnrollee(people, size);						//Сортировка массива по возрастающей, по разным параметрам 
			break;
		case ActionChoice::moreThan:
			size = showLimited(&people, size);				//Фильтр массива и возвращение нового размера
			break;
		case ActionChoice::top:
			quickSortInt(people, 0, (size - 1));
			//std::sort(&people[0], &people[size], gradeCmp); //Сортировка массива по возрастающей, по баллам
			size = topN(&people, size);						//Вывод первых N элементов отсортированного массива
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
			std::cout << "ERR. Wrong input, try again" <<std::endl;
			break;
		}
	} while (!exitEdit);

	return exitAll;
}
