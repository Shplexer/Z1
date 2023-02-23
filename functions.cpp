#include "functions.h"


void sortEnrollee(enrollee* people, int size) {
	int choice{ 0 };
	std::cout << "Choose sorting method: " << std::endl <<
		"1.By last name" << std::endl <<
		"2.By address" << std::endl <<
		"3.By grades" << std::endl;
	choice = CheckInt();
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
		std::cout << "ERR. Wrong input.";
		break;
	}
}

int CheckInt(void) {
	int input{ 0 };
	while (!(std::cin >> input)) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "ERR. Wrong input, try again" << std::endl;
	}
	while ((getchar()) != '\n');
	return input;
}

int AddToArray(enrollee** people, int srcSize) {
	int newSize{ 0 };
	std::cout << "Enter the number of enrollees you wish to add: ";
	newSize = CheckInt();
	newSize = srcSize + newSize;
	enrollee* temp = new enrollee[newSize];
	for (int i = 0; i < newSize; i++) { //?????
		if(i < srcSize){
			temp[i].setAddress((*people)[i].getAddress());
			temp[i].setFirstName((*people)[i].getFirstName());
			temp[i].setLastName((*people)[i].getLastName());
			temp[i].setMiddleName((*people)[i].getMiddleName());
			temp[i].setGrade((*people)[i].getGrade());
			temp[i].setNumber((*people)[i].getNumber());
		}
		else {
			std::cout << "====================================================================================" << std::endl;
			std::string input = "--";
			std::cout << "Enter last name: ";
			std::cin >> input;
			temp[i].setLastName(input);
			std::cout << "Enter first name: ";
			std::cin >> input;
			temp[i].setFirstName(input);
			std::cout << "Enter midlle name: ";
			std::cin >> input;
			temp[i].setMiddleName(input);
			std::cout << "Enter address: ";
			std::cin >> input;
			temp[i].setAddress(input);
			std::cout << "Enter grade: ";
			int num{ 0 };
			temp[i].setGrade(CheckInt());
			temp[i].setNumber(i + 1);
		}
	}
	delete[] * people;
	*people = new enrollee[newSize];
	for (int i = 0; i < newSize; i++) {
		(*people)[i].setAddress(temp[i].getAddress());
		(*people)[i].setFirstName(temp[i].getFirstName());
		(*people)[i].setLastName(temp[i].getLastName());
		(*people)[i].setMiddleName(temp[i].getMiddleName());
		(*people)[i].setGrade(temp[i].getGrade());
		(*people)[i].setNumber(temp[i].getNumber());
	}
	delete[] temp;
	temp = NULL;
	return newSize;
}

int showLimited(enrollee** people, int size) {
	int minGrade{ 0 };
	int newSize{ 0 };
	int counter{ 0 };
	std::cout << "Enter the lowest grade: ";
	minGrade = CheckInt();
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
		(*people)[i].setNumber(temp[i].getNumber());
	}
	delete[] temp;
	temp = NULL;
	return size;
}

int topN(enrollee** people, int size) {
	int newSize{ 0 };
	std::cout << "Enter the number of enrollees with the highest grades: ";
	newSize = CheckInt();
	enrollee* temp = new enrollee[newSize];
	size = newSize;
	for (int i = 0; i < size; i++) {
		temp[i].setAddress((*people)[i].getAddress());
		temp[i].setFirstName((*people)[i].getFirstName());
		temp[i].setLastName((*people)[i].getLastName());
		temp[i].setMiddleName((*people)[i].getMiddleName());
		temp[i].setGrade((*people)[i].getGrade());
		temp[i].setNumber((*people)[i].getNumber());
	}
	delete[] * people;
	*people = new enrollee[size];
	for (int i = 0; i < size; i++) {
		(*people)[i].setAddress(temp[i].getAddress());
		(*people)[i].setFirstName(temp[i].getFirstName());
		(*people)[i].setLastName(temp[i].getLastName());
		(*people)[i].setMiddleName(temp[i].getMiddleName());
		(*people)[i].setGrade(temp[i].getGrade());
		(*people)[i].setNumber(temp[i].getNumber());
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
	std::cout << "Enrollees: " << std::endl;
	std::cout << "====================================================================================" << std::endl;
	std::cout
		<< std::left 
		<< std::setw(SHRT) << "#"
		<< std::setw(SHRT) << "||"
		<< std::setw(MID) << "Last"
		<< std::setw(MID) << "First"
		<< std::setw(LNG) << "Middle name"
		<< std::setw(SHRT) << "||"
		<< std::setw(LNG) << "Address"
		<< std::setw(SHRT) << "||"
		<< std::right << std::setw(SHRT) << "Grade"
		<< std::setw(SHRT) << "||"
		<< std::endl;
	std::cout << "====================================================================================" << std::endl;
	for (int i = 0; i < size; i++) {
		people[i].showInfo();
	}
	std::cout << "====================================================================================" << std::endl;
}
