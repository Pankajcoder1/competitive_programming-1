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
const int MAX = 2e5 + 5;
int n, m;
int deg[MAX];
bool used[MAX];
vector<int> comp;
vector<int> g[MAX];
void dfs(int v) {
    used[v] = true;
    comp.pb(v);

    for(auto it : g[v]) {
        if(!used[it]) {
            dfs(it);
        }
    }
}

void solve() {
    cin >> n >> m;
    memset(deg, 0, sizeof(deg));
    memset(used, false, sizeof(used));

    int src, dest;
    for(int i = 0;i < m;i++) {
        cin >> src >> dest;
        src--, dest--;
        g[src].pb(dest);
        g[dest].pb(src);

        deg[src]++;
        deg[dest]++;
    }

    int ans = 0;
    for(int i = 0;i < n;i++) {
        if(!used[i]) {
            if(!comp.empty()) {
                comp.clear();
            }
            
            dfs(i);
            bool ok = true;
            for(auto it : comp) {
                ok &= (deg[it] == 2);
            }

            if(ok) {
                ans++;
            }
        }
    }

    pf(ans);
}

int main() {
    go();
    solve();
    return 0;
}