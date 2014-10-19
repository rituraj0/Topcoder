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

int N, numb[40], frnd[40][40], c[20][20], M[15], KK;
double prob[(1<<15)][15];
// The probability of a particular person being displayed, and there are 'from' friends in total
// and if none of the people who are better than him are being displayed. There are 'better' number of people better than him
double choose(int from, int better) {
    if (KK > from) { if (better) return 0.0; else return 1.0; }
    else {
        if (from - better < KK) return 0.0;
        else return ((double)c[from-better-1][KK-1]/(double)c[from][KK]);
    }
}
// Computes prob[i][j]
double compute(int i, int j) {
    vector < pair <double, int> > cur;
    for (int k = 0; k < N; k++)
        if (i&(1<<k)) // If his profile has not been visited
            if (j == -1 || frnd[M[j]][M[k]]) // If either we are on Manao's profile, or M[j] is a friend of M[k]
                cur.push_back(make_pair(prob[(i^(1<<k))][k], k));
        // Sort them, so that it is easy to know how many people are better than him
    sort(cur.begin(), cur.end(), greater< pair <double,int> >());
    double ret = 0.0;
    for (int k = 0; k < cur.size(); k++) ret += choose(((j==-1)?N:numb[M[j]]), k)*prob[(i^(1<<cur[k].second))][cur[k].second];
    return ret;
}
double tourProbability(vector <string> friends, int K) {
    // Compute the binomial coefficients
    for (int i = 0; i < 20; i++) for (int j = 0; j < 20; j++)
        if (j > i) c[i][j] = 0;
        else if (j == 0 || j == i) c[i][j] = 1;
        else c[i][j] = c[i-1][j-1] + c[i-1][j];
    // Get the friend of relations
    KK = K;
    memset(numb, 0, sizeof(numb)); memset(frnd, 0, sizeof(frnd));
    int n = friends.size(); int temp;
    for (int i = 1; i <= n; i++) {
        stringstream ss;
        ss << friends[i-1];
        while (ss >> temp) {
            if (i == 1) M[numb[i]] = temp;
            numb[i]++; frnd[i][temp] = 1;
        }
    } N = numb[1];
    // Compute the probabilities
    memset(prob, 0, sizeof(prob));
    for (int i = 0; i < N; i++) prob[0][i] = 1.0;
    for (int i = 1; i < (1<<N); i++) for (int j = 0; j < N; j++) prob[i][j] = compute(i, j);
    return compute((1<<N)-1, -1);
}

};


/* does not work , will debug later
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
*/


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
