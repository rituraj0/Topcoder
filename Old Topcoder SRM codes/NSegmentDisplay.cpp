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

class NSegmentDisplay
{
public:

bool cool( vector<string> sym , vector<string> pat , vector<bool> work)
{
   for(int i=0;i<pat.sz;i++)
   {
        bool mila=false;

           for(int j=0;j<sym.sz;j++)
           {
               bool val=true;

                  for(int k=0;k<pat[i].sz;k++)
                       if( work[k])
                          if(sym[j][k]!=pat[i][k])
                              val=false;

                  if(val)
                     mila=true;
           }

           if(!mila)
             return false;
   }

   return true;
}


string brokenSegments(vector <string> symbols, vector <string> patterns)
{
    vector<bool> work( symbols[0].sz ,0);

    for(int i=0;i<patterns.sz;i++)
         for(int j=0;j<patterns[i].sz;j++)
             if( patterns[i][j]=='1')
                work[j]=true;

    if( !cool(symbols,patterns,work) )
       return "INCONSISTENT";

   string ans="";

   for(int i=0;i<work.sz;i++)
      if( work[i])
       ans+="Y";
     else
     {
           work[i]=true;

           if( cool(symbols,patterns,work) )
             ans+="?";
            else
              ans+="N";

            work[i]=false;

     }

   return ans;
}

};


double test0() {
	string t0[] = {"1011111","0000011","1110110","1110011","0101011"
,"1111001","1111101","1000011","1111111","1111011"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"1011111"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	NSegmentDisplay * obj = new NSegmentDisplay();
	clock_t start = clock();
	string my_answer = obj->brokenSegments(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "Y?YYYYY";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"1011111","0000011","1110110","1110011","0101011"
,"1111001","1111101","1000011","1111111","1111011"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"0111111"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	NSegmentDisplay * obj = new NSegmentDisplay();
	clock_t start = clock();
	string my_answer = obj->brokenSegments(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "NYYYYYY";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"1011111","0000011","1110110","1110011","0101011"
,"1111001","1111101","1000011","1111111","1111011"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"1000000","0010000"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	NSegmentDisplay * obj = new NSegmentDisplay();
	clock_t start = clock();
	string my_answer = obj->brokenSegments(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "INCONSISTENT";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"1011111","0000011","1110110","1110011","0101011"
,"1111001","1111101","1000011","1111111","1111011"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"0010110","0010010","0010000"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	NSegmentDisplay * obj = new NSegmentDisplay();
	clock_t start = clock();
	string my_answer = obj->brokenSegments(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "NNYNYYN";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"110000111001","100000101000","000001010000"
,"101100010011","111111111101"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"010000000000","010000000000","000000000000"
,"000000000000","000000000000"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	NSegmentDisplay * obj = new NSegmentDisplay();
	clock_t start = clock();
	string my_answer = obj->brokenSegments(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "NY????NNN??N";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	string t0[] = {"00000000001000000010","01010000001011101110"
,"01010101110110011010","00111001111001000100"
,"10010111010110110000","11011011001000110001"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"00011000010000000000","10010110010000100000"
,"00010100010000001000","00010100010000001000"
,"00010000000000101000","00000000000000000000"
,"00010100010000001000","00011000010000000000"
,"00011000010000000000","00000000000000000000"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	NSegmentDisplay * obj = new NSegmentDisplay();
	clock_t start = clock();
	string my_answer = obj->brokenSegments(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "YNNYYYYNNYNNNNYNYNN?";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test6() {
	string t0[] = {"001000111101000","000001111011001"
,"010010100100010","111000100010011"
,"011011011010001","010011111101000"
,"000101011110011","010000011111000"
,"000001100100011","000000111110000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"001000110001000","000101110000011"
,"000101010000011","001000110101000"
,"010001100000111"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	NSegmentDisplay * obj = new NSegmentDisplay();
	clock_t start = clock();
	string my_answer = obj->brokenSegments(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p2 = "INCONSISTENT";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p2 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
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
	
	time = test6();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
