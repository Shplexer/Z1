#ifndef __CLASSES_H_
#define __CLASSES_H_
#include <iostream>
#include <iomanip>
#define SHRT 5
#define LNG 15
#define MID 10
class enrollee {
private:
	std::string firstName{ "--" };
	std::string lastName{ "--" };
	std::string middleName{ "--" };
	std::string address{ "--" };
	int grade{ 0 };
	int number{ 0 };
public:
	void setFirstName(std::string input) {
		firstName = input;
	}
	void setLastName(std::string input) {
		lastName = input;
	}
	void setMiddleName(std::string input) {
		middleName = input;
	}
	void setAddress(std::string input) {
		address = input;
	}
	void setGrade(int input) {
		grade = input;
	}
	void setNumber(int input) {
		number = input;
	}
	//Консольный ввод всех данных
	void setAllInfo() {
		std::string input = "--";
		std::cout << "Введите имя: ";
		std::cin >> input;
		setFirstName(input);
		std::cout << "Введите фамилию: ";
		std::cin >> input;
		setLastName(input);
		std::cout << "Введите отчество: ";
		std::cin >> input;
		setMiddleName(input);
		std::cout << "Введите адрес: ";
		std::cin >> input;
		setAddress(input);
		std::cout << "Введите оценку: ";
		int num{ 0 };
		std::cin >> num;
		setGrade(num);
	}
	//get 
	std::string getFirstName() {
		return firstName;
	}
	std::string getLastName() {
		return lastName;
	}
	std::string getMiddleName() {
		return middleName;
	}
	std::string getAddress() {
		return address;
	}
	int getGrade() {
		return grade;
	}
	int getNumber() {
		return number;
	}
	//show
	void showInfo() {
		std::string temp = lastName;
		std::cout
			<< std::left
			<< std::setw(SHRT) << number
			<< std::setw(MID) << lastName
			<< std::setw(MID) << firstName
			<< std::setw(LNG) << middleName
			<< std::setw(SHRT) << "||"
			<< std::setw(LNG) << address
			<< std::setw(SHRT) << "||"
			<< std::setw(SHRT) << grade
			<< std::right << std::setw(SHRT + 1) << "||"<<std::endl;
	}
	
};
#endif
