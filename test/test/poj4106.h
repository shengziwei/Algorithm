#pragma once
#include<stdio.h>
#include<iostream>
using namespace std;
/*Ͱ�ŵ�˼��*/
void poj4106()
{
	int i, t, k, a[255];
	char s[255];
	cin >> t;
	getchar();
	while (t--)
	{
		for (i = 0; i < 255; i++)
			a[i] = 0;
		gets_s(s);//�����ַ���

		for (i = 0; s[i] != '\0'; i++)
			a[s[i]]++;

		for (i = 0; s[i] != '\0'; i++)
		{
			if (a[s[i]] == 2)
			{
				printf("%c\n", s[i]);
				break;
			}
		}

	}
}