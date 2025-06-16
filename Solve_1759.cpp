/*
https://www.acmicpc.net/problem/1759

��ȣ �����

����
�ٷ� ���� �ֹ��� ������ �� ���踦 �ָӴϿ� ���� ä �����ϰ� ����� �� ������ Ȳ���� ��Ȳ�� ������ ��������, 702ȣ�� ���ο� ���� �ý����� ��ġ�ϱ�� �Ͽ���. 
�� ���� �ý����� ���谡 �ƴ� ��ȣ�� �����ϰ� �Ǿ� �ִ� �ý����̴�.

��ȣ�� ���� �ٸ� L���� ���ĺ� �ҹ��ڵ�� �����Ǹ� �ּ� �� ���� ����(a, e, i, o, u)�� �ּ� �� ���� �������� �����Ǿ� �ִٰ� �˷��� �ִ�. 
���� ���ĵ� ���ڿ��� ��ȣ�ϴ� �������� �������� �̷�� ���� ��ȣ�� �̷�� ���ĺ��� ��ȣ���� �����ϴ� ������ �迭�Ǿ��� ���̶�� �����ȴ�. 
��, abc�� ���ɼ��� �ִ� ��ȣ������ bac�� �׷��� �ʴ�.

�� ���� �ý��ۿ��� �������� ��ȣ�� ������� ���� ������ ������ C������ �ִٰ� �Ѵ�. 
�� ���ĺ��� �Լ��� �ν�, ���� ������ �������� �濡 ħ���ϱ� ���� ��ȣ�� ������ ������ �Ѵ�. 
C���� ���ڵ��� ��� �־����� ��, ���ɼ� �ִ� ��ȣ���� ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �� ���� L, C�� �־�����. (3 �� L �� C �� 15) ���� �ٿ��� C���� ���ڵ��� �������� ���еǾ� �־�����. 
�־����� ���ڵ��� ���ĺ� �ҹ����̸�, �ߺ��Ǵ� ���� ����.

���
�� �ٿ� �ϳ���, ���������� ���ɼ� �ִ� ��ȣ�� ��� ����Ѵ�.

*/

#include "Solve_1759.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

namespace SV1759
{
	int L, T;
	int VMax, CMax;
	vector<char> Alphabets;
	vector<char> Results;
	string vowels;

	void Recursion_1759(int depth);
	int VowelExtration_1759();

	void Recursion_1759(int depth)
	{
		if (depth == L)
		{
			int vowelCount = VowelExtration_1759();
			int ConsonantCount = L - vowelCount;

			if (vowelCount >= VMax && ConsonantCount >= CMax)
			{
				for (int i = 0; i < L; ++i)
				{
					cout << Results[i];
				}
				cout << endl;
			}

			return;
		}

		for (int i = 0; i < T; ++i)
		{
			if (depth > 0 && Results[depth - 1] >= Alphabets[i])
			{
				continue;
			}

			Results[depth] = Alphabets[i];
			Recursion_1759(depth + 1);
		}
	}

	int VowelExtration_1759()
	{
		int count = 0;
		for (const char& c : Results)
		{
			if (vowels.find(c) != string::npos)
			{
				++count;
			}
		}
		return count;
	}
}

using namespace SV1759;

void Solve_1759()
{
	cin >> L >> T;
	Alphabets.resize(T);
	Results.resize(L);
	for (int i = 0; i < T; ++i)
	{
		cin >> Alphabets[i];
	}

	sort(Alphabets.begin(), Alphabets.end());

	vowels = "aeiou";
	VMax = 1;
	CMax = 2;
	
	Recursion_1759(0);
}
