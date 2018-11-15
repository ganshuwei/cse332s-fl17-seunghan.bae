// TicTacToe.h
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 2) header file for TicTacToeGame class
//

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include "Lab2.h"
#include "GamePieces.h"
#include <iostream>
#include <vector>

#define X_BEG 1
#define X_END 3
#define Y_BEG 1
#define Y_END 3

class TicTacToeGame
{
	friend std::ostream & operator<<(std::ostream &, const TicTacToeGame &);
public:
	TicTacToeGame();
	TicTacToeGame(const TicTacToeGame &);
	TicTacToeGame(bool autoP);

	bool done();
	bool draw();
	int prompt(unsigned int &, unsigned int &);
	int turn();
	int play();
	unsigned int auto_player();

private:
	unsigned int width_;
	unsigned int height_;
	std::vector<game_pieces> gpVtr_;
	bool oTurn_; // true = Player O's turn, false = Player X's turn
	bool autoP_; // true = auto_player enabled, false = auto_player disabled (extra credit)
};

std::ostream & operator<<(std::ostream &, const TicTacToeGame &);

#endif /* TIC_TAC_TOE_H */
