// Gomoku.h
// Seunghan Bae (seunghan.bae@wustl.edu)
// (Lab 4) header file for the Gomoku class
//

#ifndef GOMOKU_H
#define GOMOKU_H

#include "GameBase.h"

#define GMK_DIM 19
#define GMK_CONNECT 5

enum direction { E, NE, N, NW, W, SW, S, SE };

class Gomoku : public GameBase
{
	friend std::ostream & operator<<(std::ostream &, const Gomoku &);
public:
	Gomoku();
	Gomoku(const Gomoku &);
	Gomoku(Gomoku &&);
	~Gomoku();

	Gomoku & operator=(const Gomoku &);
	Gomoku & operator=(Gomoku &&);

	virtual void print();
	virtual bool done();
	unsigned int doneCheck(unsigned int, unsigned int, int &);
	virtual bool draw();
	virtual int turn();
	void save();
private:
	unsigned int connect_;
};

std::ostream & operator<<(std::ostream &, const Gomoku &);

#endif /* GOMOKU_H */
