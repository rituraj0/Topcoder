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

class WebsiteRank
{
public:
    map<string,int> mapa;
    int n;

    bool gr[1500][1500],rs[1500][1500];

    int index( string in)
    {
        if( mapa.count(in))
             return mapa[in];

        n++;
        return (mapa[in]=n);
    }



long long countVotes(vector <string> votes, string website)
{
     n=0;

     fill(gr,0); fill(rs,0);

     for(int i=0;i<votes.sz;i++)
     {
         vector<string> tp=parse( votes[i] ," ");
         index(tp[0]);

         for(int j=1;j<tp.sz;j++)
                gr[ index(tp[j]) ][ index(tp[0]) ]=true;
     }

     for(int i=1;i<=n;i++)
         gr[i][i]=true;

     memcpy(rs,gr,sizeof(gr));

     for(int k=1;k<=n;k++)
         for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)
             rs[i][j]=( rs[i][j]||(rs[i][k]&&rs[k][j]) );

     for(int i=1;i<=n;i++)
         for(int  j=1;j<=n;j++)
              if( gr[i][j] && rs[j][i])
                 gr[i][j]=false;

     int deg[1550] ; fill(deg,0);

     for(int i=1;i<=n;i++)
         for(int j=1;j<=n;j++)
            if( gr[i][j] )
               deg[j]++;

     ll ans[1500]; fill(ans,0);

     for(int i=1;i<=n;i++)
          ans[i]=1;

     for(int st=1;st<=n;st++)
     {
            for(int i=1;i<=n;i++)
                  if( deg[i]==0)
            {
                  deg[i]--;

                   for(int j=1;j<=n;j++)
                      if( gr[i][j])
                       { ans[j]+=ans[i];
                         deg[j]--;
                       }
            }
     }

     return ans[ index(website) ];

}

};



double test0() {
	string t0[] = {"C A B"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "C";
	WebsiteRank * obj = new WebsiteRank();
	clock_t start = clock();
	long long my_answer = obj->countVotes(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 3LL;
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
	string t0[] = {"A B C D", "B C D", "C D"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "A";
	WebsiteRank * obj = new WebsiteRank();
	clock_t start = clock();
	long long my_answer = obj->countVotes(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 8LL;
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
	string t0[] = {"A"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "A";
	WebsiteRank * obj = new WebsiteRank();
	clock_t start = clock();
	long long my_answer = obj->countVotes(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 1LL;
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
	string t0[] = {"A B", "B A"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "A";
	WebsiteRank * obj = new WebsiteRank();
	clock_t start = clock();
	long long my_answer = obj->countVotes(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 1LL;
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
double test4() {
	string t0[] = {"A B C D E F", "B A", "C B", "D B"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "A";
	WebsiteRank * obj = new WebsiteRank();
	clock_t start = clock();
	long long my_answer = obj->countVotes(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 3LL;
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
double test5() {
	string t0[] = {"MYSITE OTHERSITE ANOTHERSITE THIRDSITE"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "MYSITE";
	WebsiteRank * obj = new WebsiteRank();
	clock_t start = clock();
	long long my_answer = obj->countVotes(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 4LL;
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
