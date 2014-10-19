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

class InformFriends
{
public:

int all[20];
bool cool[1<<16];//can infrom all
int dp[1<<16];


int maximumGroups(vector <string> in)
{
  int n=in.sz;

  for(int i=0;i<n;i++)
  {
       all[i]=(1<<i);

          for(int j=0;j<n;j++)
              if( in[i][j]=='Y')
                all[i]=( all[i]|(1<<j) );
  }

  for(int mask=0;mask<(1<<n);mask++)
  {
        int tp=0;

           for(int j=0;j<n;j++)
              if( mask&(1<<j) )
                  tp=(tp|all[j]);

          if(tp==(1<<n)-1)
            cool[mask]=1;
          else
            cool[mask]=0;
  }

  int ret=0;

  for(int mask=0;mask<(1<<n);mask++)
  {
            int ans=0;

            for(int sb=mask;sb>0;sb=(sb-1)&mask)
                  if( cool[sb])
                   ans=max( ans , dp[mask-sb] + 1 );

                   dp[mask]=ans;

                   ret=max(ret,ans);
  }

  return ret;

}

};


double test0() {
	string t0[] = {"NYYN",
 "YNYY",
 "YYNY",
 "NYYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	InformFriends * obj = new InformFriends();
	clock_t start = clock();
	int my_answer = obj->maximumGroups(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	string t0[] = {"NYYN",
 "YNYN",
 "YYNN",
 "NNNN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	InformFriends * obj = new InformFriends();
	clock_t start = clock();
	int my_answer = obj->maximumGroups(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	string t0[] = {"NYNNNY",
 "YNYNNN",
 "NYNYNN",
 "NNYNYN",
 "NNNYNY",
 "YNNNYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	InformFriends * obj = new InformFriends();
	clock_t start = clock();
	int my_answer = obj->maximumGroups(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	string t0[] = {"NYNY",
 "YNYN",
 "NYNY",
 "YNYN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	InformFriends * obj = new InformFriends();
	clock_t start = clock();
	int my_answer = obj->maximumGroups(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
