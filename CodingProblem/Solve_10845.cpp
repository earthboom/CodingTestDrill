/*
https://www.acmicpc.net/problem/10845

����
������ �����ϴ� ť�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� ���� �����̴�.

- push X	:	���� X�� ť�� �ִ� �����̴�.
- pop		:	ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
- size		:	ť�� ����ִ� ������ ������ ����Ѵ�.
- empty		:	ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
- front		:	ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
- back		:	ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

�Է�
ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. 
��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. 
�־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. 
������ �������� ���� ����� �־����� ���� ����.

���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.
*/

#include "Solve_10845.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace BP10845
{
	void Solve_10845()
	{
		int N = 0;
		cin >> N;

		vector<int> value;

		int Q[10000] = { 0, };
		int head = 0;
		int tail = 0;
		string cmd;
		while (N--)
		{
			cin >> cmd;

			if (cmd == "push")
			{
				int v = 0;
				cin >> v;
				Q[tail++] = v;
			}
			else if (cmd == "pop")
			{
				if (head < tail)
				{
					value.emplace_back(Q[head++]);
				}
				else
				{
					value.emplace_back(-1);
				}
			}
			else if (cmd == "size")
			{
				value.emplace_back(tail - head);
			}
			else if (cmd == "empty")
			{
				if (head < tail)
				{
					value.emplace_back(0);
				}
				else
				{
					value.emplace_back(1);
				}
			}
			else if (cmd == "front")
			{
				if (head < tail)
				{
					value.emplace_back(Q[head]);
				}
				else
				{
					value.emplace_back(-1);
				}
			}
			else if (cmd == "back")
			{
				if (head < tail)
				{
					value.emplace_back(Q[tail - 1]);
				}
				else
				{
					value.emplace_back(-1);
				}
			}
		}

		for (int i = 0; i < value.size(); ++i)
		{
			cout << value[i] << endl;
		}
	}
}
