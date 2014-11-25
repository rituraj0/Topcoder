#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(s) ((int)(s.size()))
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
/*Solution code starts here */

vector<int> in;
ll n,max_diff, min_len;

bool solve( ll part)
{
    if( min_len * part > n)
    {
        return false;
    }

    int cid=0;

    for(int rem=part-1;rem>=0;rem--)
    {
        int mn=in[cid];
        int mx=in[cid];

        //take min_len lements
        for(int i=cid;i<=cid+)

        int done=0;

//      while( (cid<n) && ( in[cid]-mn <=max_diff )  && ( cid + rem*min_len <= n-1 ) )

        while( (cid<n) && ( in[cid]-mn <=max_diff )  && ( cid + rem*min_len <= n-1 ) )
        {
            mn=min(mn, in[cid]);
            mx=max(mx, in[cid]);
            cid++;
            done++;

            //if done > min_diff , goimg to select optonal , then take only if mx-mn is not vloalted
        }

        if( done < min_len)
        {
            return false;
        }

        if( rem==0)// we have to take all
        {
            cid=n-1;
            mx=in[cid];
        }

        if( mx - mn <= max_diff)
        {
            continue;
        }
        else
        {
            return false;
        }
    }

    return true;
}

int main()
{
 ios_base::sync_with_stdio(0);

 cin>>n>>max_diff>>min_len;

 in.resize(n);

 for(ll i=0;i<n;i++)
    cin>>in[i];

 sort(in.begin();in.end());

 ll ans = -1;

 ll lo=1,hi=n;

 while(lo<=hi)
 {
     ll mid=(lo+hi)/2LL;

     if( solve(mid) )
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
