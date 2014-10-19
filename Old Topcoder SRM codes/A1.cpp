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

int cont[1<<20];


int main()
{
 ios_base::sync_with_stdio(0);

 memset(cont,0,sizeof(cont));

 int n,q,x;

 cin>>n>>q;


 for(int  i=0;i<n;i++)
 {
     cin>>x;
     cont[x]++;
 }

 int ans=0;

 for(int i=1;i<=q;i++)
 {
     int a1=i;
     int a2=q-a1;
     int tp=min( cont[a1], cont[a2]);
     if(a1==a2)
        tp=tp/2;
     ans+=tp;
     cont[a1]-=tp;
     cont[a2]-=tp;
 }

 cout<<ans<<endl;


 return 0;

}
