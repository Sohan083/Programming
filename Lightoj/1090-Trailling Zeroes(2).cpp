#include<bits/stdc++.h>
#define ll long long
#define write freopen("out.txt","w",stdout)
#define read freopen("in.txt","r",stdin)
using namespace std;
//vector<int>prime;
////map<int,bool>mark;
//bool mark[1000002];
//void seive()
//{
//    prime.push_back(2);
//    for(int i=4;i<=1000000;i+=2)
//    {
//        mark[i]=1;
//    }
//    int sq=sqrt(1000002);
//    for(int i=3;i<=sq;i+=2)
//    {
//        if(mark[i]!=1)
//        {
//            //cout<<i<<endl;
//            prime.push_back(i);
//            for(int j=i*i;j<=1000000;j+=i+i)
//            {
//                mark[j]=1;
//            }
//        }
//    }
//    if(sq%2==0) sq++;
//    for(int i=sq;i<=1000000;i+=2) if(mark[i]!=1)prime.push_back(i);
//}
int cal(int val, int p) {
  int ans = 0;
  int b = p;
  while (b <= val) {
    ans += val / b;
    b *= p;
  }
  return ans;
}
int po(int x,int y)
{
    int c=0;
    while(x%y==0)
    {
        c++;
        x/=y;
    }
    return c;
}
int main()
{
    //read;
    write;
    //seive();
    //cout<<prime[prime.size()-1]<<endl;
    //cout<<1<<endl;
    //for(int i=0;i<id;i++) cout<<prime[i]<<endl;
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        //int fc2=0,fc5=0;
        int n,r,p,q;
        scanf("%d %d %d %d",&n,&r,&p,&q);
        int c2=0,c5=0;
        c2+=cal(n,2);
        c5+=cal(n,5);
        c2-=cal(r,2);
        c5-=cal(r,5);
        c2-=cal(n-r,2);
        c5-=cal(n-r,5);
        c2+=(q*po(p,2));
        c5+=(q*po(p,5));
        printf("Case %d: %d\n",i,min(c2,c5));
    }
}
