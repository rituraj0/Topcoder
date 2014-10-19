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

vector<int> all[30];

int main()
{
 ios_base::sync_with_stdio(0);

 string in;

 cin>>in;

 for(int i=0;i<in.size();i++)
    all[ in[i]-'A'].pb(i);

   int ans=0;



   for(int i=0;i<30;i++)
   {

        if( all[i].size()==0)
             continue;

            for(int st=0;st<all[i].size();st++)
            {

                   int tp=1;

                   int prev=st;

                   for(int j=st+1;j<all[i].size();j++)
                      if(  (all[i][j] - all[i][prev] )&1 )
                        {
                            tp++;
                            prev=j;
                        }

                     ans=max( ans , tp);
            }

   }

   cout<<ans<<endl;

 return 0;

}
