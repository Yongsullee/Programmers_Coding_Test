#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    if(cacheSize == 0)
    {
        return 5*(int)cities.size();
    }
    
    int answer = 0;

    // { city_name, last_used }
    unordered_map<string, int> cache;
    
    for(int i=0; i<(int)cities.size(); ++i)
    {
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
        auto it = cache.find(cities[i]);
        // #1. Hit : +1 실행 시간
        if(it != end(cache))
        {
            answer += 1;
            it->second = i;
        }
        // #2. Miss : +5 실행 시간
        else
        {
            answer += 5;
            // cache가 비어있지 않을 때
            if(!cache.empty()&& (int)cache.size() == cacheSize)
            {
                // #1. LRU 수행
                int minHit = INT_MAX;
                string minHitCity = "";
                for(auto it = begin(cache); it != end(cache); ++it)
                {
                    if(it->second < minHit)
                    {
                        minHitCity = it->first;
                        minHit = it->second;
                    }
                }
                cache.erase(minHitCity);
            }
            cache.insert({cities[i], i});
        }
    }
    return answer;
}