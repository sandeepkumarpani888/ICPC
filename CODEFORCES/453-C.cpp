#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//using namespace __gnu_pbds;
using namespace std;

// (づ°ω°)づﾐe★゜・。。・゜゜・。。・゜☆゜・。。・゜゜・。。・゜

#define Foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) > (b); --(i))
#define rep(i, c) for(auto &(i) : (c))
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define PB pop_back()
#define iOS ios_base::sync_with_stdio(false)
#define sqr(a) (((a) * (a)))
#define all(a) a.begin() , a.end()
#define error(x) cerr << #x << " = " << (x) <<endl
#define Error(a,b) cerr<<"( "<<#a<<" , "<<#b<<" ) = ( "<<(a)<<" , "<<(b)<<" )\n";
#define Error3(a,b,c) cerr<<"("<<#a<<" , "<<#b<<" , "<<#c<<" ) = ( "<<(a)<<" , "<<(b)<<" , "<<(c)<<")\n";
#define Error4(a,b,c,d) cerr<<"("<<#a<<" , "<<#b<<" , "<<#c<<" , "<<#d<<" ) = ( "<<(a)<<" , "<<(b)<<" , "<<(c)<<" , "<<(d)<<")\n";
#define Error5(a,b,c,d,e) cerr<<"("<<#a<<" , "<<#b<<" , "<<#c<<" , "<<#d<<" , "<<#e<<" ) = ( "<<(a)<<" , "<<(b)<<" , "<<(c)<<" , "<<(d)<<" , "<<(e)<<")\n";
#define errop(a) cerr<<#a<<" = ( "<<((a).x)<<" , "<<((a).y)<<" )\n";
#define coud(a,b) cout<<fixed << setprecision((b)) << (a)
#define L(x) (((x)<<1)+1)
#define R(x) (((x)<<1)+2)
#define umap unordered_map
//#define double long double
#define mod 1000000007
#define mod1 1000000009
#define LIMIT 10000000000000000LL
#define INF 10000000000LL
#define MAX1 1000000000
const int inf=0x3f3f3f3f;
const long double pi=acos(-1.0);
#define MAX 50010
// #define N 100010
const string debug_line="yolo";
#define debug error(debug_line)
#define read() freopen("mergedoutput.txt","r",stdin)
#define write() freopen("output.txt","w",stdout)
//template <typename T> using os =  tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef pair<int,int>pii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef unsigned long long ull;
typedef complex <long double> complex_t;
const long double PI = acos((long double)-1.0);
const long double eps=1e-6;
ull getRand(){return ((ull)rand()<<40)+((ull)rand()<<20)+((ull)rand());}

vi paths;
bool visited[100010];
vi Adj[100010];
int cntGroups=0;
bool isOdd[100010];

void DFS(int u,int p){
	visited[u]=true;
	paths.pb(u);isOdd[u]^=1;
	rep(t1,Adj[u]){
		if(!visited[t1]){
			DFS(t1,u);
			paths.pb(u);isOdd[u]^=1;
		}
	}

	if(isOdd[u] && p!=-1){
		paths.pb(p);isOdd[p]^=1;
		paths.pb(u);isOdd[u]^=1;
	}
}

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	For(i,0,m){
		int a1,b1;
		scanf("%d%d",&a1,&b1);
		Adj[a1].pb(b1);Adj[b1].pb(a1);
	}
	int start1=-1;

	For(i,1,n+1){
		int temp;
		scanf("%d",&temp);isOdd[i]=temp;
		if(isOdd[i]){
			start1=i;
		}
	}

	if(start1==-1){
		puts("0");return 0;
	}
	else{
		DFS(start1,-1);
		if(isOdd[start1]){
			paths.PB;isOdd[start1]^=1;
		}
		For(i,1,n+1){
			if(isOdd[i]){
				puts("-1");return 0;
			}
		}
		printf("%d\n",(int)paths.size());
		rep(t1,paths){
			printf("%d\n",t1);
		}
		printf("\n");
	}
return 0;}