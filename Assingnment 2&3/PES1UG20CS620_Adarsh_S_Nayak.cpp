#include<bits/stdc++.h>
using namespace std;

#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                (a/gcd(a,b))*b
const int MAX_N = 1e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;
#define pb(x)                   push_back(x)
#define M 6
#define N 6

bool bipartiteGraph[M][N] =
{    
   {0, 1, 1, 1, 0, 1},
   {1, 0, 1, 0, 1, 0},
   {1, 0, 1, 1, 0, 1},
   {1, 0, 1, 0, 1, 0},
   {0, 0, 1, 1, 1, 0},
   {1, 1, 1, 0, 0, 1}
};

bool bipartiteMatch(int u, bool visited[], int assign[]) {
   for (int v = 0; v < N; v++) {    
      if (bipartiteGraph[u][v] && !visited[v]) {    
         visited[v] = true;    
         if (assign[v] < 0 || bipartiteMatch(assign[v], visited, assign)) {
            assign[v] = u;    
            return true;
         }
      }
   }
   return false;
}

void solve() {
   int assign[N];    
   for(int i = 0; i<N; i++)
      assign[i] = -1;    
   int jobCount = 0;

   for (int u = 0; u < M; u++) {    
      bool visited[N];
      for(int i = 0; i<N; i++)
         visited[i] = false;    
      if (bipartiteMatch(u, visited, assign))    
         jobCount++;
   }
   for(int i=0;i<N;i++)
   {
       if(assign[i]==-1)
       {
           cout<<"The course number "<<i<< " has not been assigned to any faculty"<<endl;
       }
       else
       {
            cout<<"The course number "<< i << " has been assigned to faculty "<<assign[i]<<endl;
       }
   }
  
}

int main() {
   // ios::sync_with_stdio(false);
   // cin.tie(NULL);
   // cout.tie(NULL);
   // int tc = 1;
   // cin >> tc;
   // for (int t = 1; t <= tc; t++) {
   // cout << "Case #" << t << ": ";
      solve();
   // }
   
}




