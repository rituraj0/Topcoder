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

class StarsInGraphs
{
public:

    vector<int> cont;

    int maxdeg( int C)
    {
        ll dp[55][55];

        for(int i=0;i<55;i++)
             dp[0][i]=0;

        for(int i=0;i<55;i++)
             dp[i][0]=1;

        for(int i=1;i<55;i++)
             for(int j=1;j<55;j++)
               dp[i][j]=dp[i-1][j-1]+dp[i-1][j];

        int ans=0;

        for(int i=1;i<55;i++)
        {
              int curr=0;

                 for(int j=3;j<=i;j++)
                      curr+=dp[i][j];

                 if( curr<=C)
                      ans=i;
                 else
                    return ans;
        }
    }


int starryPaths(vector <string> adj, int C)
{
     int n=adj.size();

      cont=vector<int>(n,0);

      print(cont.sz);

     for(int i=0;i<n;i++)
     {
           for(int j=0;j<n;j++)
              if( adj[i][j]=='1')
               cont[i]++;
     }



     ll dist[55]; fill(dist,63);


     int mx=maxdeg(C);

     for(int i=0;i<n;i++)
          if( (3<= cont[i]) && (cont[i]<=mx) )
               dist[i]=-1;


     for(int st=1;st<=n+1;st++)
     {

            for(int i=0;i<n;i++)
                 for(int j=0;j<n;j++)
                   if( (3<= cont[i]) && (cont[i]<=mx) && (3<= cont[j]) && (cont[j]<=mx) && (adj[i][j]=='1') &&(dist[i]-1<dist[j]) &&(cont[i]<=cont[j]) )
                    {
                        dist[j]=dist[i]-1;

                        if(st==n+1)
                            return -1;
                    }
     }

     ll ans=0;

     for(int i=0;i<n;i++)
         ans=min(ans,dist[i]);

     return (-ans);







}

};


double test0() {
	string t0[] = {"01110",
 "10111",
 "00000",
 "00000",
 "00000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1000;
	StarsInGraphs * obj = new StarsInGraphs();
	clock_t start = clock();
	int my_answer = obj->starryPaths(p0, p1);
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
double test1() {
	string t0[] = {"01011",
 "00111",
 "10011",
 "00000",
 "00000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	StarsInGraphs * obj = new StarsInGraphs();
	clock_t start = clock();
	int my_answer = obj->starryPaths(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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
	string t0[] = {"0111",
 "0000",
 "0000",
 "0000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	StarsInGraphs * obj = new StarsInGraphs();
	clock_t start = clock();
	int my_answer = obj->starryPaths(p0, p1);
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
double test3() {
	string t0[] = {"01111",
 "00000",
 "00000",
 "00000",
 "00000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 4;
	StarsInGraphs * obj = new StarsInGraphs();
	clock_t start = clock();
	int my_answer = obj->starryPaths(p0, p1);
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
double test4() {
	string t0[] = {"010001100",
 "001001100",
 "000101110",
 "000010111",
 "000001111",
 "010000000",
 "000110000",
 "000100001",
 "100001000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 10;
	StarsInGraphs * obj = new StarsInGraphs();
	clock_t start = clock();
	int my_answer = obj->starryPaths(p0, p1);
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
