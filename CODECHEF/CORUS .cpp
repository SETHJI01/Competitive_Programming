#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char S[100000];
    int k;
    unsigned long int T,N,Q,i,count=0;
    unsigned long long int C,arr[30];
    cin>>T;
    while(T--)
    {
        cin>>N>>Q;
        cin>>S;
        for(i=0;i<26;i++)
        {
            arr[i]=0;
        }i=0;
        while(S[i]!='\0')
        {
            k=S[i];
            arr[k-97]++;i++;
        }
        S[N]='\0';
        while(Q--)
        {

            count=0;
            cin>>C;

            for(i=0;i<26;i++)
            {
                if(arr[i]>C)
                    count+=arr[i]-C;
            }
            cout<<count<<endl;
        }
    }
}