#include <iostream>
#include<math.h>
#include<algorithm>
using namespace std;
/*
̰�ģ�
�Ե�Ӱ����ʱ����絽������ѡ������ĵ�Ӱ�������и���ʱ�俴�����
��Ӱ
1.������ʱ������
2.��������ǰ����ʵ��<=��һ����ʼ sum++
*/
/*�ҵĴ���
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
/*AC����*/

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
		sort(a, a + n, cmp);  //sort(start,end,cmp) cmp���ڹ涨����ķ������ɲ��Ĭ������
		int sum = 1;
		int js=a[0].end;//��ʾ����ʱ��
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
