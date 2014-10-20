#include<algorithm>
#include<iostream>
#include <sstream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<fstream>
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
#include<set>
using namespace std;

#define df(i,a,b) for(typeof(b) i=a;i>=b;i--)
#define f(i,a,b) for(typeof(b) i=a;i<=b;i++)
#define fill(x,a) memset(x,a,sizeof(x))
#define Clear(x) memset(x,0,sizeof(x))

#define pb push_back
#define mp make_pair
#define Y second
#define X first

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

typedef unsigned long long int ull;
typedef long long int ll;
typedef vector<string> VS;
typedef pair<int,int> ii;
typedef vector<int> VI;



template <class T>
inline void read(T &i)
{
bool minus=false;
char c;
for(c=getchar();(c<'0'||c>'9')&&(c!='-');c=getchar());
if(c=='-')
{minus=true;
c='0';}
for(i=0;c>='0'&&c<='9';c=getchar())
i=(i<<3)+(i<<1) + (c-48);
if(minus)
i=(~i)+1;
}


int gcd(int a,int b)
{
   if(a==b)
     return b;

   if(b<a)
     return gcd(a%b,b);

   return gcd( a, b%a);
}


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

const int maxnodes = 100002;
const int maxedges = 700000;
const int inf = 2000000000;

class PointyWizardHats {
public:

char buf1[1<<21];
int pos1;

int nextInt() {
	while (buf1[pos1] <= ' ') ++pos1;
	int res = 0;
	while (buf1[pos1] > ' ') 
		res = res*10+(buf1[pos1++]&15);
	return res;
}



int src, dest, edges;
int last[maxnodes], head[maxedges], prev[maxedges];
char flow[maxedges], cap[maxedges];
int dist[maxnodes], Q[maxnodes], work[maxnodes];
bool hasrev[maxedges];

void dinic_init() {
	memset(last, 255, sizeof(last));
	edges = 0;
}

void addedge(int u, int v, bool rev) {
	head[edges] = v;
	cap[edges] = 1;
	flow[edges] = 0;
	prev[edges] = last[u];
	last[u] = edges++;
	if (rev) {
		hasrev[edges] = hasrev[edges ^ 1] = true;
		head[edges] = u;
		cap[edges] = 0;
		flow[edges] = 0;
		prev[edges] = last[v];
		last[v] = edges++;		
	} else {
		hasrev[edges ^ 1] = false;
		edges++;
	}
}

bool dinic_bfs(int nodes) {
	memset(dist, 255, nodes * sizeof(int));
	dist[src] = 0;
	int sizeQ = 0;
	Q[sizeQ++] = src;
	for (int i = 0; i < sizeQ; i++) {
		int u = Q[i];
		for (int e = last[u]; e >= 0; e = prev[e]) {
			int v = head[e];
			if (flow[e] < cap[e] && dist[v] < 0) {
				dist[v] = dist[u] + 1;
				Q[sizeQ++] = v;
			}
		}
	}
	return dist[dest] >= 0;
}

bool dinic_dfs(int u) {
	if (u == dest)
		return true;
	for (int &e = work[u]; e >= 0; e = prev[e]) {
		int v = head[e];
		if (flow[e] < cap[e] && dist[v] == dist[u] + 1) {
			if (dinic_dfs(v)) {
				++flow[e];
				if(hasrev[e])
					--flow[e ^ 1];
				return true;
			}
		}
	}
	return false;
}

int maxFlow(int _src, int _dest, int nodes) {
	src = _src;
	dest = _dest;
	int result = 0;
	while (dinic_bfs(nodes)) {
		memcpy(work, last, nodes * sizeof(int));
		while (dinic_dfs(src))
			++result;
	}
	return result;
}


int getNumHats(vector <int> th, vector <int> tr, vector <int> bh, vector <int> br) 
{
    
    int n=th.size();
    int m=bh.size();
    
    dinic_init();
    
    int s=n+m;
    int t=n+m+1;
    
    for(int i=0;i<n;i++)
      addedge(s,i,false);
      
      
      vector<double> th1,tr1,bh1,br1;
      
      for(int i=0;i<n;i++)
        { th1.pb(th[i]);
          tr1.pb(tr[i]);
        }
        
      for(int i=0;i<m;i++)
        { bh1.pb(bh[i]);
          br1.pb(br[i]);
        } 
        
      for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
         {
              double r1=tr1[i],h1=th1[i];
              double r2=br1[j],h2=bh1[j];          
              
              if( r1 < r2 )
                if( h1 > ( r1*h2)/r2 )
                  addedge(i,j+n,true);
         }  
         
         for(int i=0;i<m;i++)
           addedge(i+n,t,false);
           
           int res=maxFlow(s, t , n+m+2 );
           
           return res;       
	
}

};


double test0() {
	int t0[] = {30};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {30};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	PointyWizardHats * obj = new PointyWizardHats();
	clock_t start = clock();
	int my_answer = obj->getNumHats(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 1;
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
	int t0[] = {4,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {4,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {5,12};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {5,4};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	PointyWizardHats * obj = new PointyWizardHats();
	clock_t start = clock();
	int my_answer = obj->getNumHats(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 1;
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
	int t0[] = {3};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1,1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {2,4};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	PointyWizardHats * obj = new PointyWizardHats();
	clock_t start = clock();
	int my_answer = obj->getNumHats(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 1;
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
double test3() {
	int t0[] = {10,10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,9};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {3,6};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	PointyWizardHats * obj = new PointyWizardHats();
	clock_t start = clock();
	int my_answer = obj->getNumHats(p0, p1, p2, p3);
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
double test4() {
	int t0[] = {3,4,5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {5,4,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {3,4,5};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {3,8,5};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	PointyWizardHats * obj = new PointyWizardHats();
	clock_t start = clock();
	int my_answer = obj->getNumHats(p0, p1, p2, p3);
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
double test5() {
	int t0[] = {1,2,3,4,5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2,3,4,5,6};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,3,4,5,6};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1,2,3,4,5};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	PointyWizardHats * obj = new PointyWizardHats();
	clock_t start = clock();
	int my_answer = obj->getNumHats(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 0;
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
double test6() {
	int t0[] = {123,214,232,323,342,343};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {123,123,232,123,323,434};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {545,322,123,545,777,999};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {323,443,123,656,767,888};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	PointyWizardHats * obj = new PointyWizardHats();
	clock_t start = clock();
	int my_answer = obj->getNumHats(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 5;
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
double test7() {
	int t0[] = {999,999,999,10000,10000,10000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {10000,10000,10000,1,2,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2324,2323,234,5454,323,232};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1,2,3222,434,5454,23};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	PointyWizardHats * obj = new PointyWizardHats();
	clock_t start = clock();
	int my_answer = obj->getNumHats(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 3;
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
	
	time = test3();
	if (time < 0)
		errors = true;
	
	time = test4();
	if (time < 0)
		errors = true;
	
	time = test5();
	if (time < 0)
		errors = true;
	
	time = test6();
	if (time < 0)
		errors = true;
	
	time = test7();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
