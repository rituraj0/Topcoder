#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define Y second
#define X first
typedef unsigned long long ll;

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

#define maxn 400009
ll memo[2][42][2];

class RoadOrFlightHard
{
public:

ll road[maxn],fly[maxn];

int N,K;

ll solve( int curr , int sel , bool onfly)
{
    if(sel>K) return LLONG_MAX;

    if(curr==N)
    {
        if(sel<=K)
              return 0;
    }

    if( memo[curr&1][sel][onfly]!=-1)  return memo[curr&1][sel][onfly];

    ll ans=LLONG_MAX;

    if( onfly)
    {
        ans=min( ans , solve(curr+1,sel,true) + fly[curr] );
        ans=min( ans , solve( curr+1,sel,false) + road[curr] );
    }
    else
    {
        ans=min( ans , solve(curr+1,sel+1,true) + fly[curr] );
        ans=min( ans,  solve(curr+1,sel,false) + road[curr] );
    }

    return memo[curr&1][sel][onfly]=ans;
}
long long minTime(int N, int roadFirst, int roadProd, int roadAdd, int roadMod, int flightFirst, int flightProd, int flightAdd, int flightMod, int K)
{
    this->N=N;
    this->K=K;

    road[0]=roadFirst%roadMod;

    for(int i=1;i<N;i++)
        road[i]=(road[i-1]*(ll)roadProd +(ll)roadAdd )%(ll)roadMod;

    fly[0]=flightFirst%flightMod;

    for(int i=1;i<N;i++)
        fly[i]=(fly[i-1]*(ll)flightProd +(ll)flightAdd )%(ll)flightMod;

    fill(memo,-1);

    for(int i=N-1;i>=0;i--)
         {
            fill( memo[i&1],-1);

                 for(int j=K;j>=0;j--)
                      for(int k=0;k<2;k++)
                          solve(i,j,k);
         }

    return solve(0,0,0);


}

};


double test0() {
	int p0 = 3;
	int p1 = 14;
	int p2 = 1;
	int p3 = 2;
	int p4 = 10;
	int p5 = 18;
	int p6 = 1;
	int p7 = 10;
	int p8 = 17;
	int p9 = 1;
	RoadOrFlightHard * obj = new RoadOrFlightHard();
	clock_t start = clock();
	long long my_answer = obj->minTime(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p10 = 14LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p10 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p10 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 3;
	int p1 = 4;
	int p2 = 1;
	int p3 = 2;
	int p4 = 10;
	int p5 = 1;
	int p6 = 1;
	int p7 = 10;
	int p8 = 17;
	int p9 = 2;
	RoadOrFlightHard * obj = new RoadOrFlightHard();
	clock_t start = clock();
	long long my_answer = obj->minTime(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p10 = 11LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p10 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p10 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 3;
	int p1 = 4;
	int p2 = 1;
	int p3 = 2;
	int p4 = 10;
	int p5 = 1;
	int p6 = 1;
	int p7 = 6;
	int p8 = 9;
	int p9 = 1;
	RoadOrFlightHard * obj = new RoadOrFlightHard();
	clock_t start = clock();
	long long my_answer = obj->minTime(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p10 = 12LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p10 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p10 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 5;
	int p1 = 85739;
	int p2 = 94847;
	int p3 = 93893;
	int p4 = 98392;
	int p5 = 92840;
	int p6 = 93802;
	int p7 = 93830;
	int p8 = 92790;
	int p9 = 3;
	RoadOrFlightHard * obj = new RoadOrFlightHard();
	clock_t start = clock();
	long long my_answer = obj->minTime(p0, p1, p2, p3, p4, p5, p6, p7, p8, p9);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p10 = 122365LL;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p10 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p10 != my_answer) {
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
