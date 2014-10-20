#include<algorithm>
#include<iomanip> 
#include<iostream>
#include<sstream>
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

#define pb push_back
#define mp make_pair
#define Y second
#define X first

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

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
typedef vector<int> vi;

class CactusCount 
{
public:


vector<vi>  adj;   // adj list
int vv [201];      // visited vertex in DFS;
int p[201];        // parent of node i
int cycle[201];    // # of times in a cycle
int maxcycle;


void dfs(int i , int n ,int c)
{
   vv[i]=0;

   for(int j=0;j<adj[i].size();j++)
    {
        int k=adj[i][j];

          if( vv[k]==-1)
	  {
              p[k]=i;
              dfs( k , n  , c);
           }
          else if( vv[k]==0 && p[i]!=k )
           {

                cycle[k]++;

                maxcycle=max( maxcycle  , cycle[k] );

                cycle[i]++;

                maxcycle=max( maxcycle , cycle[i] );

                int parent=p[i];

                 do
                  {
                    cycle[ parent]++;

                    maxcycle=max( maxcycle , cycle[parent] );

		  // cout<<parent<<"  "<<p[parent]<<endl;;
 
                    parent=p[parent];

                   
                   
                  } while( parent!=k);

               continue;

            }//end else
      }//end for

  vv[i]=c; 
           
   
 }

                       

int  countCacti(int n, vector <string> edges) 
{

    if(edges.empty()) return n;


    string edge;
    for(int i = 0; i < edges.size(); ++i)
        edge += edges[i];

    for(int i = 0; i < edge.size(); ++i)
        if(edge[i]==',') edge[i] = ' '; 
    
    adj.clear();
    adj.resize(n, vi());

    memset(vv,-1, sizeof(vv));
    memset(p, 0, sizeof(p));
    memset(cycle, 0, sizeof(cycle));

    stringstream ss(edge);
    int a, b;
    while(ss >> a >> b) {
        --a, --b;
        adj[b].push_back(a) ; adj[a].push_back(b);
    }

  int cnt=0,c=0;

 

  for(int i=0;i<n;i++)
    if( vv[i]==-1 )
       {
            p[i]=-1;
             c++;

         maxcycle=0;

          dfs(i,n,c);

          if( maxcycle <=1 )
	   cnt++;
        }

    return cnt;

          
	
}

};

double test0() {
	int p0 = 3;
	string t1[] = {"1 2,1 3,2 3"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	CactusCount * obj = new CactusCount();
	clock_t start = clock();
	int my_answer = obj->countCacti(p0, p1);
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
double test1() {
	int p0 = 10;
	vector <string> p1;
	CactusCount * obj = new CactusCount();
	clock_t start = clock();
	int my_answer = obj->countCacti(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 10;
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
	int p0 = 5;
	string t1[] = {"1 2,3 4,4 5"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	CactusCount * obj = new CactusCount();
	clock_t start = clock();
	int my_answer = obj->countCacti(p0, p1);
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
double test3() {
	int p0 = 17;
	string t1[] = {"1 2,2 3,3 4,4 5,5 3,1 3,6 7,7 8,6 8,8 9,9 1",
 "0,10 11,11 9,12 13,14 15,15 16,16 17,14 17,14 16"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	CactusCount * obj = new CactusCount();
	clock_t start = clock();
	int my_answer = obj->countCacti(p0, p1);
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
