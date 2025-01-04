#include <bits/stdc++.h>
using namespace std;

int graph[100][100];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> graph[i][j];
        }
    }

   for(int k = 0; k<n; k++){
       for(int j = 0; j<n; j++){
           for(int i = 0; i<n; i++){
               if(graph[i][k] && graph[k][j]){
                   graph[i][j] = 1;
               }
           }
       }
   }

   for(int i = 0; i<n; i++){
       for(int j = 0; j < n; j++){
           cout << graph[i][j] << " ";
       }
       cout << "\n";
   }
}
