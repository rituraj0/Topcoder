#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>

using namespace std;

int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};

class ArcadeManao {
public:
int cr,cc;
int row,col;

vector<string> level;

bool visit[55][55];

bool path( int len )
{
memset( visit, 0, sizeof(visit) );

queue<int> Q;

for(int j=0;j<col;j++)
  { visit[row-1][j]=true;
     Q.push(row-1);
     Q.push(j);
  }
  
 while(  ! Q.empty() )
 {
 
       int x=Q.front();  Q.pop();
       int y=Q.front() ; Q.pop();
       
       if( x==cr && y==cc )
         return true;
         
       for(int l=0;l<=len;l++)
         for(int k=0;k<4;k++)
          {
             int  tx=x+dx[k]*l;
             int  ty=y+dy[k];
             
             if( tx <0 || tx >= row || ty <0 || ty >=col|| visit[tx][ty]  || level[tx][ty]=='.')
              continue;
              
              
              visit[tx][ty]=true;
              
              Q.push(tx);
              Q.push(ty);
           }
  }
  
return false;
}



int shortestLadder(vector <string> level, int cr, int cc) 
{
 this->cr=cr-1;
 this->cc=cc-1;
 
 this->level=level;
 
 row=level.size();
 col=level[0].size();
 
 cout<<row<<"  "<<col<<endl;
 
 int hi=max(row,col);
int low=0;
int ans=hi;
 
 while( low <= hi )
  {
      int mid=low+(hi-low)/2;
      
      if( path(mid) )     
         { ans=mid;
            hi=mid-1;
         }
       else
          low=mid+1;
  }  
  
          
 return ans;    
       

	
}

};


double test0() {
	string t0[] = {"XXXX....",
 "...X.XXX",
 "XXX..X..",
 "......X.",
 "XXXXXXXX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 2;
	int p2 = 4;
	ArcadeManao * obj = new ArcadeManao();
	clock_t start = clock();
	int my_answer = obj->shortestLadder(p0, p1, p2);
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
double test1() {
	string t0[] = {"XXXX",
 "...X",
 "XXXX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	int p2 = 1;
	ArcadeManao * obj = new ArcadeManao();
	clock_t start = clock();
	int my_answer = obj->shortestLadder(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 1;
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
	string t0[] = {"..X..",
 ".X.X.",
 "X...X",
 ".X.X.",
 "..X..",
 "XXXXX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	int p2 = 3;
	ArcadeManao * obj = new ArcadeManao();
	clock_t start = clock();
	int my_answer = obj->shortestLadder(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p3 = 4;
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
	string t0[] = {"X"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	int p2 = 1;
	ArcadeManao * obj = new ArcadeManao();
	clock_t start = clock();
	int my_answer = obj->shortestLadder(p0, p1, p2);
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
double test4() {
	string t0[] = {"XXXXXXXXXX",
 "...X......",
 "XXX.......",
 "X.....XXXX",
 "..XXXXX..X",
 ".........X",
 ".........X",
 "XXXXXXXXXX"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	int p2 = 1;
	ArcadeManao * obj = new ArcadeManao();
	clock_t start = clock();
	int my_answer = obj->shortestLadder(p0, p1, p2);
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
