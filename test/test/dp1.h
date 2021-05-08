#pragma once
#include <iostream>
#include <algorithm>
#include<stdio.h>
#include<vector>
using namespace std;
/*


��Ŀ��
��֪Ħ��˹������ַ�ӳ���ϵ���£�
A -> 0
B -> 1
C -> 10
D -> 11
E -> 100
F -> 101
G -> 110
H -> 111
��ǰ���ǻ�ȡ����һ��01�����ַ�������Ҫ����Ħ��˹������룬���ʹ��ж����ֽ��뷽��

�ⷨ��
�ö�̬�滮:���Խ�n���ȵ��ַ����ֽ�Ϊn-1
dp[i]��ʾǰi��Ԫ���н��뷽������
if i==0/1 dp[i]=dp[i]+dp[i-1]
if i i-1=10/11 dp[i]=dp[i]+dp[i-2]
if i i-1 i-2=100/101/110/111 dp[i]=dp[i]+dp[i-3]

*/
void dp()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1];
        if (s.substr(i - 2, 2) == "10" || s.substr(i - 2, 2) == "11")
        {
            dp[i] += dp[i - 2];
        }
        if (i > 2 && (s.substr(i - 3, 3) == "100" || s.substr(i - 3, 3) == "101" || s.substr(i - 3, 3) == "110"
            || s.substr(i - 3, 3) == "111"))
        {
            dp[i] += dp[i - 3];
        }
    }
    cout << dp[n] << endl;


}
