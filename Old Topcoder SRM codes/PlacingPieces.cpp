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

bool done[35][35][1200][35];

class PlacingPieces
{
public:

    vector<int> all;
    int n;
    int L;
    int ans;

    void solve(int cid , int cont ,int len , int sid )
    {
        if(len > L)
             return;

        if(cid==n)
        {
            int sm=0;

            if(sid==n)
                sm=2000;
            else
                sm=all[sid] ;

            if( (cont+1)*sm > L-len )
                 ans=min(ans,cont);

                 return;
        }

        if( done[cid][cont][len][sid] )
            return;

        //chhsoing currnet one
        solve(cid+1,cont+1,len+all[cid],sid);

        //left current one
        solve(cid+1,cont,len,(sid==n)?cid:sid);

        done[cid][cont][len][sid]=true;
    }



int  optimalPlacement(int L, vector <int> pieces)
{
    all=pieces;
    this->L=L;
    n=all.size();

    sort(all.begin(),all.end());

      ans=n+1;

      memset(done,0,sizeof(done));

      solve(0,0,0,n);

      return ans;

}

};


double test0() {
	int p0 = 9;
	int t1[] = {1, 8};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PlacingPieces * obj = new PlacingPieces();
	clock_t start = clock();
	int my_answer = obj->optimalPlacement(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1;
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
	int p0 = 36;
	int t1[] = {1, 1, 5, 5, 5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PlacingPieces * obj = new PlacingPieces();
	clock_t start = clock();
	int my_answer = obj->optimalPlacement(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
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
	int p0 = 37;
	int t1[] = {1, 1, 5, 5, 5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PlacingPieces * obj = new PlacingPieces();
	clock_t start = clock();
	int my_answer = obj->optimalPlacement(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 5;
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
	int p0 = 18;
	int t1[] = {2, 2, 2, 9, 9, 10};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PlacingPieces * obj = new PlacingPieces();
	clock_t start = clock();
	int my_answer = obj->optimalPlacement(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
double test4() {
	int p0 = 1;
	int t1[] = {2, 3, 4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PlacingPieces * obj = new PlacingPieces();
	clock_t start = clock();
	int my_answer = obj->optimalPlacement(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
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
double test5() {
	int p0 = 703;
	int t1[] = {73, 76, 90, 42, 84, 13, 57, 88, 80, 45, 80, 1, 78, 41, 73, 40, 97, 42};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PlacingPieces * obj = new PlacingPieces();
	clock_t start = clock();
	int my_answer = obj->optimalPlacement(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 7;
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

//Powered by [KawigiEdit] 2.0!
