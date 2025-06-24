/*
Dynamic Programming ( DP )

������ ������ �� ���� ���� ������ ������ Ǫ�� �˰��� ���
�� ����� "��ġ�� �κ� ����"�� "���� �κ� ����"�� �̿��� ȿ�������� ���� �ذ�

�⺻ ����
1. Overlapping Subproblems (��ġ�� �κ� ����)
- ���� �ذ� �������� ���� ���� ������ ���� �� ���Ǵ� ��찡 �ִ�.
- DP�� �� ���� ������ ����� ������ �ߺ� ����� ȸ��

2. Optimal Substructure (���� �κ� ����)
- ���� �ذ� ������ ����� ���� �������� �������� �ذ��ϴ� ������� �����ȴٴ� Ư���� ����
- ��, ū ������ ���� ������ ������ Ǯ �� �ְ�, �� ���� �������� �����ظ� ���� ū ������ �ذ��� �� �ִٴ� ��

�⺻ ���̵��
1. Top-Down ��� (��� + �޸����̼�)
- ���� �ذ��Ϸ� �� ��, ū ������ ��������� ������, �� ���� ������ ����� ������ �ξ� ���� ������ �ٽ� ������� �ʵ��� ��
- Memoization : �̹� ����� ����� �����صΰ�, ���� ����� �ݺ����� �ʵ��� ��

2. Bottom-Up ��� (�ݺ��� + ���̺�)
- ���� �������� �������� ����Ͽ� ���� ������ �ذ�
- Tabulating : ���� ������ ����� ���̺� �����ϰ�, �̸� ������� ���������� ���� ������ �ذ�

DP ����ؾ� �� ��
1. ������ Ǯ�� �������� ���� �������� �ݺ������� ���Ǵ� ���
2. ū ������ ���� ������ ������ �� �ִ� ���
3. ����ȭ ���� ( ex : �ִ밪 / �ּҰ� ���ϴ� ���� )
*/

#include <iostream>
#include <vector>

using namespace std;

namespace DP
{
	vector<int> memo;

	// ex) �Ǻ���ġ ����
	// ��ǥ���� DP ����

	// Top - Down ��� 
	int fibo_TopDown(int n)
	{
		if (n <= 1)
		{
			return n;
		}

		if (memo[n] != -1)	// �̹� ���� ���� ������ �� ���� ��ȯ
		{
			return memo[n];
		}

		memo[n] = fibo_TopDown(n - 1) + fibo_TopDown(n - 2);	// ��� �� memoization
		return memo[n];
	}

	void Fibonacci_TopDown()
	{
		int n = 10;
		memo.resize(n + 1, -1);	// memoization �迭 �ʱ�ȭ
		cout << "Fibonacci number at position " << n << "is " << fibo_TopDown(n) << endl;
	}

	// Down - Top ���
	int fibo_BottomUp(int n)
	{
		vector<int> dp(n + 1);
		dp[0] = 0;
		dp[1] = 1;
		for (int i = 2; i <= n; ++i)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}

	void Fibonacci_BottomUp()
	{
		int n = 10;
		cout << "Fibonacci number at position " << n << "is " << fibo_BottomUp(n) << endl;
	}
}