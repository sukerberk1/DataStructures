static class QuickSort
{
	static int Partition(int* arr, int low, int high)
	{
		int pivot = arr[high];
		auto idx = low - 1;
		for (int i = low; i < high; i++)
		{
			if (arr[i] > pivot) continue;
			idx++;
			auto tmp = arr[i];
			arr[i] = arr[idx];
			arr[idx] = tmp;
		}
		idx++;
		arr[high] = arr[idx];
		arr[idx] = pivot;

		return idx;
	}
public:
	static void Sort(int* arr, int low, int high)
	{
		if (low >= high)
			return;

		int pivotIdx = Partition(arr, low, high);

		Sort(arr, low, pivotIdx - 1);
		Sort(arr, pivotIdx + 1, high);
	}
};
