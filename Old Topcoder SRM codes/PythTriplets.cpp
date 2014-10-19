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

vector <ll> parse(string s, string c)
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

  vector<ll> ret;

  for(int i=0;i<sz(ans);i++)
     ret.pb( atoi(ans[i].c_str()) );

   return ret;
}


/*Solution code starts here */

    /*Solution code starts here */
const int MAXV=250,MAXE=62500;
const int INF=1000000009;

struct maxflow
{
    int V,source,sink,start,vis[MAXV];
    int eind,eadj[MAXE],ecap[MAXE],eprev[MAXE],elast[MAXV];

    inline void init( int v)
    {
        V=v; eind=start=0;
        memset(elast,-1,V*sizeof(int) );
    }

    inline void addedge( int a, int b , int cap1 , int cap2)
    {
        eadj[eind]=b;ecap[eind]=cap1;eprev[eind]=elast[a];elast[a]=eind++;
        eadj[eind]=a;ecap[eind]=cap2;eprev[eind]=elast[b];elast[b]=eind++;
    }

    ll dfs( int num , int pcap)
    {
        if(num==sink)
             return pcap;

        if( vis[num]==start)
             return 0;

        vis[num]=start;
        int sum=0;

        for(int i=elast[num];i!=-1;i=eprev[i])
             if( ecap[i]>0)
              {
                    int  p=dfs( eadj[i] , min(pcap , ecap[i] ) );
                    ecap[i]-=p;
                    ecap[i^1]+=p;
                    pcap-=p;
                    sum+=p;

                    if(pcap==0)
                         break;
              }

              return sum;
    }

    int flow( int _source , int _sink)
    {
        if(V==0)
             return -1;

        memset(vis,-1,sizeof(vis));

        source=_source; sink=_sink;

        int total=0,aug;

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

bool perfect( ll in)
{
    double x=sqrt( (double)in );

    ll y=floor(x);

     for(ll d=-10;d<10;d++)
          if( y+d >=0 )
            {
                if( (y+d)*(y+d)==in  )
                    return true;
            }

          return false;
}

class PythTriplets
{
public:

maxflow cal_maxflow;

int findMax(vector <string> _temp)
{


    string temp="";

    for(int i=0;i<sz(_temp);i++)
         temp+=_temp[i];

    vector<ll> in=parse(temp," ");


    int n=sz(in);

    cout<<n<<endl;

    cal_maxflow.init(n+2);

    for(int i=0;i<n;i++)
         for(int j=i+1;j<n;j++)
            if( (in[i]&1)!=(in[j]&1) )
            {
                if(__gcd( in[i] , in[j])!=1 )
                     continue;

                if( perfect( in[i]*in[i] + in[j]*in[j] ) )
                {
                    if( in[i]&1)
                     cal_maxflow.addedge(i,j,1,0);
                    else
                      cal_maxflow.addedge(j,i,1,0);
                }
            }

    //een to sink

    for(int i=0;i<n;i++)
         if( in[i]&1)
              cal_maxflow.addedge(n,i,1,0);
          else
               cal_maxflow.addedge(i,n+1,1,0);

         return cal_maxflow.flow(n,n+1);

}

};


double test0() {
	string t0[] = {"3 4 4 3 11 5 12 9 4"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PythTriplets * obj = new PythTriplets();
	clock_t start = clock();
	int my_answer = obj->findMax(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
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
	string t0[] = {"20 21 3021 220"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PythTriplets * obj = new PythTriplets();
	clock_t start = clock();
	int my_answer = obj->findMax(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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
	string t0[] = {"28 19", "5 1035 21412 37995"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	PythTriplets * obj = new PythTriplets();
	clock_t start = clock();
	int my_answer = obj->findMax(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
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
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
