#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6 + 10;
int fail[maxn];
void get_fail(string s)
{
    int m = s.length();
    int j = 0;
    for (int i = 1; i < m; i++)
    {
        while (j && s[i] != s[j])
        {
            j = fail[j];
        }
        j += (s[i] == s[j]);
        fail[i + 1] = j;
    }
}
bool kmp(string s, string t)
{
    int j = 0;
    int m = t.length();
    t = " " + t;
    for (int i = 0; i < s.length(); i++)
    {
        while (j && t[j + 1] != s[i])
            j = fail[j];
        j += (t[j + 1] == s[i]);
        if (j == m)
        {
            return 1;
        }
    }
    return 0;
}
string s[21];
int dp[1 << 20][20];
int n;
int mp[21][21];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    memset(dp, 0x3f, sizeof dp);
    int val = dp[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            string s2 = s[j] + '#' + s[i];
            cout << s2 << endl;
            get_fail(s2);
            if (kmp(s[i], s[j]))
            {
                continue;
            }
            else
            {
                mp[i][j] = s[j].length() - fail[s2.length()];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        dp[1 << i][i] = s[i].length();
    }
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dp[i][j] == val)
                continue;
            else
            {
                for (int k = 0; k < n; k++)
                {
                    if ((i >> k) & 1)
                    {
                        continue;
                    }
                    else
                    {
                        if (mp[j][k] == 0)
                        {
                            dp[i | (1 << k)][j] = min(dp[i | (1 << k)][j], dp[i][j]);
                        }
                        else
                        {
                            dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + mp[j][k]);
                        }
                    }
                }
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++)
    {
        ans = min(ans, dp[(1 << n) - 1][i]);
    }
    cout << ans;
}