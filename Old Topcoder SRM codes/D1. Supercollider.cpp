#include<algorithm>
#include<iostream>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<fstream>
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

const double pi     =   acos(-1.0);
const double eps    =   1e-8;



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

ll  in[3005];

int n,k;

ll buy( int i , int  j)
{

      ll a1=buy(i-1,j);
      ll a2=sell(i-1,j-1) - in[i];

      return  bm[i][j]=max(a1,a2);

}

ll sell( int i  , int j)
{
       if(i==0 && j==0)
          return 0;

       if( i < )

       ll a1=sell(i-1,j);
       ll a1=buy( i-1,j-1) + in[i];

       reurn sm[i][j]=max(a1,a2);

}

int main()
{
 ios_base::sync_with_stdio(0);

 cin>>n>>k;

 for(int i=1;i<=n;i++)
      cin>>in[i];

   memset( sm ,  -1 , sizeof(sm));
   memset( bm , -1, sizeof(bm) );

 return 0;

}
