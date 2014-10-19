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

#define MAX_V 1009

class StoryFromTCO
{
public:

vector<int> L[MAX_V],C[MAX_V*MAX_V];
int V,dfsPos,dfsNum[MAX_V],lowlink[MAX_V],num_scc;
bool in_stack[MAX_V];
stack<int> S;

int cont[MAX_V*MAX_V];

void tarjan(int v){
    dfsNum[v] = lowlink[v] = dfsPos++;
    S.push(v); in_stack[v] = true;

    for(int i = L[v].size()-1;i>=0;--i){
        int w = L[v][i];
        if(dfsNum[w]==-1){
            tarjan(w);
            lowlink[v] = min(lowlink[v],lowlink[w]);
        }else if(in_stack[w]) lowlink[v] = min(lowlink[v], lowlink[w]);
    }

    if(dfsNum[v]==lowlink[v]){
        vector<int> com;
        int aux;

        do{
            aux = S.top(); S.pop();
            com.push_back(aux);
            in_stack[aux] = false;
        }while(aux!=v);

        C[num_scc] = com;
        ++num_scc;
    }
}

void build_scc(){
    memset(dfsNum,-1,sizeof(dfsNum));
    memset(in_stack,false,sizeof(in_stack));
    dfsPos = num_scc = 0;

    for(int i = 0;i<V;++i)
        if(dfsNum[i]==-1)
            tarjan(i);
}

int minimumChanges(vector <int> pl, vector <int> ct)
{
    V=sz(pl);

    for(int i=0;i<V;i++)
         for(int j=0;j<V;j++)
            if(i!=j)
            {
                int x=pl[i];//if i -> j theni,j true

                if( x <= ct[j] )
                      L[i].pb(j);
            }

      bool loser[1009]; fill(loser,0);

      for(int i=0;i<V;i++)
          if( pl[i] > ct[i] )
              loser[i]=true;

      build_scc();

      int ans=0;

      print(num_scc);

      for(int s=0;s<num_scc;s++)
      {
          bool mila=false;

            for(int i=0;i<sz( C[s]);i++)
                 if( loser[ C[s][i] ] )
                    mila=true;

            if( mila)
                 ans+=sz( C[s]);
            else
                C[s].clear();
      }

      return ans;
}

};


double test0() {
	int t0[] = {20,100,500,50};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {7500,2250,150,24};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	StoryFromTCO * obj = new StoryFromTCO();
	clock_t start = clock();
	int my_answer = obj->minimumChanges(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	int t0[] = {5,4,3,2,1};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {5,4,3,2,1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	StoryFromTCO * obj = new StoryFromTCO();
	clock_t start = clock();
	int my_answer = obj->minimumChanges(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 0;
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
	int t0[] = {1,5,5,5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {8,6,4,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	StoryFromTCO * obj = new StoryFromTCO();
	clock_t start = clock();
	int my_answer = obj->minimumChanges(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = -1;
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
	int t0[] = {3,1,5};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {6,4,2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	StoryFromTCO * obj = new StoryFromTCO();
	clock_t start = clock();
	int my_answer = obj->minimumChanges(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 3;
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
	int t0[] = {14,11,42,9,19};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {11,16,37,41,47}
;
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	StoryFromTCO * obj = new StoryFromTCO();
	clock_t start = clock();
	int my_answer = obj->minimumChanges(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 4;
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
double test5() {
	int t0[] = {4,1,3,3,2,4,5,5,4,4};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {3,3,5,2,4,4,5,4,3,5};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	StoryFromTCO * obj = new StoryFromTCO();
	clock_t start = clock();
	int my_answer = obj->minimumChanges(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 6;
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
double test6() {
	int t0[] = {213,177,237,444,497,315,294,104,522,635,13,26,22,276,88,249,374,17,42,245,80,553,121,625,62,105,
53,132,178,250,18,210,492,181,2,99,29,21,62,218,188,584,702,63,41,79,28,452,2};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {33,40,41,48,74,84,117,125,126,164,197,197,201,218,222,231,244,277,290,309,321,321,360,376,440,
442,465,477,491,513,639,645,647,675,706,710,726,736,736,765,801,838,845,854,863,865,887,902,908};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	StoryFromTCO * obj = new StoryFromTCO();
	clock_t start = clock();
	int my_answer = obj->minimumChanges(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 23;
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

	time = test4();
	if (time < 0)
		errors = true;

	time = test5();
	if (time < 0)
		errors = true;

	time = test6();
	if (time < 0)
		errors = true;

	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
