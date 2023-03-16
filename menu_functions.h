#ifndef __MENUFUNCTIONS_H_
#define __MENUFUNCTIONS_H_
#include <iostream>
#include <string>
#include "classes.h"
#include "Z1.h"
#include "functions.h"
#include "tester.h"

enum FileChoice { test = 1, customFile, emptyStart, leaveFileMenu };
enum ActionChoice { add = 1, sortArray, moreThan, top, save, returnToMain, leaveEditMenu };

std::string openFileMenu(std::string fileName);
bool editOptions(enrollee* source, int srcSize, std::string fileName);

#endif