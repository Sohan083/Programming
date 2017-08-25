#include<bits/stdc++.h>
#define ll long long
#define write freopen("out.txt","w",stdout)
#define read freopen("in.txt","r",stdin)
using namespace std;
vector<int>prime;
//map<int,bool>mark;
bool mark[1000002];
void seive()
{
    prime.push_back(2);
    for(int i=4;i<=1000000;i+=2)
    {
        mark[i]=1;
    }
    int sq=sqrt(1000002);
    for(int i=3;i<=sq;i+=2)
    {
        if(mark[i]!=1)
        {
            //cout<<i<<endl;
            prime.push_back(i);
            for(int j=i*i;j<=1000000;j+=i+i)
            {
                mark[j]=1;
            }
        }
    }
    if(sq%2==0) sq++;
    for(int i=sq;i<=1000000;i+=2) if(mark[i]!=1)prime.push_back(i);
}

int main()
{
    //read;
    //write;
    seive();
    //cout<<prime[prime.size()-1]<<endl;
    //cout<<1<<endl;
    //for(int i=0;i<id;i++) cout<<prime[i]<<endl;
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        ll n;
        scanf("%lld",&n);
        int sum=1;
        int sq=sqrt(n);
        for(int j=0;j<prime.size() && prime[j]<=sq;j++)
        {
            int c=0;
            if(n<prime[j])
                break;
            while(n%prime[j]==0)
            {
                c++;
                n/=prime[j];
            }
            sum=sum*(c+1);
        }
        if(n>1) sum*=2;
        sum--;
        printf("Case %d: %d\n",i,sum);
    }
}
