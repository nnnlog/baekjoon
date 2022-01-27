#include <iostream>
#include <algorithm>
#define NO_ANS 9999999
  
typedef long long lld;
  
  
int grid[51][51], n;
  
using namespace std;
  
int solve() {
    /** current 1 -> right/left, 0 -> up/down*/
    int x = 0, y = 0, state = 1, current = 1, ans = 1;
    do {
        int flag = grid[x][y];
        if (!x && !y) {
            if (!flag || flag == 2 || flag == 3 || flag == 4) {
                return NO_ANS;
            }
        }
        //cout << x << " " << y << " : " << flag << endl;
          
        int nextX = x, nextY = y;
        switch(flag) {
            case 0:
                if (current && !state) {
                    current = 0;
                    nextY++;
                }else if (!current && state) {
                    current = 1;
                    nextX++;
                }else{
                    return NO_ANS;
                }
                break;
            case 1:
                if (current && state) {
                    current = state = 0;
                    nextY++;
                }else if (!current && state){
                    current = 1;
                    state = 0;
                    nextX--;
                }else{
                    return NO_ANS;
                }
                break;
            case 2:
                if (current && !state) {
                    current = 0;
                    state = 1;
                    nextY--;
                }else if (!current && !state) {
                    current = state = 1;
                    nextX++;
                }else{
                    return NO_ANS;
                }
                break;
            case 3:
                if (current && state) {
                    nextY--;
                    current = 0;
                }else if (!current && !state) {
                    current = 1;
                    nextX--;
                }else{
                    return NO_ANS;
                }
                break;
            case 4:
                if (!current) {
                    if (state) nextY--;
                    else nextY++;
                }else{
                    return NO_ANS;
                }
                break;
            case 5:
                if (current) {
                    if (state) nextX++;
                    else nextX--;
                }else{
                    return NO_ANS;
                }
        }
          
        x = nextX;
        y = nextY;
          
        ans++;
          
        flag = grid[x][y];
          
        if (x == n - 1 && y == n - 1 && ((flag == 2 && !current && !state) || (flag == 5 && current && state))) {
            return ans;
        }
          
        if (x < 0 || y < 0 || x > n || y > n) break;
    }while(1);
      
    return NO_ANS;
} 
  
int main() {
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int k, ans = NO_ANS; cin >> n >> k;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            cin >> grid[x][y];
        }
    }
      
    if (!k) {
        int t = solve();
        cout << (t == NO_ANS ? -1 : t);
        return 0;
    }else{
        for (int y = 0; y < n; y++) {
            for (int x = 0; x < n; x++) {
                int origin = grid[x][y];
                for (int i = 0; i < 6; i++) {
                    if (origin == i) continue;
                    grid[x][y] = i;
                    int t = solve();
                    ans = min(ans, t);
                    //cout << endl << endl;
                }
                grid[x][y] = origin;
            }
        }
    }
      
    cout << (ans == NO_ANS ? -1 : ans);
      
}
