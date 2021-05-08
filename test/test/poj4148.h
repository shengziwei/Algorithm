#include<iostream>
using namespace std;

/*法一：暴力法*/
/*
int main()
{
	int p;
	int e;
	int i;
	int  d;
	int c = 0;
	while (cin >> p >> e >> i >> d, p != -1, e != -1, i != -1, d != -1)
	{
		c++;
		for (int k = d + 1; k <= 21252+d; k++)
		{
			if ((k - p) % 23 == 0 && ((k - e) % 28 == 0) && ((k - i) % 33 == 0))
			{
				cout << "Case " << c<< ": the next triple peak occurs in " << k - d << " days." << endl;
				break;
			}
		}
	}
}
*/
/*法二：枚举法*/
void poj4148()
{

	int i, p, e, d, j, k, l, t = 0;
	while (true) {
		cin >> p >> e >> i >> d;
		if ((p + e + d + i) == -4) break;
		for (j = d + 1; j < 21252 + d; j++)
			if ((j - p) % 23 == 0)break;
		for (k = j; k < 21252 + d; k += 23)
			if ((k - e) % 28 == 0)break;
		for (l = k; l < 21252 + d; l += 23 * 28)
			if ((l - i) % 33 == 0)break;
		cout << "Case " << ++t << ": the next triple peak occurs in " << l - d << " days." << endl;
	}

}