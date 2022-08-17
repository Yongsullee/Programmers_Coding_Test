#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    int lastNum = arr.front();
    
    answer.push_back(lastNum);
    for(int i=1; i<arr.size(); ++i)
    {
        if(arr[i] == lastNum)
            continue;
        else
        {
            lastNum = arr[i];
            
            answer.push_back(arr[i]);
        }
    }

    return answer;
}