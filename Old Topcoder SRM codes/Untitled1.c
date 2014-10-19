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


int main()
{
 ios_base::sync_with_stdio(0);

 ll a,b;

 cin>>a>>b;

 if(a==0)
 {
     cout<<-1*b*b<<endl;
     return 0;
 }

 if(b==0)
 {
     cout<<a*a<<endl;
     return 0;
 }

  ll ans=-(1LL<<60);

  int fa=-1,fb=-1;

 for(int ac=1;ac<=a;ac++)
 {
       ll asum=(ac-1); //sab ek ek wale
           asum+=(a-ac-1)*(a-ac-1);

         for(ll bc=ac-1; bc <= ac+1; bc++ )
         {
              if( bc < 1)
                 continue;

              if( bc > b)
                 continue;

                 ll req=bc;

                 ll bsum=0;
                 ll aval=b;

               if( aval%req!=0)
               {
                    bsum+=(aval%req)*(aval%req);
                    aval-=(aval%req);
                    req--;
               }

               if( req > 0)
               {
                   ll cs=aval/req;//curr size
                   bsum+=cs*cs*req;
               }

              if( asum - bsum > ans)
              {
                  ans=asum-bsum;
                  fa=ac;
                  fb=bc;
              }
         }

 }

 cout<<ans<<endl;
 cout<<fa<<"  "<<fb<<"\n";

 vector<string> as,bs;

  for(int i=1;i<=fa-1;fa++)
      as.pb( string('o',1) );

    as.pb( string('o',a-fa-1) );


    //now condtruct B

    if( b % fb!=0)
    {
        int tp=b%fb;

             b-=tp;

             bs.pb( string('x' , tp ) );
    }

    for(int i=1;i<=b/)



 return 0;

}





        ll req=bc;

        ll bsum=0;

        ll aval=in;

        if( aval%req!=0)
         {
            aval+=(req-aval%req);

            ll cs=aval/req;

            ll rem=in-cs*(req-1);

            bsum+=rem*rem;
            bsum+=(req-1)*cs*cs;

            cout<<cs<<"  "<<rem<<"  ";

            cout<<"-\n";
         }
         else if( aval%req==0)
          {
                ll cs=aval/req;
                bsum=req*cs*cs;
                            cout<<"-\n";
          }

          return bsum;



      ll save=aval;

       ll rem=aval%bc;

      aval+=(bc-rem )%bc;

      ll cs=aval/bc;
      ll full=save/cs;
      ll rs=save%cs;

      ll bsum=0;

      bsum+=rs*rs;
      bsum+=full*cs*cs;

         println(rem);
      println(aval);
       println(cs);
        println(full);
         println(rs);
