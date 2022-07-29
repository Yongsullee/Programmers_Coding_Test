#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;

    for (int i = 0; i < nums.size() - 2; i++)
    {
        for (int j = i + 1; j < nums.size() - 1; j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                int num = nums[i] + nums[j] + nums[k];
                int cnt = 0;
                for (int h = 2; h < num - 1; h++)
                {
                    if (num % h == 0)
                    {
                        cnt++;
                        break;
                    }
                    else
                    {
                        continue;
                    }
                }

                if (cnt == 0)
                    answer++;
            }
        }
    }

    return answer;
}