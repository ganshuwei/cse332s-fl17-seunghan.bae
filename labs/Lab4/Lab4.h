// Lab4.h
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 4) main application header file
//

#ifndef LAB4_H
#define LAB4_H

enum array_index { PROGRAM, GAME, BOARD_DIM, CONNECT };
#define EXPECTED_ARG_NUM 2

enum errors { SUCCESS, WRONG_ARG_NUM, WRONG_GAME_NAME, USER_QUIT, GAME_ENDED_DRAW, NULL_PTR_EXCEPTION, PTR_NOT_NULL, BAD_ALLOC, CANNOT_OPEN_FILE };

int usageMsg(char *, char *, int);

#endif /* LAB4_H */
