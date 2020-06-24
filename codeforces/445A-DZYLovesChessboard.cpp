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
#define mp make_pair
#define mem(name, value) memset(name, value, sizeof(name))
#define pp pair
/*** STLs ***/
typedef vector<ll>vll;typedef set<ll>sll;typedef multiset<ll>msll;
typedef queue<ll>qll;typedef map<ll,ll>mll;typedef pair<ll,ll>pll;
typedef vector<pair<ll,ll>>vpll;
/*** Sorts ***/
#define all(v) (v).begin(), (v).end()
#define srt(v) sort(all(v))
#define srtGreat(v) sort(all(v), greater<ll>())
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
    int n, m;
    sc(n);
    sc(m);

    char arr[n][m];
    f(i, 0, n) {
        f(j, 0, m) {
            sc(arr[i][j]);
        }
    }

    f(i, 0, n) {
        f(j, 0, m) {
            if(arr[i][j] == '.') {
                if(i % 2 == 0 && j % 2 == 0) {
                    arr[i][j] = 'B';
                } else if(i % 2 == 0 && j % 2 != 0) {
                    arr[i][j] = 'W';
                } else if(i % 2 != 0 && j % 2 == 0) {
                    arr[i][j] = 'W';
                } else {
                    arr[i][j] = 'B';
                }
            }
        }
    }

    f(i, 0, n) {
        f(j, 0, m) {
            cout << arr[i][j];
        }
        cout << endl;
    }
}

int main() {
    FAST_IO
    solve();
    return 0;
}