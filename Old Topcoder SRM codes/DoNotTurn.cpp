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

int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

bool done[505][505][4];
bool block[505][505];
int dist[505][505][4];

int incode( int x , int y, int d)
{
    return (x*1000*10+y*10+d);
}

vector<int> decode( int x)
{
    vector<int> ans(3);
    ans[2]=(x%10);x=x/10;
    ans[1]=(x%1000);x=x/1000;
    ans[0]=(x%1000);
    return ans;
}

class DoNotTurn
{
public:

deque< int > Q;

int minimumTurns(int N, int _X0, int _A, int _B, int _Y0, int _C, int _D, int _P, int M)
{


    ll a=_A,b=_B,c=_C,d=_D,p=_P;

    ll xp=_X0,yp=_Y0;
       xp=xp%p;
       yp=yp%p;

    fill(block,0);

    block[xp%N][yp%N]=true;

    for(int i=1;i<M;i++)
    {
        xp=(xp*a+b)%p;
        yp=(yp*c+d)%p;

        block[xp%N][yp%N]=true;
    }

    block[0][0]=block[N-1][N-1]=false;

//    for(int i=0;i<N;i++,cout<<endl)
//         for(int j=0;j<N;j++)
//          cout<<block[i][j];

    fill(done,0);
    fill(dist,63);

    for(int i=0;i<4;i++)
    {
         dist[0][0][i]=0;
         Q.push_back( incode(0,0,i) );
    }

    int ans=-1;

    while( !Q.empty() )//x,y,dir x,y pe hai & dir ki taraf muh hai
    {
        vector<int> curr=decode( Q.front() );
                            Q.pop_front();

        int x=curr[0],y=curr[1],dir=curr[2];

        int cd=dist[x][y][dir];

        if( (x==N-1)&&(y==N-1) )
             {
                 if(ans==-1)
                     ans=cd;
                 else
                     ans=min(ans,cd);
             }

        if( done[x][y][dir] ) continue;


        //cout<<" *****  "<<x<<"  "<<y<<"  "<<dir<< "  "<<cd<<endl;

        done[x][y][dir]=true;

           for(int i=0;i<4;i++)
           {
               int nx=x+dx[i];
               int ny=y+dy[i];

               if( (nx<0) || (nx >=N) || ( ny < 0)||(ny>=N) ) continue;

               if( block[nx][ny]) continue;


               int add=0;

               if(i!=dir)
                  add=1;

               int new_d=cd+add;

               //cout<<nx<<"  "<<ny<<"  "<<i<<"  "<<cd+add<<endl;

                 int  tp=incode(nx,ny,i);

                 dist[nx][ny][i]=min( dist[nx][ny][i] ,new_d);

               if(add)
               {
                   Q.push_back(tp);
               }
               else
               {
                   Q.push_front(tp);
               }
           }
    }

    return ans;
}

};


double test0() {
	int p0 = 2;
	int p1 = 0;
	int p2 = 0;
	int p3 = 1;
	int p4 = 0;
	int p5 = 0;
	int p6 = 1;
	int p7 = 10;
	int p8 = 2;
	DoNotTurn * obj = new DoNotTurn();
	clock_t start = clock();
	int my_answer = obj->minimumTurns(p0, p1, p2, p3, p4, p5, p6, p7, p8);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p9 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p9 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p9 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 3;
	int p1 = 0;
	int p2 = 1;
	int p3 = 1;
	int p4 = 1;
	int p5 = 1;
	int p6 = 0;
	int p7 = 3;
	int p8 = 3;
	DoNotTurn * obj = new DoNotTurn();
	clock_t start = clock();
	int my_answer = obj->minimumTurns(p0, p1, p2, p3, p4, p5, p6, p7, p8);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p9 = -1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p9 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p9 != my_answer) {
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
	int p1 = 0;
	int p2 = 1;
	int p3 = 1;
	int p4 = 1;
	int p5 = 1;
	int p6 = 1;
	int p7 = 3;
	int p8 = 3;
	DoNotTurn * obj = new DoNotTurn();
	clock_t start = clock();
	int my_answer = obj->minimumTurns(p0, p1, p2, p3, p4, p5, p6, p7, p8);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p9 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p9 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p9 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 10;
	int p1 = 911111;
	int p2 = 845499;
	int p3 = 866249;
	int p4 = 688029;
	int p5 = 742197;
	int p6 = 312197;
	int p7 = 384409;
	int p8 = 40;
	DoNotTurn * obj = new DoNotTurn();
	clock_t start = clock();
	int my_answer = obj->minimumTurns(p0, p1, p2, p3, p4, p5, p6, p7, p8);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p9 = 12;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p9 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p9 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 5;
	int p1 = 23;
	int p2 = 2;
	int p3 = 3;
	int p4 = 35;
	int p5 = 5;
	int p6 = 7;
	int p7 = 9;
	int p8 = 3;
	DoNotTurn * obj = new DoNotTurn();
	clock_t start = clock();
	int my_answer = obj->minimumTurns(p0, p1, p2, p3, p4, p5, p6, p7, p8);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p9 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p9 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p9 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int p0 = 2;
	int p1 = 0;
	int p2 = 0;
	int p3 = 0;
	int p4 = 0;
	int p5 = 0;
	int p6 = 0;
	int p7 = 1;
	int p8 = 0;
	DoNotTurn * obj = new DoNotTurn();
	clock_t start = clock();
	int my_answer = obj->minimumTurns(p0, p1, p2, p3, p4, p5, p6, p7, p8);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p9 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p9 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p9 != my_answer) {
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

	time = test5();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
