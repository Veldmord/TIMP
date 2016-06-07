#pragma once
#include <iostream>
class Base {
public:
	virtual void show() const = 0;
	Base(int val)
		: value(val)
	{
	}
protected:
	int value;
};

class A : public Base {
public:
	A(int val)
		: Base(val)
	{
	}
	void show() const
	{
		std::cout << "class A: " << value << std::endl;
	}
};
class B : public Base {
public:
	B(int val)
		: Base(val)
	{
	}
	void show() const
	{
		std::cout << "class B: " << value << std::endl;
	}
};
class C : public Base {
public:
	C(int val)
		: Base(val)
	{
	}
	void show() const
	{
		std::cout << "class C: " << value << std::endl;
	}
};
