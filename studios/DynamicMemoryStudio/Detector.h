#ifndef DETECTOR_H
#define DETECTOR_H

class detector {
public:
	detector();
	~detector();

	unsigned int x() const;
private:
	unsigned int x_;
	static unsigned int y_;
};

#endif /* DETECTOR_H */
