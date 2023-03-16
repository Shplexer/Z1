#include "tester.h"

void testFunc() {
	int size = TESTSIZE;
	int controlSize = CONTROLSIZE;
	enrollee* testArr = new enrollee[size];
	enrollee* controlArr = new enrollee[controlSize];

	//testing adding function
	createTestArray(testArr, size, testType::add);
	createTestArray(controlArr, controlSize, testType::add);
	size = addToArray(&testArr, size, true);
	std::cout << "ADDING FUNCTION: ";
	compareArrays(testArr, controlArr, size, controlSize);

	//testing sorting function (by grade)
	createTestArray(controlArr, controlSize, testType::sortByNum);
	quickSortInt(testArr, 0, (size-1));
	std::cout << "SORTING FUNCTION (BY GRADE): ";
	compareArrays(testArr, controlArr, size, controlSize);
	
	//testing sorting function (by last name)
	createTestArray(controlArr, controlSize, testType::sortByString);
	quickSortString(testArr, 0, (size - 1));
	std::cout << "SORTING FUNCTION (BY LAST NAME): ";
	compareArrays(testArr, controlArr, size, controlSize);

	//testing limiting by grade function
	delete[] controlArr;
	controlSize--;
	controlArr = new enrollee[controlSize];
	createTestArray(controlArr, controlSize, testType::showLimited);
	size = showLimited(&testArr, size, true);
	std::cout << "SHOWING WITH GRADES >= N FUNCTION: ";
	compareArrays(testArr, controlArr, size, controlSize);

	//testing top array members function
	delete[] controlArr;
	delete[] testArr;
	controlSize = CONTROLSIZE_2;
	size = TESTSIZE;
	controlArr = new enrollee[controlSize];
	testArr = new enrollee[size];
	createTestArray(controlArr, controlSize, testType::topN);
	createTestArray(testArr, size, testType::def);
	size = topN(&testArr, size, true);
	std::cout << "SHOWING TOP N ENROLLEES FUNCTION: ";
	compareArrays(testArr, controlArr, size, controlSize);

	//printAll(testArr, size);
	//printAll(controlArr, controlSize);
	std::cout << std::endl << "\033[36m" << "Wow, the code is actually correct... I... I'm not sure what to say... Congratulations, I guess..." << std::endl<<"Now going back to main menu." << "\033[0m" << std::endl << std::endl;
	delete[] controlArr;
	delete[] testArr;
	controlArr = nullptr;
	testArr = nullptr;
}

void createTestArray(enrollee* arr, int size, testType typeOfTest) {
	switch (typeOfTest)
	{
	case testType::add:
		for (int i = 0; i < size; i++) {
			char ch = A + i;
			std::string s{ ch };
			arr[i].setAddress(s);
			arr[i].setFirstName(s);
			arr[i].setMiddleName(s);
			arr[i].setLastName(s);
			arr[i].setGrade(i);
		}
		break;
	case testType::sortByNum:
		for (int i = 0, j = size - 1; i < size; i++, j--) {
			char ch = A + j;
			std::string s{ ch };
			arr[i].setAddress(s);
			arr[i].setFirstName(s);
			arr[i].setMiddleName(s);
			arr[i].setLastName(s);
			arr[i].setGrade(j);
		}
		break;
	case testType::sortByString:
		for (int i = 0; i < size; i++) {
			char ch = A + i;
			std::string s{ ch };
			arr[i].setAddress(s);
			arr[i].setFirstName(s);
			arr[i].setMiddleName(s);
			arr[i].setLastName(s);
			arr[i].setGrade(i);
		}
		break;
	case testType::showLimited:
		for (int i = 0, j = 1; i < size; i++, j++) {
			char ch = A + j;
			std::string s{ ch };
			arr[i].setAddress(s);
			arr[i].setFirstName(s);
			arr[i].setMiddleName(s);
			arr[i].setLastName(s);
			arr[i].setGrade(j);
		}
		break;
	case testType::topN:
		for (int i = size - 1, j = 1; i >= 0; i--, j++) {
			char ch = A + j;
			std::string s{ ch };
			arr[i].setAddress(s);
			arr[i].setFirstName(s);
			arr[i].setMiddleName(s);
			arr[i].setLastName(s);
			arr[i].setGrade(j);
		}
		break;
	case testType::def:
		for (int i = 0; i < size; i++) {
			char ch = A + i;
			std::string s{ ch };
			arr[i].setAddress(s);
			arr[i].setFirstName(s);
			arr[i].setMiddleName(s);
			arr[i].setLastName(s);
			arr[i].setGrade(i);
		}
		break;
	}
}

void compareArrays(enrollee* testArr, enrollee* controlArr, int size, int controlSize) {
	for (int i = 0; i < size; i++) {
		if (size == controlSize &&
			testArr[i].getAddress() == controlArr[i].getAddress() &&
			testArr[i].getFirstName() == controlArr[i].getFirstName() &&
			testArr[i].getMiddleName() == controlArr[i].getMiddleName() &&
			testArr[i].getLastName() == controlArr[i].getLastName() &&
			testArr[i].getGrade() == controlArr[i].getGrade()) {
			if(i == size - 1)
				std::cout << "\033[36m" << "GOOD" << "\033[0m" <<  std::endl;
		}
		else {
			std::cout << "\033[31m" << "BAD" << "\033[0m" << std::endl;
			std::cout << "Input array: " << std::endl;
			printAll(testArr, size);
			std::cout << "Control array: " << std::endl;
			printAll(controlArr, controlSize);
			break;
		}
	}
}
