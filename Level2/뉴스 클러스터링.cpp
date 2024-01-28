#include <string>
#include <algorithm>
#include <cctype>
#include <map>

using namespace std;

int solution(string str1, string str2)
{
    int answer = 0;
    map<string, pair<int, int>> m;
    double unionSet = 0;
    double jointSet = 0;

    for (int i = 0; i < str1.length() - 1; ++i)
    {
        string tmp = str1.substr(i, 2);
        transform(begin(tmp), end(tmp), begin(tmp), ::toupper);
        if (isalpha(tmp[0]) && isalpha(tmp[1]))
        {
            m[tmp].first++;
            unionSet++;
        }
    }

    for (int i = 0; i < str2.length() - 1; ++i)
    {
        string tmp = str2.substr(i, 2);
        transform(begin(tmp), end(tmp), begin(tmp), ::toupper);
        if (isalpha(tmp[0]) && isalpha(tmp[1]))
        {
            auto it = m.find(tmp);
            if (it != end(m) && it->second.first > 0)
            {
                it->second.first--;
                jointSet++;
            }
            else
            {
                unionSet++;
            }
        }
    }

    if (unionSet == 0)
    {
        return 65536;
    }

    answer = (int)((jointSet / unionSet) * 65536);
    return answer;
}
