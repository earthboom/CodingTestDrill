/*
https://www.acmicpc.net/problem/13023

BOJ 알고리즘 캠프에는 총 N명이 참가하고 있다. 사람들은 0번부터 N-1번으로 번호가 매겨져 있고, 일부 사람들은 친구이다.

오늘은 다음과 같은 친구 관계를 가진 사람 A, B, C, D, E가 존재하는지 구해보려고 한다.

- A는 B와 친구다.
- B는 C와 친구다.
- C는 D와 친구다.
- D는 E와 친구다.

위와 같은 친구 관계가 존재하는지 안하는지 구하는 프로그램을 작성하시오.

입력
첫째 줄에 사람의 수 N (5 ≤ N ≤ 2000)과 친구 관계의 수 M (1 ≤ M ≤ 2000)이 주어진다.

둘째 줄부터 M개의 줄에는 정수 a와 b가 주어지며, a와 b가 친구라는 뜻이다. (0 ≤ a, b ≤ N-1, a ≠ b) 같은 친구 관계가 두 번 이상 주어지는 경우는 없다.

출력
문제의 조건에 맞는 A, B, C, D, E가 존재하면 1을 없으면 0을 출력한다.
*/

#include "Solve_13023.h"
#include <iostream>
#include <vector>

using namespace std;

namespace BP13023
{
	int N, M;
	vector<int> RS[2000];	// 인접 리스트

	bool DFS(int current, int depth, vector<bool>& visited)
	{
		if (depth == 5)
		{
			return true;
		}

		visited[current] = true;	// 현재 사람을 방문 처리

		// 현재 사람 친구인 사람들을 방문
		for (const int& next : RS[current])
		{
			if (visited[next] == false)
			{
				if (DFS(next, depth + 1, visited))
				{
					return true;
				}
			}
		}

		visited[current] = false;	// 현재 사람을 방문 취소
		return false;
	}

	void Solve_13023()
	{
		cin >> N >> M;

		for (int i = 0; i < M; ++i)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			// 친구 관계는 양방향
			RS[a].emplace_back(b);
			RS[b].emplace_back(a);
		}

		// 각 사람을 시작점으로 DFS 탐색
		for (int i = 0; i < N; ++i)
		{
			vector<bool> visited(N, false);	// 방문 여부 체크
			if (DFS(i, 1, visited))	
			{
				cout << 1 << endl;
				return;
			}
		}

		cout << 0 << endl;
		return;
	}
}