#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vld;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<pld> vpld;
typedef unordered_map<int, int> mpii;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string a, t;
    getline(cin, a), getline(cin, t);
    deque<char> str, front, back;
    while (!t.empty()) str.push_front(t.back()), t.pop_back();

    while (str.size() >= a.size()) {
        while (1) {
            int fail = 0;
            if (str.size() < a.size()) goto bye;
            for (int i = 0; i < a.size(); i++) {
                if (a[i] != str.at(i)) {
                    fail = 1;
                    break;
                }
            }
            if (fail) front.push_back(str.front()), str.pop_front();
            else {
                for (int i = 0; i < a.size(); i++) str.pop_front();
                for (int i = 0; i < a.size() - 1 && !front.empty(); i++) str.push_front(front.back()), front.pop_back();
                for (int i = 0; i < a.size() - 1 && !back.empty(); i++) str.push_back(back.front()), back.pop_front();
                break;
            }
        }

        while (1) {
            int fail = 0;
            if (str.size() < a.size()) break;
            for (int i = 0; i < a.size(); i++) {
                if (a[a.size() - i - 1] != str.at(str.size() - i - 1)) {
                    fail = 1;
                    break;
                }
            }
            if (fail) back.push_front(str.back()), str.pop_back();
            else {
                for (int i = 0; i < a.size(); i++) str.pop_back();
                for (int i = 0; i < a.size() - 1 && !front.empty(); i++) str.push_front(front.back()), front.pop_back();
                for (int i = 0; i < a.size() - 1 && !back.empty(); i++) str.push_back(back.front()), back.pop_front();
                break;
            }
        }
    }
    bye:;

    for (char c: front) cout << c;
    for (char c: str) cout << c;
    for (char c: back) cout << c;
}
