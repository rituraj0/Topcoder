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

class ContiguousCache
{
public:

ll memo[55][110];

vector<ll> all;//all possible base addrees
vector<ll> req;

ll len;


ll cost( ll a , ll b , ll c , ll d)
{
      if( a > c)  return cost(c,d,a,b);

      if( b < c)  return len;

      return len - ( min(b,d)-c+1 ); //bracjet wala overlap
}


ll solve( int curr , int in)
{
      if(curr==req.sz)   return 0;

      ll &ans=memo[curr][in];

      if(ans!=-1) return ans;

      ans=(1LL<<60);

      for(int i=0;i<all.sz;i++)
          if( all[i]<=req[curr] && req[curr]<=all[i]+len-1 )
            ans=min( ans , solve(curr+1,i) + cost(all[i],all[i]+len-1 , all[in] , all[in]+len-1 ) );

      return ans;

}

long long minimumReads(int n, int k, vector <int> in)
{
     for(int i=0;i<in.sz;i++)
         req.pb( in[i]);

      len=k;

     for(int i=0;i<in.sz;i++)
     {
            if( in[i]+len-1<n) all.pb(in[i]);

            if( in[i]-len+1>=0) all.pb( in[i]-len+1);
     }

     all.pb(0) ; all.pb(n-len) ; all.pb(n);

     fill(memo,-1);

     return solve(0,(int)all.sz-1);

}

};


double test0() {
	int p0 = 100;
	int p1 = 3;
	int t2[] = {0, 2, 16, 13};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ContiguousCache * obj = new ContiguousCache();
	clock_t start = clock();
	long long my_answer = obj->minimumReads(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 7LL;
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
	int p0 = 100;
	int p1 = 10;
	int t2[] = {1,10,19,28,30,37};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ContiguousCache * obj = new ContiguousCache();
	clock_t start = clock();
	long long my_answer = obj->minimumReads(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 29LL;
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
	int p0 = 1000000000;
	int p1 = 500000000;
	int t2[] = {0, 999999999, 1, 500000000, 500000001, 987654321};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ContiguousCache * obj = new ContiguousCache();
	clock_t start = clock();
	long long my_answer = obj->minimumReads(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 1987654320LL;
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
double test3() {
	int p0 = 8;
	int p1 = 2;
	int t2[] = {7};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	ContiguousCache * obj = new ContiguousCache();
	clock_t start = clock();
	long long my_answer = obj->minimumReads(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p3 = 2LL;
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

	time = test3();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
