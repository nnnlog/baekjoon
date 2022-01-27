#include <iostream>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);

	pair<int, int> next;
	cin >> next.first >> next.second;
	
	do {
		cout << (next.first > next.second ? "Yes" : "No") << "\n";
		cin >> next.first >> next.second;
	}while(next.first || next.second);
}