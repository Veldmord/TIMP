#pragma once
#ifndef STACK_INCLUDED
#define STACK_INCLUDED
/*
\file
\brief заголовочный файл, реализующий структуру данных стек
\warning данная структура реализована исключительно в учебных целях
*/
template <class T>
class Stack
{
	const size_t size;
	size_t cur_size;
	T *arr;
public:
	Stack(size_t n = 100)
		: size(n), cur_size(0), arr(new T[size])
	{
	}
	/*
	\brief проверяет стек на пустоту
	\return bool-значение, показывающее, пустой ли стек
	*/
	bool empty() const
	{
		return cur_size == 0;
	}
	/*
	\brief проверяет стек на заполенность
	\return bool-значение, показывающее, полный ли стек
	*/
	bool full() const
	{
		return cur_size == size;
	}
	/*
	\brief добавляет значение на вершину стека
	\param val значение, которое нужно добавить
	Функция выполняется только если стек не полный. Также увеличивается текущий размер стека
	*/
	void push(T val)
	{
		if (!full())
			arr[cur_size++] = val;
	}
	/*
	\brief удаляет значение из вершины стека
	Функция выполняется только если стек не пустой. Также уменьшается текущий размер стека
	*/
	void pop() 
	{
		if (!empty())
			arr[--cur_size] = 0;
	}
	/*
	\brief возвращает вершину стека
	\return значение, находящееся в вершине стека
	Функция выполняется только если стек не пустой.
	*/
	T top() const
	{
		if (!empty())
			return arr[cur_size - 1];
		else
			throw std::runtime_error("stack is empty");
	}
	~Stack()
	{
		delete[] arr;
	}
};


#endif  //STACK_INCLUDED
