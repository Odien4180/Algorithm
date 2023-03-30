#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

int devideArray[5000001];
int maxCountArray[5000001];

void setDevideArray(int e){    
    for (int i = 1; i <= e; ++i){
        for (int j = 1; j <= e / i; ++j){
            ++devideArray[i * j];
        }
    }
}

void setMaxCountArray(int s, int e){
    int maxCount = -1;
    for (int i = e; i >= s; --i){
        if (devideArray[i] >= maxCount){
            maxCount = devideArray[i];
            maxCountArray[i] = i;
            cout << maxCount << endl;
        }
        else
            maxCountArray[i] = maxCountArray[i + 1];
    }
}

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    int min = 50000001;
    
    for (int start : starts)
        if (min > start)
            min = start;
    
    setDevideArray(e);
    setMaxCountArray(min, e);
    
    for (int start : starts)
        answer.push_back(maxCountArray[start]);
    
    
    return answer;
}