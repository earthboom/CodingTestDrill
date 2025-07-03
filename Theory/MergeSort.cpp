/*
Merge Sort (병합 정렬)

분할 정복(Devide and Conquer) 받식을 사용하는 정렬 알고리즘
큰 문제를 작은 문제로 나누어 해결한 후, 다시 그 작은 문제들을 결합하여 해결하는 방식으로 동작

** 병합 정렬 동작 원리
주어진 배열을 두 개의 부분으로 나누고, 그 부분들을 각각 정렬한 후, 두 정렬된 부분을 다시 병합(Merge)하는 방식으로 동작

1. 배열을 반으로 나누기	: 먼저 배열을 절반으로 나눔
2. 재귀적으로 나누기		: 각 부분을 더 이상 나눌 수 없을 때까지 계속 나눔 (이때 크기가 1인 배열은 이미 정렬된 상태)
3. 병합하기				: 나누어진 배열들을 정렬된 상태로 병합 ( 두 배열을 하나씩 비교하며 정렬하여 병합 )
4. 정렬된 배열 반환		: 병합 과정을 통해 정렬된 배열을 반환

** 병합 정렬의 특징
- 시간 복잡도	: 최악의 경우에도 O(n log n). 항상 일정한 시간 복잡도를 가짐
- 공간 복잡도	: O(n). 배열을 나누기 위해 추가 공간 사용
- 안정성			: 안정적인 정렬 알고리즘 (같은 값을 순서가 유지됨)

** 병합 정렬의 동작 예시

[ 38, 27, 43, 3, 9, 82, 10 ]을 정렬한다고 가정
1. 배열을 반으로 나눈다.	: [38, 27, 43], [3, 9, 82, 10]
2. 각각을 더 작은 부분으로 나누고, 배열 크기가 1이 되면 정렬이 완료
3. 두 배열을 병합하면서 정렬된 상태로 합친다.

*/

#include "MergeSort.h"

namespace MERGE_SORT
{
	void Merge(vector<int>& arr, int left, int mid, int right)
	{
		int n1 = mid - left + 1;  // 왼쪽 부분 배열 크기
		int n2 = right - mid;     // 오른쪽 부분 배열 크기

		// 왼, 오른쪽 부분 배열 각각 생성
		vector<int> leftArr(n1), rightArr(n2);

		// 왼쪽 부분 배열 채우기
		for (int i = 0; i < n1; i++)
		{
			leftArr[i] = arr[left + i];
		}

		// 오른쪽 부분 배열 채우기
		for (int i = 0; i < n2; i++)
		{
			rightArr[i] = arr[mid + 1 + i];
		}

		// 두 배열을 병합해, arr 배열에 정렬된 상태로 저장
		int i = 0, j = 0, k = left;
		while (i < n1 && j < n2)
		{
			if (leftArr[i] <= rightArr[j])
			{
				arr[k] = leftArr[i];
				i++;
			}
			else
			{
				arr[k] = rightArr[j];
				j++;
			}
			k++;
		}

		// 왼쪽 배열에 남은 원소들 처리
		while (i < n1) 
		{
			arr[k] = leftArr[i];
			i++;
			k++;
		}

		// 오른쪽 배열에 남은 원소들 처리
		while (j < n2) 
		{
			arr[k] = rightArr[j];
			j++;
			k++;
		}
	}

	void MergeSort(vector<int>& arr, int left, int right)
	{
		if (left < right)
		{
			int mid = left + (right - left) / 2;	// 중간 지점 계산

			MergeSort(arr, left, mid);		// 왼쪽 부분 정렬
			MergeSort(arr, mid + 1, right);	// 오른쪽 부분 정렬
			Merge(arr, left, mid, right);	// 병합
		}
	}

	void MergeSort_Main()
	{
		int n = 0;
		cin >> n;

		vector<int> arr(n, 0);
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}

		MergeSort(arr, 0, n - 1);

		for (const int& i : arr)
		{
			cout << i << " ";
		}
		cout << endl;
	}
}