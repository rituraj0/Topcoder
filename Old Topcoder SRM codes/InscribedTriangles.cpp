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

const double PI    =  3.141592653589793;
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

class InscribedTriangles
{
public:

vector<int> to,from,all;

int n;

bool cool(int a)
  {
    a = (a % 720000 + 720000) % 720000;
    for (int i = 0; i < n; i++)
      if ( (from[i]<= a && to[i]>= a )|| (a == 0 && to[i] == 720000))
        return true;
    return false;
  }


double area(int a1, int a2, int a3)
  {
    double x1 = cos(a1 / 2000.0 / 180.0 * PI);
    double y1 = sin(a1 / 2000.0 / 180.0 * PI);
    double x2 = cos(a2 / 2000.0 / 180.0 * PI);
    double y2 = sin(a2 / 2000.0 / 180.0 * PI);
    double x3 = cos(a3 / 2000.0 / 180.0 * PI);
    double y3 = sin(a3 / 2000.0 / 180.0 * PI);

    double ans= 12.5 *(x1 * y2 - y1 * x2 + x2 * y3 - y2 * x3 + x3 * y1 - y3 * x1);

    if(ans < 0)
         ans=ans*(-1.000000000000000000000);

    return ans;
  }

double  findLargest(vector <int> angleFrom, vector <int> angleTo)
{
     n=angleFrom.size();

     for(int i=0;i<n;i++)
     {
         to.pb( angleTo[i]*2 );
         from.pb( angleFrom[i]*2);

         all.pb( to[i]);
         all.pb( from[i]);
     }

     double ans=0.0;

     int as=all.size();

     for(int i=0;i<as;i++)
     {
            int op1=all[i]+240000;
            int op2=all[i]+480000;

            if( cool(op1) && cool(op2) )
            {
                ans=max( ans , area(all[i],op1,op2));
            }

          for(int j=i+1;j<as;j++)
          {

                    for(int k=j+1;k<as;k++)
                        {
                            ans=max( ans , area( all[i] ,all[j],all[k] ) ) ;
                        }


                int mid=(all[i]+all[j])/2;

                if( cool(mid) )
                {
                    ans=max( ans , area( all[i] , all[j] , mid ) );
                }

                mid+=360000;

                if( cool(mid) )
                {
                    ans=max( ans , area( all[i] , all[j] , mid ) );
                }
          }
     }

    return ans;


}

};


double test0() {
	int t0[] = {0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {360000};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	InscribedTriangles * obj = new InscribedTriangles();
	clock_t start = clock();
	double my_answer = obj->findLargest(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 32.47595264191645;
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
	int t0[] = {15000,25000,100000,265000,330000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {15000,25000,100000,265000,330000};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	InscribedTriangles * obj = new InscribedTriangles();
	clock_t start = clock();
	double my_answer = obj->findLargest(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 27.433829549752186;
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
	int t0[] = {245900,246500,249900};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {245915,246611,252901};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	InscribedTriangles * obj = new InscribedTriangles();
	clock_t start = clock();
	double my_answer = obj->findLargest(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.002789909594714814;
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
	int t0[] = {42};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {42};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	InscribedTriangles * obj = new InscribedTriangles();
	clock_t start = clock();
	double my_answer = obj->findLargest(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.0;
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
