/*
https://www.acmicpc.net/source/95321337

����
���� 4�� 1, 2, 3�� ������ ��Ÿ���� ����� �� 7������ �ִ�. 
���� ��Ÿ�� ���� ���� 1�� �̻� ����ؾ� �Ѵ�.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1

���� n�� �־����� ��, n�� 1, 2, 3�� ������ ��Ÿ���� ����� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� T�� �־�����. 
�� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, ���� n�� �־�����. n�� ����̸� 11���� �۴�.

���
�� �׽�Ʈ ���̽�����, n�� 1, 2, 3�� ������ ��Ÿ���� ����� ���� ����Ѵ�.
*/

#include "Solve_9095.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

namespace BP9095
{
	vector<int> Results;
	int T;
	int N;
	int Sum;
	int Count;

	void Check()
	{
		if (Sum == N)
		{
			++Count;
		}
		else if (Sum < N)
		{
			for (int i = 1; i <= 3; ++i)
			{
				Sum += i;
				Check();
				Sum -= i;
			}
		}
	}

	void Solve_9095()
	{
		cin >> T;
		Results.resize(T);
		for (int i = 0; i < T; ++i)
		{
			cin >> Results[i];
		}

		for (const int& num : Results)
		{
			Sum = 0;
			Count = 0;
			N = num;

			Check();

			cout << Count << endl;
		}
	}
}
