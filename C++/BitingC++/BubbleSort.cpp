#include <iostream>
#include "header.h"
using namespace std;
using namespace sangok;

void Sort(int* sortArr, int size)
{
	for (int s = 0; s < size - 1; s++)
	{
		for (int i = 0; i < size - 1 - s; i++)
		{
			if (sortArr[i] > sortArr[i + 1])
			{
				int temp = sortArr[i];
				sortArr[i] = sortArr[i + 1];
				sortArr[i + 1] = temp;
			}
		}
	}
}

int main()
{
	int num[] = {9,3,2,5,6,4,8,7,1};
	int size = sizeof(num) / sizeof(num[0]);
	for(int i = 0; i < size; i++)
	{
		cout << num[i] << endl;
	}
	Sort(num,size);
	for (int i = 0; i < size; i++)
	{
		cout << num[i] << endl;
	}
	
 }



