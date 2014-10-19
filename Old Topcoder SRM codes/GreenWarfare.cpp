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
const int MAXV=1000,MAXE=10000;
const ll INF=10000000009LL;

struct maxflow
{
    int V,source,sink,start,vis[MAXV];
    ll eind,eadj[MAXE],ecap[MAXE],eprev[MAXE],elast[MAXV];

    inline void init( int v)
    {
        V=v; eind=start=0;
        memset(elast,-1,V*sizeof(ll) );
    }

    inline void addedge( int a, int b , ll cap1 , ll cap2)
    {
        eadj[eind]=b;ecap[eind]=cap1;eprev[eind]=elast[a];elast[a]=eind++;
        eadj[eind]=a;ecap[eind]=cap2;eprev[eind]=elast[b];elast[b]=eind++;
    }

    ll dfs( int num , ll pcap)
    {
        if(num==sink)
             return pcap;

        if( vis[num]==start)
             return 0;

        vis[num]=start;
        ll sum=0;

        for(int i=elast[num];i!=-1;i=eprev[i])
             if( ecap[i]>0)
              {
                    ll p=dfs( eadj[i] , min(pcap ,(ll)ecap[i] ) );
                    ecap[i]-=p;
                    ecap[i^1]+=p;
                    pcap-=p;
                    sum+=p;

                    if(pcap==0)
                         break;
              }

              return sum;
    }

    ll flow( int _source , int _sink)
    {
        if(V==0)
             return -1;

        memset(vis,-1,sizeof(vis));

        source=_source; sink=_sink;

        ll total=0,aug;

        do
        {
            aug=dfs(source,INF);
            total+=aug;
            start++;
        }
        while( aug > 0);

        return total;
    }

};

const int MAXN=55;

class GreenWarfare
{
public:
    maxflow cal_maxflow;

    ll base_cost[MAXN],plant_cost[MAXN];

     inline ll dist( int dx ,int dy)
     {
          return (dx*dx+dy*dy);
     }



int minimumEnergyCost(vector <int> canonX, vector <int> canonY, vector <int> baseX, vector <int> baseY, vector <int> plantX, vector <int> plantY, int energySupplyRadius)
{
    int c=sz(canonX) , n=sz(baseX) ,m=sz(plantX) , source=n+m,sink=source+1;

    cal_maxflow.init(n+m+2);

    for(int i=0;i<n;i++)
         base_cost[i]=INF;

    for(int i=0;i<m;i++)
         plant_cost[i]=INF;

         for(int i=0;i<c;i++)
             for(int j=0;j<n;j++)
               base_cost[j]=min( base_cost[j],dist( canonX[i]-baseX[j] , canonY[i]-baseY[j] ) );

         for(int i=0;i<c;i++)
             for(int j=0;j<m;j++)
               plant_cost[j]=min( plant_cost[j] , dist(  canonX[i]-plantX[j] , canonY[i]-plantY[j]) );

         for(int i=0;i<n;i++)
             cal_maxflow.addedge(source,i,base_cost[i],0LL);

         for(int i=0;i<m;i++)
             cal_maxflow.addedge(n+i,sink, plant_cost[i],0LL);

         for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
              if( dist( baseX[i]-plantX[j] , baseY[i]-plantY[j] ) <= energySupplyRadius*energySupplyRadius )
               cal_maxflow.addedge(i,n+j,INF,0LL);

         return cal_maxflow.flow( source,sink);

}

};


double test0() {
	int t0[] = { 0 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 0 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1,2,3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {0,0,0};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {3};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	int t5[] = {3};
	vector <int> p5(t5, t5+sizeof(t5)/sizeof(int));
	int p6 = 4;
	GreenWarfare * obj = new GreenWarfare();
	clock_t start = clock();
	int my_answer = obj->minimumEnergyCost(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p7 = 14;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p7 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p7 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = { 0 };
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = { 0 };
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1,2,3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {0,0,0};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {2};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	int t5[] = {2};
	vector <int> p5(t5, t5+sizeof(t5)/sizeof(int));
	int p6 = 4;
	GreenWarfare * obj = new GreenWarfare();
	clock_t start = clock();
	int my_answer = obj->minimumEnergyCost(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p7 = 8;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p7 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p7 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {3,6};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {3,6};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {1,2,3,4,5};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {5,4,2,3,1};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {1,2,5};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	int t5[] = {1,2,5};
	vector <int> p5(t5, t5+sizeof(t5)/sizeof(int));
	int p6 = 5;
	GreenWarfare * obj = new GreenWarfare();
	clock_t start = clock();
	int my_answer = obj->minimumEnergyCost(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p7 = 12;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p7 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p7 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {-10,-10,10};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {10,-10,0};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {10,10,-10};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	int t5[] = {10,-10,0};
	vector <int> p5(t5, t5+sizeof(t5)/sizeof(int));
	int p6 = 10;
	GreenWarfare * obj = new GreenWarfare();
	clock_t start = clock();
	int my_answer = obj->minimumEnergyCost(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p7 = 200;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p7 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p7 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int t0[] = {0};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {0};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	int t2[] = {3};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int t3[] = {3};
	vector <int> p3(t3, t3+sizeof(t3)/sizeof(int));
	int t4[] = {1,2,3};
	vector <int> p4(t4, t4+sizeof(t4)/sizeof(int));
	int t5[] = {0,0,0};
	vector <int> p5(t5, t5+sizeof(t5)/sizeof(int));
	int p6 = 4;
	GreenWarfare * obj = new GreenWarfare();
	clock_t start = clock();
	int my_answer = obj->minimumEnergyCost(p0, p1, p2, p3, p4, p5, p6);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p7 = 14;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p7 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p7 != my_answer) {
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
