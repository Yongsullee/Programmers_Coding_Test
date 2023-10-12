/* 

    [문제] : 주어진 Brown 격자의 갯수와 Yellow 격자의 갯수를 통해 카펫의 가로와 세로 길이를 유추하는 문제

    [풀이]

    1.  먼저, 카펫의 Height 값을 저장할 변수를 선언하고, 3(최소 세로 크기)으로 초기화합니다. 
    2.  그리고, 카펫의 Width 값을 저장할 변수를 선언하고, (bronw-2)/2(세로 길이가 3일 때, 가로 길이의 값) 로 초기화합니다.
    3.  while 문을 Height 값이 Width 값과 같거나 작을 때까지 순회하며, 현재 Height 값과 Width 값을 통해 카펫을 구성하기 위해 필요한 Yellow 격자의 갯수를 계산합니다.
    4.  이때, 문제에 주어진 yellow 값과 해당 값이 동일하다면, 현재 Height 값과 Width 값을 answer에 push_back 하고 While 문을 종료합니다.
    5.  반대로, 문제에 주어진 yellow 값과 해당 값이 다르다면, Height 값을 1 증가 시키고, Width 값은 1 감소 시켜, 다음 탐색을 진행합니다. 

*/

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int W = (brown - 2)/2;
    int H = 3;
    
    while(H <= W)
    {
        int cnt_yellow = (W-2)*(H-2);
        if(cnt_yellow == yellow)
        {
            answer.push_back(W);
            answer.push_back(H);
            break;
        }
        H++;
        W--;
    }

    return answer;
}