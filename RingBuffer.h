#ifndef RING_BUFFER_H
	
template <typename T>
class RingBuffer
{
	int capacity;
	int size;
	T* arr;

	int headIndex;
	int tailIndex;

	void Enlarge();

public:
	int Size()
	{
		return size;
	}

	RingBuffer();
	RingBuffer(int initialCapacity);

	void AddBefore(T element);
	void Push(T element);
	void RemoveFromEnd();
	void RemoveFromBeginning();
	void Insert(int index, T element);
	void Display();
	void DisplayDebug();
	void WriteAt(int index, T element);

};

#endif // !RING_BUFFER_H
