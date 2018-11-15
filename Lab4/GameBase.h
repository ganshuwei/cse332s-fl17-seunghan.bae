// GameBase.h
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 4) header file for the GameBase class
//

#ifndef GAME_BASE_H
#define GAME_BASE_H

#include "Lab4.h"
#include "GamePieces.h"
#include <iostream>
#include <vector>
#include <memory>

class GameBase
{
public:
	GameBase(unsigned int, unsigned int);
	GameBase(const GameBase &);
	GameBase(GameBase &&);
	// ~GameBase();

	// GameBase & operator=(const GameBase &);
	// GameBase & operator=(GameBase &&);

	virtual void print() = 0;
	virtual bool done() = 0;
	virtual bool draw() = 0;
	virtual void prompt(unsigned int &, unsigned int &);
	virtual int turn() = 0;
	int play();
	static void start(int, char *[]);
	static std::shared_ptr<GameBase> instance();
protected:
	unsigned int width_; // width of the board
	unsigned int height_; // height of the board
	unsigned int pieceCount_; // number of game_pieces in the board
	std::vector<game_pieces> gpVtr_; // vector of game_pieces
	bool turn_; // true = Player O/White Stone's turn, false = Player X/Black Stone's turn
	unsigned int turnCount_;
	unsigned int displayLength_; // maximum length of display string
	static std::shared_ptr<GameBase> sharedPtr_;
};

#endif /* GAME_BASE_H */
