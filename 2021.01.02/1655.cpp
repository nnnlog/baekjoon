#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vl;

void debug(priority_queue<int, vi, greater<>> a) {
	while (!a.empty()) {
		cout << a.top() << " ";
		a.pop();
	}
	cout << "\n";
}
void debug(priority_queue<int> a) {
	while (!a.empty()) {
		cout << a.top() << " ";
		a.pop();
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; cin >> n;
	priority_queue<int> lower;
	priority_queue<int, vi, greater<>> upper;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		if (lower.empty()) lower.push(a);
		else {
			int mid = lower.top();
			if (mid < a) {
				upper.push(a);

				if (upper.size() > lower.size()) {
					lower.push(upper.top());
					upper.pop();
				}
			} else {
				lower.push(a);
				if (lower.size() - (i % 2) > upper.size()) {
					upper.push(lower.top());
					lower.pop();
				}
			}
		}

		/*debug(lower);
		debug(upper);
		cout << "\n";*/

		cout << lower.top() << "\n";
		//cout << "=======\n";
	}
}
