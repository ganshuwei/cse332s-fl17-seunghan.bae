#ifndef DETECTOR_H
#define DETECTOR_H

class detector {
public:
	detector();
	detector(const detector &);
	~detector();

	unsigned int x() const;
private:
	unsigned int x_;
	static unsigned int y_;
};

class wrapper {
public:
	wrapper();
	wrapper(const wrapper &);
	~wrapper();
private:
	detector * d_;
	bool b_;
};

#endif /* DETECTOR_H */
