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

int main() {
    FAST_IO
    ll n;
    sc(n);

    vll v(n, 0);
    forIn(v, n);

    ll cur1 = 1;
    ll cur2 = 2;
    int flag = 0;
    for0(n) {
        if(v[i] != cur1 && v[i] != cur2) {
            flag = 1;
            break;
        } else {
            if(v[i] == 1) {
                if(cur1 == 1) {
                    if(cur2 == 2) {
                        cur2 = 3;
                    } else if(cur2 == 3) {
                        cur2 = 2;
                    }
                } else if(cur2 == 1) {
                    if(cur1 == 2) {
                        cur1 = 3;
                    } else if(cur1 == 3) {
                        cur1 = 2;
                    }
                }
            } else if(v[i] == 2) {
                if(cur1 == 2) {
                    if(cur2 == 1) {
                        cur2 = 3;
                    } else if(cur2 == 3) {
                        cur2 = 1;
                    }
                } else if(cur2 == 2) {
                    if(cur1 == 1) {
                        cur1 = 3;
                    } else if(cur1 == 3) {
                        cur1 = 1;
                    }
                }
            } else if(v[i] == 3){
                if(cur1 == 3) {
                    if(cur2 == 1) {
                        cur2 = 2;
                    } else if(cur2 == 2) {
                        cur2 = 1;
                    }
                } else if(cur2 == 3) {
                    if(cur1 == 1) {
                        cur1 = 2;
                    } else if(cur1 == 2) {
                        cur1 = 1;
                    } 
                }
            }
        }
    }

    if(flag == 0) {
        yes;
    } else {
        no;
    }

    return 0;
}