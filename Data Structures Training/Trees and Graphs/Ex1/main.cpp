#include <iostream>
#include <fstream>
#include <stdio.h>
#include <queue>
#include <list>
#include <cstring>

using namespace std;

template<typename TnodeInfo, typename TedgeInfo>
class Graph {

    public:
        int N;                      /// number of nodes
        char **A;                   /// matrix
        TnodeInfo *nodeInfo;        /// info of the node

        Graph(int numNodes) {
            int i, j;

            N = numNodes;

            // allocate the adjacency matrix
            A = new char*[N];
            for (i = 0; i < N; i++)
                A[i] = new char[N];

			for (i = 0; i < N; i++)
                for (j = 0; j < N; j++)
                    A[i][j] = 0;

            // allocate the array with node information
            nodeInfo = new TnodeInfo[N];
        }

        ~Graph() {
            int i;
            for (i = 0; i < N; i++) {
                delete A[i];
            }
            delete A;
            delete [] nodeInfo;
        }

        void setNodeInfo(int i, TnodeInfo info) {
            nodeInfo[i] = info;
        }

        TnodeInfo getNodeInfo(int i) {
            return nodeInfo[i];
        }

        void addEdge(int i, int j) {
            A[i][j] = 1;
        }
        void removeEdge(int i, int j) {
            A[i][j] = A[j][i] = 0;
            }
};


    Graph<char, int> g(10);
    char* visited;

    void dfs(int x) {
        int y;
        printf("%d\n", x);
        visited[x] = 1;

        for (y = 0; y < g.N; y++)
            if (g.A[x][y] && !visited[y])
                dfs(y);
}
/*
    void bfs(int S) {
        std::queue<int> Q;
        int x, y;

        Q.push(S);
        visited[S] = 1;

        while (!Q.empty()) {
            x = Q.front();
            Q.pop();
            printf("%d\n", x);
            for (y = 0; y < g.N; y++)
                if (g.A[x][y] && !visited[y]) {
                    visited[y] = 1;
                    Q.push(y);
                }
           }
    }
*/

    void password(char cuv[7]){

            int i, n, lit, x, ok, path[7], z = -1, k;
            n = strlen(cuv);
            char s[n+1];

            x = -1;

            for(i = 0; i < g.N; ++i)
                if(g.getNodeInfo(i) == cuv[0]){
                   x = i;
                   s[0] = cuv[0];       ///copiez in s literele gasiteca vecini ca sa verific la final;
                   path[++z] = x;
                   break;             ///tine minte path ul
                }

            if(x == -1){
                cout << "no ";
                return;
            }

            else{

                ok = 1;
                k = 0;
                lit = 0;

                while(lit < n){
                    lit++;
                    ok = 1;
                    for(i = 0; i < 10 && ok == 1; ++i)
                        if(g.A[x][i] == 1){         ///daca exista muchie
                            if(g.getNodeInfo(i) == cuv[lit]){
                                x = i;
                                s[++k] = cuv[lit];
                                path[++z] = i;
                                ok = 0;
                            }
                        }
                }
            }

            if(strncmp(s,cuv,strlen(cuv)) != 0){
                cout << "no ";
            }
            else{
                 cout << "yes, path: ";
                for(i = 0; i < z; i++)
                    cout << path[i] << " ";
            }


    }

    int complet_check(){

        int i, j;
        for(i = 0; i < g.N; ++i)
            for(j = 0; j < g.N; ++j)
                if(g.A[i][j] != 1 && i != j)
                    return 0;  ///it is not complete
        return 1;
    }

    void kinda_lista_prieteni(int prieteni[10]){

        int i, j;
        for(i = 0; i < g.N; ++i){
            for(j = 0; j < g.N; ++j)
                if(g.A[i][j] == 1){
                    prieteni[i] +=1;
                }
        }
    }

    void demonstration(int prieteni[10]){

        int i, j, nr_min, nr_maxim;
        nr_maxim = 0;
        nr_min = 11;

        for(i = 0; i < 10; ++i)
            for(j = 0; j < i; ++j){
                if(nr_maxim <= prieteni[i])
                    nr_maxim = prieteni[i];
                if(nr_min >= prieteni[i])
                    nr_min = prieteni[i];
            }

        if(complet_check() == 1)
                cout << "You need " << g.N << " colors \n";
            else
                if(nr_min == nr_maxim)
                        cout << "You need " << nr_maxim << " colors, so I, the monkey, am right :) \n";
                    else
                            cout << "You need " << nr_maxim - nr_min << " colors \n";
    }



int main()
{
    int i, j, k, r, *deg;
    char z;

    ifstream f("date.txt");

///a)

    for(k = 0; k < 10; ++k){
        ///first we read and set the letters for each node
        f >> z;
        g.setNodeInfo(k, z);
    }

    for(r = 0; r < 11; r++){
        ///for each line in the file
        for(k = 0; k < 7; k+=2){
            ///we add 3 edges => the matrix
            f >> i;
            f >> j;
            g.addEdge(i, j);
        }
    }

    f.close();

    visited = new char[g.N];
    deg = new int[g.N];

    for (i = 0; i < g.N; ++i)
    {
        visited[i] = 0;
        deg[i] = 0;
    }

    //dfs(1);
    cout << endl;

    ///b)

    cout << "B) Find the possible password out of: \n";

    char t[7] = "PIRATE";
    cout << "The word PIRATE: ";
    password(t);
    cout << endl;

    strcpy(t, "ARRGH");
    cout << "The word ARRGH: ";
    password(t);
    cout << endl;

    strcpy(t, "ARGH");
    cout << "The word ARGH: ";
    password(t);
    cout << endl;

    strcpy(t, "RUG");
    cout << "The word RUG: ";
    password(t);
    cout << endl;

    strcpy(t, "UGH");
    cout << "The word UGH: ";
    password(t);
    cout << endl;

    strcpy(t, "RUM");
    cout << "The word RUM: ";
    password(t);
    cout << endl << endl;

    ///c)

    cout << "C) Now Jack is told: \n";

    int prieteni[10];
    /// It represents the number of friends of each i node

     for (i = 0; i < g.N; ++i)
        prieteni[i] = 0;

    kinda_lista_prieteni(prieteni);

    demonstration(prieteni);


    return 0;
}
