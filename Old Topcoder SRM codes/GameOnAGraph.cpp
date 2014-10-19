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

#define mod 1000000007

class GameOnAGraph
{
public:

    ll W[51][51] , B[51][51] , all[51][51] , C[51][51] , rm[51][51];
    int n;

  void multiply( ll c[51][51] , ll a[51][51] , ll b[51][51])
    {
        fill(rm,0);

        for(int i=0;i<n;i++)
             for(int j=0;j<n;j++)
             {
               ll tp=0;

                for(int k=0;k<n;k++)
                     tp=(tp+a[i][k]*b[k][j])%mod;

                rm[i][j]=tp;
             }

             memcpy(c,rm,sizeof(rm));
    }


  void power(int ex)
    {
         if(ex==0)
         {
            fill(C,0);
            for(int i=0;i<n;i++)
                 C[i][i]=1;
            return;
         }

         if( ex&1)
         {
            power(ex-1);
            multiply(C,C,all);
         }
         else
         {
             power(ex/2);
             multiply(C,C,C);
         }
    }


vector <int> getMarks(vector <string> adj, string colors, string marks, int t)
{
       n=colors.size();

       fill(W,0);

       for(int i=0;i<n;i++)
          if( colors[i]=='B')
       {
              for(int j=0;j<n;j++)
                  if( adj[i][j]=='1')
                   W[i][j]=1;
       }
       else
       {
           W[i][i]=1;
       }

       fill(B,0);

       for(int i=0;i<n;i++)
          if( colors[i]=='W')
       {
            for(int j=0;j<n;j++)
                  if( adj[i][j]=='1' )
                    B[i][j]=1;
       }
      else
       {
           B[i][i]=1;
       }

       multiply(all,B,W);

       power(t/2);

       if(t&1)
         multiply(C,W,C);

       vector<int> ans(n,0);

       ll in[51];
        for(int i=0;i<n;i++)
             in[i]=(marks[i]-'0');

       for(int i=0;i<n;i++)
       {
           ll tp=0;

            for(int k=0;k<n;k++)
                  tp=(tp+C[i][k]*in[k])%mod;

             ans[i]=tp;
       }

       return ans;


}

};


double test0() {
	string t0[] = {"0110","1000","1000","0000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "WBBW";
	string p2 = "1000";
	int p3 = 1;
	GameOnAGraph * obj = new GameOnAGraph();
	clock_t start = clock();
	vector <int> my_answer = obj->getMarks(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t4[] = {1, 1, 1, 0 };
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<p4[0];
		for (int i=1; i<p4.size(); i++)
			cout <<", " <<p4[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"00000","00000","00000","00000","00000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "BBWWW";
	string p2 = "99999";
	int p3 = 1;
	GameOnAGraph * obj = new GameOnAGraph();
	clock_t start = clock();
	vector <int> my_answer = obj->getMarks(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t4[] = {0, 0, 9, 9, 9 };
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<p4[0];
		for (int i=1; i<p4.size(); i++)
			cout <<", " <<p4[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"01","10"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "BW";
	string p2 = "56";
	int p3 = 2;
	GameOnAGraph * obj = new GameOnAGraph();
	clock_t start = clock();
	vector <int> my_answer = obj->getMarks(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t4[] = {6, 6 };
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<p4[0];
		for (int i=1; i<p4.size(); i++)
			cout <<", " <<p4[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"010101","101010","010101","101010","010101","101010"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string p1 = "BWBWBW";
	string p2 = "012345";
	int p3 = 10;
	GameOnAGraph * obj = new GameOnAGraph();
	clock_t start = clock();
	vector <int> my_answer = obj->getMarks(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int t4[] = {59049, 177147, 59049, 177147, 59049, 177147 };
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p4.size() > 0) {
		cout <<p4[0];
		for (int i=1; i<p4.size(); i++)
			cout <<", " <<p4[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<my_answer[0];
		for (int i=1; i<my_answer.size(); i++)
			cout <<", " <<my_answer[i];
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p4) {
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
