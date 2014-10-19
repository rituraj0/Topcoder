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

vector <ll> parse(string s, string c)
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

  vector<ll> ret;

  for(int i=0;i<ans.size();i++)
     ret.pb( atoll(ans[i].c_str() ) );

  return ret;
}


/*Solution code starts here */

#define pll pair<ll,ll>

class FibonacciKnapsack
{
public:

    ll cost[55],wt[55];
    vector<pll> in;
    int n;
    ll tot;

    map<ll,ll> memo[55];

    ll solve( int cid , ll cw )
    {
        if(cid<0)
            return 0;

         if(cw==0)
             return 0;

         if( wt[cid]<=cw)
             return cost[cid];

         if( memo[cid].count(cw) > 0)
             return memo[cid][cw];

         ll ans=0;

           ans=max( ans , solve(cid-1,cw)  );

           if( in[cid].X <=cw )
             ans=max( ans , solve(cid-1,cw-in[cid].X) + in[cid].Y );

         return (memo[cid][cw]=ans);


    }


long long maximalCost(vector <string> items, string C)
{
    tot=atoll(C.c_str());



    n=items.sz;

    for(int i=0;i<n;i++)
    {
        vector<ll> tp=parse( items[i]," ");

        in.pb( mp(tp[0],tp[1] ) );
    }

    sort(in.bg , in.en);


    wt[0]=in[0].X;
    cost[0]=in[0].Y;



    for(int i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+in[i].X;
        cost[i]=cost[i-1]+in[i].Y;
    }

    for(int i=0;i<55;i++)
     memo[i].clear();

    return solve(n-1,tot);


}

};


double test0() {
	string t0[] = {"5 555", "8 195", "13 651"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "15";
	FibonacciKnapsack * obj = new FibonacciKnapsack();
	clock_t start = clock();
	long long my_answer = obj->maximalCost(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 750LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"5 555", "8 195", "13 751"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "15";
	FibonacciKnapsack * obj = new FibonacciKnapsack();
	clock_t start = clock();
	long long my_answer = obj->maximalCost(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 751LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"55 1562", "5 814", "55 1962", "8 996", "2 716", "34 1792"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "94";
	FibonacciKnapsack * obj = new FibonacciKnapsack();
	clock_t start = clock();
	long long my_answer = obj->maximalCost(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 4568LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"13 89"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "1";
	FibonacciKnapsack * obj = new FibonacciKnapsack();
	clock_t start = clock();
	long long my_answer = obj->maximalCost(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 0LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"27777890035288 9419696870097445", 
 "53316291173 6312623457097563", 
 "165580141 8848283653257131"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "27777900000000";
	FibonacciKnapsack * obj = new FibonacciKnapsack();
	clock_t start = clock();
	long long my_answer = obj->maximalCost(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 15160907110354694LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
