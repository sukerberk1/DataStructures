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
		if (i == capacity)
			i = 0;
		else
			i++;
		j++;
	}
	headIndex = 0;
	tailIndex = j;

	arr = newArr;

	capacity = newCapacity;
}

template <typename T>
void RingBuffer<T>::Push(T element)
{
	if (size == 0)
	{
		CreateWithElement(element);
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
		CreateWithElement(element);
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
void RingBuffer<T>::CreateWithElement(T element)
{
	arr[0] = element;
	tailIndex = 1;
	size++;
}

template <typename T>
T RingBuffer<T>::PopBeginning()
{
	if (size == 0) return T();
	if (headIndex == capacity)
	{
		T val = arr[capacity];
		headIndex = 0;
		size--;
		return val;
	}
	T val = arr[headIndex];
	headIndex++;
	size--;
	return val;
}

template <typename T>
T RingBuffer<T>::PopEnd()
{
	if (size == 0) return T();
	if (tailIndex == 0)
	{
		T val = arr[tailIndex];
		tailIndex = capacity;
		size--;
		return val;
	}
	T val = arr[tailIndex];
	tailIndex--;
	size--;
	return val;
}

template <typename T>
void RingBuffer<T>::WriteAt(int index, T element)
{
	int writeIndex = (headIndex + index) % capacity;
	if (index > size) return;
	arr[writeIndex] = element;
}

template <typename T>
T RingBuffer<T>::Get(int index)
{
	int readIndex = (headIndex + index) % capacity;
	if (index > size) throw;
	return arr[readIndex];
}

template <typename T>
void RingBuffer<T>::Insert(int index, T element)
{
	if (size == 0)
	{
		CreateWithElement(element);
		return;
	}
	if (size == capacity)
	{
		Enlarge();
		return Insert(index, element);
	}
	if (index > size) throw;
	int insertIndex = (headIndex + index) % capacity;

	T tempElem = arr[insertIndex];
	arr[insertIndex] = element;
	
	if (insertIndex == capacity)
		insertIndex = 0;
	else
		insertIndex++;

	while (insertIndex != tailIndex+1)
	{	
		T elemToSwitch = arr[insertIndex];
		arr[insertIndex] = tempElem;
		tempElem = elemToSwitch;

		if (insertIndex == capacity)
			insertIndex = 0;
		else
			insertIndex++;
	}
	if (tailIndex == capacity)
		tailIndex = 0;
	else
		tailIndex++;
	size++;
}

template <typename T>
void RingBuffer<T>::Display()
{
	std::cout << "Display:" << std::endl;
	int i = headIndex;
	while (i != tailIndex)
	{
		std::cout << arr[i] << ' ';
		if (i == capacity)
			i = 0;
		else
			i++;
	}
	std::cout << "\n";
}

template <typename T>
void RingBuffer<T>::DisplayDebug()
{
	std::cout << "Display - debug:" << std::endl;
	for (int i = 0; i <= capacity; i++)
		if(i==headIndex)
			std::cout << i << ": " << arr[i] << "<- HEAD" << std::endl;
		else if (i==tailIndex)
			std::cout << i << ": " << arr[i] << "<- TAIL" << std::endl;
		else
			std::cout << i << ": " << arr[i] << std::endl;
	std::cout << "SIZE:" << this->Size() << "\n";
}
