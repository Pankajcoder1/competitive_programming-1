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
    int n;
    sc(n);

    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));
    int x;
    f(i, 2, n + 1) {
        sc(x);
        arr[i][x] = 1;
    }

    int flag1 = 0;
    int cnt = 0;
    int flag2 = 0;
    int flag3 = 0;
    f(i, 0, n + 1) {
        cnt = 0;
        flag2 = 0;
        f(j, 0, n + 1) {
            if(arr[j][i] == 1) {
                flag2 = 1;
                flag3 = 0;
                f(k, 0, n + 1) {
                    if(arr[k][j] == 1) {
                        flag3 = 1;
                        break;
                    }
                }

                if(!flag3) {
                    cnt++;
                }
            }
        }

        if(flag2) {
            if(cnt >= 3) {
                continue;
            } else {
                flag1 = 1;
                break;
            }
        }
    }

    if(flag1) {
        pf("No");
    } else {
        pf("Yes");
    }
}

int main() {
    FAST_IO
    solve();
    return 0;
}