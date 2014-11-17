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

struct point
{
    int x,y,z;
    point(int a, int b , int c)
    {
        x=a;
        y=b;
        z=c;
    }

    point()
    {

    }
};

bool adja( point a, point b)
{
    int x=0;

     x+=abs( a.x -b.x);
     x+=abs( a.y -b.y);
     x+=abs( a.z -b.z);

     return (x <=1);//may be same
}


class ShadowSculpture
{
public:

bool cool[11][11][11];
bool done[11][11][11];
int n;

vector< point> all[1005];
int curr;

bool valid( int x )
{
    return ( (0<=x) && (x <n));
}

void dfs( int x, int y , int z )
{
    if( done[x][y][z])
         return ;

    done[x][y][z] = true;

    all[ curr ].pb( point(x,y,z) );

    for(int dx=-1;dx<=1;dx++)
        for(int dy =-1; dy <=1 ; dy++)
          for(int dz= -1 ; dz <=1 ; dz++)
            {
                int nx=x+dx;
                int ny=y+dy;
                int nz=z+dz;

                if( valid(nx) && valid(ny) && valid(nz) )
                    if( cool[nx][ny][nz] )
                        if( adja( point(nx,ny,nz) , point(x,y,z) ) )
                        {
                            dfs(nx,ny,nz);
                        }
            }
}//edn dfs

string possible(vector <string> XY, vector <string> YZ, vector <string> ZX)
{
     n=sz(XY);

     print(n);

    int cont=0;

    // init all as true
    fill(cool,true);

    print(cool[1][2][3]);

    int Y_cont=0;


    //build for XY
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          if( XY[i][j]=='N')
            {
                for(int k=0;k<n;k++)
                    cool[i][j][k]=false;
            }
           else
           {
               Y_cont++;
           }

     //build for YZ
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          if( YZ[i][j]=='N')
           {
                for(int k=0;k<n;k++)
                    cool[k][i][j]=false;
            }
          else
           {
               Y_cont++;
           }

    //build for ZX

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          if( ZX[i][j]=='N')
           {
                for(int k=0;k<n;k++)
                    cool[j][k][i]=false;
            }
           else
           {
               Y_cont++;
           }

       // if no Y is there , return true;

       if( Y_cont==0)
       {
           return "Possible";
       }

     //start dfs

     fill(done,0);

     curr=0;

     for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
         for(int k=0;k<n;k++)
           if( cool[i][j][k])
             if( !done[i][j][k])
                {
                    dfs(i,j,k);

                   // cout<<curr<<"  "<<sz( all[curr] )<<"  "<<all[curr][0].x<<"  "<<all[curr][0].y<<"  "<<all[curr][0].z<<endl;

                     curr++;
                }

      // Now for all compnet check if we can get a similar congfiuaration

     bool  taken[11][11][11];

      for(int cp=0;cp<curr;cp++)
      {
            fill(taken,0);

          for(int i=0;i<sz( all[cp] ) ;i++ )
          {
              taken[ all[cp][i].x ][ all[cp][i].y ] [ all[cp][i].z ]=true;
          }

          bool ans=true;


          //for any Y  , if not Y in this list , just break the answer

                       //build for XY
                for(int i=0;i<n;i++)
                    for(int j=0;j<n;j++)
                      if( XY[i][j]=='Y')
                        {
                            bool mila=false;

                            for(int k=0;k<n;k++)
                                if( taken[i][j][k])
                                   mila=true;

                            //    cool[i][j][k]=false;

                            if( !mila)
                                   ans=false;
                        }

                 //build for YZ
                for(int i=0;i<n;i++)
                    for(int j=0;j<n;j++)
                      if( YZ[i][j]=='Y')
                       {
                           bool mila=false;

                            for(int k=0;k<n;k++)
                                 if( taken[k][i][j])
                                     mila=true;

                            if( !mila)
                                   ans=false;
                        }

                //build for ZX

                for(int i=0;i<n;i++)
                    for(int j=0;j<n;j++)
                      if( ZX[i][j]=='Y')
                       {
                            bool mila=false;

                            for(int k=0;k<n;k++)
                                 if( taken[j][k][i])
                                    mila=true;

                                //cool[j][k][i]=false;

                                if( !mila)
                                    ans=false;
                       }


                  if( ans )
                     return "Possible";
      }


     return "Impossible";
}

};


double test0() {
	string t0[] = {"YN","NN"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"YN","NN"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"YN","NN"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ShadowSculpture * obj = new ShadowSculpture();
	clock_t start = clock();
	string my_answer = obj->possible(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Possible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"YN","NY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"YN","NY"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"YN","NY"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ShadowSculpture * obj = new ShadowSculpture();
	clock_t start = clock();
	string my_answer = obj->possible(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Impossible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"YYY","YNY","YYY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"YYY","YNY","YYY"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"YYY","YNY","YYY"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ShadowSculpture * obj = new ShadowSculpture();
	clock_t start = clock();
	string my_answer = obj->possible(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Possible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"YYY","YNY","YYY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"NYY","YNY","YYY"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"YYY","YNY","YYN"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ShadowSculpture * obj = new ShadowSculpture();
	clock_t start = clock();
	string my_answer = obj->possible(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Impossible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] = {"N"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"N"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"N"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ShadowSculpture * obj = new ShadowSculpture();
	clock_t start = clock();
	string my_answer = obj->possible(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Possible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

/*

,
,


*/

double test5() {
	string t0[] = {"YYYYYYYY", "YYYYYYYY", "YYYYYYYY", "YYYYYYYY", "YYYYYYYY", "YYYYYYYY", "YYYYYYYY", "YYYYYYYY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"YYYYYYYY", "YYYYYYYY", "YYYYYYYY", "YYYYYYYY", "YYYYYYYY", "YYYYYYYY", "YYYYYYYY", "YYYYYYYY"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] =  {"YYYYYYYY", "YYYYYYYY", "YYYYYYYY", "YYYYYYYY", "YYYYYYYY", "YYYYYYYY", "YYYYYYYY", "YYYYYYYY"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ShadowSculpture * obj = new ShadowSculpture();
	clock_t start = clock();
	string my_answer = obj->possible(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Possible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

double test6() {
	string t0[] = {"YNY","YYY","YYY"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	string t1[] = {"YNY","YYY","YYY"};
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	string t2[] = {"YNY","YYY","YYY"};
	vector <string> p2(t2, t2+sizeof(t2)/sizeof(string));
	ShadowSculpture * obj = new ShadowSculpture();
	clock_t start = clock();
	string my_answer = obj->possible(p0, p1, p2);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p3 = "Possible";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p3 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p3 != my_answer) {
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
