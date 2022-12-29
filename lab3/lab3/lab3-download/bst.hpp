//header file BinarySearchTree.hpp to declare your class
#include <iostream>
using std::ostream; 

#ifndef bst_h
#define bst_h
namespace ENSC251_Lab3 {
  
  struct Node {
    int key; // key value of the node
    struct Node *parent; // pointer to parent node
    struct Node *left; // pointer to left subtree
    struct Node *right; // pointer to right subtree
  };
  typedef struct Node* NodePtr;
  
  class BinarySearchTree 
  {
    public:
	  // Constructors
	  BinarySearchTree();
	  ~BinarySearchTree();
    //copy constructor
	  BinarySearchTree(const BinarySearchTree & bst);
    //get function 
    NodePtr get_root() const;
    //overloading assignment operator 
	  BinarySearchTree & operator=(const BinarySearchTree & BinarySearchTree);
    //outpu steram
    friend ostream &operator <<(ostream&  outs, BinarySearchTree& tree);
    //insert and delte key
	  bool insertNode(int key);
    bool deleteNode(int key);

    //search the requested key
	  NodePtr searchNode(int key);
    NodePtr searchSuccessor(int key);
    //find the maximum key in the tree
    int maximum();
    //deletes the whole tree
	  void clear();
    //checks if the tree is empty 
	  bool empty() const;
    //helper function to print the tree by level 
    void ByLevelPrint(NodePtr nd , int level);
    void print();
    int height() const;
    //helper function for the destructor 
	  void clear(NodePtr nd);
    //helper function to delete a node 
    NodePtr deleteN(NodePtr z, int key);
    //helper function for the copy constructor 
	  NodePtr copyTree (const NodePtr theRoot);
    //finds the height of the tree 
    int height(NodePtr nd) const;
  private:
	  NodePtr root;
  };
 
}
#endif
