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

map< pair<int,string> , double > memo;
class PointsGame
{
public:

vector<double> px,py;
int n;

double solve( int curr , string mask)
{
     if( mask.find('w')==string::npos)
     {
          double ans=0;

          for(int i=0;i<n;i++)
             for(int j=i+1;j<n;j++)
                if( mask[i]!=mask[j])
                  ans+=sqrt( (px[i]-px[j])*(px[i]-px[j]) + (py[i]-py[j])*(py[i]-py[j]) );

          return memo[ mp(curr,mask) ]=ans;
     }

     if( memo.find( mp(curr,mask) )!=memo.end() )
         return memo[ mp(curr,mask) ];

      if(curr==0)//want maximum
      {
            double ans=0;

            for(int i=0;i<n;i++)
                  if( mask[i]=='w')
                   {
                        string tp=mask; tp[i]='r';
                        ans=max( ans , solve(1,tp) );
                   }

             return memo[ mp(curr,mask) ]=ans;
      }

       double ans=1e60;

            for(int i=0;i<n;i++)
                  if( mask[i]=='w')
                   {
                        string tp=mask; tp[i]='b';
                        ans=min( ans , solve(0,tp) );
                   }

             return memo[ mp(curr,mask) ]=ans;

}


double gameValue(vector <int> pointsX, vector <int> pointsY)
{
     memo.clear();
      n=pointsX.sz;
     string curr(n,'w');

     for(int i=0;i<n;i++)
     {
         px.pb( pointsX[i]);
         py.pb( pointsY[i]);
     }

     return solve(0,curr);

}

};


double test0() {
	int t0[] = {0,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PointsGame * obj = new PointsGame();
	clock_t start = clock();
	double my_answer = obj->gameValue(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 1.0;
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
	int t0[] = {0,0,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,5,0,5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PointsGame * obj = new PointsGame();
	clock_t start = clock();
	double my_answer = obj->gameValue(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 12.198039027185569;
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
	int t0[] = {0,0,0,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,1,5,6};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PointsGame * obj = new PointsGame();
	clock_t start = clock();
	double my_answer = obj->gameValue(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 12.0;
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
	int t0[] = {0,1,2,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,0,0,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PointsGame * obj = new PointsGame();
	clock_t start = clock();
	double my_answer = obj->gameValue(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 6.0;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
