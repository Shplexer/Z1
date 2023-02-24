#ifndef __CLASSES_H_
#define __CLASSES_H_
#include <iostream>
#include <iomanip>

#define SSHRT 3
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
	std::string getGoodLine(std::string input) {
		std::string temp = input;
		for (int i = 0; i < temp.size(); i++) {
			if (temp[i] == '_') {
				temp[i] = ' ';
			}
		}
		return temp;
	}
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
			<< std::setw(SHRT) << "||"
			<< std::setw(MID) << getGoodLine(lastName)
			<< std::setw(MID) << getGoodLine(firstName)
			<< std::setw(LNG) << getGoodLine(middleName)
			<< std::setw(SHRT) << "||"
			<< std::setw(LNG) << getGoodLine(address)
			<< std::setw(SHRT) << "||"
			<< std::setw(SHRT) << grade
			<< std::right << std::setw(SHRT) << "||"<<std::endl;
	}
	
};

#endif
