#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
#define pis pair<int, string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    ll n, total = 0, temp;
    ll arr[55] = {};

    while (tc--)
    {
        cin >> n;
        total = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            total += arr[i];
        }
        if (total % 2 == 0)
        {
            cout << 0 << '\n';
            continue;
        }
        else
        {
            int mn = 1e9;
            int cnt = 0;
            for (int i = 0; i < n; i++)
            {
                temp = total;
                cnt = 0;
                while (temp % 2 == 1)
                {
                    temp -= ceil(arr[i] / 2.0);
                    arr[i] /= 2;
                    cnt++;
                }
                mn = min(mn, cnt);
            }
            cout << mn << '\n';
        }
    }

    return 0;
}