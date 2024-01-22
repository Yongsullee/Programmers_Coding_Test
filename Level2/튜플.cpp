#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> tuples;
    string str = "";
    
    for(int i=0; i<s.size(); i++) {
        if(s[i] == '{') {
            str = "";
        }
        else if(s[i] == '}' && str != "") {
            stringstream ss(str);
            vector<int> tuple;
            string num;
            while(getline(ss, num, ',')) {
                tuple.push_back(stoi(num));
            }
            tuples.push_back(tuple);
        }
        else if(s[i] != ',' && s[i] != '}') {
            str.push_back(s[i]);
        }
    }
    
    sort(tuples.begin(), tuples.end(), [](vector<int> a, vector<int> b) {
        return a.size() < b.size();
    });
    
    for(auto &tuple : tuples) {
        for(int &num : tuple) {
            if(find(answer.begin(), answer.end(), num) == answer.end()) {
                answer.push_back(num);
            }
        }
    }
    
    return answer;
}
