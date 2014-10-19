/*Something Wrong here
See Yazini Cdoe in Arena
*/

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

vector <int> parse(string s, string c)
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

  vector<int> ret;

  for(int i=0;i<ans.sz;i++)
     ret.pb( atoi( ans[i].c_str() ) );

  return ret;
}


/*Solution code starts here */

class StampsCollection
{
public:


bool edge[55][55];
bool done[55];

vector<int> want[55];
int buyer;

vector<int> curr;
vector<int> price;


void dfs( int u)
{
     if( done[u] )
         return;

     curr.pb(u);
     done[u]=true;

     for(int i=0;i<buyer;i++)
          if( edge[u][i])
             dfs(i);
}

int  max_val( vector<int> in)
{
    cout<<"\n\nIn Max_Val\n\n";

    for(int i=0;i<in.sz;i++)
         cout<<in[i]<<"  ";

     int dp[55];


     dp[0]=0;
     dp[1]=in[0];

     int ans=dp[1];

     for(int i=2;i<=in.sz;i++)//edn at this
     {
          int mx=0;

           for(int j=0;j<=i-2;j++)
             mx=max(mx, dp[j] + in[i-1] );

           dp[i]=mx;

           ans=max(ans,dp[i]);
     }

     cout<<"\nAns is "<<ans<<endl;

     return ans;
}


int process()
{
    vector<int> all;

    for(int i=0;i<curr.sz;i++)
         all.pb( price[ curr[i] ] );

         cout<<"\n\n\n\nProceesing\n";

         for(int i=0;i<curr.sz;i++)
             cout<<curr[i]<<" ";

    if( all.sz <= 3)
    {
         if(  edge[ curr[0] ] [ curr[ curr.sz-1] ] )
             { int mx=0;

                for(int i=0;i<all.sz;i++)
                  mx=max(mx,all[i]);

                  cout<<"In M=3 Condn   "<<mx<<endl;

                 return mx;
             }

             return max_val(all);
    }


    if(  edge[ curr[0] ] [ curr[ curr.sz-1] ] )
    {
           //select  0 th ,
             vector<int> tp=all;
                tp.pop_back();
               tp.erase(tp.begin(),tp.begin()+2);

               int op1=all[0]+ max_val(tp);

           //ignore 0 th
                 tp=all;
                 tp.erase(tp.begin(),tp.begin()+1);

                 int op2=max_val(tp);

                 cout<<"Final answer is  " <<" "<<max(op1,op2)<<endl;

                 return max(op1,op2);
    }

    cout<<"Final answer is  " <<" "<<max_val(all)<<endl;

    return max_val(all);
}


int sell(int n, vector <string> demand, vector <int> _price)
{
     price=_price;

     fill(edge,0);

     buyer=demand.sz;

     for(int i=0;i<demand.sz;i++)
     {
          vector<int> tp=parse(demand[i]," ");

            for(int j=0;j<tp.sz;j++)
                 want[ tp[j] ].pb(i);
     }

     for(int i=0;i<n;i++)
     {
          vector<int> tp=want[i];

           for(int j=0;j<tp.sz;j++)
             for(int k=j+1;k<tp.sz;k++)
              edge[ tp[k] ][ tp[j] ]=edge[ tp[j] ][ tp[k] ]=true;
     }



     fill(done,0);

     int ans=0;

     for(int i=0;i<buyer;i++)
         if( !done[i] )
            {
                curr.clear();

                dfs(i);

                ans+=process();
            }

      return ans;

}

};



double test0() {
	int p0 = 10;
	string t1[] = {"0 4"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int t2[] = {3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	StampsCollection * obj = new StampsCollection();
	clock_t start = clock();
	int my_answer = obj->sell(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 3;
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
	int p0 = 2;
	string t1[] = {"1 0","0"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int t2[] = {3,5};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	StampsCollection * obj = new StampsCollection();
	clock_t start = clock();
	int my_answer = obj->sell(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 5;
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
	int p0 = 3;
	string t1[] = {"0 1","0 2","1 2"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int t2[] = {10,11,12};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	StampsCollection * obj = new StampsCollection();
	clock_t start = clock();
	int my_answer = obj->sell(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 12;
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
	int p0 = 3;
	string t1[] = {"0","1 0","1 2"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int t2[] = {5,9,5};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	StampsCollection * obj = new StampsCollection();
	clock_t start = clock();
	int my_answer = obj->sell(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 10;
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
	int p0 = 20;
	string t1[] = {"0 1","1 2","2 3","3 0","4 5","5 6","6 4","8","8","9","9 10","10 11","11 12","12"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	int t2[] = {3,7,4,1,3,3,1,5,6,5,18,10,1,5};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	StampsCollection * obj = new StampsCollection();
	clock_t start = clock();
	int my_answer = obj->sell(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 40;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
