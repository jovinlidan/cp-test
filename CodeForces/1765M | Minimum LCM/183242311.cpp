#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    a %= b;
    return gcd(b, a);
}
ll lcm(ll a, ll b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc, a, b;
    bool flag = false;
    cin >> tc;
    ll mn = 1e18;
    while (tc--)
    {
        ll n;
        flag = false;
        cin >> n;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                a = n / i;
                b = n - (n / i);
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << 1 << " " << n - 1 << '\n';
        else
            cout << a << " " << b << '\n';
    }
    return 0;
}
