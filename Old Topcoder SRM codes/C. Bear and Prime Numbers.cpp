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

#define maxi 10000011

int cont[maxi];
int prime[maxi];


int main()
{
 ios_base::sync_with_stdio(0);

 int n,x;

 cin>>n;

 for(int i=1;i<=n;i++)
 { cin>>x;
   cont[x]++;
 }

 memset(prime,0,sizeof(prime));

 for(int i=2;i<maxi;i++)
     if( prime[i] >=0)
        {
             prime[i]=cont[i];

             for(int j=2*i;j<maxi;j+=i)
             {
                 prime[i]+=cont[j];
                 prime[j]=-1;
             }

        }


    for(int i=2;i<maxi;i++)
    {
         prime[i]=max(0,prime[i]);
         prime[i]+=prime[i-1];
    }

    int Q;

    cin>>Q;

    int a,b;

    for(int i=1;i<=Q;i++)
    {
        cin>>a>>b;
        b=min(maxi-1,b);
        a=min(maxi-1,a);

        cout<<max(0,prime[b]-prime[a-1])<<endl;
    }

 return 0;

}
