// https://leetcode.com/problems/lru-cache/
#include<bits/stdc++.h>
using namespace std;

class LRUCache {
    struct Node{
        int key;
        int value;
        Node* next;
        Node* prev;
    };
    Node* get_new_node(int key, int value){
        Node* node = new Node();
        node->key = key;
        node->value = value;
        node->next = NULL;
        node->prev = NULL;
        return node;
    }
    Node* start_pointer = NULL;
    Node* end_pointer = NULL;
    int capacity = 0;
    unordered_map<int, Node*> cache;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
        
    int get(int key) {
        if(cache.find(key) == cache.end()){
            return -1;
        }

        Node* keynode = cache[key];
        if(keynode == end_pointer){
            return keynode->value;
        }

        if(keynode->prev)
            keynode->prev->next = keynode->next;
        else
            start_pointer = keynode->next;

        if(keynode->next)
            keynode->next->prev = keynode->prev;

        keynode->next = NULL;
        keynode->prev = end_pointer;

        if(end_pointer)
            end_pointer->next = keynode;

        end_pointer = keynode;

        return keynode->value;
    }
    void put(int key, int value) {

        // Case 1: key already exists → update and move to end
        if(cache.find(key) != cache.end()){
            Node* node = cache[key];
            node->value = value;
            get(key); // move it to most recent position
            return;
        }

        // Case 2: capacity full → remove LRU (start_pointer)
        if(cache.size() == capacity){

            Node* lru = start_pointer;

            cache.erase(lru->key);

            // only one node
            if(start_pointer == end_pointer){
                start_pointer = NULL;
                end_pointer = NULL;
            }
            else{
                start_pointer = start_pointer->next;
                start_pointer->prev = NULL;
            }

            delete lru;
        }

        // Case 3: insert new node at end
        Node* newnode = get_new_node(key, value);

        cache[key] = newnode;

        if(start_pointer == NULL){
            start_pointer = newnode;
            end_pointer = newnode;
        }
        else{
            end_pointer->next = newnode;
            newnode->prev = end_pointer;
            end_pointer = newnode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */