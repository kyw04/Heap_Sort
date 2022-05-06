#include <iostream>
#include <minmax.h>
#define MAX 10
using namespace std;

int a[MAX + 1] = { INT_MAX, };
void instert(int *n, int k)
{
	a[++(*n)] = k;
	int v = k, i = *n;
	while (a[i / 2] < v)
	{
		a[i] = a[i / 2];
		i /= 2;
	}
	a[i] = v;
}
int extract(int *n)
{
	int v = a[1];
	a[1] = a[(*n)--];
	int i, k = 1, t = a[1];
	while (k <= *n / 2)
	{
		i = k << 1;
		if (i < *n && a[i] < a[i + 1]) i++;
		if (t >= a[i]) break;
		a[k] = a[i];
		k = i;
	}
	a[k] = t;
	return v;
}
void heap_sort(int list[], int n)
{
	int hn = 0;
	for (int i = 0; i < n; i++)
		instert(&hn, list[i]);
	for (int i = n - 1; i >= 0; i--)
		list[i] = extract(&n);
}
int main()
{
	int arr[MAX] = { 10, 4, 6, 3, 7, 9, 1, 5, 8, 2 };

	for (int i = 0; i < MAX; i++)
		cout << arr[i] << ' ';
	cout << endl;

	heap_sort(arr, MAX);

	for (int i = 0; i < MAX; i++)
		cout << arr[i] << ' ';
	cout << endl;

	return 0;
}