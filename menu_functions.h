#ifndef __MENUFUNCTIONS_H_
#define __MENUFUNCTIONS_H_
#include <iostream>
#include <string>
#include "classes.h"
#include "header.h"
#include "functions.h"

enum FileChoice { test = 1, customFile, emptyStart, leaveFileMenu };
enum ActionChoice { add = 1, sortArray, moreThan, top, save, returnToMain, leaveEditMenu };

std::string openFileMenu();
bool editOptions(enrollee* people, int size);

#endif