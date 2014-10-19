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

string tost( int in)
{
    char s[20];
    sprintf(s,"%d",in);
    return s;
}

typedef long long ll;

class LogCutter
{
public:

vector<int> all;

int solve( int cl , int L , int C)
{
    int done=L;
    int cont=0;

    while( (cont<C) && (done>0) )
    {
        int req=done-cl;

        vector<int>::iterator it=lower_bound( all.begin() , all.end() , req);

        if( it==all.end() )
             return -1;

        cont++;

        done=*it;

        if( done <=cl )
             break;
    }

    if( done <=cl)
    {
        if( cont<C)
            return all[0];

        if( done <0 )
             done+=cl;

        return done;
    }

    return -1;

}

string  bestCut(int L, int A, int K, int C)
{
     set<int> stt;

     for(int i=1;i<=K;i++)
         stt.insert( ((ll)A*(ll)i)%(ll)(L-1) + 1 );

     for(set<int>::iterator it=stt.begin();it!=stt.end();it++)
         all.pb(*it);

      int lo=1,hi=L;

      int len=L+1,st=L+1;

      while( lo <=hi)
      {
            int  mid=(lo+hi)/2;
            int tp=solve(mid,L,C);

            if( tp!=-1 )
            {
                if( mid < len)
                {
                  len=mid;
                  st=tp;
                }
               else if( mid==len)
               {
                st=min(st,tp);
               }

                hi=mid-1;
            }
            else
            {
                lo=mid+1;
            }
      }

      return tost(len)+" "+tost(st);

}

};


double test0() {
	int p0 = 9;
	int p1 = 3;
	int p2 = 2;
	int p3 = 1;
	LogCutter * obj = new LogCutter();
	clock_t start = clock();
	string my_answer = obj->bestCut(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "5 4";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 5;
	int p1 = 2;
	int p2 = 1;
	int p3 = 2;
	LogCutter * obj = new LogCutter();
	clock_t start = clock();
	string my_answer = obj->bestCut(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "3 3";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 6;
	int p1 = 3;
	int p2 = 5;
	int p3 = 3;
	LogCutter * obj = new LogCutter();
	clock_t start = clock();
	string my_answer = obj->bestCut(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "2 1";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 10000;
	int p1 = 999983;
	int p2 = 5000;
	int p3 = 1000;
	LogCutter * obj = new LogCutter();
	clock_t start = clock();
	string my_answer = obj->bestCut(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "13 2";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	int p0 = 5;
	int p1 = 7;
	int p2 = 100;
	int p3 = 100;
	LogCutter * obj = new LogCutter();
	clock_t start = clock();
	string my_answer = obj->bestCut(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "1 1";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
