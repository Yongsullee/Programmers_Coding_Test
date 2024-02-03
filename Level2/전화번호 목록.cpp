// unordered_set 활용 : 해시 자료구조 활용 문제, 하지만 트라이 자료구조 혹은 문자열 정렬을 통해 풀이하는게 더 효율적인 방법을 보임...

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

bool solution(vector<string> phone_book)
{
    unordered_set<string> us;

    for (int i = 0; i < (int)phone_book.size(); ++i)
        us.insert(phone_book[i]);

    for (int i = 0; i < (int)phone_book.size(); ++i)
    {
        string num = "";
        for (int j = 0; j < (int)phone_book[i].size(); ++j)
        {
            num += phone_book[i][j];
            auto it = us.find(num);
            if (it != end(us) && num != phone_book[i])
            {
                return false;
            }
        }
    }

    return true;
}