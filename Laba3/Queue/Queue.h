#pragma once
#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
/*
\file
\brief заголовочный файл, реализующий структуру данных очередь
\warning данная структура реализована исключительно в учебных целях
*/
template <class T>
class Queue
{
	mutable bool isFull;
	const size_t size;
	size_t top, bottom;
	T *arr;
public:
	Queue(size_t n = 100)
		: isFull(false), size(n), top(0), bottom(0), arr(new T[size])
	{
	}
	/*
	\brief проверяет очередь на пустоту
	\return bool-значение, показывающее, пустая ли очередь
	*/
	bool empty() const
	{
		return top == bottom && !isFull;
	}
	/*
	\brief добавляет значение в конец очереди
	\param val значение, которое нужно добавить
	Функция выполняется только если очередь не полная
	*/
	void push(T val) {
		if (isFull)
			return;
		arr[bottom] = val;
		bottom = (bottom + 1) % size;
		if (top == bottom)
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
		top = (top + 1) % size;
	}
	/*
	\brief возвращает начало очереди
	\return значение, находящееся в начале очереди
	Функция выполняется только если очередь не пустая.
	*/
	T front() const {
		if (!empty())
			return arr[top];
		else 
			throw std::runtime_error("queue is empty");
	}
	~Queue() {
		delete[] arr;
	}
};


#endif // QUEUE_H_INCLUDED
