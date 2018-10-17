// g++ -std=c++14
#include<bits/stdc++.h>
typedef long long int lli;
typedef long double lld;
using namespace std;

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define all(c) c.begin(),c.end()

#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int N,M;
vector<vector<int> >gr;
vector<int>tsort;

vector<int>vis;
bool isCyclic;

void init(int n, int m){
  N = n;
  M = m;
  tsort.clear();
  vis.clear();
  isCyclic = false;
  vis.resize(n+1,0);
}

void dfs_visit(int node){
  vis[node] = 1;
  for(int i=0;i<gr[node].size();i++){
    if(vis[gr[node][i]]==1){
      isCyclic = true;
      return;
    }
    if(vis[gr[node][i]]==0){
      dfs_visit(gr[node][i]);
      if(isCyclic){
        return;
      }
    }
  }
  vis[node] = 2;
  tsort.pb(node);
}

void dfs(){
  isCyclic = false;
  for(int i=N;i>0;i--){
    if(vis[i]==0){
      dfs_visit(i);
      if(isCyclic){
        break;
      }
    }
  }
}

bool topological(){
  dfs();
  if(isCyclic){
    return false;
  }
  reverse(tsort.begin(),tsort.end());
  return true;
}

int main(){
  _
  int n,m;
  cin >> n >> m;
  init(n,m);
  gr.resize(n+1);
  for(int i=0;i<m;i++){
    int x,y;
    cin >> x >> y;
    gr[x].pb(y);
  }
  if(topological()){
    for(int i=0;i<n;i++){
      cout << tsort[i] << " ";
    }
    cout << "\n";
  }
  else{
    cout << "Sandro fails.\n";
  }
  return 0;
}
