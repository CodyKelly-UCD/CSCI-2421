//To be used in conjunction with BSTree.h and Node.h
//When you modify this, please add your name and list any changes that you made
//A few member functions have been left blank so you, the student can implemement

/*Template Directions: #include "BSTREEInt.hpp"
but do NOT compile it (or add it to the project)*/
#include "BSTree.h"

// Constructor
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::BSTree() {
	root = nullptr;
}

// Destructor
template <typename DATATYPE, typename KEYTYPE>
BSTree<DATATYPE, KEYTYPE>::~BSTree() {
    if (root !=nullptr)
        freeNode(root);
}

// Free the node
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::freeNode(Node<DATATYPE, KEYTYPE> * leaf)
{
	//Student must fill in
	//if the root is the leaf, delete that leaf
    if (Root() == leaf)
    {
        deleteNode(leaf);
    }
	// otherwise if the leaf is not null
    else if (leaf != nullptr)
    {
		//recursive call of the leaf's left
        freeNode(leaf->Left());
		//recursive call of the leaf's right
        freeNode(leaf->Right());
		//now delete the leaf
        deleteNode(leaf());
    }
}

// Add a node
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, DATATYPE &data)
{
	if (Root() == nullptr)
	{
		Node<DATATYPE, KEYTYPE> * newNodePtr = new Node<DATATYPE, KEYTYPE>;
		newNodePtr->setKey(key);
		newNodePtr->setData(data);
		root = newNodePtr;
		root->setParent(root);

	}
	else
		addNode(key, root, data);
}

// Add a node (private)
template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::addNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * leaf, DATATYPE& data) {
	//Student must fill in
	//Don't forget to set your key, Parent, then left or right
	//Based on the case you use you will addNode recursively to the left or right
 
	//First check if root is null
    if (Root() == nullptr)
    {
        //make a new node
        Node<DATATYPE, KEYTYPE> *newNode = new Node<DATATYPE, KEYTYPE>;
        //set the key and data
        newNode->setData(data);
        newNode->setKey(key);
        //set the root
        root = newNode;
        root->setParent(root);
    }
	//Otherwise
    else
    {
		//Check to see if the key is < the leaf's key
        if (key < leaf->Key())
        {
			// if left is not null then
            if (leaf->Left() != nullptr)
            {
				//Add the node to the left (recursively)
                addNode(key, leaf->Left(), data);
            }
            // Otherwise make a new node and attach it to the left
            else
            {
                Node<DATATYPE, KEYTYPE> *newNode = new Node<DATATYPE, KEYTYPE>;
                newNode->setKey(key);
                newNode->setData(data);
                newNode->setParent(leaf->Left());
                leaf->setLeft(newNode);
            }
        }

		//Check to see if the key >= leaf's key
        else if (key >= leaf->Key())
        {
			// if leaf's right is not null then
            if (leaf->Right() != nullptr)
            {
				//Add the node to the right (recursively)
                addNode(key, leaf->Right(), data);
            }
			// Otherwise make new node and attach it to the right
            else
            {
                Node<DATATYPE, KEYTYPE> *newNode = new Node<DATATYPE, KEYTYPE>;
                newNode->setKey(key);
                newNode->setData(data);
                newNode->setParent(leaf->Right());
                leaf->setRight(newNode);
            }
        }
    }
}

template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key)
{
	return findNode(key, root);
}

// Find a node
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::findNode(KEYTYPE key, Node<DATATYPE, KEYTYPE> * node)
{
	//Student must fill in
	// trap nullptr first in case we've hit the end unsuccessfully.
    if (node == nullptr)
    {
        return nullptr;
    }
	// success base case
    if (node->Key() == key)
    {
        return node;
    }
	//Greater than (Right), Less than (Left)
    if (key < node->Key())
    {
        return findNode(key, node->Left());
    }
    
    return findNode(key, node->Right());
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printInorder()
{
	printInorder(root);
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::printInorder(Node<DATATYPE, KEYTYPE> * node)
{
	//Student must fill in.  Use recursive algorithm.
	//Note that this prints using an Inorder, Depth-first search
	//but you may want to do something else when "visiting" the node....
	//like moving visited data to another datastructure
	//Don't forget your base case!
    if (node == nullptr)
    {
        return;
    }
    if (node->Left() != nullptr)
    {
        printInorder(node->Left());
    }
    cout << node->Key() << endl;
    cout << node->Data() << endl;
    if (node->Right() != nullptr)
    {
        printInorder(node->Right());
    }
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::print(ostream & out, const DATATYPE & data)
{
	out << data.number << "\t" << data.name << endl;
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::deleteNode(KEYTYPE key)
{
	setRoot(deleteNode(Root(), key));
}

//deleteNode (Private)
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::deleteNode(Node<DATATYPE, KEYTYPE> * aRoot,KEYTYPE value)
{
   
	/* Given a binary search tree and a key, this function deletes the key
	and returns the new root */
	
	// base case
	if (aRoot == nullptr) return aRoot;

	// If the key to be deleted is smaller than the aRoot's key,
	// then it lies in left subtree
	if (value < aRoot->Key())
		aRoot->setLeft(deleteNode(aRoot->Left(), value));

	// If the key to be deleted is greater than the root's key,
	// then it lies in right subtree
	else if (value > aRoot->Key())
		root->setRight(deleteNode(aRoot->Right(), value));

	// if key is same as root's key, then This is the node
	// to be deleted
	else
	{
		// node with only one child or no child
		if (aRoot->Left() == nullptr)
		{
			Node<DATATYPE, KEYTYPE> *temp = aRoot->Right();
			delete aRoot;	
			return temp;
		}
		else if (aRoot->Right() == nullptr)
		{
			Node<DATATYPE, KEYTYPE> *temp = aRoot->Left();
			delete aRoot;
			return temp;
		}

		// node with two children: Get the inorder successor (smallest
		// in the right subtree)
		Node<DATATYPE, KEYTYPE> * temp = min(aRoot->Right());

		// Copy the inorder successor's content to this node
		aRoot->setKey(temp->Key());
		aRoot->setData(temp->Data());

		// Delete the inorder successor
		aRoot->setRight(deleteNode(aRoot->Right(), temp->Key()));
	}
	return aRoot;
}


// Find the node with min key
// Traverse the left sub-BSTree recursively
// till left sub-BSTree is empty to get min
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::min(Node<DATATYPE, KEYTYPE> * node)
{
	Node<DATATYPE, KEYTYPE> * current = node;

	/* loop down to find the leftmost leaf */
	while (current->Left() != nullptr)
		current = current->Left();

	return current;
}

// Find the node with max key
// Traverse the right sub-BSTree recursively
// till right sub-BSTree is empty to get max
template <typename DATATYPE, typename KEYTYPE>
Node<DATATYPE, KEYTYPE> * BSTree<DATATYPE, KEYTYPE>::max(Node<DATATYPE, KEYTYPE> * node)
{
	Node<DATATYPE, KEYTYPE> * tempNode = node;
	if (node == nullptr)
		tempNode = nullptr;
	else if (node->Right())
		tempNode = max(node->Right());
	else
		tempNode = node;

	return tempNode;
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::fillVector(vector<Node<DATATYPE, KEYTYPE>*> &vec)
{
    if (Root() == nullptr)
    {
        return;
    }
    fillVector(Root(), vec);
    
    return;
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::fillVector(Node<DATATYPE, KEYTYPE> *node, vector<Node<DATATYPE, KEYTYPE>*> &vec)
{
    if (node == nullptr)
    {
        return;
    }
    if (node->Left() != nullptr)
    {
        fillVector(node->Left(), vec);
    }
    vec.push_back(node);
    if (node->Right() != nullptr)
    {
        fillVector(node->Right(), vec);
    }
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::toFile(ofstream &file, Node<DATATYPE, KEYTYPE> *node)
{
    if (node == nullptr)
    {
        return;
    }
    if (node->Left() != nullptr)
    {
        toFile(file, node->Left());
    }
    for (awardStruct award : *node->Data())
    {
        file << award.year << ',';
        file << award.awardName << ',';
        file << award.winner << ',';
        file << node->Key() << ',';
        file << award.filmName;
        file << endl;
    }
    if (node->Right() != nullptr)
    {
        toFile(file, node->Right());
    }
}

template <typename DATATYPE, typename KEYTYPE>
void BSTree<DATATYPE, KEYTYPE>::toFile(ofstream &file)
{
    file << "Year,Award,Winner,Name,Film\n";
    if (Root() == nullptr)
    {
        return;
    }
    toFile(file, Root());
}
