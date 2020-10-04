#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main()
{
    int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        int arr[n+1];
        bool status = true,check=true;
        for(int i=1;i<=n;i++)
        {
            if(check)
            {
                arr[i] = k+i;
                if(i==k)
                    check=false;
            }
            else
            {
                arr[i]=i-k;
            }
            if(fabs(arr[i]-i)!=k || arr[i]>n)
            {
                status=false;
                break;
            }
        }
        if(status)
        {
            for(int i=1;i<=n;i++)
                cout<<arr[i]<<" ";
        }
        else
            cout<<-1;
        cout<<endl;
    }
}
