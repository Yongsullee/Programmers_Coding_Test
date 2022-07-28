#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves)
{
    int answer = 0;
    // 뽑은 인형을 담을 벡터
    vector<int> s;

    for (int i = 0; i < moves.size(); i++)
    {
        int index = moves[i] - 1;
        for (int j = 0; j < board.size(); j++)
        {
            if (board[j][index] != 0)
            {
                int ele = board[j][index];

                s.push_back(ele);
                board[j][index] = 0;
                // 2개 이상 있을 경우
                if (s.size() >= 2)
                {
                    // 인접한 중복 두 원소 찾기, 있다면 중복 원소들 중 첫 번째 원소의 반복자 반환
                    auto it = adjacent_find(begin(s), end(s));
                    if (it != end(s))
                    {
                        s.pop_back();
                        s.pop_back();

                        answer += 2;
                    }
                }
                break;
            }
        }
    }

    return answer;
}