/*
https://www.acmicpc.net/problem/10973

문제
1부터 N까지의 수로 이루어진 순열이 있다. 이때, 사전순으로 바로 이전에 오는 순열을 구하는 프로그램을 작성하시오.
사전 순으로 가장 앞서는 순열은 오름차순으로 이루어진 순열이고, 가장 마지막에 오는 순열은 내림차순으로 이루어진 순열이다.
N = 3인 경우에 사전순으로 순열을 나열하면 다음과 같다.

1, 2, 3
1, 3, 2
2, 1, 3
2, 3, 1
3, 1, 2
3, 2, 1

입력
첫째 줄에 N(1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄에 순열이 주어진다.

출력
첫째 줄에 입력으로 주어진 순열의 이전에 오는 순열을 출력한다. 만약, 사전순으로 가장 처음에 오는 순열인 경우에는 -1을 출력한다.
*/

#include "Solve_10973.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace BP10973
{
	void Solve_10973()
	{
		int N = 0;
		cin >> N;

		vector<int> P(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> P[i];
		}

		if (prev_permutation(P.begin(), P.end()))
		{
			for (const int& x : P)
			{
				cout << x << ' ';
			}
		}
		else
		{
			cout << -1;
		}
	}
}