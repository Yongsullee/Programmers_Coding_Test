#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements)
{

    set<int> s;

    for (int i = 1; i <= (int)elements.size(); ++i)
    {
        // 최소 연속 부분 수열 개수 = 1
        int left = 0;
        // 최대 연속 부분 수열 개수 = elements.size()
        int right = left + i;

        // 왼쪽 경계가 배열의 마지막 원소를 가리킬 때 까지 진행
        while (left < elements.size())
        {
            int sum = 0;
            for (int j = left; j < right; ++j)
            {
                sum += elements[(j % (int)elements.size())];
            }
            // set 컨테이너에 삽입(중복 불가)
            s.insert(sum);

            left++;
            right++;
        }
    }

    return s.size();
}