146. LRU Cache

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

=========================================================================================

#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
    // Define the structure for a doubly linked list node
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    // Constructor to initialize the cache with a given capacity
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node(0, 0);  // Dummy head
        last = new Node(0, 0);  // Dummy last
        head->next = last;
        last->prev = head;
    }

    // Get the value associated with the key
    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }
        Node* node = map[key];
        remove(node);
        insert(node);
        return node->value;
    }

    // Insert a key-value pair into the cache
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            remove(map[key]);
        }
        if (map.size() == capacity) {
            remove(last->prev);
        }
        insert(new Node(key, value));
    }

private:
    unordered_map<int, Node*> map;  // HashMap equivalent in C++
    Node* head;
    Node* last;
    int capacity;

    // Insert a node into the doubly linked list (to the front)
    void insert(Node* node) {
        map[node->key] = node;
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }

    // Remove a node from the doubly linked list
    void remove(Node* node) {
        map.erase(node->key);
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;  // Free memory for the removed node
    }
};

int main() {
    LRUCache cache(2);  // Create an LRUCache with a capacity of 2

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;  // Returns 1
    cache.put(3, 3);               // Evicts key 2
    cout << cache.get(2) << endl;  // Returns -1 (not found)
    cache.put(4, 4);               // Evicts key 1
    cout << cache.get(1) << endl;  // Returns -1 (not found)
    cout << cache.get(3) << endl;  // Returns 3
    cout << cache.get(4) << endl;  // Returns 4

    return 0;
}
