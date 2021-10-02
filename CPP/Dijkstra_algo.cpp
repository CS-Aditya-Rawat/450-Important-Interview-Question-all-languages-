//Q367)Dijkstra algo

#include<bits/stdc++.h>
using namespace std;

int findMinVertex(bool *visited,int *distances,int v)
{
    int minVertex=-1;
    for(int i=0;i<v;i++)
    {
        if(!visited[i] && (minVertex==-1 || distances[i] < distances[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstras(int **edges,int v)
{
    bool *visited = new bool[v];
    int *distances = new int[v];
    for (int i = 0; i < v; i++)
    {
        visited[i]=false;
        distances[i]=INT_MAX;
    }
    distances[0]=0;
    for(int i=0;i<v;i++)
    {
        int minDistanceVertex = findMinVertex(visited,distances,v);
        visited[minDistanceVertex]=true;
        for(int j=0;j<v;j++)
        {
            if(edges[minDistanceVertex][j]!=0 && !visited[j])
            {
                int dist = edges[minDistanceVertex][j]+distances[minDistanceVertex];
                if(dist<distances[j])
                {
                    distances[j]=dist;
                }
            }
        }
    }

    for(int i=0;i<v;i++)
    {
        cout<<i<<" "<<distances[i]<<endl;
    }
}

int main()
{
    int v,e;
    cin>>v>>e;
    int **edges = new int*[v];
    for(int i=0;i<v;i++)
    {
        edges[i] = new int[v];
        for(int j=0;j<v;j++)
        {
            edges[i][j] = 0;
        }
    }

    for(int i=0;i<e;i++)
    {
        int f,s,distance;
        cin>>f>>s>>distance;
        edges[f][s]=distance;
        edges[s][f]=distance;
    }

    dijkstras(edges,v);

    for(int i=0;i<v;i++)
    {
        delete []edges[i];
    }
    delete []edges;
}
