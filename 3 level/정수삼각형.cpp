#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define MAX 501

int dp[MAX][MAX];

int solve(int current_y, int current_x, const vector<vector<int>>& triangle) {
	if (current_y == triangle.size() || current_x == triangle[current_y].size()) {
		return 0;
	}
	if (dp[current_y][current_x]) {
		return dp[current_y][current_x];
	}

	return dp[current_y][current_x] = max(solve(current_y + 1, current_x, triangle), solve(current_y + 1, current_x + 1, triangle)) + triangle[current_y][current_x];

}

int solution(vector<vector<int>> triangle) {
	return solve(0, 0, triangle);
}