#include <string>
#include <vector>

using namespace std;

string solution(int n) {
	string answer = "";
	string number = "412";

	while (n) {
		answer = number[n % 3] + answer;
		if (n % 3 == 0) {
			n = n / 3 - 1;
		}
		else {
			n = n / 3;
		}
	}
	return answer;
}