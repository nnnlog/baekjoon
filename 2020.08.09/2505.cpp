#include <bits/stdc++.h>

using namespace std;

vector<int> origin, temp;

int get_index(vector<int> &vec, int base, int find) {
	for (int i = base; i < vec.size(); i++)
		if (vec[i] == find) return i;

	return 0;
}

int get_index_reverse(vector<int> &vec, int base, int find) {
	for (int i = base; i >= 0; i--)
		if (vec[i] == find) return i;

	return 0;
}

void swap_a_b(vector<int> &vec, int from, int to) {
	reverse(vec.begin() + from, vec.begin() + to + 1);
}

bool sorted(vector<int> &vec) {
	for (int i = 1; i < vec.size(); i++)
		if (vec[i] != i) return false;

	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;

	origin.resize(n + 1);
	temp.resize(n + 1);

	for (int i = 1; i <= n; i++) cin >> origin[i];

	temp = origin;
	int left = n;
	for (int i = 1; i <= n; i++)
		if (temp[i] != i) {
			left = i;
			break;
		}

	if (left == n) {
		cout << "1 1\n1 1";
		return 0;
	}

	int right = get_index(temp, left, left);
	swap_a_b(temp, left, right);

	if (sorted(temp)) {
		cout << left << " " << right << "\n1 1";
		return 0;
	}

	int left2 = n + 1;
	for (int i = 1; i <= n; i++)
		if (temp[i] != i) {
			left2 = i;
			break;
		}

	int right2 = get_index(temp, left2, left2);
	swap_a_b(temp, left2, right2);

	if (sorted(temp)) {
		cout << left << " " << right << "\n" << left2 << " " << right2;
		return 0;
	}
	temp = origin;
	swap_a_b(temp, left2, right2);
	swap_a_b(temp, left, right);
	if (sorted(temp)) {
		cout << left2 << " " << right2 << "\n" << left << " " << right;
		return 0;
	}


	temp = origin;
	right = 1;
	for (int i = n; i >= 1; i--)
		if (temp[i] != i) {
			right = i;
			break;
		}

	left = get_index_reverse(temp, right, right);
	swap_a_b(temp, left, right);

	if (sorted(temp)) {
		cout << left << " " << right << "\n1 1";
		return 0;
	}

	right2 = 1;
	for (int i = n; i >= 1; i--)
		if (temp[i] != i) {
			right2 = i;
			break;
		}

	left2 = get_index_reverse(temp, right2, right2);
	swap_a_b(temp, left2, right2);

	if (sorted(temp)) {
		cout << left << " " << right << "\n" << left2 << " " << right2;
		return 0;
	}

	temp = origin;
	swap_a_b(temp, left2, right2);
	swap_a_b(temp, left2, right);
	if (sorted(temp)) {
		cout << left2 << " " << right2 << "\n" << left << " " << right;
		return 0;
	}
}
