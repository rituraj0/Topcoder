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

class TaroFriends
{
public:

vector<ll> all;

vector<ll> in;
int n;
ll X;

map<ll,int> mapa;

ll ans;

bool done[55][155][155];

void solve( int curr , int mn ,int mx)
  {
        if( curr==n)
        {
              ans=min( ans ,  all[mx]-all[mn] );

              return;
        }

        if( done[curr][mn][mx])
             return ;

         done[curr][mn][mx]=true;

         //left
          ll nmn=min( all[mn] , in[curr]-X);
          ll nmx=max( all[mx] , in[curr]-X);

          solve( curr+1 , mapa[nmn] , mapa[nmx] );
        //right
           nmn=min( all[mn] , in[curr]+X);
           nmx=max( all[mx] , in[curr]+X);

          solve( curr+1 , mapa[nmn] , mapa[nmx] );


  }

int getNumber(vector <int> coor, int x)
{
     n=coor.sz;

     for(int i=0;i<n;i++)
         in.pb( coor[i]);

     X=x;

     for(int i=0;i<n;i++)
     {
         all.pb( in[i]+X);
         all.pb( in[i]-X);
     }

   int prev=all.sz;

    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());

    int curr=all.sz;

    if(prev>curr)
         cout<<"Some duplicates\n"<<prev<<" "<<curr<<endl;;

    for(int i=0;i<all.sz;i++)
         mapa[ all[i] ]=i;

    fill(done,0);

    ans=(1LL<<62);

     println(ans);

    solve(1, mapa[ in[0] + X ]  , mapa[ in[0] + X ]  );


    fill(done,0);

    solve(1, mapa[ in[0] - X ]  , mapa[ in[0] - X ]  );


     return ans;


}

};



double test0() {
	int t0[] = {-3, 0, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 3;
	TaroFriends * obj = new TaroFriends();
	clock_t start = clock();
	int my_answer = obj->getNumber(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	int t0[] = {4, 7, -7};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 5;
	TaroFriends * obj = new TaroFriends();
	clock_t start = clock();
	int my_answer = obj->getNumber(p0, p1);
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
	int t0[] = {-100000000, 100000000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 100000000;
	TaroFriends * obj = new TaroFriends();
	clock_t start = clock();
	int my_answer = obj->getNumber(p0, p1);
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
double test3() {
	int t0[] = {3, 7, 4, 6, -10, 7, 10, 9, -5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 7;
	TaroFriends * obj = new TaroFriends();
	clock_t start = clock();
	int my_answer = obj->getNumber(p0, p1);
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
double test4() {
	int t0[] = {-4, 0, 4, 0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 4;
	TaroFriends * obj = new TaroFriends();
	clock_t start = clock();
	int my_answer = obj->getNumber(p0, p1);
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
double test5() {
	int t0[] = {7};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int p1 = 0;
	TaroFriends * obj = new TaroFriends();
	clock_t start = clock();
	int my_answer = obj->getNumber(p0, p1);
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

int main() {
	int time;
	fo;
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

     for(int i=0;i<50;i++)
         cout<<1000*i<<"  ";

     cout<<endl;

     int a=1000000000;
     cout<<2*a<<endl;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
