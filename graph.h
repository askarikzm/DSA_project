#include<iostream>
using namespace std;
#define INF 1e9
// Node class for queue (modified to keep track of distances)
template <typename T>
class Node {
public:
    T data;
    Node* next;
    double distance;
    string color;

    Node(T data, double distance = INF, string color = "white") {
        this->data = data;
        this->distance = distance;
        this->next = nullptr;
        this->color = color;
    }
};

// Queue class
template <typename T>
class Queue {
    Node<T>* front;
    Node<T>* rear;

public:
    Queue() {
        this->front = nullptr;
        this->rear = nullptr;
    }

    bool isEmpty() {
        return (this->front == nullptr);
    }

    void enqueue(T x, double distance) {
        Node<T>* newNode = new Node<T>(x, distance);
        if (this->rear == nullptr) { // Empty queue
            this->front = this->rear = newNode;
        } else {
            this->rear->next = newNode;
            this->rear = newNode;
        }
    }

    T dequeue() {
        if (this->isEmpty()) {
            cout << "Queue underflow!" << endl;
            return T(); // Return default value of T
        }

        Node<T>* temp = this->front;
        this->front = this->front->next;

        // If front becomes null, set rear to null
        if (this->front == nullptr) {
            this->rear = nullptr;
        }

        T data = temp->data;
        delete temp;
        return data;
    }

    Node<T>* getFront() {
        return this->front;
    }

    void removeNode(T data) {
        Node<T>* temp = this->front;
        Node<T>* prev = nullptr;

        if (temp != nullptr && temp->data == data) {
            this->front = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->data != data) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;

        prev->next = temp->next;
        delete temp;
    }
};

// Edge class for graph representation
template <typename T>
class Edge {
public:
    T destination;
    double weight;
    Edge* next;

    Edge(T destination, double weight = 1.0) : destination(destination), weight(weight), next(nullptr) {}
};

// Linked List class for edges
template <typename T>
class LinkedList {
    Edge<T>* head;
    T name;

public:
    LinkedList() : head(nullptr) {}
    LinkedList(T station_name) : name(station_name), head(nullptr) {}

    void addEdge(T destination, double weight) {
        Edge<T>* newConnection = new Edge<T>(destination, weight);
        if (head == nullptr) {
            head = newConnection;
        } else {
            Edge<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newConnection;
        }
    }

    Edge<T>* getEdges() {
        return head;
    }

    T getName() {
        return name;
    }
};

// Graph structure class
template <typename T>
class GraphStructure {
    int vertices;
    LinkedList<T>* network;

public:
    GraphStructure(int no_vertices, T station_names[]) {
        vertices = no_vertices;
        network = new LinkedList<T>[vertices];
        for (int i = 0; i < vertices; i++) {
            network[i] = LinkedList<T>(station_names[i]);
        }
    }

    ~GraphStructure() {
        delete[] network;
    }

    void addPredefinedConnection(int station_index, T destination, double weight) {
        if (station_index < 0 || station_index >= vertices) {
            cout << "Invalid station number!" << endl;
            return;
        }
        network[station_index].addEdge(destination, weight);
        
        // Adding the reverse edge to make the graph undirected
        int destinationIndex = getStationIndex(destination);
        if (destinationIndex != -1) {
            network[destinationIndex].addEdge(network[station_index].getName(), weight);
        }
    }

    LinkedList<T>& getStationList(int index) {
        return network[index];
    }

    int getVertexCount() {
        return vertices;
    }

    T getStationName(int index) {
        return network[index].getName();
    }

    int getStationIndex(T station) {
        for (int i = 0; i < vertices; i++) {
            if (network[i].getName() == station) {
                return i;
            }
        }
        return -1; // Station not found
    }
};
