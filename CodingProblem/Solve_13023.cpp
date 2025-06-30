/*
https://www.acmicpc.net/problem/13023

BOJ �˰��� ķ������ �� N���� �����ϰ� �ִ�. ������� 0������ N-1������ ��ȣ�� �Ű��� �ְ�, �Ϻ� ������� ģ���̴�.

������ ������ ���� ģ�� ���踦 ���� ��� A, B, C, D, E�� �����ϴ��� ���غ����� �Ѵ�.

- A�� B�� ģ����.
- B�� C�� ģ����.
- C�� D�� ģ����.
- D�� E�� ģ����.

���� ���� ģ�� ���谡 �����ϴ��� ���ϴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ����� �� N (5 �� N �� 2000)�� ģ�� ������ �� M (1 �� M �� 2000)�� �־�����.

��° �ٺ��� M���� �ٿ��� ���� a�� b�� �־�����, a�� b�� ģ����� ���̴�. (0 �� a, b �� N-1, a �� b) ���� ģ�� ���谡 �� �� �̻� �־����� ���� ����.

���
������ ���ǿ� �´� A, B, C, D, E�� �����ϸ� 1�� ������ 0�� ����Ѵ�.
*/

#include "Solve_13023.h"
#include <iostream>
#include <vector>

using namespace std;

namespace BP13023
{
	int N, M;
	vector<int> RS[2000];	// ���� ����Ʈ

	bool DFS(int current, int depth, vector<bool>& visited)
	{
		if (depth == 5)
		{
			return true;
		}

		visited[current] = true;	// ���� ����� �湮 ó��

		// ���� ��� ģ���� ������� �湮
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

		visited[current] = false;	// ���� ����� �湮 ���
		return false;
	}

	void Solve_13023()
	{
		cin >> N >> M;

		for (int i = 0; i < M; ++i)
		{
			int a = 0, b = 0;
			cin >> a >> b;
			// ģ�� ����� �����
			RS[a].emplace_back(b);
			RS[b].emplace_back(a);
		}

		// �� ����� ���������� DFS Ž��
		for (int i = 0; i < N; ++i)
		{
			vector<bool> visited(N, false);	// �湮 ���� üũ
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