#ifndef CLASSES_H
#define CLASSES_H

class A {
public:
	A();
	virtual ~A();
	
	virtual void func();
};

class B : public A {
public:
	B();
	virtual ~B();

	virtual void func();
};

#endif /* CLASSES_H */
