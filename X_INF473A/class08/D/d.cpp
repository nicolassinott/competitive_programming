#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class Bola {
    public:
        double x, y, r;
        bool touches_left = 0;
        bool touches_right = 0;

        Bola(double nx, double ny, double nr){
            r=nr; x=nx; y=ny;
            if(x-r <= 0) touches_left = 1;
            if(x+r >= 200) touches_right = 1;
        }

        double get_distance(Bola bol){
            return sqrt((x-bol.x)*(x-bol.x) + ((y-bol.y) * (y-bol.y)));
        }

        bool has_intersection(Bola bol){
            return get_distance(bol) < r + bol.r;
        }
};

class UnionFind{
    public:
        int n;
        vector<int> parents;
        vector<int> sizes;

        UnionFind(int nx){
            n = nx;
            parents.resize(n+2);
            sizes.resize(n+2);

            for(int i = 0; i < n+2; i++){
                parents[i] = i;
                sizes[i] = 1;
            }
        }

        int find_parent(int u){
            if(parents[u] == u) return u;
            else {
                int final_parent = find_parent(parents[u]);
                parents[u] = final_parent;
                return final_parent;
            }
        }

        void merge(int u, int v){
            if(sizes[u] > sizes[v]) swap(u,v);
            
            int parent_u = find_parent(u);
            int parent_v = find_parent(v);

            if(parent_u == parent_v) return;
            
            parents[parent_u] = parent_v;
            
            if(sizes[u] == sizes[v]) sizes[v]++; 
        }

        bool have_merged(){
            int parent_left = find_parent(n);
            int parent_right = find_parent(n+1);
            return parent_left == parent_right;
        }
};

int main(){
    int n; cin >> n;

    UnionFind uf(n);
    int found_max = -1;

    vector<Bola> bolas;

    for(int i = 0; i < n; i++){
        int x, y, r; cin >> x >> y >> r;
        if(found_max != -1) continue; 

        Bola bol(x,y,r);
        bolas.push_back(bol);

        if(bol.touches_left) uf.merge(i,n);
        if(bol.touches_right) uf.merge(i,n+1);

        for(int j = 0; j < i; j++){
            if(bol.has_intersection(bolas[j])) uf.merge(i,j);
        }

        if(uf.have_merged()) found_max = i;

    }

    cout << found_max << endl;

    return 0;
}