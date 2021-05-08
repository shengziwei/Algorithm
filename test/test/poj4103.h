#pragma once
#include <iostream>
#include <algorithm>
#include<stdio.h>
using namespace std;
int block[30][50];//50*50格子


/*深度优先搜索问题*/
int dfs(int i, int j, int n)
{
	if (n == 0)
		return 1;
	block[i][j] = 1;
	int num = 0;
	if (!block[i][j - 1])
		num += dfs(i, j - 1, n - 1);
	if (!block[i][j + 1])
		num += dfs(i, j + 1, n - 1);
	if (!block[i + 1][j])
		num += dfs(i + 1, j, n - 1);
	block[i][j] = 0;//****注意：此条路径走完要还原
	return num;


}
int poj4103()
{
	int n;
	cin >> n;
	memset(block, 0, sizeof(block));
	cout << dfs(0, 25, n);
	return 0;

}
