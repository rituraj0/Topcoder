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
#define Y second
#define X first

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

typedef long long ll;
#define print(a) cout<<(#a)<<" = "<<a<<"  ";
#define println(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );

vector <string> parse2(string s, string c)
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

vector <int> parse1(string s, string c)
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

  for(int i=0;i<ans.size();i++)
     ret.pb(atoi(ans[i].c_str() ) );

  return ret;
}


/*Solution code starts here */

#define pii pair<int,int>

class RailwayTickets
{
public:

    vector<pii>  prev;
    int cont[11111];



int minRejects(vector <string> travel, int seats)
{

    //paring sec

      for(int i=0;i<travel.size();i++)
      {
          vector<string> ts=parse2( travel[i] , " ");

           for(int j=0;j<ts.size();j++)
           {
               vector<int> ti=parse1(ts[j],"-");
               prev.pb( mp( ti[1],ti[0]));
           }
      }

     int ans=0;

     sort( prev.begin() , prev.end() );

     memset(cont,0,sizeof(cont));

     for(int i=0;i<prev.size();i++)
     {
           int mx=0;

             for(int j=prev[i].Y ; j< prev[i].X;j++)
                  mx=max( mx, cont[j]);

             if( mx < seats)
             {
                   for(int j=prev[i].Y ; j< prev[i].X;j++)
                    cont[j]++;
             }
             else
             {
                 ans++;
             }
     }

     return ans;

}

};


double test0() {
	int p0 = 40000;
	int p1 = 100000;
	int p2 = 150000;
	int p3 = 5000;
	FlightScheduler * obj = new FlightScheduler();
	clock_t start = clock();
	double my_answer = obj->minimizeFuel(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 76420.82744805096;
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
	int p0 = 40000;
	int p1 = 55000;
	int p2 = 150000;
	int p3 = 5000;
	FlightScheduler * obj = new FlightScheduler();
	clock_t start = clock();
	double my_answer = obj->minimizeFuel(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 138450.61724934017;
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
	int p0 = 1000;
	int p1 = 500;
	int p2 = 1000;
	int p3 = 50;
	FlightScheduler * obj = new FlightScheduler();
	clock_t start = clock();
	double my_answer = obj->minimizeFuel(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 2664.9853821314487;
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
	int p0 = 10000;
	int p1 = 100;
	int p2 = 200;
	int p3 = 5;
	FlightScheduler * obj = new FlightScheduler();
	clock_t start = clock();
	double my_answer = obj->minimizeFuel(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 24635.869665316768;
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
	int p0 = 140000;
	int p1 = 4;
	int p2 = 10000;
	int p3 = 10;
	FlightScheduler * obj = new FlightScheduler();
	clock_t start = clock();
	double my_answer = obj->minimizeFuel(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p4 = 3.6576871282155204E8;
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
