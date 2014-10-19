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

#define matrix vector<vector<ll> >

ll mini=numeric_limits<long long >::min();

class AntOnGraph
{
public:


 matrix multiply( matrix a , matrix b)
 {
     matrix ans=a;
     int row=a.size(),col=a[0].size();

     for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
        {
            ans[i][j]=mini;

            for(int k=0;k<col;k++)
                 if( (a[i][k] > mini) && (b[k][j] > mini) )//path exist
                  ans[i][j]=max(ans[i][j] , a[i][k]+b[k][j] );
        }

        return ans;
 }

matrix fastexpo( matrix a, int expo)
{
  if(expo==1) return a;

  if( expo&1) return multiply( fastexpo(a,expo-1) ,a);

  matrix tp=fastexpo( a, expo/2);

  return multiply(tp,tp);
}

string tost( ll in)
{
    char ans[25];
    sprintf(ans,"%lld",in);
    return ans;
}
string maximumBonus(vector <string> p0, vector <string> p1, vector <string> p2, int stepsPerSecond, int timeLimit)
{
    int n=p0.size();

     matrix in(n);

     for(int i=0;i<n;i++)
        in[i].resize(n);

     for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
     {
         string tp="";
                tp+=p0[i][j]; tp+=p1[i][j]; tp+=p2[i][j];

          ll curr=atoi( tp.c_str());

          if( curr==0)
            in[i][j]=mini;
          else
            in[i][j]=curr-500;
     }

    in=fastexpo(in , stepsPerSecond);

    if( in[1][1] < 0 )//if there is no
          in[1][1]=0;

    in=fastexpo(in,timeLimit);

    if( in[0][1]==mini)
        return "IMPOSSIBLE";
    return tost( in[0][1]);

}

};


double test0() {
	string t0[] = {"05","50"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"00","00"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"01","10"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	int p3 = 3;
	int p4 = 2;
	AntOnGraph * obj = new AntOnGraph();
	clock_t start = clock();
	string my_answer = obj->maximumBonus(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "3";
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
	string t0[] = {"05","50"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"00","00"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"01","10"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	int p3 = 2;
	int p4 = 3;
	AntOnGraph * obj = new AntOnGraph();
	clock_t start = clock();
	string my_answer = obj->maximumBonus(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "IMPOSSIBLE";
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
	string t0[] = {"0550","0000","0005","5000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"0000","0000","0000","0000"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"0110","0000","0001","1000"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	int p3 = 7;
	int p4 = 9;
	AntOnGraph * obj = new AntOnGraph();
	clock_t start = clock();
	string my_answer = obj->maximumBonus(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "49";
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
double test3() {
	string t0[] = {"0540","0000","0004","4000"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"0090","0000","0009","9000"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"0190","0000","0009","9000"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	int p3 = 7;
	int p4 = 9;
	AntOnGraph * obj = new AntOnGraph();
	clock_t start = clock();
	string my_answer = obj->maximumBonus(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "-5";
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
double test4() {
	string t0[] = {"079269665406","506042219642","720809987956",
 "315099331918","952306192584","406390344278",
 "999241035142","370785209189","728363760165",
 "019367419000","279718007804","610188263490"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"038604914953","804585763146","350629473403",
 "028096403898","575205051686","427800322647",
 "655168017864","582553303278","980402170192",
 "620737714031","686142310509","092421645460"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"063231394554","109852259379","740182746422",
 "853015982521","476805512496","898530717993",
 "430534005863","440162807186","132879980431",
 "685312177072","780267345400","959947501200"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	int p3 = 37;
	int p4 = 1221;
	AntOnGraph * obj = new AntOnGraph();
	clock_t start = clock();
	string my_answer = obj->maximumBonus(p0, p1, p2, p3, p4);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p5 = "20992235";
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
