#ifndef CLASSES_STUDIO_H
#define CLASSES_STUDIO_H

class TwoInts {
public:
	TwoInts();
	TwoInts(const TwoInts &);
	TwoInts(int x, int y);

	int x() const;
	int y() const;

	TwoInts & x(int);
	TwoInts & y(int);

private:
	int x_;
	int y_;
};

#endif /* CLASSES_STUDIO_H */
