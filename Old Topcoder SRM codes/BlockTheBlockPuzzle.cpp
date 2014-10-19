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

/*
	Dinic's Max Flow algorithm : based on ACRush's implementation
*/

const int maxnode=6000+5;
const int maxedge=360000+5;
const int oo=1000000000;
int node,src,dest,nedge;			// node is number of vertices. nedge is number of edges

// to[e] stores the desitnation of edge e
// nextt[e] stores the nextt edge from same source ( simulating adjList using nextt )
int to[maxedge],nextt[maxedge],flow[maxedge],cap[maxedge];

// head[v] stores the first edge out of this node
// work[v] is first edge of this node in working phase. Note as we may "delete" edges, this has to be changed in same phase
int head[maxnode], dist[maxnode], Q[maxnode], work[maxnode];

void init(int _node,int _src,int _dest)
{
	node=_node;
	src=_src;
	dest=_dest;
	for (int i=0;i<node;i++)		head[i]=-1;
	nedge=0;
}

void addedge(int u,int v,int c1,int c2)					// add to graphs edge from  u to v with cap c1 & from v to u with cap c2
{
	to[nedge]=v,cap[nedge]=c1,flow[nedge]=0,nextt[nedge]=head[u],head[u]=(nedge++);
	to[nedge]=u,cap[nedge]=c2,flow[nedge]=0,nextt[nedge]=head[v],head[v]=(nedge++);
}

// Check if using "valid" edges you can go from source to destintion. Also meanwhile make layers of graph
bool dinic_bfs()
{
	for(int i =0; i < node; i++)
		dist[i] = -1;

	dist[src]=0;	int sizeQ=0;	Q[sizeQ++]=src;
	for (int front=0;front<sizeQ; front++)
	{
		for (int u=Q[front], e=head[u]; e>=0; e=nextt[e])
		{
			int v = to[e];
			if (flow[e]<cap[e] && dist[v]<0 )			// We want dist[v] < 0 as we want only edges which are crossing layers
			{
				dist[v]=dist[u]+1;
				Q[sizeQ++]=v;
			}
		}
	}
	return dist[dest] >= 0;
}

int dinic_dfs(int u,int bot)		// Find augment pathing from u to destination, where path capacity is alredy found to be nomore then bot
{
	if (u==dest) return bot;
	for (int i=work[u];i>=0; i=nextt[i], work[u] = i)		// we are changing work[u] as in this phase, previous edge has been deleted
	{
		int v=to[i],tmp;
		if (flow[i]<cap[i] && dist[v]==dist[u]+1 && (tmp = dinic_dfs(v,min(bot,cap[i]-flow[i])) )>0)
		{
			flow[i] +=tmp;
			flow[i^1]-=tmp;						// i^1 is the reverse edge always !
			return tmp;
		}
	}
	return 0;
}

int dinic_flow()
{
	int result=0;
	while (dinic_bfs())
	{
		for (int i=0;i<node;i++) work[i]=head[i];
		while (true)
		{
			int delta=dinic_dfs(src,oo);
			if (delta==0) break;					// This phase is over
			result+=delta;
		}
	}
	return result;
}

class BlockTheBlockPuzzle
{
public:

int row,col;

int id(int x, int y)
{
    return (x*col+y);
}

int minimumHoles(vector <string> in)
{
     row=in.sz;
     col=in[0].sz;

    int all=row*col;

    init(2*all+2,2*all,2*all+1);

    int dx=-1,dy=-1;

    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
           if( in[i][j]=='$')
              dx=i,dy=j;

     int infi=1000000;

    for(int i=0;i<row;i++)
         for(int j=0;j<col;j++)
             if( ((i-dx)%3==0) &&( (j-dy)%3==0) )
                {
                    if( in[i][j]=='H') continue;

                    addedge(  id(i,j) , id(i,j)+all , (in[i][j]=='.')?1:infi ,0 );

                    if( in[i][j]=='$') addedge( id(i,j)+all , dest , infi,0 );

                    if( in[i][j]=='b') addedge( src , id(i,j) , infi ,0 );


                    for(int x=-1;x<=1;x++)
                     for(int y=-1;y<=1;y++)
                         if( abs(x)+abs(y)==1)
                         {
                            int x2=i+x*3 , y2=j+y*3;

                            if( (x2<0)||(x2>=row) || (y2<0) || (y2>=col) ) continue;

                            if( in[x2][y2]=='H') continue;

                            char c1=in[i+x][j+y];
                            char c2=in[i+2*x][j+2*y];

                            if( c1=='H' && c2=='H') continue;

                            if( c1=='.' && c2=='.')
                                 addedge( id(i,j)+all , id(x2,y2) , 2 ,0);
                            else if( (c1=='.' || c1=='H') && (c2=='.' || c2=='H') )
                                  addedge( id(i,j)+all , id(x2,y2) ,1 ,0 );
                            else
                                 addedge( id(i,j)+all , id(x2,y2) ,infi,0);

                        }
        }

        int ans=dinic_flow();

        if( ans >=infi) return -1;

        return ans;

}

};


double test0() {
	string t0[] = {"b..$",
 "....",
 "HHHH",
 "HHHH"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	BlockTheBlockPuzzle * obj = new BlockTheBlockPuzzle();
	clock_t start = clock();
	int my_answer = obj->minimumHoles(p0);
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
double test1() {
	string t0[] = {"............H..",
 "...............",
 "...............",
 "HHH$HHH.....H..",
 "HHHHHHH........",
 "HHHHHHHH.......",
 "......b..H.....",
 "...............",
 "...............",
 "...H..H..H.....",
 "...............",
 "...............",
 "...............",
 "...............",
 "..............."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	BlockTheBlockPuzzle * obj = new BlockTheBlockPuzzle();
	clock_t start = clock();
	int my_answer = obj->minimumHoles(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
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
	string t0[] = {"............H..",
 "...............",
 "...............",
 "HHH$HHH........",
 "HHHHHHH........",
 "HHHHHHHH.......",
 "......b..H.....",
 "...............",
 "...............",
 "...H..H..H.....",
 "...............",
 "...............",
 "...............",
 "...............",
 "..............."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	BlockTheBlockPuzzle * obj = new BlockTheBlockPuzzle();
	clock_t start = clock();
	int my_answer = obj->minimumHoles(p0);
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
double test3() {
	string t0[] = {"b..$...",
 "...H...",
 ".......",
 "b..b..b",
 "...H...",
 ".......",
 "b..b..b"}

;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	BlockTheBlockPuzzle * obj = new BlockTheBlockPuzzle();
	clock_t start = clock();
	int my_answer = obj->minimumHoles(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 4;
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
double test4() {
	string t0[] = {"b..b..b",
 "..b..b.",
 ".......",
 "b..$bbb",
 ".b.....",
 "....b..",
 "b..b..b"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	BlockTheBlockPuzzle * obj = new BlockTheBlockPuzzle();
	clock_t start = clock();
	int my_answer = obj->minimumHoles(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = -1;
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

	time = test4();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
