/*
https://www.acmicpc.net/problem/3085

문제
상근이는 어렸을 적에 "봄보니 (Bomboni)" 게임을 즐겨했다.
가장 처음에 N×N크기에 사탕을 채워 놓는다. 사탕의 색은 모두 같지 않을 수도 있다. 
상근이는 사탕의 색이 다른 인접한 두 칸을 고른다. 
그 다음 고른 칸에 들어있는 사탕을 서로 교환한다. 
이제, 모두 같은 색으로 이루어져 있는 가장 긴 연속 부분(행 또는 열)을 고른 다음 그 사탕을 모두 먹는다.

사탕이 채워진 상태가 주어졌을 때, 상근이가 먹을 수 있는 사탕의 최대 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 보드의 크기 N이 주어진다. (3 ≤ N ≤ 50)
다음 N개 줄에는 보드에 채워져 있는 사탕의 색상이 주어진다. 빨간색은 C, 파란색은 P, 초록색은 Z, 노란색은 Y로 주어진다.
사탕의 색이 다른 인접한 두 칸이 존재하는 입력만 주어진다.

출력
첫째 줄에 상근이가 먹을 수 있는 사탕의 최대 개수를 출력한다.
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
