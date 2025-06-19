/*
https://www.acmicpc.net/problem/1182

문제
N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 주어진다. 
(1 ≤ N ≤ 20, |S| ≤ 1,000,000) 둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다. 
주어지는 정수의 절댓값은 100,000을 넘지 않는다.

출력
첫째 줄에 합이 S가 되는 부분수열의 개수를 출력한다.
*/

#include "Solve_1182.h"
#include <iostream>
#include <vector>

using namespace std;

int N, S;
int64_t C;
vector<int> P;

void DFS(int idx, int64_t sum);

void Solve_1182()
{
	cin >> N >> S;

	C = 0;
	P.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> P[i];
	}

	DFS(0, 0);

	// 공집합의 합이 0인 경우를 제외하여야 함
	// S==0 이면 dfs 가 빈 부분수열도 카운트했으므로 1을 빼주는 작업
	if (S == 0)
	{
		C--;
	}

	cout << C << endl;
}

// idx 번째 원소를 처리하면서 현재까지의 합을 sum에 유지
void DFS(int idx, int64_t sum)
{
	// 모든 원소에 대해 포함 / 미포함을 결정했을 때
	if (idx == N)
	{
		// 부분수열(비었을 수도 있음)의 합이 S이면 카운트
		if (sum == S)
		{
			++C;
		}
		return;
	}

	// 1. P[idx]를 포함시키는 분기
	DFS(idx + 1, sum + P[idx]);
	// 2. P[idx]를 제외하는 분기
	DFS(idx + 1, sum);
}