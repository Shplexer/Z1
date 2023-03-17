#ifndef __TESTER_H_
#define __TESTER_H_

#include "functions.h"
#include "classes.h"

#define A 0x41
#define TESTSIZE 3
#define CONTROLSIZE 4
#define CONTROLSIZE_2 2

enum class testType { add = 1, sortByNum, sortByString, showLimited, topN, def};

void testFunc();
void createTestArray(enrollee* arr, int size, testType typeOfTest);
void compareArrays(enrollee* testArr, enrollee* controlArr, int size, int controlSize);
#endif
