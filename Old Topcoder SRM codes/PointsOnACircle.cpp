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
     ret.pb( atoi(ans[i].c_str()) );

  return ret;
}


/*Solution code starts here */

class PointsOnACircle
{
public:

    bool done[500];
    bool aval[500];

    int solve( int curr , int an)
    {
         if( (!aval[curr]) || done[curr] )
             return 0;
         done[curr]=true;

         return solve( (curr+an)%360 , an ) +1 + solve( (curr-an+360)%360 , an ) ;
    }


int color(vector <string> points)
{
     string st="";
     for(int i=0;i<points.sz;i++)
         st+=points[i];

     vector<int> in=parse(st," ");

     fill(aval,0);

     for(int i=0;i<in.sz;i++)
         aval[ in[i] ]=true;

     int ans=0;

     for(int an=1;an<360;an++)
     {
          int tp=0;

          fill(done,0);

          for(int i=0;i<360;i++)
          {
              int add=solve(i,an)&(~1);
              tp+=add;
          }

          ans=max(ans , tp);
     }

     return ans;


}

};

double test0() {
	string t0[] = {"0 10 15 25 40 50 60"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PointsOnACircle * obj = new PointsOnACircle();
	clock_t start = clock();
	int my_answer = obj->color(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"1"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PointsOnACircle * obj = new PointsOnACircle();
	clock_t start = clock();
	int my_answer = obj->color(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"0 1 3 7 15 31 63 127"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PointsOnACircle * obj = new PointsOnACircle();
	clock_t start = clock();
	int my_answer = obj->color(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"1","2"," ","3","4"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PointsOnACircle * obj = new PointsOnACircle();
	clock_t start = clock();
	int my_answer = obj->color(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
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
