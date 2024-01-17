#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    int size = citations.size();
    for(int i = 0; i < size; ++i){
        if(citations[i] <= i) return i;
    }
    return size;
}
