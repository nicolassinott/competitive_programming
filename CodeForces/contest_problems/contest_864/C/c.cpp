#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// int distance(int x1, int y1, int x2, int y2){
//     return max(abs(x2 - x1),abs(y2 - y1));
// }

bool check_possible(pair<int,int>& position, int n, int m){
    return (position.first >= 0) && (position.first <= n) && (position.second >= 0) && (position.second <= m);
}

int main(){
    int t; cin >> t;
    int distance1;
    int distance2;
    int distance3;

    while(t--){
        int n, m;
        scanf("%d %d", &n, &m);

        printf("? 1 1\n");
        cout.flush();

        scanf("%d", &distance1);

        if(!distance1) {
            printf("! 1 1\n");
            cout.flush();
            continue;
        }
        distance1 += 1;

        if(distance1 <= n && distance1 <= m){
            printf("? %d %d\n", distance1, distance1);
            cout.flush();

            scanf("%d", &distance2);

            if(!distance2){
                printf("! %d %d\n", distance1, distance1);
                cout.flush();
                continue;
            }

            pair<int,int> possible1 = {distance1 - distance2, distance1};
            pair<int,int> possible2 = {distance1, distance1 - distance2};

            if(!check_possible(possible1, n, m)){
                printf("! %d %d\n", possible2.first, possible2.second);
                cout.flush();
                continue;
            } else if (!check_possible(possible2, n, m)){
                printf("! %d %d\n", possible1.first, possible1.second);
                cout.flush();
                continue;
            } else {
                printf("? %d %d\n", possible1.first, possible1.second);
                cout.flush();
                scanf("%d", &distance3);

                if(distance3 != 0){
                    printf("! %d %d\n", possible2.first, possible2.second);
                    cout.flush();
                    continue;
                } else {
                    printf("! %d %d\n", possible1.first, possible1.second);
                    cout.flush();
                    continue;
                }
            }
        } else if (distance1 <= n && distance1 > m){
            printf("? %d 1\n", distance1);
            cout.flush();

            scanf("%d", &distance2);
            distance2++;

            printf("! %d %d\n", distance1, distance2);
            cout.flush();
            continue;
        } else {
            printf("? 1 %d\n", distance1);
            cout.flush();

            scanf("%d", &distance2);
            distance2++;

            printf("! %d %d\n", distance2, distance1);
            cout.flush();
            continue;   
        }
    }

    return 0;
}