#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;

    string tmpStr = "";
    string str = "1231";
    
    if(ingredient.size() < 4)
        return 0;
    
    for(int i=0; i<ingredient.size(); i++)
    {
        tmpStr.push_back(ingredient[i]+'0');
        if(tmpStr.size() >= 4)
        {
            int startIndex = tmpStr.size()-4;
            string tmpSubStr = tmpStr.substr(startIndex, 4);
            if(tmpSubStr == str)
            {
                tmpStr.erase(begin(tmpStr)+startIndex, end(tmpStr));
                answer++;
            }
        }
    }
    
    return answer;
}