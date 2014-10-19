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

class GuitarChords
{
public:

vector<int> aval,req;
map<string,int> mapa;
int ans;
int pres[15];

void solve(int curr , int mn , int mx , int mask)
{
	 if(curr==aval.size())
	 {
	 	  if( mask==(1<<req.size())-1)
	 	    {
	 	        int tp=1<<20;

	 	        if(mn<0)
	 	            tp=0;
	 	        else
				    tp=mx-mn+1;

				 ans=min(ans,tp);
	 	    }

	 	    return;
	 }

	 int av=aval[curr];

	 if( pres[av]!=-1)
	  solve(curr+1,mn,mx,mask|(1<<pres[av]) );

	  for(int i=1;i<=24;i++)
	    if( pres[ (av+i)%12 ]!=-1 )
	      {
	          int nmn=(mn<0)?i:min(i,mn);
	          int nmx=(mx<0)?i:max(i,mx);

	          solve(curr+1,nmn,nmx,mask|(1<<pres[ (av+i)%12 ] ) );
	      }

}

int stretch(vector <string> st, vector <string> chord)
{
	 mapa["A"]=0;mapa["A#"]=1;mapa["B"]=2;mapa["C"]=3;
	 mapa["C#"]=4;mapa["D"]=5;mapa["D#"]=6;mapa["E"]=7;
	 mapa["F"]=8;mapa["F#"]=9;mapa["G"]=10;mapa["G#"]=11;

	 for(int i=0;i<st.size();i++)
		aval.pb( mapa[ st[i] ] );

     for(int i=0;i<chord.size();i++)
         req.pb( mapa[ chord[i] ] );

     fill(pres,-1);

     for(int i=0;i<req.size();i++)
      pres[ req[i] ]=i;

      ans=1<<20;

      solve(0,-1,-1,0);

      return ans;

}

};


double test0() {
	string t0[] = { "A", "C", "F" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = { "C#", "F#", "A#" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	GuitarChords * obj = new GuitarChords();
	clock_t start = clock();
	int my_answer = obj->stretch(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 1;
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
	string t0[] = { "E", "A", "D", "G", "B", "E" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = { "E", "G#", "B" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	GuitarChords * obj = new GuitarChords();
	clock_t start = clock();
	int my_answer = obj->stretch(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
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
	string t0[] = { "D#" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = { "D#" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	GuitarChords * obj = new GuitarChords();
	clock_t start = clock();
	int my_answer = obj->stretch(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
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
	string t0[] = { "E", "F" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = { "F#", "D#" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	GuitarChords * obj = new GuitarChords();
	clock_t start = clock();
	int my_answer = obj->stretch(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	string t0[] = { "C", "C", "C" };
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = { "C", "E", "G" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	GuitarChords * obj = new GuitarChords();
	clock_t start = clock();
	int my_answer = obj->stretch(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
