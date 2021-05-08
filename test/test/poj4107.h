
#include <iostream>
#include<math.h>
#include<algorithm>
#include<vector>


using namespace std;
void poj4107()
{
	int n;
	cin >> n;
	int num;
	while (n--)
	{
		cin >> num;
		bool flag = false;
		vector<int> a;
		if (num % 19 == 0)
			cout << "Yes" << endl;
		else
		{
			while (num != 0)
			{
				int number = num % 10;
				a.push_back(number);
				num = num / 10;
			}
			for (int i = 0; i < a.size() - 1; i++)
			{
				if (a[i] == 9)
					if (a[i + 1] == 1)
						flag = true;
			}
			if (flag == true)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
}

