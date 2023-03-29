#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    long i_p = stol(p);
    for (int i = 0; i <= t.length() - p.length(); ++i){
        long part = stol(t.substr(i, p.length()));
        if (part <= i_p)
            ++answer;
    }
    
    return answer;
}