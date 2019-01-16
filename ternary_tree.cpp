#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

typedef struct pair<int,int> II;


long long dp[109][109];
int a[109];
int pos[109];
II seg[4*100+9];

void build(int n,int l,int r)
{
    if(l==r)
    {
        seg[n].first=pos[a[l]];
        seg[n].second=pos[a[l]];
        return;
    }
    int m=l+r>>1;
    build(2*n,l,m);
    build(2*n+1,m+1,r);
    seg[n].first=max(seg[2*n].first,seg[2*n+1].first);
    seg[n].second=min(seg[2*n].second,seg[2*n+1].second);
}

II query(int n,int l,int r,int L,int R)
{
    if(r<L||R<l)
    {
        return II(-1,100000000);
    }
    if(l>=L&&r<=R)
    {
        return seg[n];
    }
    int m=l+r>>1;
    II ans1=query(2*n,l,m,L,R);
    II ans2=query(2*n+1,m+1,r,L,R);
    return II(max(ans1.first,ans2.first),min(ans1.second,ans2.second));
}



int n;

long long f(int l,int r)
{
    //printf("%d %d\n",l,r);
    if(l>=r)
    {
        return 1;
    }
    if(dp[l][r])
    {
        return dp[l][r];
    }
    int d=a[l];
    int i=l+1;
    while(i<=r&&pos[a[i]]<pos[d])
    {
        i++;
    }
    i--;
    long long sum1=f(l+1,i);
    long long sum2=0;
    if(r==i)
    {
        sum2=1;
    }
    else
    {
        int j=i+1;
        sum2=2*f(i+1,r);
        //printf("2*{%d %d}\n",i+1,r);
        sum2%=mod;
        while(j<r)
        {
            int d1=query(1,1,n,i+1,j).first;
            int d2=query(1,1,n,j+1,r).second;
            //printf("(%d %d) {%d %d}*{%d %d}\n",d1,d2,i+1,j,j+1,r);
            if(d1<d2)
            {
                sum2+=f(i+1,j)*f(j+1,r);
                sum2%=mod;
            }
            j++;
        }
    }
    //printf("%d %d %d\n",l,r,sum1*sum2);
    return dp[l][r]=(sum1*sum2)%mod;
}


int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        pos[x]=i;
    }
    build(1,1,n);
    printf("%d",f(1,n));
    return 0;
}
