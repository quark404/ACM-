#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e3+10;
int dp[maxn];
int a[maxn],b[maxn];
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,p;
    cin>>n>>p;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>b[i];
    }
    memset(dp,0x3f,sizeof dp);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dp[max(0ll,j-b[i])]<=1e8)
            {
                dp[j]=min(dp[j],dp[max(0ll,j-b[i])]+a[i]);
            }
        }
    }
    int ans=1e18;
    for(int i=0;i<n;i++)
    {
        ans=min(ans,dp[i]+(n-i)*p);
    }
    cout<<ans;

}