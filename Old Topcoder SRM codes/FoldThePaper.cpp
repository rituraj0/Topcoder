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

class FoldThePaper
{
public:

bool valid[1<<13] , valid1[1<<13] , valid2[1<<13];

int curr[15];

void solve( int N)
{
      for(int i=0;i<N;i++)
          valid[ curr[i] ]=true;

      if(N==1)  return;

      int save[N];
       for(int i=0;i<N;i++)
         save[i]=curr[i];

       for(int i=1;i<N;i++)
       {
             int nn=max(i,N-i);

             for(int j=0;j<nn;j++)
                 curr[j]=0;

             for(int j=i;j<N;j++)
                  curr[j-i]|=save[j];

             int k=0;

             for(int j=i-1;j>=0;j--)
                  curr[k++]|=save[j];

             solve(nn);

             for(int j=0;j<N;j++)
                 curr[j]=save[j];
       }
}

int getValue(vector <string> paper)
{
      int in[15][15];
      int row=paper.sz,col;

      for(int i=0;i<row;i++)
      {
                vector<int> cp=parse( paper[i]," ");
                 col=cp.sz;

                for(int j=0;j<col;j++)
                     in[i][j]=cp[j];
      }


      fill(valid,0);
       for(int i=0;i<row;i++)
         curr[i]=(1<<i);
       solve(row);

       memcpy(valid1,valid,sizeof(valid));


          fill(valid,0);
       for(int i=0;i<col;i++)
          curr[i]=(1<<i);
       solve(col);

       memcpy(valid2,valid,sizeof(valid));


       int ans=-(1<<28);

       for(int i=0;i<(1<<row);i++)
           if( valid1[i])
             {
                for(int j=0;j<(1<<col);j++)
                   if( valid2[j])
                    {
                       int sm=0;

                          for(int a=0;a<row;a++)
                             for(int b=0;b<col;b++)
                                if( i &(1<<a))
                                   if( j &(1<<b))
                                        {
                                            sm+=in[a][b];
                                        }

                      ans=max(ans,sm);
                    }
            }


        return ans;
}

};


double test0() {
	string t0[] = {
"1 1 1",
"1 1 1"
};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FoldThePaper * obj = new FoldThePaper();
	clock_t start = clock();
	int my_answer = obj->getValue(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 6;
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
	string t0[] = {
"1 -1",
"1 -1"
};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FoldThePaper * obj = new FoldThePaper();
	clock_t start = clock();
	int my_answer = obj->getValue(p0);
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
double test2() {
	string t0[] = {
"1 -1 -1 1",
"-1 -1 -1 -1",
"-1 -1 -1 -1",
"1 -1 -1 1"
};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FoldThePaper * obj = new FoldThePaper();
	clock_t start = clock();
	int my_answer = obj->getValue(p0);
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
double test3() {
	string t0[] = {
"20 13 -2 100",
"-12 0 4 -3",
"4 1 -36 21"
};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FoldThePaper * obj = new FoldThePaper();
	clock_t start = clock();
	int my_answer = obj->getValue(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 131;
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
	string t0[] = {
"0"
};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FoldThePaper * obj = new FoldThePaper();
	clock_t start = clock();
	int my_answer = obj->getValue(p0);
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
