#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

void merge(int arr[], int l, int m, int b, int r)
{
	int i, j, h, k;
	int n1 = m - l + 1;
	int n2 = b - m;
	int n3 = r - b;

	int* L = new int[n1];
	int* M = new int[n2];
	int* R = new int[n3];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	for (h = 0; h < n3; h++)
		R[h] = arr[b + 1 + h];

	i = 0; 
	j = 0;
	h = 0;
	k = l;
	while (i < n1 && j < n2 && h < n3)
	{
		if (L[i] <= M[j] || L[i] <= R[h])
		{
			arr[k] = L[i];
			i++;
		}
		else if (M[j] <= L[i] || M[j] <= R[h])
		{
			arr[k] = M[j];
			j++;
		}
		else 
		{
			arr[k] = R[h];
			h++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = M[j];
		j++;
		k++;
	}

	while (h < n3)
	{
		arr[k] = R[h];
		h++;
		k++;
	}
}

int div_ceil(int numerator, int denominator)
{
	std::div_t res = std::div(numerator, denominator);
	return res.rem ? (res.quot + 1) : res.quot;
}


void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		//int m = div_ceil(r + l, 3);
		//int b = div_ceil(2*r + 2*l, 3);
		//int m = l + (r - l) / 3;
		//int b = 2 * m;
		int m = std::ceil(float(r - l) / 3);
		int b = 2 * m;
		cout << m << " " << b << " " << l << " " << r << endl;
		if (m != 1) {
			mergeSort(arr, l, m);
			mergeSort(arr, m + 1, b);
			mergeSort(arr, b + 1, r);

			merge(arr, l, m, b, r);
		}
	}
}

void PrintM(int arr[], int n) 
{
	cout << "Array:" << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

