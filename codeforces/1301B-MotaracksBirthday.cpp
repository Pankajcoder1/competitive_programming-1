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
void solve() {
    int n;
    sc(n);

    vector<ll> v(n);
    forIn(v, n);

    ll mn = LONG_LONG_MAX, mx = LONG_LONG_MIN;
    for(int i = 0;i < n;i++) {
        if(i > 0 && v[i] == -1 && v[i - 1] != -1) {
            mn = min(mn, v[i - 1]);
            mx = max(mx, v[i - 1]);
        }

        if(i < n - 1 && v[i] == -1 && v[i + 1] != -1) {
            mn = min(mn, v[i + 1]);
            mx = max(mx, v[i + 1]);
        }
    }

    ll res = (mn + mx) / 2;
    for(int i = 0;i < n;i++) {
        if(v[i] == -1) {
            v[i] = res;
        }
    }

    ll ans = 0;
    for(int i = 0;i < n - 1;i++) {
        ans = max(ans, abs(v[i] - v[i + 1]));
    }

    cout << ans << " " << res << endl;   
}

int main() {
    go();
    int t;
    sc(t);

    while(t--) {
        solve();
    }

    return 0;
}