#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "IPriorityQueue.h"

template<typename T>
class PriorityQueue : public IPriorityQueue<T>
{
private:
	T* _queue;
	int _capacity;
	int _nrOfElements;
	void expand();
	T findFront() const;
public:
	PriorityQueue(int capacity = 10);
	virtual~PriorityQueue();
	virtual void enqueue(const T& element);
	virtual T dequeue() throw(...);
	virtual T front() const throw(...);
	virtual bool isEmpty() const;
};
#endif PRIORITYQUEUE_H

template<typename T>
void PriorityQueue<T>::expand()
{
	_capacity += 10;
	T* temp = new T[_capacity];
	for (int i = 0; i < _nrOfElements; i++)
	{
		temp[i] = _queue[i];
	}
	delete[] _queue;
	_queue = temp;
}

template<typename T>
T PriorityQueue<T>::findFront() const
{
	T prio = _queue[0];
	for (int i = 1; i < _nrOfElements; i++)
	{
		if (_queue[i] > prio)
			prio = _queue[i];
	}
	return prio;
}

template<typename T>
PriorityQueue<T>::PriorityQueue(int capacity)
{
	_capacity = capacity;
	_nrOfElements = 0;
	_queue = new T[_capacity];
}

template<typename T>
PriorityQueue<T>::~PriorityQueue()
{
	delete[] _queue;
}

template<typename T>
void PriorityQueue<T>::enqueue(const T& element)
{
	if (_nrOfElements == _capacity)
		expand();
	_queue[_nrOfElements++] = element;
}

template<typename T>
T PriorityQueue<T>::dequeue() throw(...)
{
	if (_nrOfElements == 0)
		throw "No elements in queue";
	return findFront();
}

template<typename T>
T PriorityQueue<T>::front() const throw(...)
{
	if (_nrOfElements == 0)
		throw "No elements in queue";
	return findFront();
}

template<typename T>
bool PriorityQueue<T>::isEmpty() const
{
	return _nrOfElements == 0;
}

