#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> required_dates;
	int days = 0;
	int count = 1;

	for (int i = 0; i < progresses.size(); ++i) {
		required_dates.push_back((99 - progresses[i]) / speeds[i] + 1);
	}

	days = required_dates[0];

	for (int i = 1; i < required_dates.size(); ++i) {
		if (required_dates[i] <= days) {
			++count;
		}
		else {
			answer.push_back(count);
			count = 1;
			days = required_dates[i];
		}
	}
	answer.push_back(count);

	return answer;
}