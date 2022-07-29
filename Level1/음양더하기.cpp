#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs)
{
    int answer = 0;

    // 반복자 사용
    int index = 0;
    for (auto it = begin(absolutes); it != end(absolutes); ++it)
    {
        if (signs[index++] == true)
            answer += (*it);
        else
            answer -= (*it);
    }

    return answer;
}