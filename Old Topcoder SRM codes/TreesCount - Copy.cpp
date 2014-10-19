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

#define mod 1000000007LL

class TreesCount
{
public:

int dp[55][55];

int count(vector <string> in)
{
    int n=sz(in);

    fill(dp,63);

    for(int i=0;i<n;i++)
    {
         dp[i][i]=0;
         for(int j=0;j<n;j++)
            if( in[i][j]!='0')
              dp[i][j]=in[i][j]-'0';
    }


    for(int k=0;k<n;k++)
         for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
               dp[i][j]=min( dp[i][j] , dp[i][k]+dp[k][j]);


    vector< pair<int,int> >dist;

    for(int i=0;i<n;i++)
          dist.pb( mp(dp[0][i],i) );


    sort( dist.begin(),dist.end() );

    vector<int> cont(n,0);

    assert( sz(cont)==n);

    for(int i=n-1;i>0;i--)
    {
        int curr=dist[i].Y;
        int cd=dist[i].X;

            int cn=0;

              for(int j=0;j<i;j++)//with shorter distnace
                  {

                      int refd=dist[j].X;
                      int add=(in[  dist[j].Y ][curr]=='0'  )?(1<<25):( in[  dist[j].Y ][curr]-'0' );

                      if( refd+add==cd)
                         cn++;
                  }

               cont[i]=cn;
    }

    cont[0]=1;//definitely 0

    ll ans=1;

    for(int i=0;i<n;i++)
         ans=(ans * (ll)cont[i] )%mod;

    return ans;

}

};


double test0() {
	string t0[] = {"01",
 "10"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TreesCount * obj = new TreesCount();
	clock_t start = clock();
	int my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
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
	string t0[] = {"011",
 "101",
 "110"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TreesCount * obj = new TreesCount();
	clock_t start = clock();
	int my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
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
	string t0[] = {"021",
 "201",
 "110"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TreesCount * obj = new TreesCount();
	clock_t start = clock();
	int my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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
	string t0[] = {"0123",
 "1012",
 "2101",
 "3210"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TreesCount * obj = new TreesCount();
	clock_t start = clock();
	int my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 6;
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
double test4() {
	string t0[] = {"073542",
 "705141",
 "350721",
 "517031",
 "442304",
 "211140"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TreesCount * obj = new TreesCount();
	clock_t start = clock();
	int my_answer = obj->count(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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

	time = test4();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
