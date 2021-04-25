#include <string>
#include <vector>
#include <set>

using namespace std;

bool solution(vector<string> phone_book) {
	bool answer = true;
	set<string> phone_set;


	for (int i = 0; i < phone_book.size(); ++i) {
		phone_set.insert(phone_book[i]);
	}

	for (int i = 0; i < phone_book.size(); ++i) {
		for (int j = 1; j < phone_book[i].size(); ++j) {
			if (phone_set.find(phone_book[i].substr(0, j)) != phone_set.end()) {
				answer = false;
				break;
			}
		}
	}

	return answer;
}