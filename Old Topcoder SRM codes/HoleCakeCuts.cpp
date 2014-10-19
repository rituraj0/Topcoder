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

class HoleCakeCuts
{
public:

    bool done[550][550];
    bool hcut[550],vcut[550];
    int cl;

    void dfs(int x, int y)
    {
         if( done[x][y])  return;

         done[x][y]=true;

         if( x>0 && !vcut[x-1])
             dfs(x-1,y);

         if(x+1<2*cl & !vcut[x])
             dfs(x+1,y);

          if(y>0 && !hcut[y-1])
             dfs(x,y-1);

          if(y+1<2*cl && !hcut[y])
             dfs(x,y+1);

    }


int cutTheCake(int cl, int hl, vector <int> hc, vector <int> vc)
{
      this->cl=cl;

     fill(hcut,0); fill(vcut,0); fill(done,0);

     for(int i=0;i<hc.sz;i++)
          hcut[ hc[i]+cl-1]=true;

      for(int i=0;i<vc.sz;i++)
         vcut[ vc[i]+cl-1]=true;

      for(int i=cl-hl;i<cl+hl;i++)
         for(int j=cl-hl;j<cl+hl;j++)
          done[i][j]=true;//holes

      int ans=0;

      for(int i=0;i<cl+cl;i++)
         for(int j=0;j<cl+cl;j++)
          if(!done[i][j])
      {
           ans++;
           dfs(i,j);
      }

       return ans;

}

};



double test0() {
	int p0 = 5;
	int p1 = 3;
	int t2[] = {1, -4};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	HoleCakeCuts * obj = new HoleCakeCuts();
	clock_t start = clock();
	int my_answer = obj->cutTheCake(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int p0 = 10;
	int p1 = 5;
	vector <int> p2;
	int t3[] = {-2, 2};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	HoleCakeCuts * obj = new HoleCakeCuts();
	clock_t start = clock();
	int my_answer = obj->cutTheCake(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 4;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int p0 = 10;
	int p1 = 5;
	int t2[] = {1};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {-5, 5};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	HoleCakeCuts * obj = new HoleCakeCuts();
	clock_t start = clock();
	int my_answer = obj->cutTheCake(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 6;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	int p0 = 50;
	int p1 = 5;
	int t2[] = {40, -40};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {20, 0, -20};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	HoleCakeCuts * obj = new HoleCakeCuts();
	clock_t start = clock();
	int my_answer = obj->cutTheCake(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 12;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p4 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
