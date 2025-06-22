/*
Dynamic Programming ( DP )

복잡한 문제를 더 작은 하위 문제로 나누어 푸는 알고리즘 기법
이 방식은 "겹치는 부분 문제"와 "최적 부분 구조"를 이용해 효율적으로 문제 해결

기본 개념
1. Overlapping Subproblems (겹치는 부분 문제)
- 문제 해결 과정에서 같은 하위 문제가 여러 번 계산되는 경우가 있다.
- DP는 이 하위 문제의 결과를 저장해 중복 계산을 회피

2. Optimal Substructure (최적 부분 구조)
- 문제 해결 최적의 방법은 하윔 누제들을 최적으로 해결하는 방법으로 구성된다는 특성을 지님
- 즉, 큰 문제를 작은 문제로 나누어 풀 수 있고, 그 작은 문제들을 최적해를 합쳐 큰 문제를 해결할 수 있다는 뜻

기본 아이디어
1. Top-Down 방식 (재귀 + 메모제이션)
- 문제 해겨하려 할 때, 큰 문제를 재귀적으로 나누고, 각 하위 문제의 결과를 저장해 두어 같은 문제를 다시 계산하지 않도록 함
- Memoization : 이미 계산한 결과를 저장해두고, 동일 계산을 반복하지 않도록 함

2. Bottom-Up 방식 (반복문 + 테이블)
- 하위 문제부터 차근차근 계산하여 최종 문제를 해결
- Tabulating : 하위 문제의 결과를 테이블에 저장하고, 이를 기반으로 점차적으로 상위 문제를 해결

DP 사용해야 할 때
1. 문제의 풀이 과정에서 하위 문제들이 반복적으로 계산되는 경우
2. 큰 문제를 작은 문제로 분할할 수 있는 경우
3. 최적화 문제 ( ex : 최대값 / 최소값 구하는 문제 )
*/

#include <iostream>
#include <vector>

using namespace std;

namespace DP
{
	vector<int> memo;

	// ex) 피보나치 수열
	// 대표적인 DP 문제

	// Top - Down 방식 
	int fibo_TopDown(int n)
	{
		if (n <= 1)
		{
			return n;
		}

		if (memo[n] != -1)	// 이미 계산된 값이 있으면 그 값을 반환
		{
			return memo[n];
		}

		memo[n] = fibo_TopDown(n - 1) + fibo_TopDown(n - 2);	// 계산 후 memoization
		return memo[n];
	}

	void Fibonacci_TopDown()
	{
		int n = 10;
		memo.resize(n + 1, -1);	// memoization 배열 초기화
		cout << "Fibonacci number at position " << n << "is " << fibo_TopDown(n) << endl;
	}

	// Down - Top 방식
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