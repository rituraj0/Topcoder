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

typedef long long ll;
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

const ll mod = 1000000007;

ll memo2[31][31];
ll memo[31][31][51][51];

class ReverseResources
{
public:

vector<string> resources;
string in;


ll solve2( int l , int r )
{
     if( memo2[l][r]!=-1)
         return memo2[l][r];

     ll ans=0;

     memo2[l][r]=ans;

     for(int i=0;i<resources.size();i++)
          ans=(ans+ solve(l,r,i,0) )%mod;

     return memo2[l][r]=ans;


}

ll solve( int l , int r, int id, int pos)
{
    if(pos==resources[id].size() )
    {
         return (l==r?1:0);
    }


    if(l==r)
        return 0;

     if( memo[l][r][id][pos]!=-1 )
         return memo[l][r][id][pos];

     ll ans=0;
     memo[l][r][id][pos]=ans;

     if(resources[id][pos] != '%' )
     {
            if( in[l]==resources[id][pos])
                 ans=solve( l+1, r , id , pos+1)%mod;
     }
     else
     {
            for(int p=l+1 ; p<=r ;p++)
            {
                ll tp=(solve2(l,p)* solve(p,r,id,pos+2))%mod;

                 ans=(ans+tp)%mod;
            }
     }


     return memo[l][r][id][pos]=ans;
}


int findDecompositions(string str, vector <string> res)
{
   in=str;
   resources=res;

   memset( memo , -1, sizeof(memo));
   memset( memo2, -1, sizeof(memo2));

   return solve2(0,in.size());

}

};


double test0() {
	string p0 = "Error in module foo, code 123.";
	string t1[] = {"foo", "123", "Error in module %s.", "%s, code %s"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	ReverseResources * obj = new ReverseResources();
	clock_t start = clock();
	int my_answer = obj->findDecompositions(p0, p1);
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
	string p0 = "The fox jumped over the dog.";
	string t1[] = {"The fox %s over the dog.",
 "lazy",
 "brown",
 "jump%s",
 "s",
 "ed",
 "The %s",
 "fox %s",
 "%s over %s",
 "the dog."};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	ReverseResources * obj = new ReverseResources();
	clock_t start = clock();
	int my_answer = obj->findDecompositions(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 5;
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
	string p0 = "abcde";
	string t1[] = {"%sc%s", "b", "de", "a%s"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	ReverseResources * obj = new ReverseResources();
	clock_t start = clock();
	int my_answer = obj->findDecompositions(p0, p1);
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
double test3() {
	string p0 = "abcde";
	string t1[] = {"%se", "a%s", "%sb%s", "%sc%s", "%sd%s"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	ReverseResources * obj = new ReverseResources();
	clock_t start = clock();
	int my_answer = obj->findDecompositions(p0, p1);
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
double test4() {
	string p0 = "aaaaa";
	string t1[] = {"a","%s%s"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	ReverseResources * obj = new ReverseResources();
	clock_t start = clock();
	int my_answer = obj->findDecompositions(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 14;
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
	string p0 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	string t1[] = {"a","aa","%s%s","%sa","a%s","aaa","aa%s","a%sa",
"a%s%s","%saa","%sa%s","%s%sa","%s%s%s","aaaa",
"aaa%s","aa%sa","aa%s%s","a%saa","a%sa%s","a%s%sa",
"a%s%s%s","%saaa","%saa%s","%sa%sa","%sa%s%s",
"%s%saa","%s%sa%s","%s%s%sa","%s%s%s%s","aaaaa",
"aaaa%s","aaa%sa","aaa%s%s","aa%saa","aa%sa%s",
"aa%s%sa","aa%s%s%s","a%saaa","a%saa%s","a%sa%sa",
"a%sa%s%s","a%s%saa","a%s%sa%s","a%s%s%sa",
"a%s%s%s%s","%saaaa","%saaa%s","%saa%sa","%saa%s%s"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	ReverseResources * obj = new ReverseResources();
	clock_t start = clock();
	int my_answer = obj->findDecompositions(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 879704799;
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
double test6() {
	string p0 = "aa";
	string t1[] = {"a", "a", "%s%s", "%s%s"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	ReverseResources * obj = new ReverseResources();
	clock_t start = clock();
	int my_answer = obj->findDecompositions(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 8;
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
	
	time = test6();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
