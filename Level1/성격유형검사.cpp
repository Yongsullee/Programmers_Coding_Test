#include <string>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

// [0] : R + T, [1] : C + F, [2] : J + M, [3] : A + N
vector<pair<int, int>> statCnt = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
vector<pair<char, char>> stat = {{'R', 'T'}, {'C', 'F'}, {'J', 'M'}, {'A', 'N'}}; 

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    int statNum, point;
    bool bOriginal = true;
    
    for(int i=0; i<choices.size(); i++)
    {
        char firstChar = survey[i][0];
        char secondChar = survey[i][1];
        
        // 각 1 ~ 7 선택지의 점수는 abs(4 - choice)
        point = abs(4 - choices[i]);
        statNum = -1;
        
        // 지표번호를 구합니다.
        if(firstChar == 'R' || firstChar == 'T')
            statNum = 0;
        if(firstChar == 'C' || firstChar == 'F')
            statNum = 1;
        if(firstChar == 'J' || firstChar == 'M')
            statNum = 2;
        if(firstChar == 'A' || firstChar == 'N')
            statNum = 3;

        // "RT" = TRUE(정순), "TR" = FALSE(역순)
        firstChar < secondChar ? bOriginal = true : bOriginal = false;
        
        // 선택지가 4번이라면 어느 것도 점수를 받지 못합니다.
        if(choices[i] == 4)
        {
            continue;
        }
        // 선택지가 1~3이라면, "AB" 중 "A"에 포인트 추가
        if(choices[i] <= 3)
        {
            if(bOriginal == true)
                // 순서가 정순이라면 "RT" 중 "R"에 포인트 추가
                statCnt[statNum].first += point;
            else
                // 순서가 역순이라면 "TR" 중 "T"에 포인트 추가
                statCnt[statNum].second += point;
        }
        // 선택지가 5~7이라면, "AB" 중 "B"에 포인트 추가
        if(choices[i] >= 5)
        {
            if(bOriginal == true)
                // 순서가 정순이라면 "RT" 중 "T"에 포인트 추가
                statCnt[statNum].second += point;
            else
                // 순서가 역순이라면 "TR" 중 "R"에 포인트 추가
                statCnt[statNum].first += point;
        }
    }
    
    for(int i=0; i<statCnt.size(); i++)
    {
        // 같거나 크면 사전 순서가 빠른 유형이 선택됩니다!
        if(statCnt[i].first >= statCnt[i].second)
            answer += stat[i].first;
        else
            answer += stat[i].second;
    }
    
    return answer;
}