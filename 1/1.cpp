#include <bits/stdc++.h>
using namespace std;
#define int long long
int f[44];
int a[44];
int n, m, val;
bool solve()
{
    for (int i = 1; i <= m; i++)
    {
        f[i] = (val) & 1;
        val /= 2;
    }
    for (int i = n; i > m; i--)
    {
        int c = 0;
        for (int j = 2; j + i - 1 <= n; j++)
        {
            if (!f[j] && f[j + i - 1])
                c++;
        }
        if (c == a[i - 1])
        {
            f[i] = 0;
        }
        else if (c == a[i - 1] - 1)
        {
            f[i] = 1;
        }
        else
            return 0;
    }
    for (int i = 1; i < n; i++)
    {
        int c=0;
        for(int j=1;j+i<=n;j++)
        {
            if(!f[j]&&f[j+i])
            {
                c++;
            }
        }
        if(c!=a[i])
        return 0;
    }
    return 1;
}
signed main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
    }
    m = (n + 1) / 2;
    for (int i = 0; i < (1 << m); i++)
    {
        val = i;
        if (solve())
        {
            for (int j = 1; j <= n; j++)
            {
                cout << f[j];
            }
            return 0;
        }
    }
    cout << -1;
}