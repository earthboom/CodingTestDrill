/*
https://www.acmicpc.net/problem/15649

문제
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열

입력
첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.
*/

#include "Solve_15649.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

namespace BP15649
{
	int N;
	int M;
	vector<int> Results;
	vector<bool> Used;
	
	void Check(int num)
	{
		if (num == M)
		{
			for (int i = 0; i < M; ++i)
			{
				cout << Results[i] << (i + 1 < M ? ' ' : '\n');
			}
			return;
		}

		for (int i = 1; i <= N; ++i)
		{
			if (Used[i] == false)
			{
				Used[i] = true;
				Results[num] = i;
				Check(num + 1);
				Used[i] = false;
			}
		}
	}

	void Solve_15649()
	{
		cin >> N >> M;
		Used.assign(N + 1, false);
		Results.assign(M, 0);

		Check(0);
	}
}