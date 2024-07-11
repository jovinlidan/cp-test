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
        string s;
        cin >> s;

        int cont0 = 0;
        int cont1 = 0;

        vector<pair<int, int>> front;
        vector<pair<int, int>> back(s.length() + 5);

        for (int i = 0; i < s.length(); i++){
            if(s[i] == '0'){
                cont1 = 0;
                cont0++;
            }
            else if(s[i] == '1'){
                cont1++;
                cont0 = 0;
            }
            front.push_back({cont0, cont1});
        }
        cont0 = 0;
        cont1 = 0;
        for (int i = s.length() - 1; i >= 0; i--){
            if(s[i] == '0'){
                cont1 = 0;
                cont0++;
            }
            else if(s[i] == '1'){
                cont1++;
                cont0 = 0;
            }
            back[i] = {cont0, cont1};
        }
        int ans = 0;

        int longest01Idx = -1;
        int longest01 = 0;
        for(int i = 0; i < s.length() - 1; i++){
            if(s[i] == '0' && s[i+1] == '1'){
                if(front[i].first + front[i].second + back[i].first + back[i].second > longest01){
                    longest01 = front[i].first + front[i].second + back[i].first + back[i].second;
                    longest01Idx = i;
                }
            }
        }
        for(int i = 0 ; i < s.length()- 1; i++){
            if(s[i] == '0' && s[i+1] == '1' && i != longest01Idx){
                // cout << i << " - ";
                ans++;
            }
            else if(s[i] == '1' && s[i+1] == '0'){
                // cout << i << " -- ";
                ans++;
            }
        }

        cout << ans+1 << '\n';
        


   }

    return 0;
}