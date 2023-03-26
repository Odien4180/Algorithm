#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b){
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    unordered_map<int, int> sizeMap;
    
    for (auto iSize : tangerine){
        
        if (sizeMap.find(iSize) != sizeMap.end())
            sizeMap.insert(make_pair(iSize, 0));
        
        ++sizeMap[iSize];
    }
    
    vector<pair<int, int>> sizeVec(sizeMap.begin(), sizeMap.end());
    
    sort(sizeVec.begin(), sizeVec.end(), comp);
    
    for (auto size : sizeVec){
        k -= size.second;
        ++answer;
        if (k <= 0)
            break;    
    }
    
    return answer;
}