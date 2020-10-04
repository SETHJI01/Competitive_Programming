#include <bits/stdc++.h>

using namespace std;


int main()
{
    int t,n,x;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++)
        {
            a[i]=0;b[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>x;
                a[i] += x;
                b[j] += x;
            }
        }bool status;
        for(int i=0;i<n;i++)
        {
            int j=0;
            status = false;
            while(j<n)
            {
                if(a[i]==b[j])
                {
                    b[j]=-1;
                    status = true;
                    break;
                }
                j++;
            }
            if(!status)
                break;
        }
        if(status)
            cout<<"Possible"<<endl;
        else
            cout<<"Impossible"<<endl;
    }
}
