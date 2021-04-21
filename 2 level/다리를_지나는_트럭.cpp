#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	int value = 0;
	int front_index = 0;
	int current_index = 0;
	int current_weight = 0;
	int passing_length = bridge_length;
	int truck_weight_count = truck_weights.size();
	queue<int> passing_truck;

	for (int i = 0; i < bridge_length; ++i) {
		passing_truck.push(0);
	}

	while (front_index < truck_weight_count) {
		++answer;

		value = passing_truck.front();
		passing_truck.pop();

		if (current_weight + truck_weights[current_index] <= weight) {
			passing_truck.push(bridge_length);
			current_weight += truck_weights[current_index];
			passing_length = bridge_length;
			++current_index;
		}
		else {
			passing_truck.push(--passing_length);
		}

		if (passing_truck.front() == bridge_length || value == 1) {
			current_weight -= truck_weights[front_index++];
		}
	}

	return answer + 1;
}