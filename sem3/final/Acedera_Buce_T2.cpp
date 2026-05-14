#include <iostream>
#include <queue>
using namespace std;

int map[24][24] = {
    {0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,1,0,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0},
    {0,0,1,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
    {0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,0,0},
    {0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1,0,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,0,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0}
};
/*
adjacency:
0-d.spawn = {b.hall, a.tower}
1-b.hall = {b.elbow, b.site}
2-a.tower = {d.spawn, a.site}
3-b.elbow = {b.hall, b.site, b.garden}
4-b.site = {b.hall, b.elbow, b.garden, b.wind}
5-a.lamps = {a.site, a.tp, a.cubby}
6-a.site = {a.tower, a.lamps, a.bath, a.tp, a.cubby}
7-b.tp = {a.exit}
8-b.garden = {b.elbow, b.site, b.long}
9-b.wind = {b.site, b.short}
10-a.bath = {a.site, a. lobby}
11-b.exit = {b.short}
12-a.tp = {b.exit}
13-b.long = {b.tp, b.garden, b.fountain}
14-b.short = {b.wind, b.fountain, a.link, b.link}
15-a.cubby = {a.lamps, a.site, a.tp, a.short}
16-a.exit = {a.bath}
17-b.fountain = {b.long, b.short, a.link}
18-a.link = {b.fountain, b.link, a.side_cave}
19-b.link = {a.link, a.short, a.side_cave}
20-a.short = {a.cubby, b.link, a.lobby}
21-a.lobby = {a.bath, a.short, a.side_cave}
22-a.side_cave = {b.fountain, a.link, b.link, a.lobby, a.spawn}
23-a.spawn = {a.side_cave}
*/
string map_name[24] = {"D_Spawn", "B_Hall", "A_Tower", "B_Elbow", "B_Site", "A_Lamps", "A_Site", "B_tp", "B_Garden", "B_Wind", "A_Bath",
"B_Exit", "A_tp","B_Long", "B_Short", "A_Cubby", "A_Exit", "B_Fountain", "A_Link", "B_Link", "A_Short", "A_Lobby","A_Side_Cave", "A_Spawn"};

//converts string to int to get the respective map_name
int startInt(string start){
    for (int i = 0; i < 24; i++){
        if (map_name[i] == start)
        return i;
    }
    return -1;
}
int endInt(string end){
    for (int i = 0; i < 24; i++){
        if (map_name[i] == end)
        return i;
    }
    return -1;
}

//bfs type shit
void find_parent(int current, string map_name[], int parent[]) {
    if (parent[current] == -1) {
        cout << map_name[current];
        return;
    }
    find_parent(parent[current], map_name, parent);
    cout << " -> " << map_name[current];
}

void traverse(int sPoint, int ePoint) {
    bool isVisited[24] = {false};
    int parent[24];
    for (int i = 0; i < 24; i++) parent[i] = -1;
    queue<int> q;
    isVisited[sPoint] = true;
    q.push(sPoint);
    int current;
    while (!q.empty()) {
        current = q.front();
        q.pop();
        if (current == ePoint) break;
        for (int i = 0; i < 24; i++) {
            if (map[current][i] == 1 && !isVisited[i]) {
                isVisited[i] = true;
                parent[i] = current;
                q.push(i);
            }
        }
    }

    if (current == ePoint) {
        cout << "Start to end is reachable." << endl;
        cout << "Path from " << map_name[sPoint] << " to " << map_name[ePoint] << " is:\n";
        find_parent(current, map_name, parent);
        cout << endl;
    } else {
        cout << "Start to end is not reachable." << endl;
    }
}

int main() {
    string start_name, end_name;
    char menu;
    cout << "{D_Spawn, B_Hall, A_Tower, B_Elbow, B_Site, A_Lamps, A_Site, B_tp, B_Garden, B_Wind, A_Bath, B_Exit, A_tp, B_Long, B_Short, A_Cubby, A_Exit, B_Fountain, A_Link, B_Link, A_Short, A_Lobby,A_Side_Cave, A_Spawn}\n";
    cout << "Start: ";
    cin >> start_name;
    cout << "End: ";
    cin >> end_name;
    
    //converts string to int to be passed in traverse()
    int start = startInt(start_name);
    int end = endInt(end_name);
    if (start == -1 || end == -1){
    cout << "Invalid Input";    
    }
    else
    traverse(start, end);
    return 0;
}

