#ifndef __HEADER_H_
#define __HEADER_H_
#include <iostream>
#include <fstream>
#include <string>

#include "classes.h"
#include "functions.h"
#include "menu_functions.h"

void setList(enrollee* people, int size);
void openFile(std::string fileName);
int calculateSize(std::string fileName);
void saveToFile(enrollee* people, int size);


#endif