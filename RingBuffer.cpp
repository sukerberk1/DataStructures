#include "RingBuffer.h"
#include <iostream>

// My implementation assumps a single array index would remain empty

template <typename T>
RingBuffer<T>::RingBuffer() : headIndex(0), tailIndex(1)
{
	int cap = 8;
	arr = new T[cap];
	capacity = cap;
	size = 0;
}

template <typename T>
RingBuffer<T>::RingBuffer(int initialCapacity) : headIndex(0), tailIndex(0)
{
	arr = new T[initialCapacity];
	capacity = initialCapacity;
	size = 0;
}

template <typename T>
void RingBuffer<T>::Enlarge()
{
	std::cout << "Enlarging the internal array\n";
	int newCapacity = capacity * 2;
	T* newArr = new T[newCapacity];

	int i = headIndex;
	int j = 0;
	while (i != tailIndex)
	{
		newArr[j] = arr[i];
		if (i == capacity+1)
			i = 0;
		else
			i++;
		j++;
	}

	arr = newArr;

	capacity = newCapacity;
}

template <typename T>
void RingBuffer<T>::Push(T element)
{
	if (size == 0)
	{
		arr[0] = element;
		tailIndex = 1;
		size++;
		return;
	}
	else if (size == capacity)
	{
		Enlarge();
		return Push(element);
	}

	arr[tailIndex] = element;

	if (tailIndex == capacity)
		tailIndex = 0;
	else
		tailIndex++;

	size++;
}

template <typename T>
void RingBuffer<T>::AddBefore(T element)
{
	if (size == 0)
	{
		arr[0] = element;
		tailIndex = 1;
		size++;
		return;
	}
	else if (size == capacity)
	{
		Enlarge();
		return AddBefore(element);
	}

	if (headIndex == 0)
	{
		arr[capacity] = element;
		headIndex = capacity;
	}
	else
	{
		arr[headIndex - 1] = element;
		headIndex--;
	}
	size++;
}

template <typename T>
void RingBuffer<T>::Display()
{
	std::cout << "Display:" << std::endl;
	int i = headIndex;
	while (i != tailIndex)
	{
		std::cout << arr[i] << std::endl;
		if (i == capacity)
			i = 0;
		else
			i++;
	}
}

template <typename T>
void RingBuffer<T>::DisplayDebug()
{
	std::cout << "Display - debug:" << std::endl;
	for (int i = 0; i <= capacity; i++)
		std::cout << i << ": " << arr[i] << std::endl;
}
