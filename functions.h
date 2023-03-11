#ifndef __FUNCTIONS_H_
#define __FUNCTIONS_H_
#include <iostream>
#include <string>
#include <algorithm>
#include "classes.h"

#define TESTSIZE 5

enum SortChoice { byName = 1, byGrade };

void testFunction();
std::string fileNameCheck(std::string inputName);
std::string makeLineGood();						//—тавит "_" вместо пробелов, чтобы можно было вводить имена/адреса из несколько слов
std::string getGoodLine(std::string input);			//¬озвращает переменную, провер€€ на наличие "_" и убирает их, если найдет
int checkInt();
int addToArray(enrollee** people, int size);
int showLimited(enrollee** people, int size);
int topN(enrollee** people, int size);
bool nameCmp(enrollee& a, enrollee& b);
bool addressCmp(enrollee& a, enrollee& b);
bool gradeCmp(enrollee& a, enrollee& b);
void sortEnrollee(enrollee* people, int size);
void printAll(enrollee* people, int size);
void resizeArr(enrollee** oldArr, int oldSize, int newSize);
void quickSortInt(enrollee* arr, int start, int end);
int quickSortInt_divide(enrollee* arr, int start, int end);
void quickSortString(enrollee** arr, int start, int end);
int quickSortString_divide(enrollee* arr, int start, int end);
#endif