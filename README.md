# LeetCode-TwoSum
暴力破解法：
#include <iostream>
#include <stdio.h>
using namespace std;
int* twoSum(int* nums, int numsSize, int target) {
    int i = 0, j = 0;
    int n = numsSize;
    int* result = NULL;
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(target == nums[i] + nums[j]) {
                result = (int*)malloc(sizeof(int) * 2);
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return result;
}
void mian()
{
     int nums = {2,7,11,15};
     int numsSize = 4;
     int target = 9;
     int result = twoSum(nums,numsSize,target);
     cout <<  result[0] << endl;
     cout << result[1] << endl;
     cin.get();
} 
//下面解法共用main函数，不在赘述！
hash 法：
int* twoSum(int* nums, int numsSize, int target) {
    int min = 2147483647;
    int i = 0;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] < min)
            min = nums[i];
    }
    int max = target - min;
    int len = max - min + 1;   //确定hash长度
    int *table = (int*)malloc(len*sizeof(int));
    int *indice = (int*)malloc(2*sizeof(int));
    for (i = 0; i < len; i++) {
        table[i] = -1;         //hash初值
    }
    for (i = 0; i < numsSize; i++) {
        if (nums[i]-min < len) {
            if (table[target-nums[i]-min] != -1) {        //满足相加为target
                indice[0] = table[target-nums[i] - min];
                indice[1] = i;
                return indice;
            }
            table[nums[i]-min] = i;
        }
    }
    free(table);
    return indice;
}
解法三：
vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
        map<int,int> nummap;
        map<int,int>::iterator i;
        for(int i = 0 ;i < numbers.size(); i++)
        {
             nummap.insert(make_pair(numbers[i],i+1));//map中key存放numbers数组的值，value存放下标
        }     
        for(map<int ,int >::iterator iter = nummap.begin(); iter!= nummap.end(); iter++)
        {
                int value1 = iter->first;
                int value2 = target - value1;
                i = nummap.find(value2);
                if( i != nummap.end())
                {
                    if(value1 + value2 == target)
                    {
                        if(value1 == value2)//看找到的值是否为target的二分之一，若是二分之一，必须存在2个才符合要求
                        {
                            vector<int>::iterator j;
                            vector<int>::iterator k = find (numbers.begin(), numbers.end(), value1);
                            if(k!= numbers.end())//看是否存在两个
                            {
                                j = find(k+1, numbers.end(), value1);
                                if(j!= numbers.end())
                                {
                                    result.push_back(k-numbers.begin()+1);
                                    result.push_back(j-numbers.begin()+1);
                                    return result;
                                }
                            }
                        }
                        else//若不是二分之一，说明存在两个不同下标的不同值相加为target，从map中取出他们相应的索引
                        {   
                             result.push_back(min(nummap[value1],nummap[value2]));                           
                             result.push_back(max(nummap[value1],nummap[value2]));
                             return result;
                        }

                    }
                }
        }
        return result;
    }
    解法四：
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            if (m.count(target - nums[i])) {
                return {i, m[target - nums[i]]};
            }
            m[nums[i]] = i;
        }
        return {};
    }
--------------------- 
作者：Mark-Wang 
来源：CSDN 
原文：https://blog.csdn.net/wanghuan1990519wha/article/details/88981498 
版权声明：本文为博主原创文章，转载请附上博文链接！
