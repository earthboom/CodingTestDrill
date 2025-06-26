/*
https://www.acmicpc.net/problem/1149

문제
RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.
집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 
각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.

- 1번 집의 색은 2번 집의 색과 같지 않아야 한다.
- N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
- i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.

입력
첫째 줄에 집의 수 N(2 ≤ N ≤ 1,000)이 주어진다. 
둘째 줄부터 N개의 줄에는 각 집을 빨강, 초록, 파랑으로 칠하는 비용이 1번 집부터 한 줄에 하나씩 주어진다. 
집을 칠하는 비용은 1,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 모든 집을 칠하는 비용의 최솟값을 출력한다.
*/

#include "Solve_1149.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace BP1149
{
	void Solve_1149()
	{
		int N = 0;
		cin >> N;
				
		vector<vector<int>> cost(N + 1, vector<int>(3));	// 칠하는 비용
		vector<vector<int>> dp(N + 1, vector<int>(3));		// 최소 비용

		for (int i = 1; i <= N; ++i)
		{
			cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
		}

		// 첫째 집을 칠하는 비용
		dp[1][0] = cost[1][0];
		dp[1][1] = cost[1][1];
		dp[1][2] = cost[1][2];

		for (int i = 2; i <= N; ++i)
		{
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];	// i번 집을 R로 칠하는 비용
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];	// i번 집을 G로 칠하는 비용
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];	// i번 집을 B로 칠하는 비용
		}

		// 마지막 집을 R, G, B 로 칠한 비용 중 최소값을 출력
		cout << min({ dp[N][0], dp[N][1], dp[N][2] }) << endl;
	}
}
