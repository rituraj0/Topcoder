//shamelessly copied  Igor's Solution

#include <algorithm> 
#include <bitset> 
#include <cassert> 
#include <cctype> 
#include <cmath> 
#include <complex> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <ctime> 
#include <deque> 
#include <functional> 
#include <iostream> 
#include <iterator> 
#include <list> 
#include <map> 
#include <numeric> 
#include <queue> 
#include <set> 
#include <sstream> 
#include <stack> 
#include <string> 
#include <valarray> 
#include <vector> 
#include <utility> 

using namespace std; 

#define all(v) (v).begin(), (v).end() 

// Types 
typedef long double ld; 
typedef long long ll; 
typedef pair <int, int> pii; 
typedef vector <int> vi; 
typedef vector <pii> vp; 
typedef vector <ld> vd; 
typedef vector <string> vs; 
typedef vector <bool> vb; 
typedef queue <pii> qp; 
typedef map <string, int> msi; 

// Constants 
const int INF = 1000000000; 
const ld EPS = 1e-10L; 
const ld PI = 3.14159265358979L; 

class Tetrahedron 
{ 
// Global 

// Functions 
public:

  string exists(vector <string> d) ////shamelessly copied  Igor's Solution
  { 
    string res; 
    int n; 
    int a[4][4]; 
    for (int i = 0; i < 4; ++i) 
    { 
      istringstream in(d[i]); 
      for (int j = 0; j < 4; ++j) 
        in >> a[i][j]; 
    } 
    for (int i = 0; i < 4; ++i) 
    { 
      for (int j = 0; j < 4; ++j) 
      { 
        for (int k = 0; k < 4; ++k) 
        { 
          if (a[i][j] + a[j][k] < a[i][k]) 
            return "NO"; 
        } 
      } 
    } 
    double x0 = 0; 
    double y0 = 0; 
    double x1 = a[0][1]; 
    double y1 = 0; 
    double x2 = (a[0][2] * a[0][2] - a[1][2] * a[1][2] + x1 * x1) / (2 * x1); 
    double y2 = sqrt(a[0][2] * a[0][2] - x2 * x2); 
    double x3 = (a[0][3] * a[0][3] - a[1][3] * a[1][3] + x1 * x1) / (2 * x1); 
    double y3 = sqrt(a[0][3] * a[0][3] - x3 * x3); 
    if (hypot(x2 - x3, y2 - y3) - EPS < a[2][3] && hypot(x2 - x3, y2 + y3) + EPS > a[2][3]) 
      return "YES"; 
    else 
      return "NO"; 
    return res; 
  } 
   

}; 




double test0() {
	string t0[] = {"0 1 1 1",
 "1 0 1 1",
 "1 1 0 1",
 "1 1 1 0"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Tetrahedron * obj = new Tetrahedron();
	clock_t start = clock();
	string my_answer = obj->exists(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"0 1 2 3",
 "1 0 1 2",
 "2 1 0 1",
 "3 2 1 0"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Tetrahedron * obj = new Tetrahedron();
	clock_t start = clock();
	string my_answer = obj->exists(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"0 1 2 4",
 "1 0 1 2",
 "2 1 0 1",
 "4 2 1 0"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Tetrahedron * obj = new Tetrahedron();
	clock_t start = clock();
	string my_answer = obj->exists(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"0 6 6 3",
 "6 0 4 5",
 "6 4 0 4",
 "3 5 4 0"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Tetrahedron * obj = new Tetrahedron();
	clock_t start = clock();
	string my_answer = obj->exists(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "YES";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"0 6 6 2",
 "6 0 4 5",
 "6 4 0 4",
 "2 5 4 0"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	Tetrahedron * obj = new Tetrahedron();
	clock_t start = clock();
	string my_answer = obj->exists(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p1 = "NO";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p1 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
