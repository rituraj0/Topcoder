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

vector <int> parse(string s, string c)
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

  vector<int> ret;


  for(int i=0;i<sz(ans);i++)
       ret.pb( atoi(ans[i].c_str()) -1 );

  return ret;
}


/*Solution code starts here */

class FriendTour
{
public:

double ncr[30][30];
int KK;
bool frnd[55][55];

bool done[17][1<<17];
double memo[17][1<<17];

vector<int> graf[55];

double prob( int  curr, int  s)
{
    if( KK > s)
    {
        if(curr==0) return 1.0;
        return 0.0;
    }

    if( curr+KK >=s)
         return 0.0;

    double up=ncr[ s-curr-1][KK-1];
    double down=ncr[s][KK];

    return (up/down);
}

double solve( int curr , int mask , int req )//curr is 0 th frined
{
    if( mask == req )
          return 1.0;

    if( done[curr][mask])
         return memo[curr][mask];

    double ans=0;
    done[curr][mask]=true;
    memo[curr][mask]=0;

    int id=graf[0][curr];

    vector< pair<double,int> > all;

    for(int i=0;i<sz( graf[0] );i++)
          if( frnd[id][ graf[0][i] ] )
               {
                    int nx=graf[0][i];

                     if( (mask&(1<<nx) )==0 )
                     {
                        all.pb( mp( solve(nx, mask^(1<<nx) ,req) ,nx ) );
                     }
              }

    sort( all.begin(),all.end());
    reverse(all.begin(),all.end());

    int path=sz( graf[id] );

    if(id==0)//0 ouhs kia hai
        path--;

    for( int i=0;i< sz(all);i++)
    {
        double pb=prob(i,path);
        ans+=pb*all[i].X;
    }

    return memo[curr][mask]=ans;

}

double tourProbability(vector <string> in, int K)
{
    //ncr
     fill(ncr,0); ncr[0][0]=1;

     for(int i=1;i<30;i++)
     {
         ncr[i][0]=1;

          for(int j=1;j<30;j++)
             ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
     }
    //***
    KK=K;

    int n=sz(in);

    fill(frnd,0);

    graf[0].pb(0);

    for(int i=0;i<n;i++)
    {
         vector<int> curr=parse(in[i]," ");

         for(int j=0;j<sz(curr);j++)
             {
                graf[i].pb( curr[j] );
                frnd[i][ curr[j] ]=true;
             }
    }

    for(int i=0;i<n;i++,cout<<endl)
        for(int j=0;j<sz( graf[i]);j++)
          cout<<graf[i][j]<<"  ";

    fill(done,0);

    int s1=sz(graf[0]);

//    for(int i=0;i<(1<<s1);i++)
//         for(int j=0;j<s1;j++)
//            solve(j,i, (1<<s1)-1);


    return solve(0 , 1 , (1<<s1)-1 );//o th pe hai and0 hi gaya hai

}

};


double test0() {
	string t0[] = {"2 3 4",
 "1 3 4",
 "1 2 4",
 "1 2 3"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 1;
	FriendTour * obj = new FriendTour();
	clock_t start = clock();
	double my_answer = obj->tourProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.2222222222222222;
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
	string t0[] = {"2 3 4",
 "1 3 4",
 "1 2 4",
 "1 2 3"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 2;
	FriendTour * obj = new FriendTour();
	clock_t start = clock();
	double my_answer = obj->tourProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.6666666666666666;
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
	string t0[] = {"3 2 4",
 "3 5 1",
 "5 2 1 4",
 "3 1 5",
 "3 2 4"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 2;
	FriendTour * obj = new FriendTour();
	clock_t start = clock();
	double my_answer = obj->tourProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.3333333333333333;
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
	string t0[] = {"3 2 4",
 "3 5 1",
 "5 2 1 4",
 "3 1 5 6",
 "3 2 4",
 "4"}
;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 2;
	FriendTour * obj = new FriendTour();
	clock_t start = clock();
	double my_answer = obj->tourProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.3055555555555556;
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
double test4() {
	string t0[] = {"6 5 4 2",
 "1 6 3 5",
 "5 4 2",
 "3 1 5",
 "2 4 3 1 6",
 "1 2 5"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	int p1 = 3;
	FriendTour * obj = new FriendTour();
	clock_t start = clock();
	double my_answer = obj->tourProbability(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	double p2 = 0.73125;
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

//	time = test0();
//	if (time < 0)
//		errors = true;
//
//	time = test1();
//	if (time < 0)
//		errors = true;
//
//	time = test2();
//	if (time < 0)
//		errors = true;
//
//	time = test3();
//	if (time < 0)
//		errors = true;

	time = test4();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
