/*
https://www.acmicpc.net/problem/10866

����
������ �����ϴ� ��(Deque)�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����� �� ���� �����̴�.

- push_front X	: ���� X�� ���� �տ� �ִ´�.
- push_back X	: ���� X�� ���� �ڿ� �ִ´�.
- pop_front		: ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
- pop_back		: ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
- size			: ���� ����ִ� ������ ������ ����Ѵ�.
- empty			: ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
- front			: ���� ���� �տ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
- back			: ���� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.

�Է�
ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

���
����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.
*/

#include "Solve_10866.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace BP10866
{
	void Solve_10866()
	{
		int N = 0;
		cin >> N;

		int DQ[10000] = { 0, };
		int head = 4999;
		int tail = 5000;
		string cmd;

		vector<int> values = {};

		while (N--)
		{
			cin >> cmd;

			if (cmd == "push_front")
			{
				int v = 0;
				cin >> v;

				DQ[head--] = v;
			}
			else if (cmd == "push_back")
			{
				int v = 0;
				cin >> v;

				DQ[tail++] = v;
			}
			else if (cmd == "pop_front")
			{
				if ((head + 1) >= tail)
				{
					values.emplace_back(-1);
				}
				else
				{
					values.emplace_back(DQ[++head]);
				}
			}
			else if (cmd == "pop_back")
			{
				if (tail <= (head + 1))
				{
					values.emplace_back(-1);
				}
				else
				{
					values.emplace_back(DQ[--tail]);
				}
			}
			else if (cmd == "size")
			{
				values.emplace_back((tail - head) - 1);
			}
			else if (cmd == "empty")
			{
				if ((head + 1) >= tail)
				{
					values.emplace_back(1);
				}
				else
				{
					values.emplace_back(0);
				}
			}
			else if (cmd == "front")
			{
				if ((head + 1) >= tail)
				{
					values.emplace_back(-1);
				}
				else
				{
					values.emplace_back(DQ[head + 1]);
				}
			}
			else if (cmd == "back")
			{
				if (tail <= (head + 1))
				{
					values.emplace_back(-1);
				}
				else
				{
					values.emplace_back(DQ[tail - 1]);
				}
			}
		}

		for (const int& v : values)
		{
			cout << v << endl;
		}
	}
}
