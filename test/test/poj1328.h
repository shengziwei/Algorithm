#pragma once
#include <iostream>
#include <algorithm>
#include<stdio.h>
using namespace std;
/*贪心策略
首先：如果有任何一个海岛的y>d，则无解
此问题的切入点是：一个雷达要覆盖一个海岛，他所能安装的范围是多少

以海岛（x,y）为圆心，d为半径，该圆与x轴会有两个交点，那么雷达必须要安装在这两个交点的范围内

按照所有海岛的x轴坐标，从小到大依次计算每个海岛在x轴上的投影区间（投影可能存在重叠），
同时把每个雷达抽象成x轴上的点，那么此问题就转化成：
【已知x轴上若干个区间（可能存在交集），现在要往这些区间内放若干个点，
  问怎样放置这些点，使得每个区间内至少存在一个点，且所放置的点的总量尽可能最少】

  接着使用贪心求解：
  从左向右遍历
  A.R  在A.R放一点 P+1
  if(A.R<B.L)没有交集 P+1
  else if说明相交
  进一步判断B.R<A.R说明B在A的内部 A.R=B.R 把点放到B.R的位置上，确保区间B内有点 P不变化
*/
struct Interval
{
	double left;
	double right;
}inter[1005];
struct node
{
	int x;
	int y;
}rader[1005];
int cmp(Interval a, Interval b)
{
	return a.left < b.left;
}
int solve(Interval inter[], int n)
{
	int num = 1;
	double right = inter[0].right;
	for (int i = 1; i < n; i++)
	{
		if (inter[i].left > right)
		{
			right = inter[i].right;
			num++;
		}
		else if (inter[i].right < right)
			right = inter[i].right;
		else
		{
		}

	}
	return num;
}


void poj1328()
{
	int count = 1;
	int n, d;
	while (cin >> n >> d, n != 0 || d != 0)
	{
		bool solveable = true;
		double R2 = (double)d * d;
		for (int i = 0; i < n; i++)
		{
			cin >> rader[i].x >> rader[i].y;
			if (rader[i].y > d)
				solveable = false;
			double a = sqrt(R2 - (double)rader[i].y * rader[i].y);
			inter[i].left = rader[i].x - a;
			inter[i].right = rader[i].x + a;
		}
		sort(inter, inter + n, cmp);
		if (solveable == false)
			cout << "Case " << count << ": " << -1 << endl;
		else
			cout << "Case " << count << ": " << solve(inter, n) << endl;
		count++;
	}
}