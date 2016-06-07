#include <stdexcept>
#include "Interface.h"

template <class T = int>
class Queue : public IQ<T>
{
	bool isFull;
	const size_t size;
	size_t top_, bottom;
	T *arr;
public:
	Queue(size_t n = 100)
		: isFull(false), size(n), top_(0), bottom(0), arr(new T[size])
	{
	}
	/*
	\brief проверяет очередь на пустоту
	\return bool-значение, показывающее, пустая ли очередь
	*/
	bool empty()
	{
		return top_ == bottom && !isFull;
	}
	/*
	\brief добавляет значение в конец очереди
	\param val значение, которое нужно добавить
	Функция выполняется только если очередь не полная
	*/
	void push(const T &val) {
		if (isFull)
			return;
		arr[bottom] = val;
		bottom = (bottom + 1) % size;
		if (top_ == bottom)
			isFull = true;
	}
	/*
	\brief удаляет значение из начала очереди
	Функция выполняется только если очередь не пустая. Сбрасывает флаг того, что очередь полная
	*/
	void pop() {
		if (empty())
			return;
		isFull = false;
		top_ = (top_ + 1) % size;
	}
	/*
	\brief возвращает начало очереди
	\return значение, находящееся в начале очереди
	Функция выполняется только если очередь не пустая.
	*/
	T &top() {
		if (!empty())
			return arr[top_];
		else
			throw std::out_of_range("queue is empty");
	}

	~Queue() {
		delete[] arr;
	}
};


extern "C"
{
	__declspec(dllexport) IQ<> *GetSomeIQ()
	{
		return new Queue<>();
	}
}
