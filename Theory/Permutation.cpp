
#include "Permutation.h"
#include <iostream>
#include <vector>

using namespace std;

namespace PermutationNamespace
{
	int N, M;
	vector<int> perm;	// 현재 depth 에서 선택된 숫자 저장
	vector<bool> used;	// 숫자를 이미 사용했는지 표시
}

using namespace PermutationNamespace;

void Permutation()
{
	cin >> N >> M;

	perm.assign(M, 0);
	used.assign(N + 1, false);

	DFS(0);
}

void DFS(int depth)
{
	// 1) 원하는 depth에 도달했을 때
	if (depth == M)
	{
		for (int i = 0; i < N; ++i)
		{
			cout << perm[i] << (i + 1 < M ? ' ' : '\n');
		}
		return;
	}

	// 2) 순회 : 1 ~ N까지
	for (int i = 1; i <= N; ++i)
	{
		if (used[i])	// 이미 뽑았으면 skip!
		{
			continue;
		}

		// 3) 선택
		used[i] = true;
		perm[depth] = i;

		// 4) 재귀 호출
		DFS(depth + 1);

		// 5) 되돌리기 (back tracking)
		used[i] = false;
		perm[depth] = 0;	// 필요에 따라 생략 가능
	}
}