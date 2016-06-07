#include <iostream>

int findRoot(const int *arr, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == -1)
			return i;
	}
	return -1;
}

void direct(const int *arr, int n, int father)
{
	if (father == -1)
		father = findRoot(arr, n);
	std::cout << father << " ";
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == father)
			direct(arr, n, i);
	}
}

void reverse(const int *arr, int n, int father)
{
	if (father == -1)
		father = findRoot(arr, n);
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] == father)
			reverse(arr, n, i);
	}
	std::cout << father << " ";
}

void symmet(const int *arr, int n, int father)
{
	if (father == -1)
		father = findRoot(arr, n);
	int index = 0;
	for (; index < n; ++index)
	{
		if (arr[index] == father)
		{
			symmet(arr, n, index++);
			break;
		}
	}
	std::cout << father << " ";
	for (; index < n; ++index)
	{
		if (arr[index] == father)
			symmet(arr, n, index);
	}
}

int main()
{
	int n;
	std::cin >> n;
	int *cursors = new int[n];
	for (int i = 0; i < n; ++i)
		std::cin >> cursors[i];
	direct(cursors, n, -1);
	std::cout << std::endl;
	reverse(cursors, n, -1);
	std::cout << std::endl;
	symmet(cursors, n, -1);
	std::cout << std::endl;
	return 0;
}
