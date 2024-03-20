/*
    [문제] : 주어진 선행 스킬을 참고해 사용자들의 스킬 트리 가능성 여부 체크
    [설명]
            1. string을 순회하며, 각 char가 skill 목록의 올바른 순서에 위치하는지 find() 알고리즘 활용
*/

#include <string>
#include <vector>
using namespace std;


int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    for(const auto& skill_tree : skill_trees)
    {
        int presiquisite = 0;
        bool IsVaild = true;

        for(const auto& c : skill_tree)
        {
            auto it = skill.find(c);
            if(it == -1) continue;

            if(it == presiquisite)
            {
                presiquisite++;
            }
            else
            {
                IsVaild = false;
                break;
            }
        }
        if(IsVaild) answer++;
    }

    return answer;
}