#include <string>
#include <vector>

using namespace std;

/*
    1. 각 sizes[i] 마다 sizes[i][0]과 sizes[1]을 비교
    2. 이 중 작은 수들 끼리 다시 비교 + 큰 수들끼리 다시 비교
    3. 각 최대 숫자들을 Multiply 하면 답이 나옵니다.
*/
int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int lessMax=0;
    int largerMax=0;
    for(int i=0; i< sizes.size(); ++i)
    {
        int w = sizes[i][0];
        int h = sizes[i][1];
        if(w < h)
        {
            if(lessMax < w)
                lessMax = w;
            if(largerMax < h)
                largerMax = h;
        }
        else
        {
            if(lessMax < h)
                lessMax = h;
            if(largerMax < w)
                largerMax = w;
        }
    }
    
    answer = lessMax * largerMax;
    
    return answer;
}