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
const double eps    =   1e-9;

#define print(a) cout<<(#a)<<" = "<<a<<"  ";
#define println(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );

vector <int> parse(string s, string c)
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
     ret.pb( atoi(ans[i].c_str() ) );

  return ret;
}


/*Solution code starts here */

class RoadCrossing
{
public:

    double ans;

    vector<int> t,v,x;
    int n,rw,cw,t0;


    void solve( double curr)
    {
        if(curr < t0-eps)
            return;

        vector<double> temp;

        for(int i=0;i<n;i++)
            if( curr >=t[i]-eps)
              temp.pb( max(0.0 , min( x[i] + ( curr - t[i])*v[i]  , (double)rw  )  ) );

        sort( temp.bg,temp.en);

        for(int i=1;i<temp.sz;i++)
              if( temp[i]-temp[i-1] > cw-eps)
               ans=min( ans , curr);

    }


double passTime(vector <string> pedestrians, int roadWidth, int carWidth, int carArrival)
{


    n=pedestrians.sz;

    for(int i=0;i<n;i++)
    {
        vector<int> tp=parse( pedestrians[i] ," ");

        t.pb(tp[0]);
        v.pb(tp[1]);
        x.pb(0);
    }


    t.pb(0) ; v.pb(0) ; x.pb(0);
    t.pb(0) ; v.pb(0) ; x.pb(roadWidth);


    rw=roadWidth;
    cw=carWidth;
    t0=carArrival;

    ans=(1LL<<60);


    n=x.sz;

    solve(t0);

    for(int i=0;i<n;i++)
        solve( t[i]);

    for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
            if( fabs(v[i]-v[j]) > eps )
               solve(  (cw - (x[j] - v[j] * t[j] - x[i] + v[i] * t[i])) / (double)(v[j] - v[i]) );



    return ans;

}

};




double test0() {
	string t0[] = {"0 1", "2 5"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 8;
	int p2 = 4;
	int p3 = 3;
	RoadCrossing * obj = new RoadCrossing();
	clock_t start = clock();
	double my_answer = obj->passTime(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 3.5;
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
	string t0[] = {"40 1"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 100;
	int p2 = 100;
	int p3 = 41;
	RoadCrossing * obj = new RoadCrossing();
	clock_t start = clock();
	double my_answer = obj->passTime(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 140.0;
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
	string t0[] = {"0 1", "0 2", "0 4", "0 8", "0 16", "0 32", "0 64", "0 128", "0 256"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 100;
	int p2 = 50;
	int p3 = 3;
	RoadCrossing * obj = new RoadCrossing();
	clock_t start = clock();
	double my_answer = obj->passTime(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 3.125;
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
	string t0[] = {"0 1", "0 2", "0 4", "0 8", "0 16", "0 32", "0 64", "0 128", "0 256"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 100;
	int p2 = 51;
	int p3 = 3;
	RoadCrossing * obj = new RoadCrossing();
	clock_t start = clock();
	double my_answer = obj->passTime(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 51.0;
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
	string t0[] = {"1000 1", "100 1"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1000;
	int p2 = 1000;
	int p3 = 1000;
	RoadCrossing * obj = new RoadCrossing();
	clock_t start = clock();
	double my_answer = obj->passTime(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 2000.0;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
