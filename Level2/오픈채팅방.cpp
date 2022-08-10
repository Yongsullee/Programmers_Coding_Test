#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

// 1. key = [유저 아이디], value = [닉네임]
map<string, string> changeRecord;

// 2. bool = 입장 or 퇴장, string = [유저 아이디]
vector<pair<bool, string>> resultRecord;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    
    string Enter = "님이 들어왔습니다.";
    string Leave = "님이 나갔습니다.";

    for(int i=0; i<record.size(); ++i)
    {
        bool bDelimFound = false;
        string userString = "";
        string nickString = "";
        
        // "Enter"
        if(record[i].substr(0, 5) == "Enter")
        {
            for(int j=6; j<record[i].size(); ++j)
            {
                if(bDelimFound == false && record[i][j] == ' ')
                {
                    bDelimFound = true;
                    continue;
                }
                
                if(bDelimFound != true)
                    userString += record[i][j];
                else
                    nickString += record[i][j];
            }
            // [유저] [닉네임]
            // 1. 이미 존재 [유저 아이디]?
            if(changeRecord.find(userString) != end(changeRecord))
            {
                changeRecord[userString] = nickString;
            }
            // 2. 새로운 [유저 아이디]?
            else
            {
                changeRecord.insert(make_pair(userString, nickString));
            }
            resultRecord.push_back(make_pair(true, userString));
        }
        // "Leave"
        else if (record[i].substr(0, 5) == "Leave")
        {
            for(int j=6; j<record[i].size(); ++j)
            {
                userString += record[i][j];
            }
            
            resultRecord.push_back(make_pair(false, userString));
        }
        // "Change"
        else
        {   
            for(int j=7; j<record[i].size(); ++j)
            {
                // " "를 만나면 Flag 변수를 True로 변경합니다.
                if(bDelimFound == false && record[i][j] == ' ')
                {
                    bDelimFound = true;
                    continue;
                }
                
                // " " 직전까지 [유저 아이디] + " " 이후부터 [변경 닉네임]
                if(bDelimFound != true)
                    userString += record[i][j];
                else
                    nickString += record[i][j];
            }
            changeRecord[userString] = nickString;                
        }
    }
    
    for(int i=0; i<resultRecord.size(); i++)
    {
        // 1. resultRecord에 존재하는 [유저 아이디]를 Key로 changeRecord에서 [최종 닉네임]을 찾습니다. 
        string userID = resultRecord[i].second;
        string resultStr = changeRecord[userID];
        // 2. 입장
        if(resultRecord[i].first == true)
            resultStr.append(Enter);
        // 3. 퇴장
        else
            resultStr.append(Leave);
        
        answer.push_back(resultStr);
    }
    
    return answer;
}