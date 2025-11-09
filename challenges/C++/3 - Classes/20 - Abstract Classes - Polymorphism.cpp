#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
    void addToHead(Node* node) {
        node->prev = nullptr;
        node->next = head;
        if (head) head->prev = node;
        head = node;
        if (!tail) tail = node;
    }
    void removeNode(Node* node) {
        if (node->prev) node->prev->next = node->next;
        else head = node->next;
        if (node->next) node->next->prev = node->prev;
        else tail = node->prev;
        node->prev = node->next = nullptr;
    }
    void moveToHead(Node* node) {
        if (node == head) return;
        removeNode(node);
        addToHead(node);
    }
public:
    LRUCache(int capacity) { cp = capacity; head = tail = nullptr; }

    void set(int key, int value) override {
        auto it = mp.find(key);
        if (it != mp.end()) {
            it->second->value = value;
            moveToHead(it->second);
            return;
        }
        Node* node = new Node(key, value);
        if ((int)mp.size() == cp) {
            if (tail) {
                mp.erase(tail->key);
                Node* old = tail;
                removeNode(old);
                delete old;
            }
        }
        addToHead(node);
        mp[key] = node;
    }

    int get(int key) override {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;
        moveToHead(it->second);
        return it->second->value;
    }
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
