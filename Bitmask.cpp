#include "Bitmask.h"
#include <vector>
#include <algorithm>

using namespace std;

// Bit 체크 & 조작
void Subset()
{
	int i = 0;	// i번째

	int mask = 0;	// 0 <= mask < (1 < N)

	// i번 원소가 선택되었는가?
	bool used = (mask & (1 << i)) != 0;

	// i번 원소 선택하기
	mask |= (1 << i);

	// i번 원소 해제하기
	mask &= ~(1 << i);

	// i번 원소 토글 (켜져 있으면 끄고, 꺼져 있으면 켜기)
	mask ^= (1 << i);
}

// 부분집합 열거 예제
void EnumerationSubsets()
{
	int N = 4;

	// mask : 0 .. (1 << N) - 1 까지 돌며 모든 부분집합 순회
	for (int mask = 0; mask < (1 < N); ++mask)
	{
		vector<int> subset;
		for (int i = 0; i < N; ++i)
		{
			if (mask & (1 << i))
			{
				subset.emplace_back(i);
			}
		}
		// subset 안에는 mask에 포함된 원소들
		// 예) mask = 5(0101) -> subset = {0, 2}
	}
}

void TSP()
{
	int N = 16; // N <= 16 정도
	vector<vector<int>> dp(N);
	vector<vector<int>> cost(N);

	for (int mask = 0; mask < (1 << N); ++mask)
	{
		for (int u = 0; u < N; ++u)
		{
			// u 방문 안했으면 skip
			if ((mask & (1 << u)) == false)
			{
				continue;
			}

			for (int v = 0; v < N; ++v)
			{
				// v 이미 방문했으면 skip
				if (mask & (1 << v))
				{
					continue;
				}

				int next = mask | (1 << v);
				dp[next][v] = min(dp[next][v], dp[mask][u] + cost[u][v]);
			}
		}
	}
}