#ifndef DETECTOR_H
#define DETECTOR_H

class detector {
public:
	detector();
	detector(const detector &);
	~detector();

	unsigned int x() const;
	static unsigned int y_;
private:
	unsigned int x_;
};

class wrapper {
public:
	wrapper();
	wrapper(const wrapper &);
	wrapper(wrapper &&);
	~wrapper();

	wrapper & operator=(const wrapper &);
	wrapper & operator=(wrapper &&);
private:
	detector * d_;
};

#endif /* DETECTOR_H */
