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

int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int cost[12];

struct node
{
     int x;
     int y;
     int mins;
     int sp;

     bool operator<(const node &b)const
     {
        if( mins !=b.mins)
             return mins>b.mins;
        else
            return sp > b.sp;
     }

};

class ExpensiveTravel
{
public:
    int lcm;
    int row,col;

    bool done[55][55];


int  minTime(vector <string> in, int startRow, int startCol, int endRow, int endCol)
{
      lcm=1;

      for(int i=2;i<=9;i++)
      {
            int gcd=__gcd(lcm,i);
            lcm=(lcm*i)/gcd;
      }


      for(int i=1;i<=9;i++)
         cost[i]=lcm/i;


      row=in.size();
      col=in[0].size();


      memset(done,0,sizeof(done));

      startRow--;
      startCol--;
      endRow--;
      endCol--;

      priority_queue<node> Q;

      Q.push( (node){startRow,startCol , 1, cost[ in[startRow][startCol] -'0'] } );

      while(Q.size() > 0)
      {

            node curr=Q.top(); Q.pop();

            if( (curr.x==endRow) && (curr.y==endCol) )
                 return curr.mins;

            if( done[curr.x][curr.y] )
                 continue;

            if( in[curr.x][curr.y]=='1')
                 continue;

            done[curr.x][curr.y]=true;


              for(int i=0;i<4;i++)
              {
                    node nxt=curr;
                    nxt.x+=dx[i];
                    nxt.y+=dy[i];

                    if( nxt.x < 0 || nxt.x >=row || nxt.y < 0 || nxt.y>=col )
                        continue;

                    if( in[nxt.x][nxt.y]=='1')
                        continue;

                    nxt.sp+=cost[ in[nxt.x][nxt.y]-'0' ];

                    if( nxt.sp > lcm)
                    {
                        nxt.mins++;
                        nxt.sp=cost[ in[nxt.x][nxt.y]-'0' ] + cost[ in[curr.x][curr.y]-'0' ] ;
                    }

                    Q.push(nxt);
              }
      }



   return-1;


}

};



double test0() {
	string t0[] = {"22334"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	int p2 = 1;
	int p3 = 1;
	int p4 = 5;
	ExpensiveTravel * obj = new ExpensiveTravel();
	clock_t start = clock();
	int my_answer = obj->minTime(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"55",
 "52",
 "55"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	int p2 = 2;
	int p3 = 3;
	int p4 = 2;
	ExpensiveTravel * obj = new ExpensiveTravel();
	clock_t start = clock();
	int my_answer = obj->minTime(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"251",
 "212",
 "122"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	int p2 = 1;
	int p3 = 3;
	int p4 = 3;
	ExpensiveTravel * obj = new ExpensiveTravel();
	clock_t start = clock();
	int my_answer = obj->minTime(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"452232",
 "287979",
 "219872",
 "928234",
 "767676"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	int p2 = 6;
	int p3 = 3;
	int p4 = 1;
	ExpensiveTravel * obj = new ExpensiveTravel();
	clock_t start = clock();
	int my_answer = obj->minTime(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"11"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	int p2 = 1;
	int p3 = 1;
	int p4 = 2;
	ExpensiveTravel * obj = new ExpensiveTravel();
	clock_t start = clock();
	int my_answer = obj->minTime(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	string t0[] = {"123456789987654321"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	int p2 = 2;
	int p3 = 1;
	int p4 = 16;
	ExpensiveTravel * obj = new ExpensiveTravel();
	clock_t start = clock();
	int my_answer = obj->minTime(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p5 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p5 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p5 != my_answer) {
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
