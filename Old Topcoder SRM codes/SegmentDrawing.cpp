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

class SegmentDrawing 
{
public:


int maxScore(vector <int> x, vector <int> y, vector <int> redScore, vector <int> blueScore) 
{
	
}

};


double test0() {
	int t0[] = {0,1,0,-1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,0,-1,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {0, 1, 2, 3,
 1, 0, 6, 4,
 2, 6, 0, 5,
 3, 4, 5, 0};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {0, 2, 3, 7,
 2, 0, 4, 6,
 3, 4, 0, 5,
 7, 6, 5, 0};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	SegmentDrawing * obj = new SegmentDrawing();
	clock_t start = clock();
	int my_answer = obj->maxScore(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 27;
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
	int t0[] = {0, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {0, 101, 101, 0};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {0, 100, 100, 0};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	SegmentDrawing * obj = new SegmentDrawing();
	clock_t start = clock();
	int my_answer = obj->maxScore(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 101;
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
	int t0[] = {-3, -1, -1,  1,  1,  3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 0, -2,  2, -2,  2,  0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {0, 2, 1, 2, 1, 2,
 2, 0, 2, 1, 2, 1,
 1, 2, 0, 2, 1, 2,
 2, 1, 2, 0, 2, 1,
 1, 2, 1, 2, 0, 2,
 2, 1, 2, 1, 2, 0};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0,
 0, 0, 0, 21, 0, 0,
 0, 0, 21, 0, 0, 0,
 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	SegmentDrawing * obj = new SegmentDrawing();
	clock_t start = clock();
	int my_answer = obj->maxScore(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 25;
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
	int t0[] = {-100, 100, 0, -10, 10, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0, 0, 100, 10, 10, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = { 0, 96, 96, 25, 25, 25,
 96,  0, 96, 25, 25, 25,
 96, 96,  0, 25, 25, 25,
 25, 25, 25,  0, 10, 10,
 25, 25, 25, 10,  0, 10,
 25, 25, 25, 10, 10,  0};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = { 0, 30, 30, 20, 20, 20,
 30,  0, 30, 20, 20, 20,
 30, 30,  0, 20, 20, 20,
 20, 20, 20,  0, 86, 86,
 20, 20, 20, 86,  0, 86,
 20, 20, 20, 86, 86,  0};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	SegmentDrawing * obj = new SegmentDrawing();
	clock_t start = clock();
	int my_answer = obj->maxScore(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 546;
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
	int t0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {0, 15, 2, 3, 4, 5, 6, 7, 8, 9,
 15, 0, 15, 2, 3, 4, 5, 6, 7, 8,
 2, 15, 0, 15, 2, 3, 4, 5, 6, 7,
 3, 2, 15, 0, 15, 2, 3, 4, 5, 6,
 4, 3, 2, 15, 0, 15, 2, 3, 4, 5,
 5, 4, 3, 2, 15, 0, 15, 2, 3, 4,
 6, 5, 4, 3, 2, 15, 0, 15, 2, 3,
 7, 6, 5, 4, 3, 2, 15, 0, 15, 2,
 8, 7, 6, 5, 4, 3, 2, 15, 0, 15,
 9, 8, 7, 6, 5, 4, 3, 2, 15, 0}
;
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {0, 0, 2, 3, 4, 5, 6, 7, 8, 9,
 0, 0, 0, 2, 3, 4, 5, 6, 7, 8,
 2, 0, 0, 0, 2, 3, 4, 5, 6, 7,
 3, 2, 0, 0, 0, 2, 3, 4, 5, 6,
 4, 3, 2, 0, 0, 100, 2, 3, 4, 5,
 5, 4, 3, 2, 100, 0, 0, 2, 3, 4,
 6, 5, 4, 3, 2, 0, 0, 0, 2, 3,
 7, 6, 5, 4, 3, 2, 0, 0, 0, 2,
 8, 7, 6, 5, 4, 3, 2, 0, 0, 0,
 9, 8, 7, 6, 5, 4, 3, 2, 0, 0};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	SegmentDrawing * obj = new SegmentDrawing();
	clock_t start = clock();
	int my_answer = obj->maxScore(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 300;
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

//Powered by [KawigiEdit] 2.0!
