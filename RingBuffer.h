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
	void CreateWithElement(T element);

public:
	int Size()
	{
		return size;
	}

	RingBuffer();
	RingBuffer(int initialCapacity);

	void AddBefore(T element);
	void Push(T element);
	T PopEnd();
	T PopBeginning();
	void Insert(int index, T element);
	void Display();
	void DisplayDebug();
	void WriteAt(int index, T element);
	T Get(int index);

};

#endif // !RING_BUFFER_H
