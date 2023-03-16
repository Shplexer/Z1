#ifndef __FUNCTIONS_H_
#define __FUNCTIONS_H_
#include <iostream>
#include <string>
#include <algorithm>
#include "classes.h"

#define D 0x44
#define TESTMINGRADE 1
#define TESTTOPN 2

enum SortChoice { byName = 1, byGrade };

std::string fileNameCheck(std::string inputName);
std::string makeLineGood();							//—тавит "_" вместо пробелов, чтобы можно было вводить имена/адреса из несколько слов
std::string getGoodLine(std::string input);			//¬озвращает переменную, провер€€ на наличие "_" и убирает их, если найдет
int checkInt();
int addToArray(enrollee** arr, int size, bool test);
int showLimited(enrollee** arr, int size, bool test);
int topN(enrollee** arr, int size, bool test);
void sortEnrollee(enrollee* arr, int size);
void printAll(enrollee* arr, int size);
void resizeArr(enrollee** oldArr, int oldSize, int newSize);
void quickSortInt(enrollee* arr, int start, int end);
int quickSortInt_divide(enrollee* arr, int start, int end);
void quickSortString(enrollee* arr, int start, int end);
int quickSortString_divide(enrollee* arr, int start, int end);
#endif