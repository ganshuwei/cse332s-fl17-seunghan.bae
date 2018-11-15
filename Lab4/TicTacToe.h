// TicTacToe.h
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 4) header file for the TicTacToe class
//

#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include "GameBase.h"

#define TTT_DIM 5

class TicTacToe : public GameBase
{
	friend std::ostream & operator<<(std::ostream &, const TicTacToe &);
public:
	TicTacToe();
	TicTacToe(const TicTacToe &);
	TicTacToe(TicTacToe &&);
	~TicTacToe();

	TicTacToe & operator=(const TicTacToe &);
	TicTacToe & operator=(TicTacToe &&);

	virtual void print();
	virtual bool done();
	virtual bool draw();
	virtual int turn();
	void save();
};

std::ostream & operator<<(std::ostream &, const TicTacToe &);

#endif /* TIC_TAC_TOE_H */
