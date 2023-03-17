#ifndef __Z1_H_
#define __Z1_H_
#include <fstream>
#include <tuple>
#include "classes.h"
#include "functions.h"
#include "menu_functions.h"

enum fileName{change = 1, newFile, exitName};
enum saveFileName { changeFile = 1, thisFile};

void setList(enrollee* people, int size, std::string fileName);
std::string openFile(std::string fileName);
void saveToFile(enrollee* people, int size, std::string saveFileName);
int calculateSize(std::string fileName);


#endif