#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz size()
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

#define print(a) cout<<(#a)<<" = "<<a<<"  ";
#define println(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );

vector <string> parse(string s, string c)
{
  int len = c.length(), p = -len, np;
  vector <string> ans;

  do
    {
      np = s.find(c, p+len);
      ans.push_back(s.substr(p+len, np - p - len));
      p = np;
    }
  while (p != string::npos);

  return ans;
}


/*Solution code starts here */

#define mod 1000000007

ll dp[31];

int id( ll in)
{
     for(int i=1;i<=30;i++)
          if(dp[i]==in)
            return i;

            return -1;
}

ll memo[100009][35];
ll ans[100009];

ll  solve( int n , int k)// n is
{
      cout<<n<< " "<<k<<endl;

     if( memo[n][k]!=-1)
          return memo[n][k];


     fill(ans,0);

     ans[0]=1;

     for(int i=1;i<=n;i++)
          for(int j=30;j>=1;j--)
              if(j!=k)
                {
                     int tp=i-dp[j];

                        if(tp>=0)
                       ans[i]=(ans[i]+ans[tp])%mod;
                }

             for(int i=0;i<=n;i++)
                 cout<<ans[i]<<".";

      return memo[n][k]=ans[n];

}


int main()
{
 ios_base::sync_with_stdio(0);

 dp[1]=1;
 dp[2]=2;

 for(int i=3;i<=30;i++)
      { dp[i]=dp[i-1]+dp[i-2];
          cout<<dp[i]<<"  ";
      }

      cout<<"\n\n";


    fill(memo,-1) ;

    int q;

    cin>>q;

    for(int j=1;j<=q;j++)
    {
         ll n ,k;

         cin>>n>>k;

         cout<<solve( n , id(k) )<<endl;
    }


 return 0;

}
