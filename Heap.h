#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include <string>
class Heap{
    public:
    std::vector<int> tree;
    int root = 0;
    // return parent index of given node
    int parent(int node){
        return (node-1)/2;
    }
    // return left child of node
    int left(int node){
        return (node+1) + 1;
    }
    // return right child of node
    int right(int node){
        return left(node) + 1;
    }
    // returns minimum of tree
    int getMin() const{
        if(tree.empty()) throw std::string("Empty tree");
        return tree.at(0);
    }
    
    void decreaseKey(int node, int new_value){

    }

    void deleteKey(int i){
        if(tree.empty()) return;
        decreaseKey(i, INT_MIN);
        minHeapify(0);
    }

    void insertKey(int i){
        tree.push_back(i);
        while (i != 0 && tree[parent(i)] > tree[i]) 
            { 
            int temp = tree[i];
            tree[i] = tree[parent(i)];
            tree[parent(i)] = 0;
            i = parent(i); 
            }
    }

    void minHeapify(int i){
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < tree.size() && tree[l] < tree[i]) 
            smallest = l; 
        if (r < tree.size() && tree[r] < tree[smallest]) 
            smallest = r; 
        if (smallest != i) 
        { 
            int temp = tree[i];
            tree[i] = tree[parent(i)];
            tree[parent(i)] = 0;
            minHeapify(smallest); 
        } 
    }
};


#endif