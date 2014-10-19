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

class PotentialArithmeticSequence
{
public:

int  tobinary( int in)
{
    string ans="";

    while( (in>0) || (( (int)ans.size())<60) )
    {
        if(in&1)
            ans="1"+ans;
        else
            ans="0"+ans;
        in=in/2;
    }

    int cn=0;
    int i=sz(ans);
    i--;

    while(i>0)
    {
        if( ans[i]=='0')
             cn++;
        else
            break;

            i--;
    }
    return cn;
}

vector<int> prev,aage;

vector<int> in;

void go( vector<int> x)
{
    for(int i=0;i<sz(x);i++)
         cout<<x[i]<<"   -  ";

    cout<<"\n\n";;
}

bool cool( int x ,int y)
{
    vector<int> curr;

     int mx=-1,id=-1;

    for(int i=x;i<=y;i++)
           curr.pb( in[i] );


        //any two consutive same , return 0

    for(int i=1;i<sz(curr);i++)
         if( curr[i-1]==curr[i])
            return false;

    for(int i=0;i<sz(curr);i++)
         if( curr[i]>mx)
       {
        mx=curr[i];
        id=i;
      }




    ///compare piche
      vector<int> bk;

      for(int i=id-1;i>=0;i--)
          bk.pb( curr[i]);

      vector<int> bk_req;

      for(int i=0;i<id;i++)
          bk_req.pb( prev[i] );

      if( bk_req!=bk)
        return false;

  //compare aage

       vector<int> ag;

       for(int i=id+1;i<sz(curr);i++)
          ag.pb( curr[i]);

       vector<int> ag_req;

       for(int i=1;id+i<sz(curr);i++ )
          ag_req.pb( aage[i-1]);

       if( ag_req!=ag)
         return false;


//        go(bk);
//        go(bk_req);
//        go(ag);
//        go(ag_req);

       return true;

}
int numberOfSubsequences(vector <int> d)
{
    int mx=(1<<20);
    for(int i=-1;i>=-55;i--)
         { prev.pb( tobinary(mx+i));
           cout<<prev[ sz(prev)-1]<<endl;
         }

        cout<<"***********\n";
    for(int i=1;i<=55;i++)
          {aage.pb( tobinary(mx+i) );
            cout<<aage[ sz(aage)-1 ]<<endl;
          }

    in=d;

    int ans=sz(in);

    cout<<cool(0,1)<<endl;

    for(int i=0;i<sz(in);i++)
         for(int j=i+1;j<sz(in);j++)
            {

                int add=cool(i,j);

               //cout<<i<<"  "<<j<<"  **  "<<add<<endl;;

               ans+=add;

                //cout<<" ** * *\n\n";
            }


    return ans;

}

};


double test0() {
	int t0[] = {0,1,0,2,0,1,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	PotentialArithmeticSequence * obj = new PotentialArithmeticSequence();
	clock_t start = clock();
	int my_answer = obj->numberOfSubsequences(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 28;
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
	int t0[] = {0,0,0,0,0,0,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	PotentialArithmeticSequence * obj = new PotentialArithmeticSequence();
	clock_t start = clock();
	int my_answer = obj->numberOfSubsequences(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 7;
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
	int t0[] = {0,0,0,0,1,1,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	PotentialArithmeticSequence * obj = new PotentialArithmeticSequence();
	clock_t start = clock();
	int my_answer = obj->numberOfSubsequences(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 8;
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
	int t0[] = {0,100,0,2,0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	PotentialArithmeticSequence * obj = new PotentialArithmeticSequence();
	clock_t start = clock();
	int my_answer = obj->numberOfSubsequences(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 11;
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
	int t0[] = {1,11,3,0,1,0,1,0,1,0,1,0,3,0,2,0,0,0,0,1,2,3,20};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	PotentialArithmeticSequence * obj = new PotentialArithmeticSequence();
	clock_t start = clock();
	int my_answer = obj->numberOfSubsequences(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 49;
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
