#include "Z1.h"

std::ifstream file;

int main(){
	//setlocale(LC_ALL, "Russian");
	//system("chcp 1251");
	int size{ 1 };
	bool exitCondition;
	do {
		exitCondition = false;
		std::string fileName{INITFILENAME};
		fileName = openFileMenu(fileName);
		if (fileName == INITFILENAME) {
			continue;
		}
		size = calculateSize(fileName);
		enrollee* people = new enrollee[size];
		setList(people, size);
		exitCondition = editOptions(people, size, fileName);
		file.close();
		delete[] people;
		people = nullptr;
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
			std::cout << "File \"" << getGoodLine(fileName) << "\" is open" << std::endl;
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

void setList(enrollee* people, int size) {
	for (int i = 0; i < size; i++)
	{
		std::string str{ "--" };
		char tmp{ ' ' };
		file >> tmp;							//удаление \n в конце строк
		std::getline(file, str, ' ');
		people[i].setLastName(tmp + str);

		std::getline(file, str, ' ');
		people[i].setFirstName(str);

		std::getline(file, str, ' ');
		people[i].setMiddleName(str);

		std::getline(file, str, ' ');
		people[i].setAddress(str);

		int num{ 0 };
		file >> num;
		people[i].setGrade(num);

		people[i].setNumber(i + 1);
	}
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