// Lab1.h
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 1) main application header file: definitions of enums, functions, and (classes/structs) used in Lab1.cpp
//

#ifndef LAB1_H
#define LAB1_H

#include <string>

enum array_index { PROGRAM, INPUT_FILE };
#define EXPECTED_ARG_NUM 2

enum errors { SUCCESS, WRONG_ARG_NUM, CANNOT_OPEN_FILE, CANNOT_READ_LINE, CANNOT_EXTRACT_DIM, NO_PIECE_DEF, VECTOR_DIM_MISMATCH };

void toLowerCase(std::string &);

int usageMsg(char *, char *);

#endif /* LAB1_H */
