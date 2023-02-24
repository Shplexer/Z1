#include "header.h"

std::ifstream file;

int main(){
	//setlocale(LC_ALL, "Russian");
	std::string fileName{ "--" };
	int size{ 1 };
	bool exitCondition = false;
	do {
		size = openFileMenu();
		enrollee* people = new enrollee[size];
		setList(people, size);						
		exitCondition = editOptions(people, size);
		file.close();
		delete[] people;
		people = NULL;
	} while (!exitCondition);
	return 0;
}

void openFile(std::string fileName) {
	file.open(fileName);
	if(file.is_open())
		std::cout << "File \""<<getGoodLine(fileName) << "\" is open" << std::endl;
	else
		std::cout << "File \"" << getGoodLine(fileName) << "\" is created! Don't forget to save it!" << std::endl;
}

void setList(enrollee* people, int size) {
	for (int i = 0; i < size; i++)
	{
		std::string str{ "--" };
		char tmp{ ' ' };
		file >> tmp;
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

void saveToFile(enrollee* people, int size) {
	std::string saveFileName{ "==" };
	std::ofstream save;
	std::cout << "Enter the name of the file you wish to save the list to: ";
	saveFileName = makeLineGood();
	saveFileName = saveFileName + ".txt";
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