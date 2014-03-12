//
// bintree.h
//
// Paul Simpson
// CSS 343
// Lab2
//

#ifndef BINTREE_H
#define BINTREE_H

#include "nodedata.h"

//-----------------------------------------------------------------------------
// class BinTree
//
// Stores a collection of NodeData objects in a binary tree.
//
// Assumptions:
//  -- two trees are equal if they have the same data and same structure
//  -- when building from file, $$ marks end of input for that set
//  -- bstreeToArray assumes statically allocated array of 100 NULL elements
//  -- the height of a node at a leaf is 1, height of a node at the next level
//     is 2, height of a value not found is zero
//-----------------------------------------------------------------------------

class BinTree {
    friend ostream& operator<<(ostream &, const BinTree &);
    
public:
    BinTree();                    // constructor
    ~BinTree();                   // destructor, calls makeEmpty
    bool isEmpty() const;         // true if tree is empty, otherwise false
    void makeEmpty();             // make the tree empty
    
    bool operator==(const BinTree &) const;  // equal data and structure
    bool operator!=(const BinTree &) const;  // opposite of operator==
    
    bool insert(NodeData*);                  // put data in tree
    bool retrieve(const NodeData &, NodeData *&) const;  // find data
    void displaySideways() const;            // displays the tree sideways
    int getHeight(const NodeData &) const;   // height of node
    NodeData* getRoot() const;
    
    void bstreeToArray(NodeData* []);        // moves tree to array
    void arrayToBSTree(NodeData* []);        // balanced tree from array
    
private:
    struct Node {
        NodeData* data; // pointer to data object
        Node* left;     // left subtree pointer
        Node* right;    // right subtree pointer
    };
    Node* root; // root of the tree
    
    // utility functions
    void inorderHelper(Node*, ostream &) const;  // helper for operator<<
    void sideways(Node*, int) const;  // helper for displaySideways()
    void makeEmptyHelper(Node*);  // helper for makeEmpty()
    bool equalHelper(Node*, Node*) const; // helper for operator==
    int heightHelper(Node*, const NodeData &) const;  // helper for getHeight()
    int getNodeHeight(Node*) const;   // helper for heightHelper()
    void toArrayHelper(Node*, NodeData* [], int &);//helper for bstreeToArray()
    Node* toBSTreeHelper(NodeData* [], int, int); // helper for arrayToBSTree()
    
};


#endif



