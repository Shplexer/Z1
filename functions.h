#ifndef __FUNCTIONS_H_
#define __FUNCTIONS_H_
#include <iostream>
#include <string>
#include <algorithm>
#include "classes.h"
#define SHRT 5
#define LNG 15
#define MID 10

enum SortChoice { byName = 1, byCity, byGrade };

void sortEnrollee(enrollee* people, int size);
int showLimited(enrollee** people, int size);
int topN(enrollee** people, int size);
bool nameCmp(enrollee& a, enrollee& b);
bool cityCmp(enrollee& a, enrollee& b);
bool gradeCmp(enrollee& a, enrollee& b);
void printAll(enrollee* people, int size);

#endif