#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string new_id)
{
    string answer = "";
    int i = 0;
    // step 1: 대문자를 소문자로 치환
    for (i = 0; i < new_id.length(); i++)
    {
        if (new_id[i] >= 'A' && new_id[i] <= 'Z')
            new_id[i] = tolower(new_id[i]);
    }
    // step 2: 소문자, 숫자, 빼기, 밑줄, 마침표만 answer에 추가
    for (i = 0; i < new_id.length(); i++)
    {
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
            answer.push_back(new_id[i]);
    }
    // step 3: 마침표가 2번 이상 연속되면 하나 지우기
    i = 1;
    while (i < answer.length())
    {
        if (answer[i - 1] == '.' && answer[i] == '.')
        {
            answer.erase(answer.begin() + i);
            continue;
        }
        i++;
    }
    // step 4: 처음과 끝의 마침표 제거하기
    if (answer[0] == '.')
        answer.erase(answer.begin());
    if (answer[answer.length() - 1] == '.')
        answer.erase(answer.end() - 1);
    // step 5: 빈 문자열이라면 "a" 대입하기
    if (answer.length() == 0)
        answer.push_back('a');
    // step 6: 길이가 16 이상이면 16번째 문자부터 끝까지 제거하기 (제거 후 끝 마침표 제거)
    if (answer.length() >= 16)
    {
        answer.erase(answer.begin() + 15, answer.end());
        if (answer[answer.length() - 1] == '.')
            answer.erase(answer.end() - 1);
    }
    // step 7: 길이가 2 이하라면 길이가 3이 될때까지 마지막 문자 붙이기
    if (answer.length() <= 2)
    {
        char c = answer[answer.length() - 1];
        while (answer.length() != 3)
        {
            answer.push_back(c);
        }
    }
    return answer;
}