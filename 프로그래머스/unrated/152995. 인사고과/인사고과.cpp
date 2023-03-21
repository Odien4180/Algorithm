#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(vector<int> scoreA, vector<int> scoreB){
    return scoreA[0] < scoreB[0];
}

bool compareSum(vector<int> scoreA, vector<int> scoreB){
    int sumA = scoreA[0] + scoreA[1];
    int sumB = scoreB[0] + scoreB[1];
    return sumA > sumB;
}

int solution(vector<vector<int>> scores) {
    int answer = -1; 
    int myA = scores[0][0];
    int myB = scores[0][1];
    
    sort(scores.begin(), scores.end(), compare);
    
    int lastA = -1;
    int largestB = -1;
    int tempLargestB = -1;
    
    for (int i = scores.size() - 1; i >= 0; --i){
        if (scores[i][0] != lastA && tempLargestB > largestB)
            largestB = tempLargestB;
        
        if (tempLargestB < scores[i][1])
            tempLargestB = scores[i][1];
        
        lastA = scores[i][0];
        
        if (scores[i][1] < largestB)
            scores.erase(scores.begin() + i);
    }
    
    sort(scores.begin(), scores.end(), compareSum);
    
    for (int i = 0; i < scores.size(); ++i)
        if (scores[i][0] == myA && scores[i][1] == myB){
            answer = i + 1;
            break;
        }
            
    
    return answer;
}