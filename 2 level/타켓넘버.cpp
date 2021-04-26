#include <string>
#include <vector>

using namespace std;

int TargetNumber(int current_number, int current_sum, const vector<int>& numbers, const int& target){
    if(current_number == numbers.size()){
        return (current_sum == target)? 1 : 0;
    }
    
    return TargetNumber(current_number + 1, current_sum + numbers[current_number], numbers, target) + 
        TargetNumber(current_number + 1, current_sum - numbers[current_number], numbers, target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    answer = TargetNumber(0, 0, numbers, target);
    
    return answer;
}