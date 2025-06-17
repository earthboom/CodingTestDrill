#include "Bitmask.h"
#include <vector>
#include <algorithm>

using namespace std;

// Bit üũ & ����
void Subset()
{
	int i = 0;	// i��°

	int mask = 0;	// 0 <= mask < (1 < N)

	// i�� ���Ұ� ���õǾ��°�?
	bool used = (mask & (1 << i)) != 0;

	// i�� ���� �����ϱ�
	mask |= (1 << i);

	// i�� ���� �����ϱ�
	mask &= ~(1 << i);

	// i�� ���� ��� (���� ������ ����, ���� ������ �ѱ�)
	mask ^= (1 << i);
}

// �κ����� ���� ����
void EnumerationSubsets()
{
	int N = 4;

	// mask : 0 .. (1 << N) - 1 ���� ���� ��� �κ����� ��ȸ
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
		// subset �ȿ��� mask�� ���Ե� ���ҵ�
		// ��) mask = 5(0101) -> subset = {0, 2}
	}
}

void TSP()
{
	int N = 16; // N <= 16 ����
	vector<vector<int>> dp(N);
	vector<vector<int>> cost(N);

	for (int mask = 0; mask < (1 << N); ++mask)
	{
		for (int u = 0; u < N; ++u)
		{
			// u �湮 �������� skip
			if ((mask & (1 << u)) == false)
			{
				continue;
			}

			for (int v = 0; v < N; ++v)
			{
				// v �̹� �湮������ skip
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