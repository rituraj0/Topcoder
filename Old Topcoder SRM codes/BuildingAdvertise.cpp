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

typedef long long ll;

vector<ll> in;

class BuildingAdvertise
{
public:

    ll solve( )
    {
        in.pb(0);

        ll ans=0;

        int i=0;

        stack<ll> st;

        while(i < in.size() )
        {
            if( (st.size()==0) || (in[st.top()] <=in[i]) )
            {
                st.push( i++ );
            }
           else
           {
                    ll tp=st.top() ; st.pop();

                    ll len=0;

                    if( st.size()==0)
                        len=i;
                     else
                          len=i-1-st.top();

                     ans=max( ans, in[tp]*len);
           }
        }

        return ans;
    }


long long  getMaxArea(vector <int> h, int n)
{
    in.resize(n);

     int m=h.size();
     int j=0;

     for(int i=0;i<n;i++)
     {
        in[i]=h[j];
        int s=(j+1)%m;
        h[j]=( (h[j]^h[s])+13)%835454957;
        j=s;
     }

     return solve();

}

};
