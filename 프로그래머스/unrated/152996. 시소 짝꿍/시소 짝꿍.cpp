#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    long long weightMap[1001] = {0,};
    
    for (auto weight : weights)
        ++weightMap[weight];
    
    for (int i = 100; i < 1001; ++i){
        if (weightMap[i] == 0)
            continue;
        
        long long iCombi = weightMap[i];
        answer += iCombi * (iCombi - 1) / 2;
        
        int iVal1 = i * 3 / 2;
        int iVal2 = i * 2;
        int iVal3 = i * 4 / 3;
        
        if (i % 2 == 0 && iVal1 < 1001)
            answer += weightMap[iVal1] * weightMap[i];
            
        if (iVal2 < 1001)
            answer += weightMap[iVal2] * weightMap[i];
        
        if (i % 3 == 0 && iVal3 < 1001)
            answer += weightMap[iVal3] * weightMap[i];
    }
    
    return answer;
}