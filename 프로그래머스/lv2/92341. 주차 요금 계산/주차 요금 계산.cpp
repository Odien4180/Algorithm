#include <string>
#include <vector>
#include <sstream>
#include <map>

#define MAX_TIME 1439

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

int GetCost(int useMinute, vector<int> &fees){
    int cost = fees[1];
    if (useMinute > fees[0]){
        int valueableMinute = useMinute - fees[0];
        int payCount = valueableMinute / fees[2];
        
        if (payCount * fees[2] < valueableMinute)
            ++payCount;
        
        cost += payCount * fees[3];
    }
    
    return cost;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    map<int, int> totalTimeMap;
    map<int, int> timeMap;
    
    for (auto record : records){
        vector<string> splitedRecord = split(record, ' ');
        vector<string> timeRecord = split(splitedRecord[0], ':');
        
        int minute = stoi(timeRecord[0]) * 60 + stoi(timeRecord[1]);
        int carNum = stoi(splitedRecord[1]);
            
        if (splitedRecord[2] == "IN"){
            timeMap[carNum] = minute;
            totalTimeMap[carNum] += MAX_TIME - minute;        
        }
        else
            totalTimeMap[carNum] += minute - MAX_TIME;
    }
    
    for (auto totalTime : totalTimeMap)
        answer.push_back(GetCost(totalTime.second, fees));
    
    return answer;
}