// Lab0.h
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 0) main application header file: definition of enums and functions used in Lab0.cpp
//

#ifndef LAB0_H
#define LAB0_H

#include <string>
#include <vector>

using namespace std;

enum Array_Index {PROGRAM, INPUT_FILE};
#define EXPECTED_ARG_NUM 2

enum Errors {SUCCESS, WRONG_ARG_NUM, CANNOT_OPEN_FILE, FILE_IS_EMPTY};

int parseInput(vector<string> &, char *);

int usageMsg(char *);

#endif /* LAB0_H */
