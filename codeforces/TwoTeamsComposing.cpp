/*
    A quantum in a binary world.
*/
#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
/*** Input Output ***/
#define sci1(a) scanf("%d",&a)
#define sc1(a) scanf("%lld",&a)
#define pf1(a) printf("%d\n",a)
#define pfll1(a) printf("%lld\n",a)
#define pfll2(a,b) printf("%lld %lld\n",a,b)
/*** Loops ***/
#define foR0(num) for(ll i = 0; i < num; i++)
#define foR1(num) for(ll i = 1; i <= num; i++)
#define foRev(num) for(ll i = num - 1; i >= 0; i--)
#define forIn(arr, num) for(ll i = 0; i < num; i++) sc1(arr[i]);
#define forIn1(arr, num) for(ll i = 1; i <= num; i++) sc1(arr[i]);
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
#define apnt(arr, num) for(ll i = 0; i < num; i++) cout << arr[i] << (i + 1 < num ? ' ' : '\n');
/*** Define Values ***/
#define mod 1000000007
#define eps 1e-7
/*** Abbrevations **/
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define mem(name, value) memset(name, value, sizeof(name))
#define pp pair
/*** STLs ***/
typedef vector <ll> vll;
typedef set <ll> sll;
typedef multiset <ll> msll;
typedef queue <ll> qll;
typedef map <ll, ll> mll;
typedef pair <ll, ll> pll;
typedef vector <pair <ll , ll> > vpll;
/*** Sorts ***/
#define all(v) (v).begin(), (v).end()
#define rev(v) reverse(all(v))
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
    int testcases;
    sci1(testcases);

    ll size;
    while(testcases--) {
        sc1(size);

        vll v(size, 0);
        forIn(v, size)

        mll m;
        for(ll i = 0;i < size;i++) {
            m[v[i]]++;
        }

        mll::iterator it = m.begin();
        ll largest_occurences = it->ss;
        for(it = m.begin();it != m.end();++it) {
            if(it->ss > largest_occurences) {
                largest_occurences = it->ss;
            }
        }
        
        ll ans = 0;
        if(m.size() > largest_occurences && m.size() > 1) {
            ans = largest_occurences;
        } else if(m.size() == largest_occurences) {
            ans = m.size() - 1;
        } else {
            ans = m.size();
        }

        pfll1(ans);
    }
    return 0;
}