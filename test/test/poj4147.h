#pragma once
#include <iostream>
#include <algorithm>
using namespace std;



void hanoi(int n, char a, char b, char c)
{
	if (n == 1)
		cout << n << ":" << a << "->" << c << endl;
	else {
		hanoi(n - 1, a, c, b);
		cout << n << ":" << a << "->" << c << endl;
		hanoi(n - 1, b, a, c);
	}

}
void poj4147()
{
	int n = 0;
	cin >> n;
	char a, b, c;
	cin >> a >> b >> c;
	hanoi(n, a, b, c);
}

