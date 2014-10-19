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

class Egalitarianism3
{
public:

ll dp[55][55];

int maxCities(int n, vector <int> a, vector <int> b, vector <int> len)
{

    if(n==1)
         return 1;

   for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
      if( i==j)
         dp[i][j]=0;
      else
           dp[i][j]=1e9;


  for( int i=0;i<n-1;i++)
      dp[ a[i] ][ b[i] ]=dp[ b[i] ][ a[i] ]=len[i];


for(int k=1;k<=n;k++)
  for(int i=1;i<=n;i++)
     for(int j=1;j<=n;j++)
     {
      dp[i][j]=min( dp[i][j] , dp[i][k]+dp[k][j]);
     }

 int ans=0;


 for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
 {
     vector<int> tp; tp.pb(i); tp.pb(j);

     int d=dp[i][j];

      for(int k=1;k<=n;k++)
          if( (k!=i)&&(k!=j) )
          {
                bool cool=true;

                for(int m=0;m<sz(tp);m++)
                {
                        if( dp[ tp[m] ][ k ]!=d)
                             cool=false;
                }

              if(cool)
                tp.pb(k);
        }

        ans=max( ans , sz(tp) );
 }

 return ans;

}

};


double test0() {
	int p0 = 4;
	int t1[] = {1,1,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,3,4};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1,1,1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	Egalitarianism3 * obj = new Egalitarianism3();
	clock_t start = clock();
	int my_answer = obj->maxCities(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 3;
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
	int p0 = 6;
	int t1[] = {1,2,3,2,3};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,3,4,5,6};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {2,1,3,2,3};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	Egalitarianism3 * obj = new Egalitarianism3();
	clock_t start = clock();
	int my_answer = obj->maxCities(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 3;
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
	int t1[] = {1,1,1,1,1,1,1,1,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {2,3,4,5,6,7,8,9,10};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {1000,1000,1000,1000,1000,1000,1000,1000,1000};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	Egalitarianism3 * obj = new Egalitarianism3();
	clock_t start = clock();
	int my_answer = obj->maxCities(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 9;
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
	int p0 = 1;
	vector <int> p1;
	vector <int> p2;
	vector <int> p3;
	Egalitarianism3 * obj = new Egalitarianism3();
	clock_t start = clock();
	int my_answer = obj->maxCities(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p4 = 1;
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
