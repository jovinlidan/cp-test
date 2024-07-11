#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll f(ll x)
{
    ll cur = 1;
    while (cur <= x)
    {
        cur *= 2;
    }
    return cur;
}
void solve()
{
    ll n;
    cin >> n;
    cout << n << "\n";
    for (ll i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        cout << i << " " << f(x) - x << "\n";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}