#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1; i<=t; i++)
    {
        int n;
        scanf("%d",&n);
        stack<int>st;
        int ar[30000];
        for(int j=1; j<=n; j++)
        {
            scanf("%d",&ar[j]);
        }
        st.push(0);
        ar[0]=-1;
        int lb[30000];
        int up[30000];
        for(int j=1; j<=n; j++)
        {
            int t=st.top();
            if(ar[j]>ar[t])
            {
                lb[j]=t;
                //cout<<lb[j]<<endl;
                st.push(j);
            }
            else
            {
                while(ar[j]<=ar[t] && !st.empty())
                {
                    st.pop();
                    t=st.top();
                }
                lb[j]=t;
                st.push(j);
            }
        }
        while(!st.empty()) st.pop();
        st.push(n+1);
        ar[n+1]=-1;
        for(int j=n; j>=1; j--)
        {
            int t=st.top();
            if(ar[j]>ar[t])
            {
                up[j]=t;
                st.push(j);
            }
            else
            {
                while(ar[j]<=ar[t] && !st.empty())
                {
                    st.pop();
                    t=st.top();
                }
                up[j]=t;
                st.push(j);
            }
        }
        int ans=-1;
        for(int j=1; j<=n; j++)
        {
            int bo=up[j]-lb[j]-1;
            int x=bo*ar[j];
            ans=max(ans,x);
        }
        printf("Case %d: %d\n",i,ans);
    }
}
