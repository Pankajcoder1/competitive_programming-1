/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;typedef unsigned long long ull;
/*** Input Output ***/
#define sc(a) cin >> a
#define pf(a) cout << a << endl
/*** Loops ***/
#define f(i, p, num) for(ll i = p; i < num; i++)
#define forIn(arr, num) for(ll i = 0; i < num; i++) cin >> arr[i];
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
/*** Define Values ***/
#define mod1 1000000007
#define mod2 998244353
#define eps 1e-7
/*** Abbrevations **/
#define pb push_back
#define ff first
#define ss second
#define mem(name, value) memset(name, value, sizeof(name))
/*** STLs ***/
typedef vector<ll>vll;typedef set<ll>sll;typedef multiset<ll>msll;
typedef map<ll,ll>mll;typedef pair<ll,ll>pll;
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
void solve() {
    string line;
    int cases = 0;
    while(getline(cin, line)) {
        int v[7200] = {}, x;
        int i, j, k, cnt = 0;
        stringstream sin(line);
        int mx = 0xfffffff, time = 0xfffffff;
        while(sin >> x) {
            mx = min(mx, x);
            int base = -x;
            cnt++;
            while(base <= 3600) {
                base += x; // red
                for(i = base+1, j = 0; j < x-5; i++, j++)
                    v[i]++;
                base += x;
            }
        }
        for(i = mx; i <= 3601; i++) {
            if(v[i] == cnt) {
                time = i;
                break;
            }
        }
        time--;
        printf("Set %d ", ++cases);
        if(time <= 3600) {
            printf("synchs again at %d minute(s) and %d second(s) after all turning green.\n", time/60, time%60);
        } else {
            puts("is unable to synch after one hour.");
        }
    }
}

int main() {
    FAST_IO
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    solve();
    return 0;
}