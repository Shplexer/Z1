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
	temp = NULL;
}

void sortEnrollee(enrollee* people, int size) {
	int choice{ 0 };
	bool exit = false;
	std::cout << "Choose sorting method: " << std::endl <<
		"1.By last name" << std::endl <<
		"2.By grades" << std::endl;
	do {
		choice = checkInt();
		switch (choice)
		{
		case SortChoice::byName:
			//std::sort(&people[0], &people[size], nameCmp);
			quickSortString(&people, 0, (size - 1));
			exit = true;
			break;
		case SortChoice::byGrade:
			quickSortInt(people, 0, (size - 1));
			//std::sort(&people[0], &people[size], gradeCmp);
			exit = true;
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
		std::cin.clear();				//discard err flag
		std::cin.ignore(INT_MAX, '\n');	//clear buffer for INT_MAX characters or until \n
		std::cout << "ERR. Wrong input, try again" << std::endl;
	}
	while ((getchar()) != '\n');
	return input;
}

int addToArray(enrollee** people, int srcSize) {
	int newSize{ 0 };
	std::cout << "Enter the number of enrollees you wish to add: ";
	newSize = checkInt();
	newSize = srcSize + newSize;
	resizeArr(people, srcSize, newSize);
	for (int i = srcSize; i < newSize; i++) {
		std::cout << "==============================================================================================" << std::endl;
		std::string input = "--";
		int num{ 0 };
		std::cout << "Enter last name: ";
		(*people)[i].setLastName(makeLineGood());
		std::cout << "Enter first name: ";
		(*people)[i].setFirstName(makeLineGood());
		std::cout << "Enter middle name: ";
		(*people)[i].setMiddleName(makeLineGood());
		std::cout << "Enter address: ";
		(*people)[i].setAddress(makeLineGood());
		std::cout << "Enter grade: ";
		(*people)[i].setGrade(checkInt());
		(*people)[i].setNumber(i + 1);
	}
	return newSize;
}

int showLimited(enrollee** people, int size) {
	bool exit = true;
	int newSize{ 0 };
	int counter{ 0 };
	int minGrade{ 0 };
	do{
		counter = 0;
		std::cout << "Enter the lowest grade: ";
		minGrade = checkInt();
		for (int i = 0; i < size; i++) {
			if((*people)[i].getGrade() >= minGrade) {
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
			if ((*people)[i].getGrade() >= minGrade) {
				(*people)[j].setAddress((*people)[i].getAddress());
				(*people)[j].setFirstName((*people)[i].getFirstName());
				(*people)[j].setLastName((*people)[i].getLastName());
				(*people)[j].setMiddleName((*people)[i].getMiddleName());
				(*people)[j].setGrade((*people)[i].getGrade());
				(*people)[j].setNumber((*people)[i].getNumber());
				j++;
			}
		}
		resizeArr(people, size, newSize);
	return newSize;
}

int topN(enrollee** people, int size) {
	int newSize{ 0 };
	std::cout << "Enter the number of enrollees with the highest grades: ";
	do {
		newSize = checkInt();
		if (newSize > size)
			std::cout << "ERR. Wrong input, try again" <<std::endl;
	} while (newSize > size);
	resizeArr(people, size, newSize);
	return newSize;
}

bool nameCmp(enrollee& a, enrollee& b) {
	return a.getFirstName() < b.getFirstName();
}

bool addressCmp(enrollee& a, enrollee& b) {
	return a.getAddress() < b.getAddress();
}

bool gradeCmp(enrollee& a, enrollee& b) {
	return a.getGrade() > b.getGrade();
}

void printAll(enrollee* people, int size) {
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
		people[i].setNumber(i + 1);
		people[i].showInfo();
	}
	std::cout << "==============================================================================================" << std::endl;
}


int quickSortInt_divide(enrollee* arr, int start, int end) {
	int pivot = arr[end].getGrade();
	int index = start;
	for (int i = start; i < end; i++) {
		if (arr[i].getGrade() > pivot) {
			enrollee temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
			index++;

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
		while (j < arr[i].getLastName().size()){
			if (arr[i].getLastName()[j] < pivot[j]) {
				enrollee temp = arr[i];
				arr[i] = arr[index];
				arr[index] = temp;
				index++;
				break;
			}
			else if(arr[i].getLastName()[j] == pivot[j]){
				j++;
				std::cout << "j = " << j <<" "<< arr[i].getLastName() << " -- " << pivot<< std::endl;
			}
			else {
				//std::cout << "fak off" <<  std::endl;
				break;
			}
		}
	}
	std::string temp = arr[end].getLastName();
	arr[end].setLastName(arr[index].getLastName());
	arr[index].setLastName(temp);
	return index;
}

void quickSortString(enrollee** arr, int start, int end) {
	if (start < end) {
		int d = quickSortString_divide(*arr, start, end);
		quickSortString(arr, start, (d - 1));
		quickSortString(arr, (d + 1), end);
	}
}


