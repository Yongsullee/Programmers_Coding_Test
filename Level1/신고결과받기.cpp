#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    // vector<int> answer의 크기를 정하고, 0값으로 초기화 합니다.
    vector<int> answer(id_list.size(), 0);
    
    // Map 자료구조 이용을 위해, unordered_map 클래스 사용합니다.
    unordered_map<string, int> idx_map;
    for(int i=0; i<id_list.size(); ++i) idx_map[id_list[i]] = i; // 멤버 index 저장
    
    /*  set 자료구조를 이용해, ID의 중복 입력을 방지합니다.
    *
    *   신고 당한 ID를 key 값으로, 신고한 ID들을 set 자료구조에 넣습니다.
    */

    unordered_map<string, set<string>> report_map;
    
    /*  String parsing을 위해, sstream을 사용합니다.
    *
    *   이때, string 객체 2개를 선언하고,
    *   ss 객체 >> first >> second를 통해 parsing 결과를 넣어줍니다.
    */

    stringstream ss;
    for(auto rep: report) {
        ss.str(rep);
        string first, second; ss >> first >> second; // 문자열 parsing
        
        /* 
        	신고 정보 저장
        	first가 second를 신고 -> second의 set에는 second를 신고한 사람들
        */
        report_map[second].insert(first);
        
        ss.clear();
    }
    
    /*
    *
    *  각 원소의 set의 size를 K와 비교합니다
    * 
    */
   
    for(auto it: report_map) { // it.second = set<string>
        if(it.second.size() >= k) { // 어떤 멤버를 신고한 사람이 k명 이상이면
            for(auto set_it: it.second) { // 신고한 사람들의
                int idx = idx_map[set_it];                
                answer[idx]++; // count 증가 (메일 전송)
            }            
        }
    }    
    
    return answer;
}