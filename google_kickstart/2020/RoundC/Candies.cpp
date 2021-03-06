/*** I came, I saw, I conquered. ***/
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;typedef unsigned long long ull;
/*** Input Output ***/
#define sc(a) cin >> a
#define pf(a) cout << a << endl
/*** Loops ***/
#define for0(num) for(ll i = 0; i < num; i++)
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
/*** Swapping ***/
void swapll(ll *a,ll *b){ll tmp=*a;*a=*b;*b=tmp;}
void swapc(char *a,char *b){char tmp=*a;*a=*b;*b=tmp;}
/*----------------------------------------------------------------*/
struct Node{
    ll sum, sumA, size;
    
    void init(ll value) {
        sum = sumA = value;
        size = 1;
    }

    void merge(Node L, Node R) {
        size = L.size + R.size;
        sum = L.sum + R.sum;
        sumA = L.sumA + R.sumA + (ll) R.sum * L.size;
    }
};

ll x = 1;
void solve() {
    ll n, q;
    sc(n);
    sc(q);

    vll a(n + 1);
    for(ll i = 1;i <= n;i++) {
        sc(a[i]);

        if(i % 2 == 1) {
            a[i] *= -1;
        }   
    }

    int B = 1;
    while(B <= n) {
        B *= 2;
    }

    vector<Node> tree(2 * B);
    for0(B) {
        tree[B + i].init(0);
    }

    for(ll i = 1;i <= n;i++)  {
        tree[B + i].init(a[i]);
    }

    for(ll i = B - 1;i >= 1;i--) {
        tree[i].merge(tree[2 * i], tree[2 * i + 1]);
    }

    ll total = 0;
    while(q--) {
        char type;
        sc(type);

        if(type == 'U') {
            ll id, value;
            sc(id);
            sc(value);

            if(id % 2 == 1) {
                value *= -1;
            }

            tree[B+id].init(value);
            for(ll i = (B + id) / 2;i >= 1;i /= 2) {
                tree[i].merge(tree[2 * i], tree[2 * i + 1]);
            }
        } else {
            ll L, R;
            sc(L);
            sc(R);

            bool sign = L % 2;
            L += B;
            R += B;

            bool single = (L == R);
            Node left, right;
            left = tree[L];
            right = tree[R];

            while(L + 1 < R) {
                if(L % 2 == 0) {
                    left.merge(left, tree[L + 1]);
                }

                if(R % 2 == 1) {
                    right.merge(tree[R - 1], right);
                }

                L /= 2;
                R /= 2;
            }

            Node answer = left;
            if(!single) {
                answer.merge(left, right);
            }

            if(sign) {
                answer.sumA *= -1;
            }

            total += answer.sumA;
        }
    }

    string out = "Case #" + to_string(x) + ": " + to_string(total);
    pf(out);
    x++;
}

int main() {
    FAST_IO
    ll testcases;
    sc(testcases);

    while(testcases--) {
        solve();
    }
    return 0;
}