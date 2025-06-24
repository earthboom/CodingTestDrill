/*
https://www.acmicpc.net/problem/11726

문제
2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

아래 그림은 2×5 크기의 직사각형을 채운 한 가지 방법의 예이다.

입력
첫째 줄에 n이 주어진다. (1 ≤ n ≤ 1,000)

출력
첫째 줄에 2×n 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지를 출력한다.
*/

#include "Solve_11726.h"
#include <iostream>
#include <vector>

using namespace std;

namespace BP11726
{
	void Solve_11726()
	{
		const int Value = 10007;
		
		int N = 0;
		cin >> N;

		// DP[i] 는 2 x i 크기의 직사각형을 채우는 방법의 수를 의미 (이 생각을 잘 떠올리지 못하고 있음)
		vector<int> DP(N + 1, 0);	// N + 1 크기로 생성

		DP[1] = 1;	// 2 x 1 크기는 1가지 방법으로 채울 수 있음
		if (N > 1)
		{
			DP[2] = 2;	// 2 x 2 크기는 2가지 방법으로 채울 수 있음
		}

		// 점화식
		for (int i = 3; i <= N; ++i)
		{
			DP[i] = (DP[i - 1] + DP[i - 2]) % Value;
		}

		cout << DP[N] << endl;
	}
}