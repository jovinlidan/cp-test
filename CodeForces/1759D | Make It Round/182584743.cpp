#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int tc, two, five, nn;
    ll n, m;

    cin >> tc;

    while (tc--)
    {
        cin >> n >> m;
        nn = n;
        two = five = 0;
        ll ans = 1;
        while (n % 2 == 0)
        {
            n /= 2;
            two++;
        }

        while (n % 5 == 0)
        {
            n /= 5;
            five++;
        }

        int mn = min(five, two);

        five -= mn;
        two -= mn;

        while (two > 0 && ans * 5 <= m)
        {
            ans *= 5;
            two--;
        }
        while (five > 0 && ans * 2 <= m)
        {
            ans *= 2;
            five--;
        }

        while (ans * 10 <= m)
        {
            ans *= 10;
        }

        for (int i = 9; i >= 2; i--)
        {
            if (ans * i <= m)
            {
                ans *= i;
                break;
            }
        }
        cout << ans * nn << '\n';
    }
}