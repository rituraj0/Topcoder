#include<iostream>
using namespace std;
int main()
{
    int t,k,c,w;
    cin>>t;
    do
    {
         cout<<"\n";
         cin>>c>>k>>w;
         if(c*w<=k)
          {
                       cout<<"\n Yes";
          }
         else
          {
                    cout<<"\n No";
          }
         t--;
    }while(t>=1);
 return 0;
}
