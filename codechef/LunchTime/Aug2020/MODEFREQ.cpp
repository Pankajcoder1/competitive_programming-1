/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;typedef unsigned long long ull;
/*** Input Output ***/
#define sc(a) cin >> a
#define pf(a) cout << a << endl
/*** Loops ***/
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
/*** Define Values ***/
#define mod 1000000007
/*** Abbrevations **/
#define pb push_back
#define ff first
#define ss second
#define mem(name, value) memset(name, value, sizeof(name))
/*** Sorts ***/
#define all(v) (v).begin(), (v).end()
#define srt(v) sort(all(v))
/*** Bit-Stuff ***/
#define GET_SET_BITS(a) (__builtin_popcount(a))
#define GET_SET_BITSLL(a) ( __builtin_popcountll(a))
#define GET_TRAIL_ZERO(a) (__builtin_ctz(a))
#define GET_LEAD_ZERO(a) (__builtin_clz(a))
#define GET_PARITY(a) (__builtin_parity(a))
/*** Some Prints ***/
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
/*----------------------------------------------------------------*/
bool cmp(pair<int, int> a, pair<int, int> b) {
    if(a.ff == b.ff) {
        return a.ss < b.ss;
    }

    return a.ff > b.ff;
}
void solve() {
    int n;
    sc(n);

    int arr[11];
    mem(arr, 0);

    int x;
    for(int i = 0;i < n;i++) {
        sc(x);
        arr[x]++;
    }

    map<int, int> mp;
    for(int i = 1;i <= 10;i++) {
        if(arr[i] != 0) {
            mp[arr[i]]++;
        }
    }

    vector<pair<int, int>> store;
    for(auto it : mp) {
        store.pb({it.ss, it.ff});
    }

    sort(all(store), cmp);
    pf(store[0].ss);
}

int main() {
    FAST_IO
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t;
    sc(t);

    while(t--) {
        solve();
    }

    return 0;
}