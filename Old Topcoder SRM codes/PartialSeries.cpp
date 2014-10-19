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

int memo[1<<16][11][3];

class PartialSeries
{
public:

    vector<int> seri,aval;
    int m,n;

    vector<int> final_ans;



int solve( int curr , int mask , int prev , int pc)
{
          if(curr>m)
             return 0;

          if( seri[curr]!=-1)
          {
                int add=0;

                if( pc==0 && seri[curr]>prev)
                      add=1;

                if( pc==2 && seri[curr]<prev)
                      add=1;

                int npc=1;

                if( curr>1 && seri[curr]>prev)
                     npc=2;

                if( curr>1 && seri[curr] < prev)
                      npc=0;

                return solve(curr+1,mask,seri[curr],npc)+add;
          }

          if( memo[mask][prev][pc]!=-1)
              return memo[mask][prev][pc];

          int ans=memo[mask][prev][pc]=1000;

        for(int i=0;i<n;i++)
          if( mask &(1<<i) )
          {
               int add=0;

               if( pc==0 && aval[i]>prev)
                      add=1;

                if( pc==2 && aval[i]<prev)
                      add=1;

                int npc=1;

                if( curr>1 && aval[i]>prev)
                     npc=2;

                if( curr >1 && aval[i] < prev)
                      npc=0;

                 int tp=solve(curr+1,mask-(1<<i) , aval[i] , npc )+add ;

                 ans=min( ans , tp);
          }

          return ( memo[mask][prev][pc]=ans);

}


void build( int curr , int mask , int prev, int pc)
{
     if( curr>m)
         return;

     if( seri[curr]!=-1)
     {

                int npc=1;

                if( curr>1 && seri[curr]>prev)
                     npc=2;

                if( curr>1 && seri[curr] < prev)
                      npc=0;

                final_ans.pb( seri[curr]);

                build(curr+1,mask,seri[curr],npc);

                return;
     }

     int ans=solve(curr,mask,prev,pc);

      for(int i=0;i<n;i++)
          if( mask &(1<<i) )
          {
               int add=0;

               if( pc==0 && aval[i]>prev)
                      add=1;

                if( pc==2 && aval[i]<prev)
                      add=1;

                int npc=1;

                if( curr>1 && aval[i]>prev)
                     npc=2;

                if( curr >1 && aval[i] < prev)
                      npc=0;

                 int tp=solve(curr+1,mask-(1<<i) , aval[i] , npc )+add ;

                 if(tp==ans)
                 {
                     final_ans.pb( aval[i]);

                     build(curr+1,mask-(1<<i) , aval[i] , npc );

                     return;
                 }
          }//end if

}


vector <int> getFirst(vector <int> series, vector <int> available)
{

    m=series.sz;

    seri=vector<int>(m+1,0);

    for(int i=0;i<m;i++)
          seri[i+1]=series[i];

    aval=available;
    n=aval.sz;

    sort(aval.bg,aval.en);

    fill(memo,-1);

    solve(1,(1<<n)-1,0,1);

    final_ans.clear();

    build(1,(1<<n)-1,0,1);

    return final_ans;


}

};


double test0() {
	int t0[] = {-1,-1,-1,-1,-1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,2,3,4,5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PartialSeries * obj = new PartialSeries();
	clock_t start = clock();
	vector <int> my_answer = obj->getFirst(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {1, 2, 3, 4, 5 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
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
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {1,2,-1,4,5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PartialSeries * obj = new PartialSeries();
	clock_t start = clock();
	vector <int> my_answer = obj->getFirst(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {1, 2, 10, 4, 5 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
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
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {1,-1,6,2,4,-1,2,7,-1,-1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1,2,4,7,8,8};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PartialSeries * obj = new PartialSeries();
	clock_t start = clock();
	vector <int> my_answer = obj->getFirst(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {1, 1, 6, 2, 4, 2, 2, 7, 7, 4 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
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
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {8,-1,6,4,-1,-1,6};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,3,6};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PartialSeries * obj = new PartialSeries();
	clock_t start = clock();
	vector <int> my_answer = obj->getFirst(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {8, 6, 6, 4, 2, 3, 6 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
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
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {-1, 5, -1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 1, 9};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	PartialSeries * obj = new PartialSeries();
	clock_t start = clock();
	vector <int> my_answer = obj->getFirst(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t2[] = {1, 5, 9 };
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
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
	if (my_answer != p2) {
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
