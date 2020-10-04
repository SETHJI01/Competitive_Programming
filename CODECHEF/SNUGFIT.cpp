#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        long long int arr1[n],arr2[n],sum=0;
        for(i=0;i<n;i++)
            cin>>arr1[i];
        for(i=0;i<n;i++)
            cin>>arr2[i];
        sort(arr1,arr1+n);
        sort(arr2,arr2+n);
        for(i=0;i<n;i++)
        {
            sum=sum+min(arr1[i],arr2[i]);
        }
        cout<<sum<<endl;


    }
    return 0;
}