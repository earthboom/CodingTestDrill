/*
Quick Sort

분할 정복 (Divide and Conquer) 방식의 정렬 알고리즘 중 하나로, 평균적으로 빠른 성능을 보임
Pivot을 기준으로 배열을 나누고, 그 나눈 부분을 재귀적으로 정렬하는 방식

** 퀵 정렬의 동작 원리
1. Pivot 선택	: 배열에서 하나의 원소를 피벗으로 선택 (일반적으로 첫 번째 원소, 마지막 원소, 중앙 원소 등을 선택)
2. 배열 분할		: Pivot을 기준으로 배열을 두 부분으로 나눈다. Pivot보다 작은 원소는 왼쪽에, 큰 원소는 오른쪽에 배치
3. 재귀적 정렬	: Pivot을 기준으로 나누어진 두 부분에 대해 각각 퀵 정렬을 재귀적으로 수행. 이 과정은 배열의 크기가 1이 될 때까지 계속
4. 정렬 종료		: 더 이상 나눌 부분이 없으면, 배열이 정렬

** 퀵 정렬의 장, 단점

* 장점
	- 시간 복잡도		: 평균적으로 O(n log n). 최악의 경우에도 O(n^2). Pivot 선택을 잘하면 대부분의 경우 O(n log n) 에 가까운 성능을 보임
	- 공간 복잡도		: O(log n)로 다른 정렬 알고리즘에 비해 상대적으로 적은 추가 공간 사용
	- 비교적 빠른 성능	: 많은 경우에서 다른 정렬 알고리즘보다 빠름

* 단점
	- 최악의 경우 O(n^2) 가 될 수 있음. 예로 이미 정렬된 배열이거나 거의 정렬된 배열에서는 성능이 나쁨
	- 재귀적인 호출임으로, 재귀 깊이가 깊어지면 스택 오버플로우 발생의 여지가 있음

** 퀵 정렬의 동작 예시

[3, 6, 8, 10, 1, 2, 1] 

1. pivot을 3으로 선택
2. 3을 기준으로 배열을 나누면, [1, 2, 1] (작은 값)과 [6, 8, 9] (큰 값)로 나뉨
3. 각 부분에 대해 재귀적으로 퀵 정렬 계속 수행

*/

#include "QuickSort.h"

namespace QUICK_SORT
{
	// 배열을 나누는 함수 : pivot을 기준으로 배열을 분할
	int Partition(vector<int>& arr, int low, int high)
	{
		int pivot = arr[high];	// 마지막 원소를 pivot으로 선택
		int i = low - 1;	// pivot 보다 작은 원소의 마지막 인덱스

		for (int j = low; j < high; ++j)
		{
			if (arr[j] <= pivot)
			{
				++i;
				swap(arr[i], arr[j]);	// 작은 원소 앞으로 보내기
			}
		}

		swap(arr[i + 1], arr[high]);	// pivot을 적절한 위치로 이동
		return i + 1;	// Pivot 최종 위치 반환
	}

	void QuickSort(vector<int>& arr, int low, int high)
	{
		if (low < high)
		{
			// 배열을 두 부분으로 나눈 후, 각 부분을 재귀적으로 정렬
			int pi = Partition(arr, low, high);	// pivot 위치

			QuickSort(arr, low, pi - 1);	// pivot 왼쪽 부분 정렬
			QuickSort(arr, pi + 1, high);	// pivot 오른쪽 부분 정렬
		}
	}

	void QuickSort_Main()
	{
		int n = 0;
		cin >> n;

		int v = 0;
		vector<int> arr;
		for (int i = 0; i < n; ++i)
		{
			cin >> v;
			arr.emplace_back(v);
		}

		QuickSort(arr, 0, n-1);

		for (int i = 0; i < n; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
}