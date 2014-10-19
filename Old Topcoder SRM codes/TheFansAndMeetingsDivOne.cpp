#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;

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

class TheFansAndMeetingsDivOne 
{
public:


double find(vector <int> minJ, vector <int> maxJ, vector <int> minB, vector <int> maxB, int k) 
{
	
}

};


double test0() {
	int t0[] = {1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {9};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {5};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {5};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int p4 = 1;
	TheFansAndMeetingsDivOne * obj = new TheFansAndMeetingsDivOne();
	clock_t start = clock();
	double my_answer = obj->find(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p5 = 0.1111111111111111;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {5, 2, 5, 1, 1, 2, 4, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {7, 6, 7, 3, 4, 3, 5, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {8, 9, 7, 11, 12, 7, 8, 40};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {9, 10, 9, 33, 14, 7, 11, 40};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int p4 = 2;
	TheFansAndMeetingsDivOne * obj = new TheFansAndMeetingsDivOne();
	clock_t start = clock();
	double my_answer = obj->find(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p5 = 4.724111866969009E-5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {4, 7, 4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {7, 7, 7};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {40, 40, 40};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {40, 40, 40};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int p4 = 1;
	TheFansAndMeetingsDivOne * obj = new TheFansAndMeetingsDivOne();
	clock_t start = clock();
	double my_answer = obj->find(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p5 = 0.0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {3, 6, 2, 1, 1, 10, 3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {6, 9, 5, 6, 5, 10, 9};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1, 1, 1, 1, 8, 3, 1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {3, 9, 7, 3, 10, 6, 5};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int p4 = 4;
	TheFansAndMeetingsDivOne * obj = new TheFansAndMeetingsDivOne();
	clock_t start = clock();
	double my_answer = obj->find(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p5 = 0.047082056525158976;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
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
