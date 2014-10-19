#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
#define sz(s) ((int)(s.size()))

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

class StrongEconomy
{
public:


ll solve( ll p , ll f , ll old , ll tar , ll done)
{
     ll income=p*f;
     ll req=max(tar-old,0LL);
     ll cr=(req+income-1)/income;
     return (cr+done);
}


long long earn(long long p, long long f, long long cost, long long tar)
{

    if( (p>(1e6))  && (f>(1e6)) )
         return 1;

    ll old=0;

    ll ans=solve(p,f,old,tar,0);

    for(int r=1;r<(1e7);r++)
    {
        if( (p>(1e6))  && (f>(1e6)) )
            break;

       ll income=p*f;

       ll can=(income+old)/cost;

       old+=income;

       for(ll i=0;i<can;i++)
       {

            old-=cost;

            if( p < f)
             p++;
            else
              f++;

            ans=min(ans,solve(p,f,old,tar,r) );


          if( (p>(1e6))  && (f>(1e6)) )
            break;
       }

    }


    return ans;

}

};

int main()
{


}
