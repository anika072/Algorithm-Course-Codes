#include <bits/stdc++.h>
#include<iostream>
using namespace std;
struct Edge {
   int src, dest, weight;
};
struct Graph {
   int V, E;
   struct Edge* edge;
};
struct Graph* createGraph(int V, int E) {
   struct Graph* graph = new Graph;
   graph->V = V;
   graph->E = E;
   graph->edge = new Edge[E];
   return graph;
}
void BellmanFord(struct Graph* graph, int src) {
   int V = graph->V;
   int E = graph->E;
   int dist[V];
   for (int i = 0; i < V; i++)
      dist[i] = INT_MAX;
      dist[src] = 0;
   for (int i = 1; i <= V - 1; i++) {
      for (int j = 0; j < E; j++) {
         int u = graph->edge[j].src;
         int v = graph->edge[j].dest;
         int weight = graph->edge[j].weight;
         if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
         dist[v] = dist[u] + weight;
      }
   }
   for (int i = 0; i < E; i++) {
      int u = graph->edge[i].src;
      int v = graph->edge[i].dest;
      int weight = graph->edge[i].weight;
      if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
         printf("Graph contains negative weight cycle");
         return;
      }
   }
   printf("Vertex :\t\t\t ");
   for (int i = 0; i < V; ++i)
      printf("%d \t", i);
      printf("\nDistance From Source : ");
   for (int i = 0; i < V; ++i)
      printf("%d \t",dist[i]);
   return;
}
int main() {
   int V,E;
   cout<<"Enter number of vertices:";
   cin>>V;
   cout<<"Enter number of edges:";
   cin>>E;
   struct Graph* graph = createGraph(V, E);
   for(int i=0;i<E;i++){
       cin>>graph->edge[i].weight;
       cin>>graph->edge[i].src;
       cin>>graph->edge[i].dest;
   }
   BellmanFord(graph, 0);
   return 0;
}
