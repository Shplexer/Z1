#include "functions.h"

std::string fileNameCheck(std::string inputName) {
	std::string temp;
	size_t nameSize = inputName.size();
	for (size_t i = nameSize - 4; i < nameSize; i++) {
		temp = temp + inputName[i];
	}
	if (temp != ".txt") {
		inputName = inputName + ".txt";
	}
	return inputName;
}

std::string makeLineGood(){
	std::string input{ "==" };
	std::getline(std::cin >> std::ws, input);
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == ' ') {
			input[i] = '_';
		}
	}
	return input;
}

std::string getGoodLine(std::string input) {
	std::string temp = input;
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] == '_') {
			temp[i] = ' ';
		}
	}
	return temp;
}

void resizeArr(enrollee** oldArr, int oldSize, int newSize) {
	enrollee* temp = new enrollee[newSize];
	for (int i = 0; i < newSize; i++) {
		if (i < oldSize) {
			temp[i].setAddress((*oldArr)[i].getAddress());
			temp[i].setFirstName((*oldArr)[i].getFirstName());
			temp[i].setLastName((*oldArr)[i].getLastName());
			temp[i].setMiddleName((*oldArr)[i].getMiddleName());
			temp[i].setGrade((*oldArr)[i].getGrade());
			temp[i].setNumber((*oldArr)[i].getNumber());
		}
		else {
			temp[i].setNumber(i + 1);
		}
	}
	delete[] * oldArr;
	*oldArr = new enrollee[newSize];
	for (int i = 0; i < newSize; i++) {
		(*oldArr)[i].setAddress(temp[i].getAddress());
		(*oldArr)[i].setFirstName(temp[i].getFirstName());
		(*oldArr)[i].setLastName(temp[i].getLastName());
		(*oldArr)[i].setMiddleName(temp[i].getMiddleName());
		(*oldArr)[i].setGrade(temp[i].getGrade());
		(*oldArr)[i].setNumber(temp[i].getNumber());
	}
	delete[] temp;
	temp = nullptr;
}

void sortEnrollee(enrollee* arr, int size) {
	int choice{ 0 };
	bool exit;
	std::cout << "Choose sorting method: " << std::endl <<
		"1.By last name" << std::endl <<
		"2.By grades" << std::endl;
	do {
		exit = true;
		choice = checkInt();
		switch (choice)
		{
		case SortChoice::byName:
			quickSortString(arr, 0, (size - 1));
			break;
		case SortChoice::byGrade:
			quickSortInt(arr, 0, (size - 1));
			break;
		default:
			std::cout << "ERR. Wrong input, try again" <<std::endl;
			exit = false;
			break;
		}
	} while (!exit);
}

int checkInt() {
	int input{ 0 };
	while (!(std::cin >> input)) {
		std::cin.clear();											//discard err flag
		std::cin.ignore(INT_MAX, '\n');								//clear buffer for INT_MAX characters or until '\n'
		std::cout << "ERR. Wrong input, try again" << std::endl;
	}
	while ((getchar()) != '\n');
	return input;
}

int addToArray(enrollee** arr, int srcSize, bool test) {
	int newSize{ 0 };
	if (test == false) {
		std::cout << "Enter the number of enrollees you wish to add: ";
		newSize = checkInt();
	}
	else{
		newSize++;
	}
	newSize = srcSize + newSize;
	resizeArr(arr, srcSize, newSize);
	for (int i = srcSize; i < newSize; i++) {
		if (test == false) {
			std::cout << "==============================================================================================" << std::endl;
			std::string input = "--";
			int num{ 0 };
			std::cout << "Enter last name: ";
			(*arr)[i].setLastName(makeLineGood());
			std::cout << "Enter first name: ";
			(*arr)[i].setFirstName(makeLineGood());
			std::cout << "Enter middle name: ";
			(*arr)[i].setMiddleName(makeLineGood());
			std::cout << "Enter address: ";
			(*arr)[i].setAddress(makeLineGood());
			std::cout << "Enter grade: ";
			(*arr)[i].setGrade(checkInt());
		}
		else {
			char ch = D;
			std::string s{ ch };
			(*arr)[i].setLastName(s);
			(*arr)[i].setFirstName(s);
			(*arr)[i].setMiddleName(s);
			(*arr)[i].setAddress(s);
			(*arr)[i].setGrade(i);
		}
	}
	return newSize;
}

int showLimited(enrollee** arr, int size, bool test) {
	bool exit = true;
	int newSize{ 0 };
	int counter{ 0 };
	int minGrade{ 0 };
	do{
		counter = 0;
		if (!test) {
			std::cout << "Enter the lowest grade: ";
			minGrade = checkInt();
		}
		else {
			minGrade = TESTMINGRADE;
		}
		for (int i = 0; i < size; i++) {
			if((*arr)[i].getGrade() >= minGrade) {
				counter++;
			}
		}
		if (counter == 0) {
			std::cout << "No enrollees with such grades found. Try again" << std::endl;
			exit = false;
		}
		else {
			exit = true;
		}
	} while (!exit);
		newSize = counter;
		for (int i = 0, j = 0; j < newSize; i++) {
			if ((*arr)[i].getGrade() >= minGrade) {
				(*arr)[j].setAddress((*arr)[i].getAddress());
				(*arr)[j].setFirstName((*arr)[i].getFirstName());
				(*arr)[j].setLastName((*arr)[i].getLastName());
				(*arr)[j].setMiddleName((*arr)[i].getMiddleName());
				(*arr)[j].setGrade((*arr)[i].getGrade());
				(*arr)[j].setNumber((*arr)[i].getNumber());
				j++;
			}
		}
		resizeArr(arr, size, newSize);
	return newSize;
}

int topN(enrollee** arr, int size, bool test) {
	int newSize{ 0 };
	quickSortInt(*arr, 0, (size - 1));
	if (!test) {
		std::cout << "Enter the number of enrollees with the highest grades: ";
		do {
			newSize = checkInt();
			if (newSize > size)
				std::cout << "ERR. Wrong input, try again" <<std::endl;
		} while (newSize > size);
	}
	else {
		newSize = TESTTOPN;
	}
	resizeArr(arr, size, newSize);
	return newSize;
}

void printAll(enrollee* arr, int size) {
	std::cout << "==============================================================================================" << std::endl;
	std::cout << "Enrollees: " << std::endl;
	std::cout << "==============================================================================================" << std::endl;
	std::cout
		<< std::left 
		<< std::setw(SSHRT) << "#"
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
	std::cout << "==============================================================================================" << std::endl;
	for (int i = 0; i < size; i++) {
		arr[i].setNumber(i + 1);
		arr[i].showInfo();
	}
	std::cout << "==============================================================================================" << std::endl;
}


int quickSortInt_divide(enrollee* arr, int start, int end) {
	enrollee pivot = arr[end];
	int index = start;
	for (int i = start; i < end; i++) {
		if (arr[i].getGrade() > pivot.getGrade()) {
			enrollee temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
			index++;

		}
		else if (arr[i].getGrade() == pivot.getGrade()) {				//if grades are equal we sort by last name
			int j = 0;
			while (j < arr[i].getLastName().size()) {
				if (arr[i].getLastName()[j] < pivot.getLastName()[j]) {
					enrollee temp = arr[i];
					arr[i] = arr[index];
					arr[index] = temp;
					index++;
					break;
				}
				else if (arr[i].getLastName()[j] == pivot.getLastName()[j]) {
					j++;
				}
				else {
					break;
				}
			}
		}
	}
	enrollee temp = arr[end];
	arr[end] = arr[index];
	arr[index] = temp;
	return index;
}

void quickSortInt(enrollee* arr, int start, int end) {
	if (start < end) {
		int d = quickSortInt_divide(arr, start, end);
		quickSortInt(arr, start, (d - 1));
		quickSortInt(arr, (d + 1), end);
	}

}

int quickSortString_divide(enrollee* arr, int start, int end) {
	std::string pivot = arr[end].getLastName();
	int index = start;
	for (int i = start; i < end; i++) {
		int j = 0;
		while (j < arr[i].getLastName().size()) {
			if (arr[i].getLastName()[j] < pivot[j]) {
				enrollee temp = arr[i];
				arr[i] = arr[index];
				arr[index] = temp;
				index++;
				break;
			}
			else if (arr[i].getLastName()[j] == pivot[j]) {
				j++;
			}
			else {
				break;
			}
		}
	}
	enrollee temp = arr[end];
	arr[end] = arr[index];
	arr[index] = temp;
	return index;
}

void quickSortString(enrollee* arr, int start, int end) {
	if (start < end) {
		int d = quickSortString_divide(arr, start, end);
		quickSortString(arr, start, (d - 1));
		quickSortString(arr, (d + 1), end);
	}
}


