#include <bits/stdc++.h>

using namespace std;

bool isEdge(int i, int j, int x, int y)
{
    if (i == 0 || j == 0 || i == x - 1 || j == y - 1)
        return true;
    return false;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
   int n, m ;
   cin >> n >> m;
   cout << min(n, m ) << " " << max(n , m) << '\n';

    }

    return 0;
}