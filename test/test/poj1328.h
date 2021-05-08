#pragma once
#include <iostream>
#include <algorithm>
#include<stdio.h>
using namespace std;
/*̰�Ĳ���
���ȣ�������κ�һ��������y>d�����޽�
�������������ǣ�һ���״�Ҫ����һ�������������ܰ�װ�ķ�Χ�Ƕ���

�Ժ�����x,y��ΪԲ�ģ�dΪ�뾶����Բ��x������������㣬��ô�״����Ҫ��װ������������ķ�Χ��

�������к�����x�����꣬��С�������μ���ÿ��������x���ϵ�ͶӰ���䣨ͶӰ���ܴ����ص�����
ͬʱ��ÿ���״�����x���ϵĵ㣬��ô�������ת���ɣ�
����֪x�������ɸ����䣨���ܴ��ڽ�����������Ҫ����Щ�����ڷ����ɸ��㣬
  ������������Щ�㣬ʹ��ÿ�����������ٴ���һ���㣬�������õĵ���������������١�

  ����ʹ��̰����⣺
  �������ұ���
  A.R  ��A.R��һ�� P+1
  if(A.R<B.L)û�н��� P+1
  else if˵���ཻ
  ��һ���ж�B.R<A.R˵��B��A���ڲ� A.R=B.R �ѵ�ŵ�B.R��λ���ϣ�ȷ������B���е� P���仯
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