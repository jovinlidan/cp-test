#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int mxN = 1e5 + 5;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    a %= b;
    return gcd(b, a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc, n, a, val;
    cin >> tc;

    while (tc--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            if (i == 0)
                val = a;
            val = gcd(val, a);
            if (i == n - 1)
                cout << a / val << '\n';
        }
    }
    return 0;
}
