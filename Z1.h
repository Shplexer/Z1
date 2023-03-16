#ifndef __HEADER_H_
#define __HEADER_H_
#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"
#include "functions.h"
#include "menu_functions.h"

#define INITFILENAME "nonexistentfile123ifyouactuallyusedthatnameforyourfilewowwhatiswrongwithyou"

enum fileName{change = 1, newFile, exitName};

void setList(enrollee* people, int size);
std::string openFile(std::string fileName);
void saveToFile(enrollee* people, int size, std::string saveFileName);
int calculateSize(std::string fileName);


#endif