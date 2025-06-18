/*
https://www.acmicpc.net/problem/11723

����
����ִ� ������ S�� �־����� ��, �Ʒ� ������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.

add x		:	S�� x�� �߰��Ѵ�. (1 �� x �� 20) S�� x�� �̹� �ִ� ��쿡�� ������ �����Ѵ�.
remove x	:	S���� x�� �����Ѵ�. (1 �� x �� 20) S�� x�� ���� ��쿡�� ������ �����Ѵ�.
check x		:	S�� x�� ������ 1��, ������ 0�� ����Ѵ�. (1 �� x �� 20)
toggle x	:	S�� x�� ������ x�� �����ϰ�, ������ x�� �߰��Ѵ�. (1 �� x �� 20)
all			:	S�� {1, 2, ..., 20} ���� �ٲ۴�.
empty		:	S�� ���������� �ٲ۴�.

�Է�
ù° �ٿ� �����ؾ� �ϴ� ������ �� M (1 �� M �� 3,000,000)�� �־�����.

��° �ٺ��� M���� �ٿ� �����ؾ� �ϴ� ������ �� �ٿ� �ϳ��� �־�����.

���
check ������ �־���������, ����� ����Ѵ�.
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

	// Bit Mask �� ���� S ����
	// Bit i (0 <= i < 32)�̸� 1�̸� "���� i"�� ���տ� ���Ե� ����
	// �츮�� 1 <= x < 20�� ����ϹǷ�, Bit 1 ~ 20�� ����ϰ� Bit 0�� ����
	unsigned int S = 0;
	
	int M = 0;	// ���� �� ����
	cin >> M;

	int x = 0;
	string cmd = "";

	while (M--)
	{
		cin >> cmd;

		if (cmd == "add")
		{
			// add x : S�� x�� �߰�
			cin >> x;
			// Bit x�� 1�� ���� (�̹� 1�̸� �״��)
			// ex) x=5 -> 1 << 5 = 0x100000
			S |= (1 << x);
		}
		else if (cmd == "remove")
		{
			// remove x : S���� x�� ����
			cin >> x;
			// Bit x�� 0���� Ŭ���� (�̹� 0�̸� �״��)
			// ~(1 << x) �� Bit x�� 0�̰� ������ 1�� ����ũ
			S &= ~(1 << x);
		}
		else if (cmd == "check")
		{
			// check x : S�� x�� ������ 1, ������ 0 ���
			cin >> x;
			// S & (1 << x) �� 0�� �ƴϸ� Bit X�� 1 -> x ����
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
			// toggle x : x�� ������ ����, ������ �߰�
			cin >> x;
			// XOR �������� Bit x�� ����
			S ^= (1 << x);
		}
		else if (cmd == "all")
		{
			// all : S�� {1, 2, ... , 20} ���� ����
			// (1 << 21) - 1 �� Bit 0 ���� 20���� ���� 1 -> elements 1 ~ 20 ��� ����
			S = (1 << 21) - 1;
		}
		else if (cmd == "empty")
		{
			// empty : S�� ���������� (��� Bit 0)
			S = 0;
		}
	}
}