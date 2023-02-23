#ifndef __MENUFUNCTIONS_H_
#define __MENUFUNCTIONS_H_
#include <iostream>
#include <string>
#include "classes.h"
#include "header.h"
#include "functions.h"

enum FileChoice { templateFile = 1, customFile, leaveFileMenu };
enum ActionChoice { add = 1, sortArray, moreThan, top, returnToSrc, save, returnToMain, leaveEditMenu };

int openFileMenu(void);
bool editOptions(enrollee* people, int size);

#endif