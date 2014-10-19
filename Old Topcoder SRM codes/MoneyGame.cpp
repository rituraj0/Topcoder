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

typedef long long ll;
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



class MoneyGame
{
public:


int toint( vector<int> a)
{
    return a[0]*121+a[1]*11+a[2];
}

vector<int> tovec(int in)
{
    vector<int> ans(3,0);
    ans[2]=in%11;
    ans[1]=(in/11)%11;
    ans[0]=in/121;
    return ans;
}

bool done[2][1500][1500];
int memo[2][1500][1500];

vector<int> all,cost;

int solve( int curr , int p1 , int p2 )
{
     if( done[curr][p1][p2])
         return memo[curr][p1][p2];

     done[curr][p1][p2]=true;

     int ans=-(1<<28);

     vector<int> a=tovec(p1) , b=tovec(p2) , pot(3,0);

     for(int i=0;i<3;i++)
          pot[i]=all[i]-a[i]-b[i];

     if( curr==0)
     {
            if( a[0]==0 && a[1]==0 && a[2]==0)
                 ans=-cost[0]*b[0] -cost[1]*b[1]-cost[2]*b[2] ;

            for(int k=0;k<3;k++)
                  if( a[k] >0)
                    {
                        a[k]--;

                        for(int x=0;x<=pot[0];x++)
                             for(int y=0;y<=pot[1];y++)
                               for(int z=0;z<=pot[2];z++)
                                 if( cost[k] > x*cost[0] + y*cost[1] + z*cost[2] )
                                {
                                    a[0]+=x;
                                    a[1]+=y;
                                    a[2]+=z;

                                    ans=max( ans , -solve(1,toint(a) , toint(b) ) );

                                    a[0]-=x;
                                    a[1]-=y;
                                    a[2]-=z;
                                }

                                a[k]++;
                    }
     }

   if( curr==1)
     {
            if( b[0]==0 && b[1]==0 && b[2]==0)
                 ans=-cost[0]*a[0] -cost[1]*a[1]-cost[2]*a[2] ;

            for(int k=0;k<3;k++)
                  if( b[k] >0)
                    {
                        b[k]--;

                        for(int x=0;x<=pot[0];x++)
                             for(int y=0;y<=pot[1];y++)
                               for(int z=0;z<=pot[2];z++)
                                   if( cost[k] > x*cost[0] + y*cost[1] + z*cost[2] )
                                {
                                    b[0]+=x;
                                    b[1]+=y;
                                    b[2]+=z;

                                    ans=max( ans , -solve(0,toint(a) , toint(b) ) );

                                    b[0]-=x;
                                    b[1]-=y;
                                    b[2]-=z;
                                }

                                b[k]++;
                    }
     }

      return memo[curr][p1][p2]=ans;
}

int play(vector <int> lennysCoins, vector <int> fredsCoins, vector <int> values)
{
    for(int i=0;i<3;i++)
         all.pb( lennysCoins[i] + fredsCoins[i]);

    cost=values;

    memset( done , 0, sizeof(done));

    return solve(0,toint(lennysCoins) , toint(fredsCoins) );


}

};



double test0() {
	int t0[] = {0,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,1,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {20,10,2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	MoneyGame * obj = new MoneyGame();
	clock_t start = clock();
	int my_answer = obj->play(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = -2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {0,1,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,1,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {20,10,2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	MoneyGame * obj = new MoneyGame();
	clock_t start = clock();
	int my_answer = obj->play(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {1,1,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,0,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1,5,10};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	MoneyGame * obj = new MoneyGame();
	clock_t start = clock();
	int my_answer = obj->play(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {4,4,3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {4,3,4};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {100,753,100};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	MoneyGame * obj = new MoneyGame();
	clock_t start = clock();
	int my_answer = obj->play(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 600;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {0,0,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {5,5,5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1000,1000,1000};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	MoneyGame * obj = new MoneyGame();
	clock_t start = clock();
	int my_answer = obj->play(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = -15000;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int t0[] = {3,2,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0,0,0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {6,8,14};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	MoneyGame * obj = new MoneyGame();
	clock_t start = clock();
	int my_answer = obj->play(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 42;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p3 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p3 != my_answer) {
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
