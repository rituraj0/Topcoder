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

class TaroJiroGrid
{
public:


string in[55];
int n;

int dp[55][55];

bool cool(int a, char ac , int b , char bc)
{
    string temp[55];

    for(int i=0;i<=n;i++)
        temp[i]=in[i];

    for(int i=1;i<=n;i++)
        {
          temp[a][i]=ac;

           temp[b][i]=bc;
        }

   fill(dp,0);

   for(int row=1;row<=n;row++)
   for(int col=1;col<=n;col++)
   {
       if( temp[row][col]==temp[row-1][col])
          dp[row][col]=dp[row-1][col]+1;
       else
         dp[row][col]=1;

       if( dp[row][col] > (n/2) )
         return false;
   }

   return true;
}

bool noop()
{
    string temp[55];

    for(int i=0;i<=n;i++)
        temp[i]=in[i];

   fill(dp,0);

   for(int row=1;row<=n;row++)
   for(int col=1;col<=n;col++)
   {
       if( temp[row][col]==temp[row-1][col])
          dp[row][col]=dp[row-1][col]+1;
       else
         dp[row][col]=1;

       if( dp[row][col] > (n/2) )
         return false;
   }

   return true;
}
int getNumber(vector <string> grid)
{
    n=sz(grid);

    in[0]=string(100,'x');

    cout<<sz(in[0])<<endl;


    for(int i=1;i<=n;i++)
    {
        in[i]="$"+grid[i-1];
    }


    int ans=3;//wbw paatern and enjoy

    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
      {
          if( cool(i,'B',j,'W') )
             ans=2;

          if( cool(i,'W',j,'B') )
             ans=2;

         if( cool(i,'W',j,'W') )
             ans=2;

         if( cool(i,'B',j,'B') )
             ans=2;
      }

   for(int i=1;i<=n;i++)
   {
          if( cool(i,'B',0,'$') )
             ans=1;

          if( cool(i,'W',0,'$') )
             ans=1;
   }

   if( noop() )
     ans=0;

   return ans;

}

};


double test0() {
	string t0[] = {"WB",
 "BB"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TaroJiroGrid * obj = new TaroJiroGrid();
	clock_t start = clock();
	int my_answer = obj->getNumber(p0);
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
	string t0[] = {"WB",
 "WW"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TaroJiroGrid * obj = new TaroJiroGrid();
	clock_t start = clock();
	int my_answer = obj->getNumber(p0);
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
	string t0[] = {"WB",
 "WB"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TaroJiroGrid * obj = new TaroJiroGrid();
	clock_t start = clock();
	int my_answer = obj->getNumber(p0);
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
	string t0[] = {"WBBW",
 "WBWB",
 "WWBB",
 "BWWW"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TaroJiroGrid * obj = new TaroJiroGrid();
	clock_t start = clock();
	int my_answer = obj->getNumber(p0);
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
double test4() {
	string t0[] = {"WBBWBB",
 "BBWBBW",
 "WWBWBW",
 "BWWBBB",
 "WBWBBW",
 "WWWBWB"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	TaroJiroGrid * obj = new TaroJiroGrid();
	clock_t start = clock();
	int my_answer = obj->getNumber(p0);
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
