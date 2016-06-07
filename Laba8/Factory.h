#pragma once
template <class Base, class... Args>
class AbstractCreator
{
public:
	virtual Base* create(Args&... args) const = 0;
};

template <class C, class Base, class... Args>
class Creator : public AbstractCreator<Base, Args...>
{
public:
	Base * create(Args&... args) const override
	{
		return new C(args...);
	}
};
