#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {

    priority_queue<int, vector<int>> pq;
    queue<pair<int, int>> q;
    int answer = 0;
    int order = 1;

    for(int i=0; i < (int)priorities.size(); ++i)
    {
        pq.push(priorities[i]);
        q.push({i, priorities[i]});
    }

    while(!pq.empty())
    {
        int prior = pq.top();
        pq.pop();

        while(!q.empty() && q.front().second != prior)
        {
            q.push(q.front());
            q.pop();
        }
        if(q.front().first == location)
        {
            answer = order;
            break;
        }
        q.pop();
        order++;
    }

    return answer;
}