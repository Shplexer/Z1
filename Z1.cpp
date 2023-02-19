#include "header.h"

std::fstream file;

int main(){
	setlocale(LC_ALL, "Russian");
	std::string fileName{ "--" };
	int size{ 1 };

	std::tie(fileName, size) = openFileMenu();	//��������� ����

	enrollee* people = new enrollee[size];
	setList(people, size); //��������� ������ � ������ �� �����

	editOptions(people, size); //���� ��������������
	file.close();
	delete[] people;
	people = NULL;
	return 0;
}

void openFile(std::string fileName) {
	file.open(fileName);
	while (!file.is_open())
	{
		std::cout << "������ �������� ����� " << fileName << std::endl;
		std::cout << "������� �������� �����, ������� ����� �������/��������: ";
		std::cin >> fileName;
	}
	std::cout << "���� ������" << std::endl;
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

		/*std::getline(file, str, '\n');
		people[i].SetGrade(str);*/
		int num{ 0 };

		file >> num;

		people[i].setGrade(num);
	}
}
