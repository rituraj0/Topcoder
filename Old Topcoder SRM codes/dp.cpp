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
typedef long long ll;
#define pii pair<ll,ll>

ll n;
ll k;
ll pt[200010];
ll est[200010];

bool win[200010];

bool comp( pii a , pii b)
{
     if( a.X > b.X)
         return true;

      if( a.Y==n)
      {
          if( win[ b.Y] )
            return true;
      }

      return false;
}

bool solve(ll curr)
{
     cout<<curr<<"---\n";

    vector<pii> all;

    ll np=0;

    memset(win,0,sizeof(win) );

    for(int i=0;i<n;i++)
          if( curr >=est[i] )
          {
              win[i]=true;
              np++;
              all.pb( mp(pt[i],i) );
              curr=curr-est[i];
          }
         else
         {
             all.pb( mp( pt[i]+1 , i) );
          }

         all.pb( mp(np,n) );

         sort( all.begin(),all.end(),comp);

//         for(int i=0;i<all.size();i++)
//             cout<<all[i].X<<" - "<<all[i].Y<<endl;

         ll ans=n+1;

         for(int i=0;i<n+1;i++)
              if( all[i].Y==n)
                ans=i;



         if( ans <=k-1)
               return true;

         return false;

}

int main()
{
	 ios_base::sync_with_stdio(0);

	 cin>>n>>k;

	 for(int i=0;i<n;i++)
         cin>>pt[i]>>est[i];

     ll lo=0,hi=(1LL<<60);

     ll ans=-1;

     cout<<solve(3)<<endl;

     while( lo <= hi)
     {
           ll mid=(lo+hi)/2;

           if( solve(mid))
           {
               ans=mid;
               hi=mid-1;
           }
           else
           {
                lo=mid+1;
           }
     }

     cout<<ans<<endl;

 return 0;

}
