#include <string>
#include <vector>

using namespace std;

// [0 ~ 9] = {false,};
vector<bool> b(10, false);

int solution(vector<int> numbers)
{
    int answer = -1;

    // 1. numbers 순회하며 항목 체크
    for (int i = 0; i < numbers.size(); ++i)
    {
        int index = numbers[i];

        b[index] = true;
    }

    // 2. false인 index를 더해줍니다.
    for (int i = 0; i < b.size(); ++i)
    {
        if (b[i] == true)
            continue;
        else
            answer += i;
    }

    return answer + 1;
}