// binaryChop04_iterative.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int chop(int target, int volume[], int left, int right) {

	int dividingElement;
	int numberOfElements;
	int totalElements;
	totalElements = (volume[right] - volume[left]);
	numberOfElements = (target - volume[left]);
	dividingElement = left + (numberOfElements / totalElements) * (right - left);

	while ((volume[dividingElement]!=target)&&(dividingElement != -1))
	{
		dividingElement = left + (numberOfElements / totalElements) * (right - left);
		if (left>right)
		{
			dividingElement = -1;
		}
		else if (volume[dividingElement]>target)
		{
			right = dividingElement - 1;
		}
		else
		{
			left = dividingElement +1;
		}
	}
	return dividingElement;
}
int main()
{
	int target = 7;
	int volume[10] = { 1,2,3, 4,5, 6, 7, 13, 22 ,125 };
	int left = 0;
	int right;
	right = (sizeof(volume) / sizeof(*volume));
	cout << target << " was found at position " << chop(target, volume, left, right);
	cin >> target;
}

