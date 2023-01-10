#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

#define X first
#define Y second
int n, m;
int city[51][51];  // �Է¹��� ���� �迭
vector<pair<int,int>> house; // ���� ��ǥ
vector<pair<int,int>> chicken; // ���� ġŲ�� ��ǥ

int main(){
    fastio;

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){ 
            cin >> city[i][j];
            if(city[i][j] == 1) house.push_back({i,j});
            if(city[i][j] == 2) chicken.push_back({i,j});
        }
    }
    
    // ���� �ٸ� ġŲ�� ����(chicken1.size()) �� m���� ��� ��Ƴ���
    vector<int> v;
    for(int i = 0; i < chicken.size(); i++) v.push_back(i < m ? 0 : 1);
    
    int ans = INT_MAX;
    do{
        // ����� �ȵ� ġŲ�� ��ǥ
        vector<pair<int,int>> alive;
        for(int i = 0; i < v.size(); i++)
            if(v[i] == 0)
                alive.push_back({chicken[i].X, chicken[i].Y});
        
        int sum_mn = 0;
        for(auto h : house){
            int dist_mn = 100;
            for(auto a : alive){
                int dist = abs(h.X - a.X) + abs(h.Y - a.Y);
                dist_mn = min(dist_mn, dist);
            }
            sum_mn += dist_mn;
        }
        ans = min(ans, sum_mn);
    }while(next_permutation(v.begin(), v.end()));

    cout << ans << '\n';
}