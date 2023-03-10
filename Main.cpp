#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

typedef pair<int, int> Vpair;

int main(){
    int i = 0, j = 0, x = 0, head = 0, V = 0, E = 0, u = 0, v = 0, w = 0, sol = 0;
    vector<int> id;//for union-find
    vector<int> size;//for union-find weighting
    vector< pair<int, Vpair> > edges;

    cin >> V;
    cin >> E;
    
    for(i = 0; i<E; i++){
        if(scanf("%d %d %d", &u, &v, &w) !=  3) return 1;
        w = -w;
        edges.push_back({w, {u, v}});
    }

    sort(edges.begin(), edges.end());

    /* initialize all disconnected */
    for (i = 0; i <= V; i++) {
        id.push_back(i);
        size.push_back(1);
    }

    vector< pair<int, Vpair> >::iterator it;
    for (it=edges.begin(); it!=edges.end(); it++){
        int u = it->second.first;
        int v = it->second.second;
        //find the head of the groups
        for (i = u; i != id[i]; i = id[i]);
        for (j = v; j != id[j]; j = id[j]);

        if (i != j){
            // Update MST weight
            sol -= it->first;
            //Perform union, pick right direction
            if (size[i] < size[j]) {
                id[i] = j;
                size[j] += size[i];
                head = j;
            }else {
                id[j] = i;
                size[i] += size[j];
                head = i;
            }
            //retrace the path and compress to the top
            for (i = u; i != id[i]; i = x) {
                x = id[i];
                id[i] = head;
            }
            for (j = v; j != id[j]; j = x) {
                x = id[j];
                id[j] = head;
            }
        }
    }

    cout << sol << endl;
    return 0;    
}