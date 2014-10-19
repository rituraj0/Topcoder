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

int start[100009],len[100009];


int main()
{
 ios_base::sync_with_stdio(0);

 string in;
 int n;

 cin>>in;

 n=in.size();

 int curr=1;

  int st=0;

 while(st<n)
 {


      int nx=st+1;

      while( (nx < n) && (in[nx]=='0') )
          nx++;

       start[curr]=st;
       len[curr]=nx-st-1;

        curr++;
       st=nx;
 }

// for(int i=1;i<curr;i++)
//     cout<<start[i]<<"  "<<len[i]<<"\n";

   int id=-1;

   for(int i=2;i<curr;i++)
       if( len[i] > start[i] -1 )
        {
            id=i;
        }

       else if( len[i]==start[i]-1)
       {
              if( in[0] < in[ start[i] ] )
                 id=i;
       }


       if(id==-1)
         cout<<curr-1<<endl;
       else
       cout<<curr-1-id+1<<endl;


 return 0;

}
