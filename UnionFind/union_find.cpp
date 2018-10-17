#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long int lli;
///////////////////////// COPY FROM HERE /////////////////////////
int N = 100001;
int arr[100001];
int siz[100001];
// call this in main
void init(){
  for(int i=0;i<N;i++){
    arr[i] = i;
    siz[i] = 1;
  }
}
// returns head of the component to which node belongs
int root(int node){
  if(arr[node]==node){
    return node;
  }
  return arr[node] = root(arr[node]);
}
// merges nodes n1,n2
void Union(int n1,int n2){
  int root1 = root(n1);
  int root2 = root(n2);
  if(root1==root2){
    return;
  }
  if(siz[root1]>siz[root2]){
    siz[root1] += siz[root2];
    arr[root2] = root1;
  }
  else{
    siz[root2] += siz[root1];
    arr[root1] = root2;
  }
}
// returns true if n1,n2 belong to same component
bool find(int n1,int n2){
  int root1 = root(n1);
  int root2 = root(n2);
  if(root1==root2){
    return true;
  }
  return false;
}
///////////////////////// COPY TILL HERE /////////////////////////
int n,m;
int main(){
  ios::sync_with_stdio(false);
  cin >> n >> m;
  init();
  for(int i=0;i<m;i++){
    int u,v;
    cin >> u >> v;
    Union(u,v);
    set<int>roots;
    vector<int>ans;
    for(int j=1;j<=n;j++){
      int x = root(j);
      if(roots.find(x)==roots.end()){
        roots.insert(x);
        ans.push_back(siz[x]);
      }
    }
    sort(ans.begin(),ans.end());
    for(int j=0;j<ans.size();j++){
      cout << ans[j] << " ";
    }
    cout << "\n";
  }
  return 0;
}
