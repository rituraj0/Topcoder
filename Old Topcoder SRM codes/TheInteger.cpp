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
    bool bada,eq,taken;

    state()
    {
        pos=-1,mask=0,bada=0,eq=0,taken=0;
    }

    state( short a, short b, bool c, bool d, bool e)
    {
        pos=a ;mask=b;
        bada=c; eq=d; taken=e;
    }
};


string tost( ll in)
{
    char tp[20];
    sprintf(tp,"%lld",in);
    string ans=(string)tp;

    while(ans.sz<19)
        ans="0"+ans;

    return ans;
}
class TheInteger
{
public:

queue<state> Q;

state prev[20][1100][2][2][2];
short edge[20][1100][2][2][2];//is pos pe , last state se anne me kya laga tha
bool done[20][1100][2][2][2];

bool cool( state st , string in , int k)
{
    if( st.pos==19)
         if( __builtin_popcount( st.mask)==k)
             if( st.bada || st.eq)
                return true;

         return false;
}

ll build( state in)
{
     vector<int> all;

     while(1)
     {
         short pos=in.pos,mask=in.mask;
         bool bada=in.bada,eq=in.eq,taken=in.taken;

          if(edge[pos][mask][bada][eq][taken]!=-1)
            all.pb( edge[pos][mask][bada][eq][taken]);
         else
             break;

         in=prev[pos][mask][bada][eq][taken];
     }

     ll ans=0;

     assert(all.sz==19);

     for(int i=18;i>=0;i--)
     {
//         cout<<all[i]<<" ";
         ans=ans*10+all[i];
     }

     return ans;
}
long long find(long long n, int k)
{

//   cout<<prev[0][1][1][0][0].pos<<endl;
//   cout<<tost(103)<<endl;

   string in=tost(n);

   fill(done,0);

   Q.push( state(0,0,0,1,0) );
   edge[0][0][0][1][0]=-1;

   state mila;

   while( !Q.empty() )
   {
       state curr=Q.front();  Q.pop();

       short pos=curr.pos,mask=curr.mask;
       bool bada=curr.bada , eq=curr.eq,taken=curr.taken;

       if( done[pos][mask][bada][eq][taken] ) continue;

       done[pos][mask][bada][eq][taken]=true;

       if( cool(curr,in,k) )
       {
           mila=curr;
           break;
       }

       if( pos==19) continue;

        for(int x=0;x<=9;x++)
        {
            short new_pos=pos+1;

            bool new_eq=false,new_bada=false;
            bool new_taken=false;

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

             new_taken=taken;

             if( x > 0)
                 new_taken=true;

            short new_mask= mask ;

            if( x > 0)
                 new_mask=(mask | (1<<x) );
            else if( taken)
                 new_mask=(mask | (1<<x) );

             if( (!new_bada)&&(!new_eq) ) continue;

             if( prev[new_pos][new_mask][new_bada][new_eq][new_taken].pos!=-1)  continue;

             prev[new_pos][new_mask][new_bada][new_eq][new_taken]=curr;
             edge[new_pos][new_mask][new_bada][new_eq][new_taken]=x;

             Q.push( state(new_pos,new_mask,new_bada , new_eq,new_taken) );

        }//end for

    }//edn while


//   cout<<mila.pos<<"  "<<mila.mask<<"  "<<mila.bada<<" "<<mila.eq<<"  "<<mila.taken<<endl;

   // state
    //

   return build(mila);

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
