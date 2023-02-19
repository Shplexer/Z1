#include "functions.h"

void sortEnrollee(enrollee* people, int size) {
	int choice{ 0 };
	std::cout << "Выберите метод сортировки" << std::endl <<
		"1.По Фамилии" << std::endl <<
		"2.По Адресу" << std::endl <<
		"3.По Оценке" << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case SortChoice::byName:
		std::sort(&people[0], &people[size], nameCmp);
		break;
	case SortChoice::byCity:
		std::sort(&people[0], &people[size], cityCmp);
		break;
	case SortChoice::byGrade:
		std::sort(&people[0], &people[size], gradeCmp);
		break;
	default:
		std::cout << "Ошибка.";
		break;
	}
}

int showLimited(enrollee** people, int size) {
	int minGrade{ 0 };
	int newSize{ 0 };
	int counter{ 0 };
	std::cout << "Введите минимальное кол-во баллов: ";
	std::cin >> minGrade;
	for (int i = 0; i < size; i++) {
		if((*people)[i].getGrade() >= minGrade) {
			counter++;
		}
	}
	newSize = counter;
	enrollee* temp = new enrollee[newSize];
	for (int i = 0, j = 0; j < newSize; i++) {
		if ((*people)[i].getGrade() >= minGrade) {
			temp[j] = (*people)[i];
			j++;
		}
	}
	size = newSize;
	delete[] *people;
	*people = new enrollee[size];
	for (int i = 0; i < size; i++) {
		(*people)[i].setAddress(temp[i].getAddress());
		(*people)[i].setFirstName(temp[i].getFirstName());
		(*people)[i].setLastName(temp[i].getLastName());
		(*people)[i].setMiddleName(temp[i].getMiddleName());
		(*people)[i].setGrade(temp[i].getGrade());
	}
	delete[] temp;
	temp = NULL;
	return size;
}

int topN(enrollee** people, int size) {
	int minGrade{ 0 };
	int newSize{ 0 };
	std::cout << "Введите количество абитуриентов с самыми высокими баллами: ";
	std::cin >> newSize;
	enrollee* temp = new enrollee[newSize];
	size = newSize;
	for (int i = 0; i < size; i++) {
		(temp)[i].setAddress((*people)[i].getAddress());
		(temp)[i].setFirstName((*people)[i].getFirstName());
		(temp)[i].setLastName((*people)[i].getLastName());
		(temp)[i].setMiddleName((*people)[i].getMiddleName());
		(temp)[i].setGrade((*people)[i].getGrade());
	}
	delete[] * people;
	*people = new enrollee[size];
	for (int i = 0; i < size; i++) {
		(*people)[i].setAddress(temp[i].getAddress());
		(*people)[i].setFirstName(temp[i].getFirstName());
		(*people)[i].setLastName(temp[i].getLastName());
		(*people)[i].setMiddleName(temp[i].getMiddleName());
		(*people)[i].setGrade(temp[i].getGrade());
	}
	delete[] temp;
	temp = NULL;
	return size;
}

bool nameCmp(enrollee& a, enrollee& b) {
	return a.getFirstName() < b.getFirstName();
}

bool cityCmp(enrollee& a, enrollee& b) {
	return a.getAddress() < b.getAddress();
}

bool gradeCmp(enrollee& a, enrollee& b) {
	return a.getGrade() > b.getGrade();
}

void printAll(enrollee* people, int size) {
	std::cout << "====================================================================================" << std::endl;
	std::cout << "Список абитуриентов: " << std::endl;
	std::cout << "====================================================================================" << std::endl;
	std::cout
		<< std::left 
		<< std::setw(SHRT) << "#"
		<< std::setw(MID) << "Фамилия"
		<< std::setw(MID) << "Имя"
		<< std::setw(LNG) << "Отчество"
		<< std::setw(SHRT) << "||"
		<< std::setw(LNG) << "Адрес"
		<< std::setw(SHRT) << "||"
		<< std::right << std::setw(SHRT) << "Оценка"
		<< std::setw(SHRT) << "||"
		<< std::endl;
	std::cout << "====================================================================================" << std::endl;
	for (int i = 0; i < size; i++) {
		people[i].setNumber(i+1);
		people[i].showInfo();
	}
	std::cout << "====================================================================================" << std::endl;
}

