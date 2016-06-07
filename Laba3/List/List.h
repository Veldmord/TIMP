#pragma once
#ifndef LIST_H
#define LIST_H

template<class T>
struct Node
{
	T _data;
	Node* _next;
	Node(T data) : _data(data), _next(nullptr)
	{}
	Node(T data, Node* next) : _data(data), _next(next)
	{}
};

template<class T>
class List
{
	typedef Node<T> _Node;
	_Node* _head;
	size_t size;
public:
	List() : _head(nullptr), size(0)
	{
	}
	
	void AddNth(T data, size_t n)
	{
		if (n == 0) {
			_head = new _Node(data, _head);
			size++;
			return;
		}
		size_t i = 0;
		_Node *t = _head;
		while (i != (n - 1))
		{
			t = t->_next;
			i++;
		}
		t->_next = new _Node(data, t->_next);
		size++;
	}
	
	T GetNth(size_t n) const
	{
		if (n < 0 || n >= size)
			throw std::out_of_range("invalid index");
		size_t i = 0;
		_Node *t = _head;
		while (i != n)
		{
			t = t->_next;
			i++;
		}
		return t->_data;
	}
	
	void DeleteNth(size_t n)
	{
		if (size == 0)
			throw std::runtime_error("list is empty");
		if (n == 0)
		{
			_Node *t = _head;
			_head = t->_next;
			delete t;
			size--;
			return;
		}
		size_t i = 0;
		_Node* t = _head;
		while (i != (n - 1))
		{
			t = t->_next;
			i++;
		}
		_Node *t1 = t->_next;
		t->_next = t1->_next;
		delete t1;
		size--;
	}
	~List()
	{
		if (size == 0) return;
		while (_head)
		{
			_Node * t = _head;
			_head = _head->_next;
			delete t;
		}
	}
};

#endif // LIST_H
