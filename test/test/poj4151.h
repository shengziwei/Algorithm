#include <iostream>
#include<math.h>
#include<algorithm>
using namespace std;
/*
贪心：
对电影结束时间从早到晚排序，选结束早的电影看，就有更多时间看后面的
电影
1.按结束时间排序
2.遍历，当前结束实践<=下一部开始 sum++
*/
/*我的代码
int main()
{
	int n;
	while (cin >> n, n != 0)
	{
		int movie[100][2] = { 0 };
		for (int i = 0; i < n; i++)
		{
			cin >> movie[i][0];
			cin >> movie[i][1];
		}
		int m;
		cin >> m;
		int max = 1;
		for (int i = n - 1; i >= 0; i--)
		{
			int begin = movie[i][0];
			int num = 1;
			for (int j = n - 1; j >= 0; j--)
			{

				if (movie[j][1] <= begin)
				{
					begin = movie[j][0];
					num++;
				}
			}
			if (num > max)
				max = num;
		}
		cout << max<<endl;
	}
}*/
/*AC代码*/

struct node
{
	int begin;
	int end;
}a[105];
int cmp(node a, node b)
{
	return a.end < b.end;
}
void poj4151()
{
	int n;
	while (cin >> n, n != 0)
	{
		for (int i = 0; i < n; i++)
		{
		cin>>a[i].begin>>a[i].end;
		}
		sort(a, a + n, cmp);  //sort(start,end,cmp) cmp用于规定排序的方法，可不填，默认升序
		int sum = 1;
		int js=a[0].end;//表示结束时间
		for (int i = 0; i < n; i++)
		{
			if (a[i].begin >= js)
			{
				sum++;
				js = a[i].end;
			}
		}
		cout << sum << endl;
	}

}
