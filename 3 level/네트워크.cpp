#include <string>
#include <vector>
using namespace std;

#define MAX 201
int dp[MAX];
int answer;

int network(int current, const int n, const vector<vector<int>>& computers) {
	if (dp[current]) {
		return 0;
	}
	dp[current] = 1;
	for (int i = 0; i < n; ++i) {
		if (computers[current][i]) {
			network(i, n, computers);
		}
	}
	return 0;
}

int solution(int n, vector<vector<int>> computers) {
	answer = 0;

	for (int i = 0; i < n; ++i) {
		if (!dp[i]) {
			network(i, n, computers);
			++answer;
		}
	}
	return answer;
}