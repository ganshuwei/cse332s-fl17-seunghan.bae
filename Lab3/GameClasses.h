// GameClasses.h
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 3) header file for game classess
//

#ifndef GAME_CLASSES_H
#define GAME_CLASSES_H

#include "Lab3.h"
#include "GamePieces.h"
#include <iostream>
#include <vector>

#define TTT_DIM 5
#define GMK_DIM 19
#define GMK_CONNECT 5

enum direction {E, NE, N, NW, W, SW, S, SE};

class GameBase
{
public:
	GameBase(unsigned int, unsigned int);

	virtual void print() = 0;
	virtual bool done() = 0;
	virtual bool draw() = 0;
	virtual void prompt(unsigned int &, unsigned int &);
	virtual int turn() = 0;
	int play();
	static GameBase * start(int, char *[]);
protected:
	const unsigned int width_; // width of the board
	const unsigned int height_; // height of the board
	const unsigned int pieceCount_; // number of game_pieces in the board
	std::vector<game_pieces> gpVtr_; // vector of game_pieces
	bool turn_; // true = Player O/White Stone's turn, false = Player X/Black Stone's turn
	unsigned int displayLength_; // maximum length of display string
};

class TicTacToe : public GameBase
{
	friend std::ostream & operator<<(std::ostream &, const TicTacToe &);
public:
	TicTacToe();

	virtual void print();
	virtual bool done();
	virtual bool draw();
	virtual int turn();
};

class Gomoku : public GameBase
{
	friend std::ostream & operator<<(std::ostream &, const Gomoku &);
public:
	Gomoku();
	Gomoku(unsigned int, unsigned int);

	virtual void print();
	virtual bool done();
	unsigned int doneCheck(unsigned int, unsigned int, int &);
	virtual bool draw();
	virtual int turn();
private:
	const unsigned int connect_;
};

std::ostream & operator<<(std::ostream &, const TicTacToe &);
std::ostream & operator<<(std::ostream &, const Gomoku &);

#endif /* GAME_CLASSES_H */
