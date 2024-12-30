#include<iostream>
using namespace std;
#define INF 1e9
template <typename T>
void dijkstra_algo(GraphStructure<T>& graph, T source, T destination) {
    int vertices = graph.getVertexCount();
    double* dist = new double[vertices]; // Distance array
    T* prev = new T[vertices]; // Previous node array for path reconstruction
    Queue<T> q;

    // Initialize distances and previous array
    for (int i = 0; i < vertices; i++) {
        dist[i] = INF;
        prev[i] = T(); // Default value to indicate no predecessor
    }

    // Find the source index and initialize it
    int sourceIndex = graph.getStationIndex(source);
    if (sourceIndex == -1) {
        cout << "Source station not found!" << endl;
        delete[] dist;
        delete[] prev;
        return;
    }
    dist[sourceIndex] = 0; // Distance to the source is 0
    q.enqueue(source, 0);  // Enqueue source with 0 distance

    // Dijkstra's algorithm loop
    while (!q.isEmpty()) {
        T current = q.dequeue();  // Dequeue the node with the smallest distance
        int currentIndex = graph.getStationIndex(current);

        // Explore neighbors of the current node
        LinkedList<T>& neighbors = graph.getStationList(currentIndex);
        Edge<T>* edges = neighbors.getEdges();

        while (edges != nullptr) {
            T neighbor = edges->destination;
            int neighborIndex = graph.getStationIndex(neighbor);
            double newDist = dist[currentIndex] + edges->weight;

            if (newDist < dist[neighborIndex]) {
                dist[neighborIndex] = newDist; // Update distance
                prev[neighborIndex] = current; // Update predecessor
                q.enqueue(neighbor, newDist);  // Enqueue the neighbor
            }
            edges = edges->next; // Move to the next neighbor
        }
    }

    // Find the destination index
    int destIndex = graph.getStationIndex(destination);
    if (destIndex == -1) {
        cout << "Destination station not found!" << endl;
        delete[] dist;
        delete[] prev;
        return;
    }

    // Print the shortest distance to the destination
    cout << "Shortest distance from " << source << " to " << destination << ": " << dist[destIndex] << endl;

    // Reconstruct the path
    cout << "Path: ";
    T current = destination;
    vector<T> path;
    while (current != T()) {
        path.push_back(current);
        current = prev[graph.getStationIndex(current)];
    }
    reverse(path.begin(), path.end());
    // Print the reconstructed path with green color
    for (size_t i = 0; i < path.size(); i++) {
        cout << "\033[32m" << path[i] << "\033[0m"; // \033[32m sets the text color to green, \033[0m resets it
        if (i < path.size() - 1) cout << " -> ";
    }
    cout << endl;

    
    delete[] dist;
    delete[] prev;
}
