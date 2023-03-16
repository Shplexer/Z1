#include "classes.h"

void enrollee::showInfo() {
	std::cout
		<< std::left
		<< std::setw(SSHRT) << number
		<< std::setw(SHRT) << "||"
		<< std::setw(MID) << getGoodLine(lastName)
		<< std::setw(MID) << getGoodLine(firstName)
		<< std::setw(LNG) << getGoodLine(middleName)
		<< std::setw(SHRT) << "||"
		<< std::setw(LNG) << getGoodLine(address)
		<< std::setw(SHRT) << "||"
		<< std::setw(SHRT) << grade
		<< std::right << std::setw(SHRT) << "||" << std::endl;
}

std::string enrollee::getGoodLine(std::string input) {
	std::string temp = input;
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] == '_') {
			temp[i] = ' ';
		}
	}
	return temp;
}