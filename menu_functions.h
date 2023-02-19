#ifndef __MENUFUNCTIONS_H_
#define __MENUFUNCTIONS_H_
#include <iostream>
#include <string>
#include <tuple>
#include "classes.h"
#include "header.h"
#include "functions.h"


#define TEMPLATE_SIZE 10

enum FileChoice { templateFile = 1, customFile, leaveFile };
enum ActionChoice { sortArray = 1, moreThan, top, returnToSrc, leaveEditMenu };

std::tuple < std::string, int > openFileMenu(void);
void editOptions(enrollee* people, int size);

#endif