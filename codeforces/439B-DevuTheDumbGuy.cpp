#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a[100005];

int main() {
    int n, x;
    cin >> n >> x;

    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    ll ans = 0;
    for(int i = 0;i < n;i++) {
        ans += a[i] * max(x - i, 1);
    }
    
    cout << ans << endl;
    return 0;
}