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

#define pii pair<int,int>

#define mod 1000000009

class DrivingPlans
{
public:

int dist[2005],cont[2005];
bool zero[2005];
vector< pii > adj[2005];

int count(int N, vector <int> A, vector <int> B, vector <int> C)
{
    int m=A.sz;

    fill(zero,0);

    for(int i=0;i<A.sz;i++)
    {
         A[i]--; B[i]--;
        adj[ A[i] ].pb( mp(B[i] , C[i]) );
        adj[ B[i] ].pb( mp(A[i] , C[i]) );

        if(C[i]==0)
        zero[ A[i] ]=zero[ B[i] ]=true;
    }

    if( zero[0] || zero[N-1] )
        return -1;

     set<pii> Q;

     fill(dist,63);

     for(int i=0;i<N;i++)
          if( zero[i])
            cont[i]=-1;
         else
            cont[i]=0;

    dist[0]=0; cont[0]=1;

    Q.insert( mp(0,0) );

    while( Q.size() > 0)
    {
        pii curr=*Q.begin(); Q.erase( Q.begin() );
        int u=curr.Y;

        if( curr.X > dist[u] ) continue;

        for(int i=0;i<adj[u].sz;i++)
        {
            int v=adj[u][i].X;
            int wt=adj[u][i].Y;

            if( dist[u]+wt < dist[v])
            {
                //this block of code is reuired ,
//                pii del=mp( dist[v],v);
//                set<pii>::iterator it=Q.find(del);
//                if(it!=Q.end() )
//                    Q.erase(it);
                //without above block , Wrong answer on test ~300

                dist[v]=dist[u]+wt;
                Q.insert( ( mp(dist[v],v) ) );

                if( !zero[v])
                    cont[v]=cont[u];
            }
            else if( dist[u] + wt == dist[v] )
            {
                 if( zero[u])
                     cont[v]=-1;
                 else if( cont[v]!=-1)
                    cont[v]=( cont[v]+cont[u])%mod;
            }
        }
    }

   return cont[N-1];

}

};


double test0() {
	int p0 = 4;
	int t1[] = {1,1,2,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,3,4,4};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1,1,1,1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	DrivingPlans * obj = new DrivingPlans();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 2;
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
	int p0 = 4;
	int t1[] = {1,1,2,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,3,4,4};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1,1,1,0};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	DrivingPlans * obj = new DrivingPlans();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = -1;
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
	int p0 = 7;
	int t1[] = {1,1,2,3,4,4,5,6};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,3,4,4,5,6,7,7};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1,1,2,2,3,3,4,4};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	DrivingPlans * obj = new DrivingPlans();
	clock_t start = clock();
	int my_answer = obj->count(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 4;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
