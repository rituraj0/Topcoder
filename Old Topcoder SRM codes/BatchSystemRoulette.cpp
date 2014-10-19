#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
#define sz(s) ((int)(s.size()))

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

class BatchSystemRoulette
{
public:

map<string,double> mapa;

vector <double> expectedFinishTimes(vector <int> d, vector <string> us)
{
    int n=sz(d);

    for(int i=0;i<n;i++)
    {
        mapa[ us[i] ]+=d[i];
    }

    vector<double> ans(n);

     for(int i=0;i<n;i++)
     {
            double eq=0;
            double own=mapa[ us[i] ];
            double low=0;

            for( map<string,double>::iterator it=mapa.begin();it!=mapa.end();it++)
            {
                if(it->Y==own)
                    eq++;

                if(it->Y < own)
                     low+=it->Y;
            }


             double tp=low;
             tp+=(eq-1)*own/2.0;//sam wale

             tp+=(own-d[i])/2.0;

             ans[i]=tp+d[i];
     }

     return ans;

}

};


double test0() {
	int t0[] = {3, 2, 4, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string t1[] = {"Gil Grissom", "Sarah Sidle", "Warrick Brown", "Catherine Willows"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	BatchSystemRoulette * obj = new BatchSystemRoulette();
	clock_t start = clock();
	vector <double> my_answer = obj->expectedFinishTimes(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double t2[] = {6.0, 3.0, 10.0, 1.0 };
	vector <double> p2(t2, t2+sizeof(t2)/sizeof(double));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
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
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {3, 2, 4, 1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string t1[] = {"mac taylor", "Mac Taylor", "Mac Taylor", "Peyton Driscoll"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	BatchSystemRoulette * obj = new BatchSystemRoulette();
	clock_t start = clock();
	vector <double> my_answer = obj->expectedFinishTimes(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double t2[] = {4.0, 8.0, 9.0, 1.0 };
	vector <double> p2(t2, t2+sizeof(t2)/sizeof(double));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
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
	if (my_answer != p2) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {13, 14, 15, 56, 56};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	string t1[] = {"Tim Speedle", "Tim Speedle", "Tim Speedle", "Horatio Caine", "YEEEAAAAAAAAAAH"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	BatchSystemRoulette * obj = new BatchSystemRoulette();
	clock_t start = clock();
	vector <double> my_answer = obj->expectedFinishTimes(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double t2[] = {27.5, 28.0, 28.5, 126.0, 126.0 };
	vector <double> p2(t2, t2+sizeof(t2)/sizeof(double));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p2.size() > 0) {
		cout <<p2[0];
		for (int i=1; i<p2.size(); i++)
			cout <<", " <<p2[i];
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
	if (my_answer != p2) {
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
