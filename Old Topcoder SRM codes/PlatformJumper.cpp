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




/*Solution code starts here */

#define pii pair<int,int>
#define piii pair<int,pii>

piii parse(string s, string c)
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

  vector<int> ret;

  for(int i=0;i<ans.sz;i++)
     ret.pb( atoi( ans[i].c_str() ) );

  return mp( ret[1] , mp(ret[0] , ret[2] ) );
}

class PlatformJumper
{
public:

    vector<piii> in;
    int n;

    int memo[55];

    ll v,g;

   bool can( int a, int b) //chack if can jump froma to b
   {
        ll y= abs(in[a].X-in[b].X) ;
        ll x= abs(in[a].Y.X-in[b].Y.X);

        return( v*v*2*y >=x*x*g);

   }

   int solve( int curr)
   {
       if( memo[curr]!=-1)
         return memo[curr];

       int ans=0;

       for(int i=0;i<curr;i++)
          if( can(curr,i) )
            ans=max( ans , solve(i) );

       return memo[curr]=ans+in[curr].Y.Y;
   }

int maxCoins(vector <string> platforms, int v, int g)
{
     n=platforms.sz;
     this->v=v;
     this->g=g;

     for(int i=0;i<n;i++)
        in.pb( parse( platforms[i] ," ") );


    sort(in.bg,in.en);

     fill( memo,-1);

     int ans=0;

     for(int i=n-1;i>=0;i--)
         ans=max( ans, solve(i) );

     return ans;


}

};


double test0() {
	string t0[] = {"3 10 7", "5 15 7", "8 9 12" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 2;
	int p2 = 10;
	PlatformJumper * obj = new PlatformJumper();
	clock_t start = clock();
	int my_answer = obj->maxCoins(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 14;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"0 0 1", "2 4 1", "4 0 1"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	int p2 = 2;
	PlatformJumper * obj = new PlatformJumper();
	clock_t start = clock();
	int my_answer = obj->maxCoins(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"0 0 1", "5000 5000 10"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 100;
	int p2 = 87;
	PlatformJumper * obj = new PlatformJumper();
	clock_t start = clock();
	int my_answer = obj->maxCoins(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 10;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
