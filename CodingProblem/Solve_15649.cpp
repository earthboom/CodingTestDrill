/*
https://www.acmicpc.net/problem/15649

����
�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����

�Է�
ù° �ٿ� �ڿ��� N�� M�� �־�����. (1 �� M �� N �� 8)

���
�� �ٿ� �ϳ��� ������ ������ �����ϴ� ������ ����Ѵ�. �ߺ��Ǵ� ������ ���� �� ����ϸ� �ȵǸ�, �� ������ �������� �����ؼ� ����ؾ� �Ѵ�.

������ ���� ������ �����ϴ� ������ ����ؾ� �Ѵ�.
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