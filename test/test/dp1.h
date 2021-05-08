#pragma once
#include <iostream>
#include <algorithm>
#include<stdio.h>
#include<vector>
using namespace std;
/*


题目：
已知摩尔斯电码和字符映射关系如下：
A -> 0
B -> 1
C -> 10
D -> 11
E -> 100
F -> 101
G -> 110
H -> 111
当前我们获取到了一串01数字字符串，需要进行摩尔斯电码解码，请问共有多少种解码方法

解法：
用动态规划:可以将n长度的字符串分解为n-1
dp[i]表示前i个元素中解码方法总数
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
