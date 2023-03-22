#include <string>
#include <vector>
#include <iostream>


using namespace std;

bool visit[200];

int answer = 0;

void dfs(int com, vector<vector<int>>& computers){
    if (visit[com]) return;
    visit[com] = true;
    
    
    for (int i = 0; i < computers[com].size(); ++i){
        if (i == com) continue;
        if (!computers[com][i]) continue;
        
        dfs(i, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    
    for (int i = 0; i < computers.size(); ++i){
        if (!visit[i]){
            answer++;
            dfs(i, computers);        
        }
    }
    
    return answer;
}