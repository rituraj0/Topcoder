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

class QuantumAlchemy
{
public:

bool cool( vector<int> req, vector<int> aval)
{
    for(int i=0;i<26;i++)
          if( req[i] > aval[i])
            return false;

     return true;
}


int minSteps(string initial, vector <string> reactions)
{
    map<int,string> part;

    for(int i=0;i<reactions.size();i++)
    {
        int x=reactions[i][ reactions[i].size()-1]-'A';
        string tp=reactions[i].substr( 0 , reactions[i].size()-3);

        part[x]=tp;
    }

    int ans=0;

    vector<int> aval(26,0);
    for(int i=0;i<initial.size();i++)
         aval[ initial[i]-'A' ]++;

     vector<int> req(26,0);
                 req['X'-'A']++;

    for(int it=0;it<=100000;it++)
    {
          if( cool(req,aval) )
             return ans;

          ans++;

          for(int i=0;i<26;i++)
              if( req[i] > aval[i])
              {
                  if( part.count(i)==0)
                     continue;

                   string tp=part[i];

                   for(int j=0;j<tp.size();j++)
                     req[ tp[j] -'A' ]++;

                      req[i]--;
                      break;

              }
    }

    return -1;

}

};

//{, }

double test0() {
	string p0 = "EVOEOCZEOOEOOEVEOEOOEOEOEOEOZOEEOEOECOEEOEOOEOEO";
	string t1[] = {"OZE->C", "ZOEC->V", "QA->X", "ZV->F", "SFCV->A", "EO->Z", "VOC->S", "CSVF->Q"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	QuantumAlchemy * obj = new QuantumAlchemy();
	clock_t start = clock();
	int my_answer = obj->minSteps(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 27;
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
	string p0 = "AABBB";
	string t1[] = {"BZ->Y", "ZY->X", "AB->Z"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	QuantumAlchemy * obj = new QuantumAlchemy();
	clock_t start = clock();
	int my_answer = obj->minSteps(p0, p1);
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
double test2() {
	string p0 = "AAABB";
	string t1[] = {"BZ->Y", "ZY->X", "AB->Z"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	QuantumAlchemy * obj = new QuantumAlchemy();
	clock_t start = clock();
	int my_answer = obj->minSteps(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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
	string p0 = "AAXB";
	string t1[] = {"BZ->Y", "ZY->X", "AB->Z"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	QuantumAlchemy * obj = new QuantumAlchemy();
	clock_t start = clock();
	int my_answer = obj->minSteps(p0, p1);
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
	string p0 = "ABCDEFGHIJKLMNOPQRSTUVWYZABCDEFGHIJKLMNOPQRSTUVWYZ";
	string t1[] = {"ABCE->Z", "RTYUIO->P", "QWER->T", "MN->B"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	QuantumAlchemy * obj = new QuantumAlchemy();
	clock_t start = clock();
	int my_answer = obj->minSteps(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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
