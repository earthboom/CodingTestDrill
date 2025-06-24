
#include "Permutation.h"
#include <iostream>
#include <vector>

using namespace std;

namespace PermutationNamespace
{
	int N, M;
	vector<int> perm;	// ���� depth ���� ���õ� ���� ����
	vector<bool> used;	// ���ڸ� �̹� ����ߴ��� ǥ��
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
	// 1) ���ϴ� depth�� �������� ��
	if (depth == M)
	{
		for (int i = 0; i < N; ++i)
		{
			cout << perm[i] << (i + 1 < M ? ' ' : '\n');
		}
		return;
	}

	// 2) ��ȸ : 1 ~ N����
	for (int i = 1; i <= N; ++i)
	{
		if (used[i])	// �̹� �̾����� skip!
		{
			continue;
		}

		// 3) ����
		used[i] = true;
		perm[depth] = i;

		// 4) ��� ȣ��
		DFS(depth + 1);

		// 5) �ǵ����� (back tracking)
		used[i] = false;
		perm[depth] = 0;	// �ʿ信 ���� ���� ����
	}
}