#include <string>
#include <vector>
#include <queue>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    queue<string>  queue1;
    queue<string>  queue2;
    
    for (auto card : cards1)
        queue1.push(card);
    
    for (auto card : cards2)
        queue2.push(card);
    
    for (int i = 0; i < goal.size(); ++i){
        if (goal[i] == queue1.front())
        {
            queue1.pop();
            continue;
        }
        
        if (goal[i] == queue2.front())
        {
            queue2.pop();
            continue;
        }
        
        return "No";
    }
    
    return "Yes";
}