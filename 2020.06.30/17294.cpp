#include <iostream>

using namespace std;

int main() {
    string a; getline(cin, a);
    if (a.size() <= 2) cout << "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!";
    else {
        bool flag = false;
        double r = a[1] - a[0];

        for (int i = 1; i < a.size() - 1; i++) {
            if (a[i] + r != a[i + 1]) {
                flag = true;
                break;
            }
        }

        cout << (!flag ? "◝(⑅•ᴗ•⑅)◜..°♡ 뀌요미!!" : "흥칫뿡!! <(￣ ﹌ ￣)>");
    }
}