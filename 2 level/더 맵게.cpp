#include <string>
#include <vector>   
#include <queue>

using namespace std;



int solution(vector<int> scoville, int K) {
	int answer = 0;
	int goal_scoville = 0;
	priority_queue<int, vector<int>, greater<int>> prique;

	int scoville_size = scoville.size();
	for (int i = 0; i < scoville_size; ++i) {
		prique.push(scoville[i]);
	}
	int first_food = 0, second_food = 0;
	while (prique.top() < K && prique.size() > 1) {
		first_food = prique.top(); prique.pop();
		second_food = prique.top(); prique.pop();
		goal_scoville = first_food + second_food * 2;
		prique.push(goal_scoville);
		++answer;
	}
	if (prique.top() < K)
		return -1;

	return answer;
}