#include "menu_functions.h"

std::tuple <std::string, int> openFileMenu(void) {
	int size{ 1 };
	int choice{ 0 };
	std::string fileName{ "--" };
	std::cout << "����� ����������!" << std::endl << "������� �2 ����������� ������ �1 ��� �������� �������� ��������" << std::endl;
	std::cout << "====================================================================================" << std::endl;
	std::cout << "�������: ���������� ����������� ����� ��� ��������� ���������� �������."<<std::endl<<
		"������ � ������ ����������� � ������� ������� Set, Get, Show." << std::endl<<
		"����������: �������, ���, ��������, �����, �����. ������� ������ ��������. ����������� ����������� ���������: " << std::endl <<
		"� ���������������� ������ ���� ������������, " << std::endl <<
		"� ������ ������������, ����� ������ � ������� �� ������ ��������," << std::endl <<
		"� ������ N ������������, ������� ����� ������� ����� ������." << std::endl;
	std::cout << "====================================================================================" << std::endl;
	std::cout << "1. ��������� ������" << std::endl << "2. ��������� ���������������� ����" << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case FileChoice::templateFile:
		fileName = "template";
		size = TEMPLATE_SIZE;
		break;
	case FileChoice::customFile:
		std::cout << "������� �������� �����, ������� ����� �������/��������: ";
		std::cin >> fileName;
		std::cout << "������� ���������� ������������: ";
		std::cin >> size;
		break;
	case FileChoice::leaveFile:
		std::cout << "�����...";
		std::exit(0);
	default:
		std::cout << "������";
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
		std::cout << "��� ��������������:" << std::endl <<
			"1.������������� ������ �� ����������" << std::endl <<
			"2.������ ������������, ����� ������ ������� �� ������ �������" << std::endl <<
			"3.������ N ������������ ������� ���������� ���������� ������" << std::endl <<
			"4.��������� � ��������� �����" << std::endl <<
			"5.�����." << std::endl;
		std::cout << "====================================================================================" << std::endl;
		std::cin >> action_choice;
		switch (action_choice) {
		case ActionChoice::sortArray:
			sortEnrollee(people, size);						//���������� ������� �� ������������, �� ������ ���������� 
			break;
		case ActionChoice::moreThan:
			size = showLimited(&people, size);				//������ ������� � ����������� ������ �������
			break;
		case ActionChoice::top:
			std::sort(&people[0], &people[size], gradeCmp); //���������� ������� �� ������������, �� ������
			size = topN(&people, size);						//����� ������ N ��������� ���������������� �������
 			break;
		case ActionChoice::returnToSrc:						//����� ������� � ���������
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
			std::cout << "�����...";
			exitEdit = true;
			break;
		default:
			std::cout << "������";
			break;
		}
	} while (!exitEdit);
	delete[] people;
	people = NULL;
}
