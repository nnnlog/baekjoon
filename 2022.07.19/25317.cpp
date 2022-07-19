#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;


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

struct Fraction {
    ll a, b; // 분모 분자
    int e;

    bool same(const ll x) const {
        return same({1, x, 0});
    }

    bool same(const Fraction &other) const {
        __int128 i = a, j = b, k = other.a, l = other.b;
        return j * k == i * l;
    }

    bool operator<(const Fraction &other) const {
        __int128 i = a, j = b, k = other.a, l = other.b;
        __int128 x = j * k, y = i * l;
        return x == y ? e < other.e : x < y;
    }

//    bool operator==(const Fraction &other) const {
//        return same(other) && e == other.e;
//    }
//
//    bool operator!=(const Fraction &other) const {
//        return !(*this == other);
//    }
};

#define ordered_set tree<Fraction, null_type,less<>, rb_tree_tag,tree_order_statistics_node_update>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ordered_set A, B;
    int q;
    cin >> q;
    int always_zero = 0, additional = 0;
    while (q--) {
        int a;
        cin >> a;
        if (a == 1) {
            ll b, c;
            cin >> b >> c;
            if (b == 0) {
                if (!c) always_zero = 1;
                else if (c < 0) additional++;
            } else {
                int minus = (b < 0) ^ (c < 0);
                (b > 0 ? A : B).insert({abs(b), abs(c) * (minus ? 1 : -1), q});
            }
        } else {
            ll b;
            cin >> b;
            if (always_zero) cout << "0\n";
            else {
                int x, y;
                {
                    auto it = A.lower_bound({1, b, 0});
                    if (it == A.end()) x = 0;
                    else if (it->same(b)) {
                        cout << "0\n";
                        continue;
                    } else x = A.size() - A.order_of_key(*it);
                }
                {
                    auto it = B.lower_bound({1, b, 0});
                    if (it == B.end()) y = B.size();
                    else if (it->same(b)) {
                        cout << "0\n";
                        continue;
                    } else y = B.order_of_key(*it);
                }
                int count = x + y + additional;
//                cout << x << " " << y << " " << additional << "\n";
//                cout << "A: ";
//                for (Fraction f: A) cout << f.a << " " << f.b << ", ";
//                cout << "\nB:";
//                for (Fraction f: B) cout << f.a << " " << f.b << ", ";
                cout << (count % 2 ? '-' : '+') << "\n";
            }
        }
    }
}
