#pragma once
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct candy {
	int v;
	int w;
	double cost;
};
bool cmp(candy x, candy y)
{
	return x.cost > y.cost;
}
void opj4110()
{
	int n, weight;
	cin >> n >> weight;
	double sum = 0.0;
	struct candy a[100];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].v >> a[i].w;
		a[i].cost = a[i].v / (double)a[i].w;
	}
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++)
		if (a[i].w <= weight)
		{
			sum += a[i].v;
			weight -= a[i].w;
		}
		else
		{
			sum += weight * a[i].cost;
			break;
		}
	cout << setiosflags(ios::fixed) << setprecision(1) << sum;
}