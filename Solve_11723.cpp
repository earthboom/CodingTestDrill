/*
https://www.acmicpc.net/problem/11723

문제
비어있는 공집합 S가 주어졌을 때, 아래 연산을 수행하는 프로그램을 작성하시오.

add x		:	S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
remove x	:	S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
check x		:	S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
toggle x	:	S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
all			:	S를 {1, 2, ..., 20} 으로 바꾼다.
empty		:	S를 공집합으로 바꾼다.

입력
첫째 줄에 수행해야 하는 연산의 수 M (1 ≤ M ≤ 3,000,000)이 주어진다.

둘째 줄부터 M개의 줄에 수행해야 하는 연산이 한 줄에 하나씩 주어진다.

출력
check 연산이 주어질때마다, 결과를 출력한다.
*/


#include "Solve_11723.h"
#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

void Solve_11723()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// Bit Mask 로 집합 S 구현
	// Bit i (0 <= i < 32)이면 1이면 "원소 i"가 집합에 포함된 상태
	// 우리는 1 <= x < 20만 사용하므로, Bit 1 ~ 20을 사용하고 Bit 0은 무시
	unsigned int S = 0;
	
	int M = 0;	// 연산 총 개수
	cin >> M;

	int x = 0;
	string cmd = "";

	while (M--)
	{
		cin >> cmd;

		if (cmd == "add")
		{
			// add x : S에 x를 추가
			cin >> x;
			// Bit x를 1로 세팅 (이미 1이면 그대로)
			// ex) x=5 -> 1 << 5 = 0x100000
			S |= (1 << x);
		}
		else if (cmd == "remove")
		{
			// remove x : S에서 x를 제거
			cin >> x;
			// Bit x를 0으로 클리어 (이미 0이면 그대로)
			// ~(1 << x) 는 Bit x만 0이고 나머지 1인 마스크
			S &= ~(1 << x);
		}
		else if (cmd == "check")
		{
			// check x : S에 x가 있으면 1, 없으면 0 출력
			cin >> x;
			// S & (1 << x) 가 0이 아니면 Bit X가 1 -> x 포함
			if (S & (1 << x))
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else if (cmd == "toggle")
		{
			// toggle x : x가 있으면 제거, 없으면 추가
			cin >> x;
			// XOR 연산으로 Bit x만 반전
			S ^= (1 << x);
		}
		else if (cmd == "all")
		{
			// all : S를 {1, 2, ... , 20} 으로 설정
			// (1 << 21) - 1 은 Bit 0 부터 20까지 전부 1 -> elements 1 ~ 20 모두 포함
			S = (1 << 21) - 1;
		}
		else if (cmd == "empty")
		{
			// empty : S를 공집합으로 (모든 Bit 0)
			S = 0;
		}
	}
}