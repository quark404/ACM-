#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k;
const int maxn = 5e3 + 10;
string s[maxn];
int rk[maxn];
vector<int> pr[3001][26];
int pre[maxn][3001];
signed main()
{
   ios::sync_with_stdio(false);
   cin.tie(0), cout.tie(0);
   cin >> n >> m >> k;
   for (int i = 1; i <= n; i++)
   {
      cin >> s[i];
   }
   for (int i = 1; i <= n; i++)
   {
      for (int j = 1; j <= m; j++)
      {
         if (s[i][j - 1] != '.')
            pr[j][s[i][j - 1] - 'A'].push_back(i);
      }
   }
   for (int i = 0; i < 26; i++)
   {
      int now = 0;
      for (int j = 1; j <= m; j++)
      {
         now = 0;
         for (auto x : pr[j][i])
         {
            pre[x][j] = now;
            now = x;
         }
      }
   }
   int val = -1;
   for (int i = 2; i <= n; i++)
   {
      for (int j = 1; j <= i - 1; j++)
      {
         rk[j] = 0;
      }
      int ok = 0;
      for (int j = 1; j <= m; j++)
      {
         int now = i;
         while (now)
         {
            now = pre[now][j];
            rk[now]++;
            if (rk[now] >= k)
            {
               ok = max(ok, now);
            }
            if (rk[now] >= k && now == i - 1)
            {
               cout << i - 1 << ' ' << i;
               return 0;
            }
         }
      }
      if (ok)
      {
         cout << ok << ' ' << i;
         return 0;
      }
   }
   cout << -1;
}