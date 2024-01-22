#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> um;
    
    for(int i=0; i<(int)clothes.size(); ++i)
        um[clothes[i][1]]++;
    
    for(auto it = begin(um); it != end(um); ++it)
        answer *= (it->second+1);
    
    return answer-1;
}