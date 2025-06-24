/*
https://www.acmicpc.net/problem/4375

����
2�� 5�� ������ �������� �ʴ� ���� n(1 �� n �� 10000)�� �־����� ��, �� �ڸ����� ��� 1�θ� �̷���� n�� ����� ã�� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� ���� ���� �׽�Ʈ ���̽��� �̷���� �ִ�. �� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, n�� �־�����.

���
�� �ڸ����� ��� 1�θ� �̷���� n�� ��� �� ���� ���� ���� �ڸ����� ����Ѵ�.
*/

#include "Solve_4375.h"
#include <iostream>

using namespace std;

namespace BP4375
{
	void Solve_4375()
	{
		int n = 0;

		while ((cin >> n))
		{
			int rem = 1 % n;
			int length = 1;

			while (rem != 0)
			{
				rem = (rem * 10 + 1) % n;
				++length;
			}

			cout << length << endl;
		}
	}
}