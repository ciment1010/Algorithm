#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int n, mn = 0x7f7f7f7f;
int grade[22][22];

int main(){
    fastio;

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> grade[i][j];
    vector<int> team(n);
    fill(team.begin() + n/2, team.end(), 1);
    
    do{
        int diff = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(team[i] != team[j]) continue;
                if(team[i] == 0) diff += (grade[i][j] + grade[j][i]);
                else diff -= (grade[i][j] + grade[j][i]);
            }
        }
        mn = min(mn, abs(diff));
    }while(next_permutation(team.begin(), team.end()));
    cout << mn << '\n';
}