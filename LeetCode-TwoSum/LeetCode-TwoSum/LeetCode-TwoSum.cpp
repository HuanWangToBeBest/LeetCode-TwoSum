// LeetCode-TwoSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <math.h>
#include <unordered_map>
#include <algorithm>
using namespace std;
int* twoSum(int* nums, int numsSize, int target) {
	int i = 0, j = 0;
	int n = numsSize;
	int* result = NULL;
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			if (target == nums[i] + nums[j]) {
				result = (int*)malloc(sizeof(int) * 2);
				result[0] = i;
				result[1] = j;
				return result;
			}
		}
	}
	return result;
}
//����ⷨ����main����������׸����
//hash ����
int* twoSum1(int* nums, int numsSize, int target) {
	int min = 2147483647;
	int i = 0;
	for (i = 0; i < numsSize; i++) {
		if (nums[i] < min)
			min = nums[i];
	}
	int max = target - min;
	int len = max - min + 1;   //ȷ��hash����
	int *table = (int*)malloc(len * sizeof(int));
	int *indice = (int*)malloc(2 * sizeof(int));
	for (i = 0; i < len; i++) {
		table[i] = -1;         //hash��ֵ
	}
	for (i = 0; i < numsSize; i++) {
		if (nums[i] - min < len) {
			if (table[target - nums[i] - min] != -1) {        //�������Ϊtarget
				indice[0] = table[target - nums[i] - min];
				indice[1] = i;
				return indice;
			}
			table[nums[i] - min] = i;
		}
	}
	free(table);
	return indice;
}
//�ⷨ����
vector<int> twoSum2(vector<int> &numbers, int target) {
	vector<int> result;
	map<int, int> nummap;
	map<int, int>::iterator i;
	for (int i = 0; i < numbers.size(); i++)
	{
		nummap.insert(make_pair(numbers[i], i + 1));//map��key���numbers�����ֵ��value����±�
	}
	for (map<int, int >::iterator iter = nummap.begin(); iter != nummap.end(); iter++)
	{
		int value1 = iter->first;
		int value2 = target - value1;
		i = nummap.find(value2);
		if (i != nummap.end())
		{
			if (value1 + value2 == target)
			{
				if (value1 == value2)//���ҵ���ֵ�Ƿ�Ϊtarget�Ķ���֮һ�����Ƕ���֮һ���������2���ŷ���Ҫ��
				{
					vector<int>::iterator j;
					vector<int>::iterator k = find(numbers.begin(), numbers.end(), value1);
					if (k != numbers.end())//���Ƿ��������
					{
						j = find(k + 1, numbers.end(), value1);
						if (j != numbers.end())
						{
							result.push_back(k - numbers.begin() + 1);
							result.push_back(j - numbers.begin() + 1);
							return result;
						}
					}
				}
				else//�����Ƕ���֮һ��˵������������ͬ�±�Ĳ�ֵͬ���Ϊtarget����map��ȡ��������Ӧ������
				{
					result.push_back(min(nummap[value1], nummap[value2]));
					result.push_back(max(nummap[value1], nummap[value2]));
					return result;
				}

			}
		}
	}
	return result;
}
//�ⷨ�ģ�
vector<int> twoSum3(vector<int>& nums, int target) {
	unordered_map<int, int> m;
	for (int i = 0; i < nums.size(); ++i) {
		if (m.count(target - nums[i])) {
			return { i, m[target - nums[i]] };
		}
		m[nums[i]] = i;
	}
	return {};
}
int main()
{
    std::cout << "Hello World!\n"; 
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
