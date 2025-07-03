/*
Merge Sort (���� ����)

���� ����(Devide and Conquer) �޽��� ����ϴ� ���� �˰���
ū ������ ���� ������ ������ �ذ��� ��, �ٽ� �� ���� �������� �����Ͽ� �ذ��ϴ� ������� ����

** ���� ���� ���� ����
�־��� �迭�� �� ���� �κ����� ������, �� �κе��� ���� ������ ��, �� ���ĵ� �κ��� �ٽ� ����(Merge)�ϴ� ������� ����

1. �迭�� ������ ������	: ���� �迭�� �������� ����
2. ��������� ������		: �� �κ��� �� �̻� ���� �� ���� ������ ��� ���� (�̶� ũ�Ⱑ 1�� �迭�� �̹� ���ĵ� ����)
3. �����ϱ�				: �������� �迭���� ���ĵ� ���·� ���� ( �� �迭�� �ϳ��� ���ϸ� �����Ͽ� ���� )
4. ���ĵ� �迭 ��ȯ		: ���� ������ ���� ���ĵ� �迭�� ��ȯ

** ���� ������ Ư¡
- �ð� ���⵵	: �־��� ��쿡�� O(n log n). �׻� ������ �ð� ���⵵�� ����
- ���� ���⵵	: O(n). �迭�� ������ ���� �߰� ���� ���
- ������			: �������� ���� �˰��� (���� ���� ������ ������)

** ���� ������ ���� ����

[ 38, 27, 43, 3, 9, 82, 10 ]�� �����Ѵٰ� ����
1. �迭�� ������ ������.	: [38, 27, 43], [3, 9, 82, 10]
2. ������ �� ���� �κ����� ������, �迭 ũ�Ⱑ 1�� �Ǹ� ������ �Ϸ�
3. �� �迭�� �����ϸ鼭 ���ĵ� ���·� ��ģ��.

*/

#include "MergeSort.h"

namespace MERGE_SORT
{
	void Merge(vector<int>& arr, int left, int mid, int right)
	{
		int n1 = mid - left + 1;  // ���� �κ� �迭 ũ��
		int n2 = right - mid;     // ������ �κ� �迭 ũ��

		// ��, ������ �κ� �迭 ���� ����
		vector<int> leftArr(n1), rightArr(n2);

		// ���� �κ� �迭 ä���
		for (int i = 0; i < n1; i++)
		{
			leftArr[i] = arr[left + i];
		}

		// ������ �κ� �迭 ä���
		for (int i = 0; i < n2; i++)
		{
			rightArr[i] = arr[mid + 1 + i];
		}

		// �� �迭�� ������, arr �迭�� ���ĵ� ���·� ����
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

		// ���� �迭�� ���� ���ҵ� ó��
		while (i < n1) 
		{
			arr[k] = leftArr[i];
			i++;
			k++;
		}

		// ������ �迭�� ���� ���ҵ� ó��
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
			int mid = left + (right - left) / 2;	// �߰� ���� ���

			MergeSort(arr, left, mid);		// ���� �κ� ����
			MergeSort(arr, mid + 1, right);	// ������ �κ� ����
			Merge(arr, left, mid, right);	// ����
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