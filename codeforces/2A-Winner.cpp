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
const int MAX = 1e3 + 5;
string names[MAX];
int score[MAX];
void solve() {
    int n;
    sc(n);

    map<string, int> man;
    for(int i = 0;i < n;i++) {
        cin >> names[i] >> score[i];
        man[names[i]] += score[i];
    }

    int mx = -1;
    for(int i = 0;i < n;i++) {
        mx = max(mx, man[names[i]]);
    }

    map<string, int> b;
    for(int i = 0;i < n;i++) {
        b[names[i]] += score[i];
        if(b[names[i]] >= mx && man[names[i]] >= mx) {
            pf(names[i]);
            break;
        }
    }
}

int main() {
    go();
    solve();
    return 0;
}