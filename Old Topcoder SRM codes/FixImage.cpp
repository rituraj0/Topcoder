#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
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

#define print(a) cout<<(#a)<<" = "<<a<<"  ";
#define println(a) cout<<(#a)<<" = "<<a<<"\n";
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


class FixImage
{
public:

    int row,col;
    int done[55][55];
    int xmi[55],xma[55],ymi[55],yma[55];

    vector<string> img;

    void dfs(int x, int y)
    {
        if( x<0 || x>=row || y<0 || y>=col)
             return ;

        if( done[x][y] || img[x][y]=='.')
             return;

        done[x][y]=true;

        xmi[x]=min( xmi[x] , y);
        xma[x]=max( xma[x] , y);

        ymi[y]=min( ymi[y],x);
        yma[y]=max( yma[y],x);

        dfs(x-1,y); dfs(x+1,y);
        dfs(x,y-1); dfs(x,y+1);
    }


vector <string> originalImage(vector <string> alteredImage)
{
    img=alteredImage;
    row=img.sz,col=img[0].sz;

    bool rem=true;



    while(rem)
    {
         rem=0;

         fill(done,0);

         for(int i=0;i<row;i++)
             for(int j=0;j<col;j++)
                if( (!done[i][j]) && (img[i][j]=='#') )
                {
                    fill(xmi,63); fill(xma,-1);
                    fill(ymi,63);fill(yma,-1);

                    dfs(i,j);

//                    cout<<i<<" "<<j<<endl;
//
//                    cout<<"\nxmin\n";
//                    for(int k=0;k<row;k++)
//                         cout<<xmi[k]<<"  ";
//                    cout<<"\nxmax\n";
//                    for(int k=0;k<row;k++)
//                         cout<<xma[k]<<"  ";
//
//                    cout<<"\nymin\n";
//                    for(int k=0;k<col;k++)
//                         cout<<ymi[k]<<" ";
//                    cout<<"\nYmax\n";
//                     for(int k=0;k<col;k++)
//                         cout<<yma[k]<<"  ";
//                     cout<<"\n\n";

                    for(int x=0;x<row;x++)
                          for(int y=xmi[x];y<=xma[x];y++)
                    {
                          if( img[x][y]=='.')
                             rem=true;

                           done[x][y]=true;
                           img[x][y]='#';
                    }

                   for(int y=0;y<col;y++ )
                       for(int x=ymi[y];x<=yma[y];x++)
                   {
                         if( img[x][y]=='.')
                             rem=true;

                           done[x][y]=true;
                           img[x][y]='#';

                   }
         }
    }

    return img;

}

};




double test0() {
	string t0[] = {"....",
 ".##.",
 ".##.",
 "...."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FixImage * obj = new FixImage();
	clock_t start = clock();
	vector <string> my_answer = obj->originalImage(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {"....", ".##.", ".##.", "...." };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<"\""<<p1[0]<<"\"";
		for (int i=1; i<p1.size(); i++)
			cout <<", \"" <<p1[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {".....",
 ".###.",
 ".#.#.",
 ".###.",
 "....."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FixImage * obj = new FixImage();
	clock_t start = clock();
	vector <string> my_answer = obj->originalImage(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {".....", ".###.", ".###.", ".###.", "....." };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<"\""<<p1[0]<<"\"";
		for (int i=1; i<p1.size(); i++)
			cout <<", \"" <<p1[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {".......",
 ".###...",
 ".#..##.",
 ".###.#.",
 ".....#."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FixImage * obj = new FixImage();
	clock_t start = clock();
	vector <string> my_answer = obj->originalImage(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {".......", ".###...", ".#####.", ".#####.", ".....#." };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<"\""<<p1[0]<<"\"";
		for (int i=1; i<p1.size(); i++)
			cout <<", \"" <<p1[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] =  {".................",
 "#####.#..#..#####",
 "..#...#..#....#..",
 "..#...#..###..#..",
 "................."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FixImage * obj = new FixImage();
	clock_t start = clock();
	vector <string> my_answer = obj->originalImage(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {".................", "#####.#..#..#####", "..#...#..#....#..", "..#...#..###..#..", "................." };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<"\""<<p1[0]<<"\"";
		for (int i=1; i<p1.size(); i++)
			cout <<", \"" <<p1[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	string t0[] =  {"###.####",
  "#.#.#..#",
  ".#...#.#",
  ".#####.#",
  "......#.",
  "########"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FixImage * obj = new FixImage();
	clock_t start = clock();
	vector <string> my_answer = obj->originalImage(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {"########", "########", "########", "########", "########", "########" };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<"\""<<p1[0]<<"\"";
		for (int i=1; i<p1.size(); i++)
			cout <<", \"" <<p1[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	string t0[] = {"..###..",
 "..#.#..",
 "##...##",
 "#.....#",
 "#.....#",
 "#.....#",
 "##...##",
 "..#.#..",
 "..###.."};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	FixImage * obj = new FixImage();
	clock_t start = clock();
	vector <string> my_answer = obj->originalImage(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string t1[] = {"..###..", "..###..", "##...##", "##...##", "##...##", "##...##", "##...##", "..###..", "..###.." };
	vector <string> p1(t1, t1+sizeof(t1)/sizeof(string));
	cout <<"Desired answer: " <<endl;
	cout <<"\t{ ";
	if (p1.size() > 0) {
		cout <<"\""<<p1[0]<<"\"";
		for (int i=1; i<p1.size(); i++)
			cout <<", \"" <<p1[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	cout <<endl <<"Your answer: " <<endl;
	cout <<"\t{ ";
	if (my_answer.size() > 0) {
		cout <<"\""<<my_answer[0]<<"\"";
		for (int i=1; i<my_answer.size(); i++)
			cout <<", \"" <<my_answer[i]<<"\"";
		cout <<" }" <<endl;
	}
	else
		cout <<"}" <<endl;
	if (my_answer != p1) {
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
