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

#define pll pair<ll,ll>

class DeviceProgramming
{
public:

ll cost( ll mx , ll over , ll szz)
{
     mx-=over;

     ll pc=(szz/mx)+( (szz%mx) > 0);

     return szz+pc*over;
}


long long minBytes(vector <int> offset, vector <int> sizes, int maxPacketSize, int overhead)
{
     vector<pll> in;

    int n=offset.sz;

    for(int i=0;i<n;i++ )
          in.pb( mp(offset[i] , offset[i] + sizes[i] -1 ) );

    sort(in.bg,in.en);

    ll dp[55]; fill(dp,63);


    for(int  i=0;i<n;i++)
    {
        dp[i]=cost( maxPacketSize , overhead , in[i].Y-in[0].X+1 );

          for(int j=1;j<=i;j++)
             dp[i]=min( dp[i] , dp[j-1] + cost( maxPacketSize , overhead ,in[i].Y-in[j].X+1) );
    }

    return dp[n-1];

}

};


double test0() {
	int t0[] = {0, 42, 60};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {40, 15, 2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 26;
	int p3 = 6;
	DeviceProgramming * obj = new DeviceProgramming();
	clock_t start = clock();
	long long my_answer = obj->minBytes(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 78LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {0, 42, 60};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {40, 15, 13};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 26;
	int p3 = 6;
	DeviceProgramming * obj = new DeviceProgramming();
	clock_t start = clock();
	long long my_answer = obj->minBytes(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 92LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {0, 2, 13};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 7, 2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 10;
	int p3 = 5;
	DeviceProgramming * obj = new DeviceProgramming();
	clock_t start = clock();
	long long my_answer = obj->minBytes(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 26LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {10264, 111, 357, 100066, 714};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {117, 134, 235, 2395, 23};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 100;
	int p3 = 10;
	DeviceProgramming * obj = new DeviceProgramming();
	clock_t start = clock();
	long long my_answer = obj->minBytes(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 3254LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {1, 100000000, 450000000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {99999999, 315000000, 500000000};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 1000;
	int p3 = 30;
	DeviceProgramming * obj = new DeviceProgramming();
	clock_t start = clock();
	long long my_answer = obj->minBytes(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 943298999LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int t0[] = {0, 1000000000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1000000000, 1000000000};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int p2 = 1000;
	int p3 = 999;
	DeviceProgramming * obj = new DeviceProgramming();
	clock_t start = clock();
	long long my_answer = obj->minBytes(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p4 = 2000000000000LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p4 != my_answer) {
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
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
