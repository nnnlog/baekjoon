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

vector<string> split(const string &str) {
	vector<string> ret;
	string tmp;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') ret.push_back(tmp), tmp.clear();
		else tmp.push_back(str[i]);
	}
	ret.push_back(tmp);
	return ret;
}
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
ll parse_time(const string &ymd, const string &hms) {
	//istringstream ss(ymd + " " + hms);
    
	/*
    tm ok{};
	ss >> get_time(&ok, "%Y-%m-%d %H:%M:%S");
	time_t time_stamp = mktime(&ok);
	*/
    string s = ymd + " " + hms;
    int Y = stoi(s.substr(0, 4));
    int M = stoi(s.substr(5, 2));
    int D = stoi(s.substr(8, 2));
    int hh = stoi(s.substr(11, 2));
    int mm = stoi(s.substr(14, 2));
    int ss = stoi(s.substr(17, 2));
    int tot_days = 0;
    for(int y = 2000; y < Y; y++)
        tot_days = tot_days + 365 + (y % 4 == 0);
    for(int m = 1; m < M; m++){
        tot_days = tot_days + days[m];
		if(m == 2 && Y % 4 == 0)
			tot_days++;
	}
    tot_days = tot_days + (D - 1);
    
    int tot_s = hh * 3600 + mm * 60 + ss;
    
    return (tot_days) * (3600 * 24) + tot_s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, e; cin >> n >> e >> ws;
	vi to_category_id(n), to_real_video_id(n);
	vi cnt_by_id(n), cnt_by_category(n);
	unordered_map<string, int> conv_category;
	mpii conv_video_id;
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);

		auto part = split(s);
		int id = atoi(part.back().c_str());
		part.pop_back();
		string category = part.back();

		if (!conv_category.count(category)) conv_category[category] = conv_category.size();

		to_category_id[conv_video_id[id] = conv_video_id.size()] = conv_category[category];
		to_real_video_id[conv_video_id[id]] = id;
	}

	vpii Q;
	while (e--) {
		string a, b, c;
		cin >> a >> b >> c;

		int tm = parse_time(a, b);
		if (c == "R") Q.emplace_back(tm, -1e9);
		else {
			int id = conv_video_id[atoi(c.c_str())] + 1;
			Q.emplace_back(tm, id);
			Q.emplace_back(tm + 60 * 60 * 72, -id);
		}
	}

	vector<set<pii>> S_by_category(conv_category.size());
	set<pair<int, pii>> S;

	for (int i = 0; i < conv_category.size(); i++) S.insert({-0, {0, i}}); // {-개수, {아이디, 그룹 아이디}}
	for (int i = 0; i < n; i++) S_by_category[to_category_id[i]].insert({-0, i}); // {-개수, 아이디}

	auto update = [&](int id, int diff) {
		int gid = to_category_id[id];

		auto it = S_by_category[gid].begin();
		S.erase({-cnt_by_category[gid] + it->first, {it->second, gid}});
		S_by_category[gid].erase({-cnt_by_id[id], to_real_video_id[id]});

		cnt_by_id[id] += diff;
		cnt_by_category[gid] += diff;

		S_by_category[gid].insert({-cnt_by_id[id], to_real_video_id[id]});
		it = S_by_category[gid].begin();
		S.insert({-cnt_by_category[gid] + it->first, {it->second, gid}});
	};

	sort(all(Q));
	for (const auto &[_, q] : Q) {
		if (q == -1e9) cout << S.begin()->second.first << "\n";
		else update(abs(q) - 1, q > 0 ? 1 : -1);
	}
}
