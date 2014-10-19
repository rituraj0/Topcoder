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

int nextt[1<<18],Q[1<<18],dist[1<<18],deg[1<<18];

class RoundAboutCircle
{
public:


int maxScore(int N)
{
     for(int i=1;i<=N;i++)
     {
          int sm=0;
          int j=i;
          while(j)
          {
              sm+=j%10;
              j=j/10;
          }

          nextt[i]=(i+sm-1)%N+1;
     }

     fill(deg,0);

     for(int i=1;i<=N;i++)
         deg[ nextt[i] ]++;

     int qs=0;

     for(int i=1;i<=N;i++)
          if( deg[i]==0)
          {
           Q[++qs]=i;
          }

      for(int i=1;i<=qs;i++)
      {
               int k=Q[i];
               deg[ nextt[k] ]--;

               if( deg[ nextt[k] ]==0)
                  Q[++qs]=nextt[k];
      }

      fill(dist,-1);

      for(int i=1;i<=N;i++)
         if( dist[i]==-1 && deg[i]>0)
            {
                int len=1;

                for(int k=nextt[i] ;k!=i ; k=nextt[k] )
                  len++;

                for(int k=i;dist[k]<0 ;k=nextt[k])
                   dist[k] =len;
            }


       for(int i=qs;i>=1;i--)
       {
           int k=Q[i];
           dist[k]=dist[ nextt[k] ]+1;
       }

       int ans=0;

       for(int i=1;i<=N;i++)
         { ans=max(ans,dist[i]);
         }


       return ans;



}

};


double test0() {
	int p0 = 4;
	RoundAboutCircle * obj = new RoundAboutCircle();
	clock_t start = clock();
	int my_answer = obj->maxScore(p0);
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
double test1() {
	int p0 = 5;
	RoundAboutCircle * obj = new RoundAboutCircle();
	clock_t start = clock();
	int my_answer = obj->maxScore(p0);
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
double test2() {
	int p0 = 17;
	RoundAboutCircle * obj = new RoundAboutCircle();
	clock_t start = clock();
	int my_answer = obj->maxScore(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 11;
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
	int p0 = 566;
	RoundAboutCircle * obj = new RoundAboutCircle();
	clock_t start = clock();
	int my_answer = obj->maxScore(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 176;
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
