//
// bintree.cpp
//
// Paul Simpson
// CSS 343
// Lab2
//

#include "bintree.h"

//-----------------------------------------------------------------------------
// constructor

BinTree::BinTree() {
    root = NULL;
}

//-----------------------------------------------------------------------------
// destructor

BinTree::~BinTree() {
    makeEmpty();
}

//-----------------------------------------------------------------------------
// isEmpty

bool BinTree::isEmpty() const {
    return root == NULL;
}

//-----------------------------------------------------------------------------
// makeEmpty
// delete all nodes and the values they point to

void BinTree::makeEmpty() {
    makeEmptyHelper(root);
    root = NULL;
}

//-----------------------------------------------------------------------------
// makeEmptyHelper
// helper function for makeEmpty

void BinTree::makeEmptyHelper(Node* current) {
    
    // walk until a leaf is found
    if (current != NULL) {
        makeEmptyHelper(current->left);     // walk left
        makeEmptyHelper(current->right);    // walk right
        
        // remove the Node and its NodeData
        delete current->data;
        delete current;
    }
}

//-----------------------------------------------------------------------------
// operator==
// returns true if two trees have the same data and structure, otherwise false

bool BinTree::operator==(const BinTree &right) const {
    return equalHelper(root, right.root);
}

//-----------------------------------------------------------------------------
// equalHelper
// helper function for operator==

bool BinTree::equalHelper(Node* lhs, Node* rhs) const {
    
    // both nodes are a leaf
    if (lhs == NULL && rhs == NULL)
        return true;
    
    // at least one node has data, but the other doesn't
    if (lhs == NULL || rhs == NULL)
        return false;
    
    // same data, walk the left and right
    if (*lhs->data == *rhs->data) {
        bool left = equalHelper(lhs->left, rhs->left);
        bool right = equalHelper(lhs->right, rhs->right);
        
        return left && right;
    }
    else {
        return false;
    }
}

//-----------------------------------------------------------------------------
// operator!=

bool BinTree::operator!=(const BinTree &right) const {
    return !(*this == right);
}

//-----------------------------------------------------------------------------
// insert
// accepts NodeData parameter to add into the tree based on the operator<
// and operator> of the NodeData class

bool BinTree::insert(NodeData* dataPtr) {
    
    if (isEmpty()) {

        // build Node and attach new data
        Node* nodePtr = new Node;
        nodePtr->data = dataPtr;
        nodePtr->left = NULL;
        nodePtr->right = NULL;
        
        root = nodePtr;
    }
    else {
        Node* current = root;   // to walk the tree
        bool success = false;   // inserted or not
        
        while (!success) {
            if (*dataPtr < *current->data) {
                if (current->left == NULL) {
                    
                    // build Node and attach new data
                    Node* nodePtr = new Node;
                    nodePtr->data = dataPtr;
                    nodePtr->left = NULL;
                    nodePtr->right = NULL;
                    
                    // found the correct spot
                    current->left = nodePtr;
                    success = true;
                }
                else {
                    current = current->left;   // walk left
                }
            }
            else if (*dataPtr > *current->data) {
                if (current->right == NULL) {
                    
                    // build Node and attach new data
                    Node* nodePtr = new Node;
                    nodePtr->data = dataPtr;
                    nodePtr->left = NULL;
                    nodePtr->right = NULL;
                    
                    // found the correct spot
                    current->right = nodePtr;
                    success = true;
                }
                else {
                    current = current->right;  // walk right
                }
            }
            else {
                // don't insert duplicate
                return false;
            }
        }
    }
    return true;
}

//-----------------------------------------------------------------------------
// retrieve
// searches tree for matching NodeData (first parameter) and returns a pointer
// to that node (second parameter) if it is found in the tree.
// result pointer is NULL if match is not found

bool BinTree::retrieve(const NodeData &search, NodeData *&result) const {
    result = NULL;              // NULL if not found
    
    if (!isEmpty()) {
        
        Node* current = root;   // walking pointer
        bool stop = false;      // whether stopped yet
        
        // if item is less than current item, walk left subtree,
        // otherwise walk right subtree until found, or the end
        // of the tree is reached
        while (!stop) {
            if (*current->data != search) {
                if (search < *current->data) {
                    if (current->left == NULL) {     // found end
                        stop = true;
                        return false;
                    }
                    else
                        current = current->left;     // one step left
                }
                else {
                    if (current->right == NULL) {    // found end
                        stop = true;
                        return false;
                    }
                    else
                        current = current->right;    // one step right
                }
            }
            else {
                stop = true;
                result = current->data;
                return true;
            }
        }
    }
    return false;
}

//-----------------------------------------------------------------------------
// getHeight
// finds the height of a node for a matching NodeData, returns zero if the
// data is not found.

int BinTree::getHeight(const NodeData &target) const {
    return heightHelper(root, target);
}

//-----------------------------------------------------------------------------
// getRoot

NodeData* BinTree::getRoot() const {
    return root->data;
}

//-----------------------------------------------------------------------------
// heightHelper
// walks through every node in the tree checking for a matching node,
// if found, calls another recursive helper function to determine the height

int BinTree::heightHelper(Node* current, const NodeData &target) const {
    
    // walk until a leaf is found
    if (current == NULL) {
        return 0;
    }
    else if (target == *current->data) {
        
        // call helper function to actually find the height
        return getNodeHeight(current);
    }
    else {
        int left = heightHelper(current->left, target);     // walk left
        int right = heightHelper(current->right, target);   // walk right
        
        return left + right;
        
    }
}

//-----------------------------------------------------------------------------
// getNodeHeight
// helper function for heightHelper, gets the height of specified Node

int BinTree::getNodeHeight(Node* current) const {
    
    // walk until leaf is found
    if (current == NULL) {
        return 0;
    }
    else {
        int left = getNodeHeight(current->left);    // walk left
        int right = getNodeHeight(current->right);  // walk right
        
        // we are only interested in whatever side of the tree is larger
        return max(left, right) + 1;
    }
}

//-----------------------------------------------------------------------------
// bstreeToArray
// walks through tree and adds data to array in order, also empties it out

void BinTree::bstreeToArray(NodeData* data[]) {
    int count = 0;    // count position in array to insert
    
    // call recursive helper
    toArrayHelper(root, data, count);
    
    root = NULL;
}

//-----------------------------------------------------------------------------
// toArrayHelper
// helper function for bstreeToArray

void BinTree::toArrayHelper(Node* current, NodeData* data[], int &i) {
    
    // perform in order traversal and assign data to array
    if (current != NULL) {
        toArrayHelper(current->left, data, i);   // walk left
        data[i] = current->data;
        i++;
        toArrayHelper(current->right, data, i);  // walk right

        delete current;  // clean up afterwards
    }
}

//-----------------------------------------------------------------------------
// arrayToBSTree
// builds balanced tree from array of sorted NodeData

void BinTree::arrayToBSTree(NodeData* data[]) {
    
    // find size of array
    int i = 0;
    while(data[i] != NULL)
        i++;
    
    // make sure there are no items already in the tree
    makeEmpty();
    
    // call recursive helper
    root = toBSTreeHelper(data, 0, i - 1);
}

//-----------------------------------------------------------------------------
// toBSTreeHelper
// helper function for arrayToBSTree

BinTree::Node* BinTree::toBSTreeHelper(NodeData* data[], int min, int max) {
    
    // walk until each item is put into tree
    if (min > max) {
        return NULL;
    }
    else {
        
        // since array is sorted, grab item in the middle
        // recursively and place it into the tree so
        // the end result will be balanced
        int mid = (max + min) / 2;
        
        // build new node and assign over the data
        Node* nodePtr = new Node;
        nodePtr->data = data[mid];
        data[mid] = NULL;
        
        nodePtr->left = toBSTreeHelper(data, min, mid - 1);   // walk left
        nodePtr->right = toBSTreeHelper(data, mid + 1, max);  // walk right
        
        return nodePtr;
    }
    
}

//-----------------------------------------------------------------------------
// operator<<
// displays tree in order to output stream

ostream& operator<<(ostream &output, const BinTree &tree) {
    
    // call recursive helper
    tree.inorderHelper(tree.root, output);
    
    output << endl;
    
    return output;
}

//-----------------------------------------------------------------------------
// inorderHelper
// helper function for operator<<

void BinTree::inorderHelper(Node* current, ostream &output) const {
    
    // walk until a leaf is found
    if (current != NULL) {
        inorderHelper(current->left, output);   // walk left
        output << *current->data;
        inorderHelper(current->right, output);  // walk right
    }
}







