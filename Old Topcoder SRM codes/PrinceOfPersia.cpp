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

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

#define infi 999999

class PrinceOfPersia
{
public:

int n;
int s,t;

int cap[500][500];

bool done[500];


int dfs( int curr , int wt)
{
      if(curr==t)
         return wt;

      if( done[curr])
         return 0;

      done[curr]=true;

      for(int i=0;i<n;i++)
          if( cap[curr][i]  > 0 )
            {
                int tp=dfs(i , min(wt , cap[curr][i] ) );

                if( tp > 0)
                {
                    cap[curr][i]-=tp;
                    cap[i][curr]+=tp;
                    return tp;
                }
            }


            return 0;
}


int solve()
{
    int ans=0;

    while(1)
    {
        fill(done,0);

        int tp=dfs(s,infi);

        if(tp==0)
             break;

        ans+=tp;
    }

    return ans;

}


int minObstacles(vector <string> in)
{
    int row=in.sz;
    int col=in[0].sz;
    int d=row*col;

     n=2*row*col+2;
     s=n-2;
     t=n-1;

     fill(cap,0);

     for(int r1=0;r1<row;r1++)
         for(int c1=0;c1<col;c1++)
            for(int k=0;k<4;k++)
            {
                int r2=r1+dx[k];
                int c2=c1+dy[k];

                if( r2>=0 && r2<row && c2>=0 && c2<col )
                {
                    int p1=r1*col+c1;
                    int p2=r2*col+c2;
                    cap[p1+d][p2]=infi;
                }

            }

        int np=0;

        for(int i=0;i<d;i++)
        {
            int r1=i/col;
            int c1=i%col;

            char ch=in[r1][c1];

            cap[i][i+d]=1;

            if( ch=='P')
            {
                np++;

                if(np==1)
                     cap[s][i+d]=infi;
                else
                    cap[i][t]=infi;
            }
            else if( ch=='#')
            {
                cap[i][i+d]=0;
            }
        }

        int ans=solve();

        if( 2*ans > infi)
              return -1;

        return ans;


}

};


double test0() {
	string t0[] = {"P....",
 "...##",
 "##...",
 "....P"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PrinceOfPersia * obj = new PrinceOfPersia();
	clock_t start = clock();
	int my_answer = obj->minObstacles(p0);
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
double test1() {
	string t0[] = {".....",
 ".P.P.",
 "....."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PrinceOfPersia * obj = new PrinceOfPersia();
	clock_t start = clock();
	int my_answer = obj->minObstacles(p0);
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
double test2() {
	string t0[] = {".#P.",
 ".P#."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PrinceOfPersia * obj = new PrinceOfPersia();
	clock_t start = clock();
	int my_answer = obj->minObstacles(p0);
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
double test3() {
	string t0[] = {"####",
 "#PP#",
 "####"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PrinceOfPersia * obj = new PrinceOfPersia();
	clock_t start = clock();
	int my_answer = obj->minObstacles(p0);
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
