## Time Complexity Analysis for Metro Bus Simulation Project

This document provides a detailed time complexity analysis of the functions used in your metro bus simulation project. Understanding the time complexity helps in optimizing the performance and ensuring the scalability of the application.

---

### **Utility Functions**
These functions are used for basic string manipulations.

#### `toLowerCase(string str)` and `toUpperCase(string str)`
- **Time Complexity**: \(O(n)\)
    - \(n\) is the length of the string.
    - Each character in the string is converted individually, resulting in a linear time complexity.

---

### **Authentication Functions**
These functions handle user authentication, including sign-up and sign-in processes.

#### `signUp()`
- **Time Complexity**: \(O(n)\)
    - Writing the username and password to the file is \(O(n)\), where \(n\) is the length of the username and password combined.
    - This involves file I/O operations which are linear with respect to the input size.

#### `signIn()`
- **Time Complexity**: \(O(m \times k)\)
    - \(m\): Number of entries in the `log.txt` file.
    - \(k\): Average length of a username-password entry.
    - The function reads all entries line by line to check credentials, resulting in a linear scan of the file.

---

### **Graph and Pathfinding Functions**
These functions are crucial for simulating the metro bus routes and finding the shortest paths.

#### `askForSourceAndDestination(string &source, string &destination, GraphStructure<string> &graph)`
- **Time Complexity**: \(O(V + E \log V)\)
    - This function calls `dijkstra_algo`, which has the same complexity.
    - \(V\): Number of vertices (stations).
    - \(E\): Number of edges (connections between stations).

#### `dijkstra_algo(GraphStructure<T> &graph, T source, T destination)`
- **Time Complexity**: \(O(V + E \log V)\)
    - Uses Dijkstra's algorithm to find the shortest path.
    - Utilizes a priority queue for the smallest distance selection, which takes \(\log V\) time per operation.

#### `metroRoutes()`
- **Time Complexity**: \(O(E)\)
    - \(E\): Number of predefined connections added.
    - Each call to `addPredefinedConnection` is \(O(1)\), making the overall complexity linear with respect to the number of edges.

---

### **Display Functions**
These functions handle the display of text and designs in the console.

#### `centerText(const string& text, int width)`
- **Time Complexity**: \(O(n)\)
    - \(n\): Length of the string.
    - Computes padding and appends spaces to center the text.

#### `displayMetroBusDesign()`
- **Time Complexity**: \(O(n)\)
    - \(n\): Total number of characters in the displayed design.
    - Involves iterating through the design characters.

---

### **GraphStructure Functions**
These functions manage the graph structure representing the metro bus network.

#### `addPredefinedConnection(int station_index, T destination, double weight)`
- **Time Complexity**: \(O(1)\)
    - Adds edges directly to the adjacency list, making it a constant time operation.

---

### **Queue Operations**
These functions manage queue operations for various purposes in the simulation.

#### `enqueue(T x, double distance)`
- **Time Complexity**: \(O(1)\)
    - Adds a new node to the end of the queue, which is a constant time operation.

#### `dequeue()`
- **Time Complexity**: \(O(1)\)
    - Removes the front node from the queue, also a constant time operation.

#### `removeNode(T data)`
- **Time Complexity**: \(O(n)\)
    - \(n\): Number of elements in the queue.
    - Performs a linear search to find and remove the node.

---

### **Overall Complexity**
The most computationally expensive part of your program is **Dijkstra's Algorithm** in the `askForSourceAndDestination` function, which dominates the program's overall time complexity:
- **Overall Time Complexity**: \(O(V + E \log V)\)

This analysis should help you understand the performance characteristics of your metro bus simulation project. If you need further clarification or optimization suggestions, feel free to ask!
