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

struct st
{
    int remain,step;
    bool win;

    st()
    {
    }

    st( int a, int b , bool c)
    {
        remain=a;
        step=b;
        win=c;
    }
};

int dx[]={-1,1,0,0,-2,2,0,0};
int dy[]={0,0,-1,1,0,0,-2,2};



class TheEasyChase
{
public:

st state[2][21][21][21][21];
queue< vector<int> > Q;

int n;

bool cool( int x, int y)
{
    if( (x < 1 )||(x> n) || (y < 1) || (y>n) ) return false;

    return true;
}

int near0( int x)
{
    int ans=0;

    if(x>1) ans++;
    if(x<n) ans++;

    return ans;
}

int near1( int x)//2 move chal sakta hai
{
    int ans=0;

    if(x>1) ans++;
    if(x<n) ans++;

    if(x>1+1) ans++;
    if(x<n-1) ans++;

    return ans;
}

bool cool( vector<int> in)
{
    for(int i=1;i<in.sz;i++)
    {
        if( (1<=in[i])&&(in[i]<=n) )
            continue;

        return false;
    }

    return true;
}


void solve()//1 do move chal sakta hai
{
     for(int i=1;i<=n;i++)
         for(int j=1;j<=n;j++)
           for(int a=1;a<=n;a++)
             for(int b=1;b<=n;b++)
               {
                    int n1=near0(i)+near0(j);
                    state[0][i][j][a][b]=st(n1,0,false);

                    int n2=near1(a)+near1(j);
                    state[1][i][j][a][b]=st(n2,0,false);
               }

      for(int i=1;i<=n;i++)
         for(int j=1;j<=n;j++)
         {
                    vector<int> tp(5,0);
                    tp[0]=0;tp[1]=i;tp[2]=j;tp[3]=i;tp[4]=j;

                    Q.push(tp);

                    tp[0]=1;

                    Q.push(tp);
         }

        while( !Q.empty() )
        {
                vector<int> target=Q.front(); Q.pop();

                int last=8;

                if( target[0]==1)
                     last=4;

                st cs=state[ target[0] ][ target[1] ][ target[2] ][ target[3] ][ target[4] ];

                for(int i=0;i<last;i++)
                {
                    vector<int> source=target;

                    source[0]=1-target[0];

                    if( target[0]==0)
                    {
                        source[3]+=dx[i];
                        source[4]+=dy[i];
                    }
                    else
                    {
                        source[1]+=dx[i];
                        source[2]+=dy[i];
                    }

                    if(!cool(source))
                        continue;

                    st prev=state[ source[0] ][ source[1] ][ source[2] ][ source[3] ][ source[4] ];

                    if( prev.remain==0) continue;

                    if( cs.win==false)
                        prev.remain=0;
                    else
                         prev.remain--;

                    prev.win=!cs.win;
                    prev.step=cs.step+1;

                    state[ source[0] ][ source[1] ][ source[2] ][ source[3] ][ source[4] ]=prev;

                    if( prev.remain==0)
                    {
                        Q.push( source );
                    }


                }//end for
        }//end while

}

string tost( int in)
{
    char ans[20];
    sprintf(ans,"%d",in);
    return ans;
}

string winner(int n, int rowWhite, int colWhite, int rowBlack, int colBlack)
{
   this->n=n;

   while(Q.sz) Q.pop();

   solve();

   st tp=state[0][rowWhite][colWhite][rowBlack][colBlack];


   string win,mv;

     mv=tost(tp.step);

   if(tp.win)
   {
         win="WHITE";
   }
   else
   {
       win="BLACK";
   }

   return (win+" "+mv);

}

};


double test0() {
	int p0 = 2;
	int p1 = 1;
	int p2 = 1;
	int p3 = 2;
	int p4 = 2;
	TheEasyChase * obj = new TheEasyChase();
	clock_t start = clock();
	string my_answer = obj->winner(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "BLACK 2";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 2;
	int p1 = 2;
	int p2 = 2;
	int p3 = 1;
	int p4 = 2;
	TheEasyChase * obj = new TheEasyChase();
	clock_t start = clock();
	string my_answer = obj->winner(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "WHITE 1";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 3;
	int p1 = 1;
	int p2 = 1;
	int p3 = 3;
	int p4 = 3;
	TheEasyChase * obj = new TheEasyChase();
	clock_t start = clock();
	string my_answer = obj->winner(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "BLACK 6";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p5 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p5 != my_answer) {
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
