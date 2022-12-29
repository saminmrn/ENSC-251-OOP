//bst.cpp to implement your class
//this file insludes the class implemenation of BinarySearchTree
//updated by Samin Moradkhan and James Ryan Martin 
//July 2022
#include "bst.hpp"
using namespace std; 

namespace ENSC251_Lab3 
{
    //defauly constructor 
    BinarySearchTree:: BinarySearchTree()
    {
        root= NULL; 
    }
    //copy constructor 
    BinarySearchTree:: BinarySearchTree(const BinarySearchTree &bst)
    {
        root=copyTree(bst.root); 
    }


    // Helper method to copy tree 
    NodePtr BinarySearchTree ::copyTree(const NodePtr theRoot) 
    {
	    if (theRoot == NULL)
		    {
			    return NULL;
		    }
	    NodePtr newNode = new Node; 
        //copy the key
        newNode-> key= theRoot->key;
        newNode->parent = theRoot->parent; 
	    newNode->left = copyTree(theRoot->left);
	    newNode->right = copyTree(theRoot->right);
	    return newNode;
    }

    // Overloaded assignment operator
    BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &bst)
    {
	    if (this != &bst)
	    {
		    clear();
		    root = copyTree(bst.root);
	    }
	    return *this;
    }
    //destructor 
    BinarySearchTree::~BinarySearchTree()
    {
	    clear();
    }
    //helper method to delete the tree 
    void BinarySearchTree::clear()
    {
	    clear(root);
	    root = NULL;
    }
    //deleting the whole tree 
    void BinarySearchTree::clear(NodePtr nd)
    {
	    if (nd != NULL)
	    {
		    clear(nd->left);
		    clear(nd->right);
		    delete nd;
	    }
    }

    //returninhg the node if the key exists otherwise NULL 
    NodePtr BinarySearchTree::searchNode(int key)
    {
	    NodePtr p = root;
	    while (p != NULL)//search until reached the bottom row of the tree
	    {
		    if (key == p->key)
		    {
			    return p ;
		    }
		    else if (key < p->key)
		    {
			    p = p->left;
		    }
		    else
		    {
			    p = p->right;
		    }
	    }
	    return NULL;
    }
    //returns the root of the tree
    NodePtr BinarySearchTree::get_root() const
    {
        return root; 
    }
    //inserts a node in the binary search tree 
    bool BinarySearchTree::insertNode(int key)
    {
        if (searchNode(key)!=NULL)
        {
            cout<<"This key is already inserted.";
            return false; 
        }
        NodePtr newNode = new Node;
        newNode->key= key;
        newNode->left=NULL;
        newNode->right=NULL;
	    NodePtr p = root;
	    NodePtr next = root;

	    if (empty())
	    {
		    root = newNode;
            root->parent=NULL; 
            return true; 
	    }
	    else
	    { // non-empty
	    //  Find parent of new node
		    while (next != NULL)
		    {
			    p = next;
			    if (key< p->key)
			    {
				    next = p->left;
			    }
			    else
			    {
				    next = p->right;
			    }
		    }
		    // Insert new node
		    if (key< p->key)//if the key is smaller than the parent, its a left child
		    {
			    p->left = newNode;
                p->left->parent=p;
                newNode->parent= p; 
                return true; 
		    }
		    else//if the key is bigger than the parent, its a right child
		    {
			    p->right = newNode;
                p->right->parent=p; 
                newNode->parent= p;
                return true; 
		    }
	    }
        return false ; 
    }
    //deletes the node holding the key from the bst 
    bool BinarySearchTree::deleteNode(int key)
    {
        if (searchNode(key)==NULL)
        {
            cout<<"This key does not exist."<<endl; 
            return false ;
        }
        else 
        {
            deleteN(root,key);
            return true; 
        }

    }

    //check if the tree is empty 
    bool BinarySearchTree::empty() const
    {
        return root == NULL;
    }
    //prints the bst level by level 
    void  BinarySearchTree::print()
    {
        int h = this->height();
        for (int i = 1; i <= h; i++)
        {
            ByLevelPrint(root, i);
            cout<<endl;
        }    
    }
    //helper method to print the bst 
    void  BinarySearchTree::ByLevelPrint(NodePtr nd , int level ) 
    {
        if (empty())
        {
            std::cout << "this tree is empty" << std::endl;
        }
        if (nd==NULL)
        {
            return; 
        }
        if (level == 1)
           if(nd->parent!= NULL)
           {
            cout<< nd-> key<< "("<<nd->parent->key<<"->"; 
            if (nd->key<nd->parent->key )//if its a left child 
            {
                std::cout<<"left), ";
            }
            else //if its a right child 
            {
                std::cout<<"right), "; 
            }
           }
           else 
           {
                cout<< nd->key; 
           }
        else if (level > 1) 
        {
            ByLevelPrint(nd->left, (level-1) );
            ByLevelPrint(nd->right, (level -1));
        }

    }
    //return the height of the tree 
    int BinarySearchTree::height() const
    {
	    if (root == NULL)
	    {
		    return -1;
	    }
	    return height(root);
    }
    //helper method to find the height of the tree 
    int BinarySearchTree::height(NodePtr nd) const
    {
	    if (nd == NULL)
	    {
		    return 0;
	    }
	    else
	    {
		    int htLeft = height(nd->left);
		    int htRight = height(nd->right);
            if (htLeft > htRight) 
            {
                return (htLeft + 1);
            }
            else 
            {
                return (htRight + 1);
            }
	    }
    }
    //searches and returns the node holding the successor of the key 
    NodePtr BinarySearchTree::searchSuccessor(int key)
    {
		int maxnum = maximum(); //find the max number key
		if (key == maxnum) 
        {
		    cout << "The key is the largest, it does not have a succesor." << endl;
			return NULL;
		}
		else 
        {
			NodePtr x;
			x = searchNode(key);

			while (key<maxnum){ //searching the tree until found the max
				key++;
				x = searchNode(key);
				if (x != NULL) {
					return x;
				}

			}
			return NULL;
		}

    }
    //finding the maximum value in the tree(right most leaf) 
    int BinarySearchTree::maximum()
    {
		NodePtr temp = root;
		while (temp->right != NULL) {
				temp = temp->right;
		}
		return (temp->key);
    }
    //prints the tree by level
    ostream &operator <<(ostream&  outs, BinarySearchTree& tree)
    {
        tree.print(); 
        return outs; 
    }

//helper function to delete the node 
NodePtr BinarySearchTree::deleteN(NodePtr z, int key) 
{
		if (z ==NULL) 
        {
			return NULL;
		}
		else if (key < z->key) // loop through the tree until find the desire node
		{
			z->left = deleteN(z->left, key);
		}
		else if (key > z->key)
		{
			z->right = deleteN(z->right, key);
		}
		else if (key == z->key) {
			if (z->left == NULL && z->right == NULL) 
            {// node has no child 
				z = NULL;
			}
			else if (z->left == NULL && z->right != NULL) 
            { //node has a left child
				z->right->parent = z->parent;
				z = z->right;
			}
			else if (z->right == NULL && z->left != NULL) 
            {//node has a right child
				z->left->parent = z->parent;
				z = z->left;
			}
			else 
            {
				NodePtr temp = searchSuccessor(key); //find a successor
				z->key = temp->key;  //copy the to node that is being deleted
				z->right->parent = z;
				z->left->parent = z;
				z->right = deleteN(z->right, temp->key); //find the successor node and delete it
				delete temp; //delete the node
			}
		}

		return z;
	}
}


