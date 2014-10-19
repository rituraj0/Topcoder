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

struct state
{
    short pos, mask;
    bool bada,eq;

    state()
    {
        pos=-1,mask=0,bada=0,eq=0;
    }

    state( short a, short b, bool c, bool d)
    {
        pos=a ;mask=b;
        bada=c; eq=d;
    }
};


string tost( ll in)
{
    char tp[20];
    sprintf(tp,"%lld",in);
    string ans=(string)tp;

    while(ans.sz<18)
        ans="0"+ans;

    return ans;
}
class TheInteger
{
public:

queue<state> Q;

state prev[20][1100][2][2];
short edge[20][1100][2][2];//is pos pe , last state se anne me kya laga tha
bool done[20][1100][2][2];

bool cool( state st , string in , int k)
{
    if( st.pos==18)
         if( __builtin_popcount( st.mask)==k)
}

long long find(long long n, int k)
{

   cout<<prev[0][1][1][0].pos<<endl;
   cout<<tost(103)<<endl;

   string in=tost(n);

   fill(done,0);

   Q.push( state(0,0,0,1) );
   edge[0][0][0][1]=-1;

   while( !Q.empty() )
   {
       state curr=Q.front();  Q.pop();

       short pos=curr.pos,mask=curr.mask;
       bool bada=curr.bada , eq=curr.eq;

       if( done[pos][mask][bada][eq] ) continue;

       done[pos][mask][bada][eq]=true;

       if( pos==18) continue;

        for(int x=0;x<=9;x++)
        {
            short new_pos=pos+1;
            short new_mask=( mask|(1<<x) );

            bool new_eq=false,new_bada=false;

            if(eq)
            {
                if(x==in[pos]-'0')
                     new_eq=true;
            }

             new_bada=bada;

             if( eq)
             {
                 if( x > in[pos]-'0' )
                     new_bada=true;
             }

             if( (!new_bada)&&(!new_eq) ) continue;

             if( prev[new_pos][new_mask][new_bada][new_eq].pos!=-1)  continue;

             prev[new_pos][new_mask][new_bada][new_eq]=curr;
             edge[new_pos][new_mask][new_bada][new_eq]=x;

             Q.push( state(new_pos,new_mask,new_bada , new_eq) );

        }//end for

    }//edn while


    string ans="";

    state
    //



   return 0;
}

};


double test0() {
	long long p0 = 47LL;
	int p1 = 1;
	TheInteger * obj = new TheInteger();
	clock_t start = clock();
	long long my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 55LL;
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
	long long p0 = 7LL;
	int p1 = 3;
	TheInteger * obj = new TheInteger();
	clock_t start = clock();
	long long my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 102LL;
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
	long long p0 = 69LL;
	int p1 = 2;
	TheInteger * obj = new TheInteger();
	clock_t start = clock();
	long long my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 69LL;
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
	long long p0 = 12364LL;
	int p1 = 3;
	TheInteger * obj = new TheInteger();
	clock_t start = clock();
	long long my_answer = obj->find(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	long long p2 = 12411LL;
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

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
