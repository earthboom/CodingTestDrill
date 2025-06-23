/*
https://www.acmicpc.net/problem/3085

����
����̴� ����� ���� "������ (Bomboni)" ������ ����ߴ�.
���� ó���� N��Nũ�⿡ ������ ä�� ���´�. ������ ���� ��� ���� ���� ���� �ִ�. 
����̴� ������ ���� �ٸ� ������ �� ĭ�� ����. 
�� ���� �� ĭ�� ����ִ� ������ ���� ��ȯ�Ѵ�. 
����, ��� ���� ������ �̷���� �ִ� ���� �� ���� �κ�(�� �Ǵ� ��)�� �� ���� �� ������ ��� �Դ´�.

������ ä���� ���°� �־����� ��, ����̰� ���� �� �ִ� ������ �ִ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ������ ũ�� N�� �־�����. (3 �� N �� 50)
���� N�� �ٿ��� ���忡 ä���� �ִ� ������ ������ �־�����. �������� C, �Ķ����� P, �ʷϻ��� Z, ������� Y�� �־�����.
������ ���� �ٸ� ������ �� ĭ�� �����ϴ� �Է¸� �־�����.

���
ù° �ٿ� ����̰� ���� �� �ִ� ������ �ִ� ������ ����Ѵ�.
*/

#include "Solve_3085.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

namespace BP3085
{
	int N;
	vector<string> Matrix;

	int IsCheck()
	{
		int BestCount = 0;
		for (int i = 0; i < N; ++i)
		{
			int cnt = 1;
			for (int j = 1; j < N; ++j)
			{
				if (Matrix[i][j] == Matrix[i][j - 1])
				{
					++cnt;
				}
				else
				{
					BestCount = max(BestCount, cnt);
					cnt = 1;
				}
			}
			BestCount = max(BestCount, cnt);
		}

		for (int j = 0; j < N; ++j)
		{
			int cnt = 1;
			for (int i = 1; i < N; ++i)
			{
				if (Matrix[i][j] == Matrix[i - 1][j])
				{
					++cnt;
				}
				else
				{
					BestCount = max(BestCount, cnt);
					cnt = 1;
				}
			}
			BestCount = max(BestCount, cnt);
		}
		return BestCount;
	}

	void Solve_3085()
	{
		cin >> N;
		Matrix.resize(N);

		for (int i = 0; i < N; ++i)
		{
			cin >> Matrix[i];
		}

		int answer = 1;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (j + 1 < N && Matrix[i][j] != Matrix[i][j + 1])
				{
					swap(Matrix[i][j], Matrix[i][j + 1]);
					answer = max(answer, IsCheck());
					swap(Matrix[i][j], Matrix[i][j + 1]);
				}

				if (i + 1 < N && Matrix[i][j] != Matrix[i + 1][j])
				{
					swap(Matrix[i][j], Matrix[i + 1][j]);
					answer = max(answer, IsCheck());
					swap(Matrix[i][j], Matrix[i + 1][j]);
				}
			}
		}

		cout << answer << endl;
	}
}
