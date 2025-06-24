/*
https://www.acmicpc.net/problem/15988

문제
정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 
합을 나타낼 때는 수를 1개 이상 사용해야 한다.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1

정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 
각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 1,000,000보다 작거나 같다.

출력
각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 1,000,000,009로 나눈 나머지를 출력한다.
*/

#include "Solve_15988.h"
#include <iostream>
#include <vector>

using namespace std;

namespace BP15988
{
	void Solve_15988()
	{
		int T = 0;
		cin >> T;

		const int Value = 1000000009;
		vector<long> DP(1000001, 0);

		DP[0] = 1;
		DP[1] = 1;
		DP[2] = 2;
		DP[3] = 4;

		for (int i = 4; i <= 1000000; ++i)
		{
			DP[i] = (DP[i - 1] + DP[i - 2] + DP[i - 3]) % Value;
		}

		int n = 0;
		for (int i = 0; i < T; ++i)
		{
			cin >> n;
			cout << DP[n] << endl;
		}
	}
}