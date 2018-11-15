// Lab3.h
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 3) main application header file
//

#ifndef LAB3_H
#define LAB3_H

enum array_index { PROGRAM, GAME, BOARD_DIM, CONNECT };
#define EXPECTED_ARG_NUM 2
#define ONE_MORE_ARG 3
#define TWO_MORE_ARG 4

enum errors { SUCCESS, WRONG_ARGUMENT, USER_QUIT, GAME_ENDED_DRAW };

int usageMsg(char *, char *, char *, char *);

#endif /* LAB3_H */
