#include <bits/stdc++.h>
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

#define print(a) cout<<(#a)<<" = "<<a<<"\n";
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

#define pii pair<int,int>

class SettingTents
{
public:

vector<pii> all[20005];

bool online( pii a, pii b)
{
     return (a.X*b.Y==a.Y*b.X);
}

int countSites(int N, int M)
{
    for(int i=-100;i<=100;i++)
         for(int j=-100;j<=100;j++)
    {
        all[ (i*i+j*j) ].pb( mp(i,j) );
    }


    ll ans=0;

   int cn=0;

  for(int d=1;d<=20000;d++)
     for(int i=0;i<all[d].sz;i++)
      for(int j=i+1;j<all[d].sz;j++)
  {
       cn++;

       if( online( all[d][i]  ,all[d][j]) ) continue;

       int sx=all[d][i].X + all[d][j].X;
       int sy=all[d][i].Y + all[d][j].Y;

       int max_x=0,max_y=0,min_x=0,min_y=0;

       max_x=max( max_x , max( all[d][i].X , max( all[d][j].X , sx) ) );
       min_x=min( min_x , min( all[d][i].X , min( all[d][j].X , sx) ) );

       max_y=max( max_y , max( all[d][i].Y , max( all[d][j].Y , sy) ) );
       min_y=min( min_y , min( all[d][i].Y , min( all[d][j].Y , sy) ) );

       int wid=max_x-min_x;

       int len=max_y-min_y;

       if( wid > N) continue;
       if( len > M) continue;

       ll cont=(N-wid+1)*(M-len+1);

       ans+=cont;
  }

    print(cn);
  return (ans/4);

}

};


double test0() {
	int p0 = 2;
	int p1 = 2;
	SettingTents * obj = new SettingTents();
	clock_t start = clock();
	int my_answer = obj->countSites(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
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
	int p0 = 1;
	int p1 = 6;
	SettingTents * obj = new SettingTents();
	clock_t start = clock();
	int my_answer = obj->countSites(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
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
	int p0 = 6;
	int p1 = 8;
	SettingTents * obj = new SettingTents();
	clock_t start = clock();
	int my_answer = obj->countSites(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 527;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
