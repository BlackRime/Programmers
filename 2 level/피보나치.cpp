#include <string>
#include <vector>

using namespace std;
int dp[100001];

int fibo(int n) {
	if (dp[n]) {
		return dp[n];
	}

	dp[n] = (fibo(n - 2) + fibo(n - 1)) % 1234567;
	return dp[n];
}

int solution(int n) {

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	return fibo(n);
}