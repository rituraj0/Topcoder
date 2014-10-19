#include<algorithm>
#include<iostream>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<fstream>
#include <iomanip>
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
#include<set>
using namespace std;

#define pb push_back
#define mp make_pair
#define Y second
#define X first

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

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

#define pi  3.1415926535897932384626433832795


int n;
double l,r;
double x[25],y[25],an[25];
double dp[1<<21];

int main()
{
 ios_base::sync_with_stdio(0);

 cout<<fixed<<setprecision(15);

 cin>>n>>l>>r;

 for(int i=0;i<n;i++)
      cin>>x[i]>>y[i]>>an[i];

  for(int i=0;i<(1<<21);i++)
      dp[i]=-100000000000000;

  dp[0]=l;

  for(int mask=0; mask<(1<<n) ;mask++ )
     for(int i=0;i<n;i++)
       if( (mask&(1<<i))==0 )
        {
          double rem=atan( (dp[mask]-x[i])/y[i] ) + an[i]/180.0*pi;

          double nl;

          if( rem > pi/2-0.000000001)
              nl=r;
          else
              nl=min(r , x[i] + tan(rem)*y[i] );

          dp[ mask|(1<<i)]=max( dp[ mask|(1<<i)] , nl );

        }


   cout<<dp[(1<<n)-1]-l<<endl;

 return 0;

}
