// Lab2.h
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 2) main application header file
//

#ifndef LAB2_H
#define LAB2_H

enum array_index { PROGRAM, GAME };
#define EXPECTED_ARG_NUM 2
#define EXTRA_ARG_NUM 3

enum errors { SUCCESS, WRONG_ARGUMENT, USER_QUIT, GAME_ENDED_DRAW };

int usageMsg(char *, char *, char *);

#endif /* LAB2_H */
