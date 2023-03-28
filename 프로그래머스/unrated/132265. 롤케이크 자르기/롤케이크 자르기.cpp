#include <string>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    int right[1000001];
    int rightTypeCount = 0;
    int left[1000001];
    int leftTypeCount = 0;
    
    for (int i = 0; i < topping.size(); ++i){
        if (right[topping[i]] == 0)
            rightTypeCount++;
        right[topping[i]]++;
    }
    
    for (int i = 0; i < topping.size(); ++i){
        right[topping[i]]--;
        if (right[topping[i]] == 0)
            rightTypeCount--;
        
        if (left[topping[i]] == 0)
            leftTypeCount++;
        left[topping[i]]++;
        if (rightTypeCount == leftTypeCount)
            answer++;
    }
    
    return answer;
}