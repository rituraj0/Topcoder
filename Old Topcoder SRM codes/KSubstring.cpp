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

class KSubstring
{
public:

 ll in[3010] , sum[3010];

vector <int> maxSubstring(int A0, int X, int Y, int M, int n)
{
     in[1]=A0;

     for(int i=2;i<=n;i++)
         in[i]=( in[i-1]*(ll)X +(ll)Y)%M;

     sum[0]=0;
     for(int i=1;i<=n;i++)
         sum[i]=in[i]+sum[i-1];

     ll diff=(1LL<<62), id=-1;

     for(int k=n/2;k>=1;k--)
     {
         set<ll> st;

         int last=n-k+1;

         for(int i=n-k+1;i>=1;i--)
         {
               for( ; last >0 && i+k <=last;last--)
                  st.insert(sum[last+k-1]-sum[last-1]);

               if( st.size() >0)
               {
                    ll curr=sum[i+k-1]-sum[i-1];
                    set<ll>::iterator it=st.lower_bound(curr);

                    if( it!=st.end() && llabs(curr-*it)<diff)
                    {
                        diff=llabs(curr-*it);
                        id=k;
                    }

                    if(it!=st.begin())
                    {
                        it--;

                             if( llabs(curr-*it)<diff)
                            {
                              diff=llabs(curr-*it);
                              id=k;
                             }

                    }

               }
         }
     }

     vector<int> ans; ans.pb(id) ; ans.pb(diff);

     return  ans;

}

};


double test0() {
	int p0 = 5;
	int p1 = 3;
	int p2 = 4;
	int p3 = 25;
	int p4 = 5;
	KSubstring * obj = new KSubstring();
	clock_t start = clock();
	vector <int> my_answer = obj->maxSubstring(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t5[] = {2, 1 };
	vector <int> p5(t5, t5+sizeof(t5)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p5.size() > 0) {
		cout <<p5[0];
		for (int i=1; i<p5.size(); i++)
			cout <<", " <<p5[i];
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
	if (my_answer != p5) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 8;
	int p1 = 19;
	int p2 = 17;
	int p3 = 2093;
	int p4 = 12;
	KSubstring * obj = new KSubstring();
	clock_t start = clock();
	vector <int> my_answer = obj->maxSubstring(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t5[] = {5, 161 };
	vector <int> p5(t5, t5+sizeof(t5)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p5.size() > 0) {
		cout <<p5[0];
		for (int i=1; i<p5.size(); i++)
			cout <<", " <<p5[i];
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
	if (my_answer != p5) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 53;
	int p1 = 13;
	int p2 = 9;
	int p3 = 65535;
	int p4 = 500;
	KSubstring * obj = new KSubstring();
	clock_t start = clock();
	vector <int> my_answer = obj->maxSubstring(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t5[] = {244, 0 };
	vector <int> p5(t5, t5+sizeof(t5)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p5.size() > 0) {
		cout <<p5[0];
		for (int i=1; i<p5.size(); i++)
			cout <<", " <<p5[i];
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
	if (my_answer != p5) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 12;
	int p1 = 34;
	int p2 = 55;
	int p3 = 7890;
	int p4 = 123;
	KSubstring * obj = new KSubstring();
	clock_t start = clock();
	vector <int> my_answer = obj->maxSubstring(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t5[] = {35, 4 };
	vector <int> p5(t5, t5+sizeof(t5)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p5.size() > 0) {
		cout <<p5[0];
		for (int i=1; i<p5.size(); i++)
			cout <<", " <<p5[i];
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
	if (my_answer != p5) {
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
