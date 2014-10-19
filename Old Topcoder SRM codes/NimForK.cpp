#include<algorithm>
#include<sstream>
#include <bits/stdc++.h>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(it,x) for(typeof(x.begin()) it=x.begin();it!=x.end();++it)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define CLEAR(x,with) memset(x,with,sizeof(x))
#define sz size()
typedef long long ll;

int n, k;
vector<vector<int> > m;
double cache[51][21][21];

struct NimForK
{
  double getAverage(const vector<int>& take, int here, int remaining, int whoWins)
  {
    double ret = 0;
    REP(i,take.sz)
      ret += go((here+1)%k, remaining-take[i], whoWins);
    return ret / take.sz;
  }
  double go(int here, int remaining, int whoWins)
  {
    if(remaining == 0) return (whoWins == (here+k-1)%k) ? 1.0 : 0.0;
    double& ret = cache[remaining][here][whoWins];
    if(ret >= 0.0) return ret;
    ret = 0.0;
    vector<int> winningMove, possibleMove, elseMove;
    REP(i,m[remaining].sz)
    {
      int take = m[remaining][i];
      if(take <= remaining)
      {
        double p = go((here+1)%k, remaining-take, here);
        if(p == 1.0)
          winningMove.pb(take);
        else if(p > 0.0)
          possibleMove.pb(take);
        else
          elseMove.pb(take);
      }
    }
    if(winningMove.sz > 0)
      ret = getAverage(winningMove, here, remaining, whoWins);
    else if(possibleMove.sz > 0)
      ret = getAverage(possibleMove, here, remaining, whoWins);
    else if(elseMove.sz > 0)
      ret = getAverage(elseMove, here, remaining, whoWins);
    else
      ret = 0; // nobody wins
    return ret;
  }
  vector <int> winners(int n, int k, vector <string> moves)
  {
    REP(i,51) REP(j,21) REP(k,21) cache[i][j][k] = -1;
    ::n = n; ::k = k;
    m.resize(moves.sz+1);
    REP(i,moves.sz)
    {
      istringstream inp(moves[i]);
      int x;
      while(inp >> x) m[i+1].pb(x);
    }

    vector<int> ret;
    REP(i,k)
      if(go(0, n, i) > 0.0)
        ret.pb(i+1);
    return ret;
  }
};


double test0() {
	int p0 = 8;
	int p1 = 2;
	string t2[] = {"1", "1 2", "1 2 3", "1 2 3", "1 2 3", "1 2 3", "1 2 3", "1 2 3"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	NimForK * obj = new NimForK();
	clock_t start = clock();
	vector <int> my_answer = obj->winners(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = {2 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 7;
	int p1 = 2;
	string t2[] = {"1", "1 2", "1 2 3", "1 2 3", "1 2 3", "1 2 3", "1 2 3"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	NimForK * obj = new NimForK();
	clock_t start = clock();
	vector <int> my_answer = obj->winners(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = {1 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 5;
	int p1 = 3;
	string t2[] = {"1", "1 2", "1 2 3", "1 2 3", "1 2 3"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	NimForK * obj = new NimForK();
	clock_t start = clock();
	vector <int> my_answer = obj->winners(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = {2, 3 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 6;
	int p1 = 3;
	string t2[] = {"1", "1 2", "1 2 3", "1 2 3", "1 2 3", "1 2 3"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	NimForK * obj = new NimForK();
	clock_t start = clock();
	vector <int> my_answer = obj->winners(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t3[] = {1, 3 };
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
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
	int p1 = 20;
	string t2[] = {""};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	NimForK * obj = new NimForK();
	clock_t start = clock();
	vector <int> my_answer = obj->winners(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	vector <int> p3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p3.size() > 0) {
		cout <<p3[0];
		for (int i=1; i<p3.size(); i++)
			cout <<", " <<p3[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p3) {
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
