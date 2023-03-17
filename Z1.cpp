#include "Z1.h"

std::ifstream file;

int main(){
	//setlocale(LC_ALL, "Russian");
	//system("chcp 1251");
	int size{ 1 };
	bool exitCondition;
	do {
		exitCondition = false;
		std::string fileName{};
		bool isTest = false;
		tie(fileName, isTest) = openFileMenu(fileName, isTest);
		if (isTest) {
			continue;
		}
		size = calculateSize(fileName);
		enrollee* src = new enrollee[size];
		setList(src, size, fileName);
		exitCondition = editOptions(src, size, fileName);
		file.close();
		delete[] src;
		src = nullptr;
	} while (!exitCondition);
	return 0;
}

std::string openFile(std::string fileName) {
	bool exit;
	int choice;
	do {
		exit = false;
		fileName = fileNameCheck(fileName);
		file.open(fileName);
		if (file.is_open()) {
			std::cout << "Your file is open!" << std::endl;
			exit = true;
		}
		else {
			std::cout << std::endl << "The name of the file you have entered does not exist." << std::endl
				<< "1.Change the name of the file" << std::endl
				<< "2.Create a new empty file" << std::endl
				<< "3.Exit" << std::endl;
			choice = checkInt();
			switch (choice)
			{
			case fileName::change:
				std::cout << "Enter the name of a source file: ";
				fileName = makeLineGood();
				break;
			case fileName::newFile:
				file.open(fileName);
				std::cout << "New file " << fileName << " is created! Don't forget to save it!" << std::endl;
				exit = true;
				break;
			case fileName::exitName:
				std::cout << "Exiting the program...";
				std::exit(0);
			default:
				std::cout << "ERR. Wrong input, try again" << std::endl;
				break;
			}
		}
	} while (!exit);
	return fileName;
}

void setList(enrollee* people, int size, std::string fileName) {
	std::ifstream setFile;
	setFile.open(fileName);
	for (int i = 0; i < size; i++)
	{
		std::string str{ "--" };
		char tmp{ ' ' };
		setFile >> tmp;							//удаление \n в конце строк
		std::getline(setFile, str, ' ');
		people[i].setLastName(tmp + str);

		std::getline(setFile, str, ' ');
		people[i].setFirstName(str);

		std::getline(setFile, str, ' ');
		people[i].setMiddleName(str);

		std::getline(setFile, str, ' ');
		people[i].setAddress(str);

		int num{ 0 };		
		setFile >> num;
		people[i].setGrade(num);

		people[i].setNumber(i + 1);
	}
	setFile.close();
}

int calculateSize(std::string fileName) {
	std::string line;
	int count = 0;
	std::ifstream mFile(fileName);
	if (mFile.is_open())
	{
		while (mFile.peek() != EOF)
		{
			getline(mFile, line);
			count++;
		}
		mFile.close();
		//std::cout << "Number of lines in the file are: " << count << std::endl;
	}

	return count;
}

void saveToFile(enrollee* people, int size, std::string saveFileName) {
	std::ofstream save;
	bool exit;
	if (file.is_open()) {
		std::cout << "The name of an open file: " << saveFileName << std::endl <<
			"Whould you like to make a new one or save into this one?" << std::endl <<
			"1. Save to another file" << std::endl <<
			"2. Save here" << std::endl;
		do {
			exit = true;
			int choice = checkInt();
			if (choice == saveFileName::changeFile) {
				std::cout << "Enter a path to the file: ";
				saveFileName = makeLineGood();
			}
			if (choice != saveFileName::changeFile && choice != saveFileName::thisFile) {
				exit = false;
			}
		} while (!exit);
	}
	else {
		std::cout << "No opened file found. Please enter a path to the file you wish to save your project to: ";
		saveFileName = makeLineGood();
	}
	saveFileName = fileNameCheck(saveFileName);
	save.open(saveFileName, std::ios::out);
	for (int i = 0; i < size; i++) {
		save << people[i].getLastName() << " " <<
			people[i].getFirstName() << " " <<
			people[i].getMiddleName() << " " <<
			people[i].getAddress() << " " <<
			people[i].getGrade() << std::endl;
	}
	save.close();
}