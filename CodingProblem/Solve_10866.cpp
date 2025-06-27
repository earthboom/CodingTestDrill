/*
https://www.acmicpc.net/problem/10866

문제
정수를 저장하는 덱(Deque)를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여덟 가지이다.

- push_front X	: 정수 X를 덱의 앞에 넣는다.
- push_back X	: 정수 X를 덱의 뒤에 넣는다.
- pop_front		: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
- pop_back		: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
- size			: 덱에 들어있는 정수의 개수를 출력한다.
- empty			: 덱이 비어있으면 1을, 아니면 0을 출력한다.
- front			: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
- back			: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.

입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.
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
