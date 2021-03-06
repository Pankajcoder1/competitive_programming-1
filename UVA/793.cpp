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
map<int, int> mp;
void initialize(int n) {
    for(int i = 1;i <= n;i++) {
        mp[i] = i;
    }
}

int find_set(int x) {
    if(mp[x] == x) {
        return x;
    }

    return find_set(mp[x]);
}

void union_set(int a, int b) {
    int x = find_set(a), y = find_set(b);
    mp[x] = y;
}

bool is_interconnected(int x, int y) {
    if(find_set(x) == find_set(y)) {
        return true;
    }

    return false;
}

int main() {
    FAST_IO
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    char str[100000], type;
    int x, y, n, t;

    scanf("%d\n", &t);
    while(t--) {
        scanf("%d\n", &n);
        int cnt1 = 0, cnt2 = 0;

        initialize(n);
        while(fgets(str, sizeof(str), stdin)) {
            if(str[0] == '\n') {
                break;
            }

            sscanf(str, "%c%d%d", &type, &x, &y);
            if(type == 'c') {
                union_set(x, y);
            } else if(type == 'q') {
                if(is_interconnected(x, y)) {
                    cnt1++;
                } else {
                    cnt2++;
                }
            }

        }

        cout << cnt1 << "," << cnt2 << endl;
        if(t > 0) {
            cout << endl;
        }
    }

    return 0;
}