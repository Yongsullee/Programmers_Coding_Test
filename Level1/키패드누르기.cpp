#include <string>
#include <vector>
#include <map>
#include <utility>
#include <cmath>
#include <algorithm>

using namespace std;

map<int, char> m{
    {1, 'L'},
    {4, 'L'},
    {7, 'L'},
    {3, 'R'},
    {6, 'R'},
    {9, 'R'},
    {2, 'U'},
    {5, 'U'},
    {8, 'U'},
    {11, 'U'},
};

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    // 0 -> 11 로 교체
    replace_if(begin(numbers), end(numbers), [](int num){ return num == 0;}, 11);
    
    // "right" or "left" -> 'R' or 'L'
    if(hand == "left")
        hand = "L";
    else if (hand == "right")
        hand = "R";
    
    // * == 10 -> Left , # == 12 -> Right
    pair<int, int> currentHand(10, 12);
    
    int num = -1;
    for(int i=0; i < numbers.size(); i++)
    {
        num = numbers[i];
        
        if( m[num] != 'U' )
        {
            answer.push_back(m[num]);
        }
        // 1. 2 - 5 - 8 일 경우
        else
        {

            int leftDist = abs(num - currentHand.first);

            int rightDist = abs(num - currentHand.second);
            
            leftDist % 3 ? leftDist = (leftDist/3) + (leftDist%3) : leftDist /= 3;
            rightDist % 3 ? rightDist = (rightDist/3) + (rightDist%3) : rightDist /= 3;
            
            if( leftDist == rightDist)
            {
                answer.append(hand);
            }
            else{
                if ( min(leftDist, rightDist) == leftDist )
                    answer.push_back('L');

                else
                    answer.push_back('R');       
            }
        }
        if(answer.back() == 'L')
            currentHand.first = num;
        else
            currentHand.second = num;
    }
    return answer;
}