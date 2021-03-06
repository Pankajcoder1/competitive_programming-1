/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;typedef unsigned long long ull;
#define sc(a) cin >> a
#define pf(a) cout << a << endl
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
#define mod 1000000007
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
void go() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
/*----------------------------------------------------------------*/
int grid[2501][2501];
void solve() {
    int n, m;
    cin >> n >> m;

    string str;
    for(int i = 0;i < n;i++) {
        cin >> str;
        for(int j = 0;j < m;j++) {
            grid[i][j] = str[j] - '0';
        }
    }

    int sum;
    for(int i = 0;i < n;i++) {
        sum = 0;
        for(int j = 0;j < m;j++) {
            sum += grid[i][j];
            grid[i][j] = sum;
            if(i - 1 >= 0) {
                grid[i][j] += grid[i - 1][j];
            }
        }
    }

    int ans = 2500 * 2500, gsum;
    for(int i = 2;i <= max(n, m);i++) {
        sum = gsum = 0;
        for(int j = 0;j < n;j += i) {
            for(int k = 0;k < m;k += i) {
                int x = min(j + i - 1, n - 1);
                int y = min(k + i - 1, m - 1);
                sum = grid[x][y];

                if(j - 1 >= 0 && k - 1 >= 0) {
                    sum += grid[j - 1][k - 1];
                }

                if(j - 1 >= 0) {
                    sum -= grid[j - 1][y];
                }

                if(k - 1 >= 0) {
                    sum -= grid[x][k - 1];
                }

                gsum += min(sum, i * i - sum);
            }
        }
        ans = min(ans, gsum);
    }

    pf(ans);
}

int main() {
    go();
    solve();
    return 0;
}