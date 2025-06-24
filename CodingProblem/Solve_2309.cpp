/*
https://www.acmicpc.net/problem/2309

����
�պ� ���� �ϰ� �����̵�� �Բ� ��ȭ�Ӱ� ��Ȱ�ϰ� �ִ� �鼳���ֿ��� ���Ⱑ ã�ƿԴ�. 
�ϰ��� ��ġ�� ���ƿ� �����̰� �ϰ� ���� �ƴ� ��ȩ ���̾��� ���̴�.

��ȩ ���� �����̴� ��� �ڽ��� "�鼳 ���ֿ� �ϰ� ������"�� ���ΰ��̶�� �����ߴ�. 
�پ ������ �������� ������ �ִ� �鼳���ִ�, ���ེ���Ե� �ϰ� �������� Ű�� ���� 100�� ���� ����� �´�.

��ȩ �������� Ű�� �־����� ��, �鼳���ָ� ���� �ϰ� �����̸� ã�� ���α׷��� �ۼ��Ͻÿ�.

�Է�
��ȩ ���� �ٿ� ���� �����̵��� Ű�� �־�����. �־����� Ű�� 100�� ���� �ʴ� �ڿ����̸�, ��ȩ �������� Ű�� ��� �ٸ���, ������ ������ ���� ������ ��쿡�� �ƹ��ų� ����Ѵ�.

���
�ϰ� �������� Ű�� ������������ ����Ѵ�. �ϰ� �����̸� ã�� �� ���� ���� ����.
*/

#include "Solve_2309.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

namespace BP2309
{
	void Solve_2309()
	{
		int total = 0;
		vector<int> Heights;
		while (Heights.size() < 9)
		{
			int n = 0;
			cin >> n;

			if (n >= 100)
			{
				continue;
			}

			vector<int>::iterator it = find(Heights.begin(), Heights.end(), n);
			if (it == Heights.end())
			{
				total += n;
				Heights.emplace_back(n);
			}
		}

		cout << endl;

		int remove_0 = -1;
		int remove_1 = -1;
		for (int i = 0; i < 9; ++i)
		{
			for (int j = i + 1; j < 9; ++j)
			{
				int sum = total - (Heights[i] + Heights[j]);
				if (sum == 100)
				{
					remove_0 = i;
					remove_1 = j;
				}
			}

			if (remove_0 >= 0 && remove_1 >= 0)
			{
				break;
			}
		}

		vector<int> Results;
		for (int i = 0; i < 9; ++i)
		{
			if (i == remove_0 || i == remove_1)
			{
				continue;
			}

			Results.emplace_back(Heights[i]);
		}

		std::sort(Results.begin(), Results.end());

		for (const int& height : Results)
		{
			cout << height << endl;
		}
	}
}