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

class MarriageProblemRevised
{
public:


int neededMarriages(vector <string> in)
{
     int n=in.sz,m=in[0].sz;

     for(int i=0;i<n;i++)
     {
          int mila=0;

             for(int j=0;j<m;j++)
                  if( in[i][j]=='1')
                   mila++;

             if(!mila)
                 return -1;
     }



     for(int i=0;i<m;i++)
     {
          int mila=0;

             for(int j=0;j<n;j++)
                  if( in[j][i]=='1')
                   mila++;

             if(!mila)
                 return -1;
     }


     int all[55]; fill(all,0);

     for(int i=0;i<n;i++)
     {
           all[i]=(1<<i);

            for(int j=0;j<m;j++)
                  if( in[i][j]=='1')
                    all[i]+=(1<<(n+j));
     }

     for(int i=0;i<m;i++)
     {
          all[i+n]=(1<<(n+i));

           for(int j=0;j<n;j++)
              if( in[j][i]=='1')
                all[i+n]+=(1<<j);
     }


     int req=(1<<(n+m));
     int ans=n+m;



     for(int i=0;i<req;i++)
     {
           int tp=0;

           int select=0;

          for(int j=0;j<n+m;j++)
              if( i&(1<<j) )
                  {tp=(tp|all[j]);
                  select++;
                  }



              if(tp==req-1)
                 ans=min( ans , select );
     }

     return ans;

}

};


double test0() {
	string t0[] = {"111"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MarriageProblemRevised * obj = new MarriageProblemRevised();
	clock_t start = clock();
	int my_answer = obj->neededMarriages(p0);
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
	string t0[] = {"100", "010", "001"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MarriageProblemRevised * obj = new MarriageProblemRevised();
	clock_t start = clock();
	int my_answer = obj->neededMarriages(p0);
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
	string t0[] = {"00", "00"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MarriageProblemRevised * obj = new MarriageProblemRevised();
	clock_t start = clock();
	int my_answer = obj->neededMarriages(p0);
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
double test3() {
	string t0[] = {"0001", "0001", "0001", "1111"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MarriageProblemRevised * obj = new MarriageProblemRevised();
	clock_t start = clock();
	int my_answer = obj->neededMarriages(p0);
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
double test4() {
	string t0[] = {"11101011","00011110","11100100","01010000","01000010","10100011","01110110","10111111"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	MarriageProblemRevised * obj = new MarriageProblemRevised();
	clock_t start = clock();
	int my_answer = obj->neededMarriages(p0);
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
