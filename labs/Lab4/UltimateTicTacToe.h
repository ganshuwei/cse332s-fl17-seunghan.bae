// UltimateTicTacToe.h
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 4) header file for the UltimateTicTacToe class
//

#ifndef ULTIMATE_TIC_TAC_TOE_H
#define ULTIMATE_TIC_TAC_TOE_H

#include "GameBase.h"
#include <string>

#define UTTT_DIM 11

class UltimateTicTacToe : public GameBase
{
	friend std::ostream & operator<<(std::ostream &, const UltimateTicTacToe &);
public:
	UltimateTicTacToe();
	UltimateTicTacToe(const UltimateTicTacToe &);
	UltimateTicTacToe(UltimateTicTacToe &&);
	~UltimateTicTacToe();

	UltimateTicTacToe & operator=(const UltimateTicTacToe &);
	UltimateTicTacToe & operator=(UltimateTicTacToe &&);

	virtual void print();
	virtual bool done();
	void subDone();
	virtual bool draw();
	virtual int turn();
	void save();
private:
	std::vector<std::string> uVtr_; // stores the winner of each sub-TicTacToe game
};

std::ostream & operator<<(std::ostream &, const UltimateTicTacToe &);

#endif /* ULTIMATE_TIC_TAC_TOE_H */
