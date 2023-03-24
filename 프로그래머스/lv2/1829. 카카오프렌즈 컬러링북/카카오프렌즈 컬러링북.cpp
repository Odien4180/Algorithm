#include <vector>
#include <iostream>

using namespace std;

bool picMap[101][101];

int number_of_area;
int max_size_of_one_area;

int area = 0;

void Search(int key, pair<int, int> pos, vector<vector<int>> _picture){
    if (pos.first > _picture.size() || pos.second > _picture[0].size()) return;
    if (picMap[pos.first][pos.second] == false) return;
    if (key != _picture[pos.first][pos.second]) return;
    
    area++;
    
    picMap[pos.first][pos.second] = false;
    
    Search(key, make_pair(pos.first + 1, pos.second), _picture);
    Search(key, make_pair(pos.first - 1, pos.second), _picture);
    Search(key, make_pair(pos.first, pos.second + 1), _picture);
    Search(key, make_pair(pos.first, pos.second - 1), _picture);
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    number_of_area = 0;
    max_size_of_one_area = 0;
    
    for (int i = 0; i < picture.size(); ++i){
        for (int j = 0; j < picture[i].size(); ++j){
            picMap[i][j] = true;
        }
    }
    
    for (int i = 0; i < picture.size(); ++i){
        for (int j = 0; j < picture[i].size(); ++j){
            if (picMap[i][j] == true && picture[i][j] != 0){
                area = 0;
                Search(picture[i][j], make_pair(i, j), picture);
                
                number_of_area++;
                if (area > max_size_of_one_area)
                    max_size_of_one_area = area;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}