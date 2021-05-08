#pragma once
#include <iostream>
#include <algorithm>
#include<stdio.h>
using namespace std;

void poj2586()
{
	int s, d;
	while (cin >> s >> d)
	{
		int x, y;
		for (int i = 4; i >= 0; i--)
		{
			//5个月一次循环的样子，所以5个月亏n次，代表了12个月会亏 2n次
			x = i;
			y = 5 - i;
			if (s * x < d * y)
			{
				break;
			}
		}
		int surplus = 0;
		if (x != 1 && x != 0)
			surplus = s * (12 - 2 * y) - d * y * 2;
		else if (x == 1)
			surplus = s * 3 - 9 * d;
		else if (x == 0)
			surplus = -12 * d;
		if (surplus > 0)
		{
			cout << surplus << endl;
		}
		else
			cout << "Deficit" << endl;
	}
	return 0;
}

