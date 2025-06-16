/*
https://www.acmicpc.net/problem/15650

����
�ڿ��� N�� M�� �־����� ��, �Ʒ� ������ �����ϴ� ���̰� M�� ������ ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

1���� N���� �ڿ��� �߿��� �ߺ� ���� M���� �� ����
�� ������ ���������̾�� �Ѵ�.

�Է�
ù° �ٿ� �ڿ��� N�� M�� �־�����. (1 �� M �� N �� 8)

���
�� �ٿ� �ϳ��� ������ ������ �����ϴ� ������ ����Ѵ�. �ߺ��Ǵ� ������ ���� �� ����ϸ� �ȵǸ�, �� ������ �������� �����ؼ� ����ؾ� �Ѵ�.

������ ���� ������ �����ϴ� ������ ����ؾ� �Ѵ�.
*/

#include "Solve_15650.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

namespace SV15650
{
	int N;
	int M;
	vector<int> Results;

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

		for (int i = num + 1; i <= N; ++i)
		{
			if (num > 0 && Results[num - 1] >= i)
			{
				continue;
			}

			Results[num] = i;
			Check(num + 1);
		}
	}
}

using namespace SV15650;

void Solve_15650()
{
	cin >> N >> M;
	Results.assign(M, 0);

	Check(0);
}
