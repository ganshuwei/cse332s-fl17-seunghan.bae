// Sudoku.h
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 4) header file for the Sudoku class
//

#ifndef SUDOKU_H
#define SUDOKU_H

#include "GameBase.h"

#define SDK_DIM 9

class Sudoku : public GameBase
{
	friend std::ostream & operator<<(std::ostream &, const Sudoku &);
public:
	Sudoku();
	Sudoku(const Sudoku &);
	Sudoku(Sudoku &&);
	~Sudoku();

	Sudoku & operator=(const Sudoku &);
	Sudoku & operator=(Sudoku &&);
	
	void loadSudoku0();
	virtual void print();
	virtual bool done();
	virtual bool draw();
	virtual void prompt(unsigned int &, unsigned int &, unsigned int &);
	virtual int turn();
	void save();
};

std::ostream & operator<<(std::ostream &, const Sudoku &);

#endif /* SUDOKU_H */
