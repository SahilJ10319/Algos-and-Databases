#pragma once
#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

template <typename T1,typename T2>
class NodeT
{
public:
	T1 key;
	T2 value;
	NodeT<T1, T2> *left;
	NodeT<T1, T2> *right;
	NodeT<T1, T2> *parent;
	bool isBlack;
	NodeT()
	{
		this->left = nullptr;
		this->right = nullptr;
		this->parent = nullptr;
		this->isBlack = false;
	}
	NodeT(T1 Key_Parameter,T2 Value_Parameter)
	{
		this->key = Key_Parameter;
		this->value = Value_Parameter;
		this->left = nullptr;
		this->right = nullptr;
		this->parent = nullptr;
		this->isBlack = false;
	}
};

template <typename T1,typename T2>
class RedBlackTree
{
	NodeT<T1, T2> *root;
	int NoOfNodes;
	NodeT<T1, T2>* MinimumNode(NodeT<T1, T2> *Node); //Function to Find Minimum Node(key) in the Tree 
	NodeT<T1, T2>* MaximumNode(NodeT<T1, T2> *Node); //Function to Find Maximum Node(key) in the Tree
	void deleteTree(NodeT<T1, T2> *Temp); //Recursive function to Delete Tree
	void LeftRotate(NodeT<T1, T2> *Node); //left Rotation of a node
	void RightRotate(NodeT<T1, T2> *Node); //right Rotation of a node
	bool SearchTreeHelper(NodeT<T1, T2> *Node, T1 Key_Parameter); //Recursive function to Find node
	void DeleteFix(NodeT<T1, T2> *Node); //After Deletion this function balances the tree
	void RedBlackTransplant(NodeT<T1, T2> *u, NodeT<T1, T2> *v); //for swapping of nodes
	bool DeleteNodeHelper(NodeT<T1, T2> *Node, T1 Key_Parameter); //Helper function to delete
	void InsertFix(NodeT<T1, T2> *Node); //After Insertion this function balances the tree
	void PrintHelper(NodeT<T1, T2> *root, string indent, bool last); // Recursive function to print Tree
	void HelpLNRforValues(NodeT<T1, T2>* Temp,T1 Key_Parameter_1, T1 Key_Parameter_2, vector<T2> &values); //Helper function for getting vector of values from tree
	void HelpLNRforKeys(NodeT<T1, T2>* Temp, T1 Key_Parameter_1, T1 Key_Parameter_2, vector<T1> &keys); //Helper function for getting vector of keys from tree
	NodeT<T1, T2>* DeepCopy(NodeT<T1, T2> *Node); //Helper function for constructor/equal operator

public:
	RedBlackTree();	//Default Constructor
	RedBlackTree(const RedBlackTree<T1, T2> &Obj);	//Copy Constructor
	RedBlackTree<T1, T2> operator=(const RedBlackTree<T1, T2> &Obj); //Overload Equal Operator
	bool insert(T1 Key_Parameter, T2 Value_Parameter); //insert Operation
	bool remove(T1 Key_Parameter); //Delete Operation
	bool search(T1 Key_Parameter); //search returns bool indication key exists or not
	vector<T2> search(T1 Key_Parameter_1, T1 Key_Parameter_2); //search returns vector containing all values between range in ascending order
	vector<T2> values(); //Return vector containing all values in the tree in ascending order
	vector<T1> keys(); //Return vector containing all keys in the tree in ascending order
	int size() const; //Returns size of tree
	NodeT<T1, T2>* getRoot() const; //Returns root
	void print(); //print Tree (FOR ME)
	~RedBlackTree(); //Destructor
};

template<typename T1, typename T2>
NodeT<T1, T2>* RedBlackTree<T1, T2>::MinimumNode(NodeT<T1, T2>* Node)
{
	while (Node->left != nullptr)
	{
		Node = Node->left;
	}
	return Node;
}

template<typename T1, typename T2>
NodeT<T1, T2>* RedBlackTree<T1, T2>::MaximumNode(NodeT<T1, T2>* Node)
{
	while (Node->right != nullptr)
	{
		Node = Node->right;
	}
	return Node;
}

template<typename T1, typename T2>
void RedBlackTree<T1, T2>::deleteTree(NodeT<T1, T2>* Temp)
{
	if (Temp != nullptr)
	{
		deleteTree(Temp->left);
		deleteTree(Temp->right);
		delete Temp;
	}
}

template<typename T1, typename T2>
void RedBlackTree<T1, T2>::LeftRotate(NodeT<T1, T2>* Node)
{
	NodeT<T1, T2> *Temp = Node->right;
	Node->right = Temp->left;
	if (Temp->left != nullptr)
	{
		Temp->left->parent = Node;
	}
	Temp->parent = Node->parent;
	if (Node->parent == nullptr)
	{
		this->root = Temp;
	}
	else if (Node == Node->parent->left)
	{
		Node->parent->left = Temp;
	}
	else
	{
		Node->parent->right = Temp;
	}
	Temp->left = Node;
	Node->parent = Temp;
}

template<typename T1, typename T2>
void RedBlackTree<T1, T2>::RightRotate(NodeT<T1, T2>* Node)
{
	NodeT<T1, T2> *Temp = Node->left;
	Node->left = Temp->right;
	if (Temp->right != nullptr) {
		Temp->right->parent = Node;
	}
	Temp->parent = Node->parent;
	if (Node->parent == nullptr) {
		this->root = Temp;
	}
	else if (Node == Node->parent->right) {
		Node->parent->right = Temp;
	}
	else {
		Node->parent->left = Temp;
	}
	Temp->right = Node;
	Node->parent = Temp;
}

template<typename T1, typename T2>
bool RedBlackTree<T1, T2>::SearchTreeHelper(NodeT<T1, T2> *Node, T1 Key_Parameter)
{
	if (Node == nullptr || Key_Parameter == Node->key)
	{
		if (Node == nullptr) {
			return false;
		}
		return true;
	}

	if (Key_Parameter < Node->key)
	{
		return SearchTreeHelper(Node->left, Key_Parameter);
	}
	return SearchTreeHelper(Node->right, Key_Parameter);
}

template<typename T1, typename T2>
void RedBlackTree<T1, T2>::DeleteFix(NodeT<T1, T2> *Node)
{
	NodeT<T1, T2> *Temp;
	while (Node != root && Node->isBlack == false)
	{
		if (Node == Node->parent->left)
		{
			Temp = Node->parent->right;
			if (Temp->isBlack == true)
			{
				Temp->isBlack = false;
				Node->parent->isBlack = true;
				LeftRotate(Node->parent);
				Temp = Node->parent->right;
			}

			if (Temp->left->isBlack == false && Temp->right->isBlack == false)
			{
				Temp->isBlack = true;
				Node = Node->parent;
			}
			else
			{
				if (Temp->right->isBlack == false)
				{
					Temp->left->isBlack = false;
					Temp->isBlack = true;
					RightRotate(Temp);
					Temp = Node->parent->right;
				}
				Temp->isBlack = Node->parent->isBlack;
				Node->parent->isBlack = false;
				Temp->right->isBlack = false;
				LeftRotate(Node->parent);
				Node = root;
			}
		}
		else {
			Temp = Node->parent->left;
			if (Temp->isBlack == true) {
				Temp->isBlack = false;
				Node->parent->isBlack = true;
				RightRotate(Node->parent);
				Temp = Node->parent->left;
			}

			if (Temp->left->isBlack == false && Temp->right->isBlack == false) {
				Temp->isBlack = true;
				Node = Node->parent;
			}
			else {
				if (Temp->left->isBlack == false) {
					Temp->right->isBlack = false;
					Temp->isBlack = true;
					LeftRotate(Temp);
					Temp = Node->parent->left;
				}

				Temp->isBlack = Node->parent->isBlack;
				Node->parent->isBlack = false;
				Temp->left->isBlack = false;
				RightRotate(Node->parent);
				Node = root;
			}
		}
	}
	Node->isBlack = false;
}

template<typename T1, typename T2>
void RedBlackTree<T1, T2>::RedBlackTransplant(NodeT<T1, T2>* Node_1, NodeT<T1, T2>* Node_2)
{
	if (Node_1->parent == nullptr)
	{
		root = Node_2;
	}
	else if (Node_1 == Node_1->parent->left)
	{
		Node_1->parent->left = Node_2;
	}
	else
	{
		Node_1->parent->right = Node_2;
	}
	if (Node_2 != nullptr) {
		Node_2->parent = Node_1->parent;
	}
}

template<typename T1, typename T2>
bool RedBlackTree<T1, T2>::DeleteNodeHelper(NodeT<T1, T2>* Node, T1 Key_Parameter)
{
	bool isDeleted = false;
	NodeT<T1, T2> *TraversalNode = nullptr;
	NodeT<T1, T2> *x, *y;
	while (Node != nullptr)
	{
		if (Node->key == Key_Parameter) {
			TraversalNode = Node;
		}

		if (Node->key <= Key_Parameter) {
			Node = Node->right;
		}
		else {
			Node = Node->left;
		}
	}

	if (TraversalNode == nullptr) {
		cout << "key not found in the tree" << endl;
		return isDeleted;
	}
	isDeleted = true;
	this->NoOfNodes--;
	y = TraversalNode;
	int y_original_color = y->isBlack;
	if (TraversalNode->left == nullptr) {
		x = TraversalNode->right;
		RedBlackTransplant(TraversalNode, TraversalNode->right);
	}
	else if (TraversalNode->right == nullptr) {
		x = TraversalNode->left;
		RedBlackTransplant(TraversalNode, TraversalNode->left);
	}
	else {
		y = MinimumNode(TraversalNode->right);
		y_original_color = y->isBlack;
		x = y->right;
		if (y->parent == TraversalNode)
		{
			if (x != nullptr)
				x->parent = y;
		}
		else {
			RedBlackTransplant(y, y->right);
			y->right = TraversalNode->right;
			y->right->parent = y;
		}

		RedBlackTransplant(TraversalNode, y);
		y->left = TraversalNode->left;
		y->left->parent = y;
		y->isBlack = TraversalNode->isBlack;
	}
	delete TraversalNode;
	if (y_original_color == false)
	{
		if (x != nullptr) {
			DeleteFix(x);
		}
	}
	return isDeleted;
}

template<typename T1, typename T2>
void RedBlackTree<T1, T2>::InsertFix(NodeT<T1, T2>* Node)
{
	NodeT<T1, T2>* Temp;
	while (Node->parent->isBlack == true) {
		if (Node->parent == Node->parent->parent->right) {
			Temp = Node->parent->parent->left;
			if (Temp != nullptr && Temp->isBlack == true) {
				Temp->isBlack = false;
				Node->parent->isBlack = false;
				Node->parent->parent->isBlack = true;
				Node = Node->parent->parent;
			}
			else {
				if (Node == Node->parent->left) {
					Node = Node->parent;
					RightRotate(Node);
				}
				Node->parent->isBlack = false;
				Node->parent->parent->isBlack = true;
				LeftRotate(Node->parent->parent);
			}
		}
		else {
			Temp = Node->parent->parent->right;

			if (Temp != nullptr && Temp->isBlack == true) {
				Temp->isBlack = false;
				Node->parent->isBlack = false;
				Node->parent->parent->isBlack = true;
				Node = Node->parent->parent;
			}
			else {
				if (Node == Node->parent->right) {
					Node = Node->parent;
					LeftRotate(Node);
				}
				Node->parent->isBlack = false;
				Node->parent->parent->isBlack = true;
				RightRotate(Node->parent->parent);
			}
		}
		if (Node == root) {
			break;
		}
	}
	root->isBlack = false;
}

template<typename T1, typename T2>
void RedBlackTree<T1, T2>::PrintHelper(NodeT<T1, T2>* root, string indent, bool last)
{
	if (root != nullptr) {
		cout << indent;
		if (last) {
			cout << "R----";
			indent += "   ";
		}
		else {
			cout << "L----";
			indent += "|  ";
		}

		string sColor = root->isBlack ? "RED" : "BLACK";
		cout << root->key << "(" << sColor << ")" << endl;
		PrintHelper(root->left, indent, false);
		PrintHelper(root->right, indent, true);
	}
}

template<typename T1, typename T2>
void RedBlackTree<T1, T2>::HelpLNRforValues(NodeT<T1, T2>* Temp, T1 Key_Parameter_1, T1 Key_Parameter_2, vector<T2> &values)
{
	if (Temp != nullptr) {
		HelpLNRforValues(Temp->left, Key_Parameter_1, Key_Parameter_2, values);
		if (Temp->key >= Key_Parameter_1 && Temp->key <= Key_Parameter_2)
		{
			values.push_back(Temp->value);
		}
		HelpLNRforValues(Temp->right, Key_Parameter_1, Key_Parameter_2, values);
	}
}

template<typename T1, typename T2>
void RedBlackTree<T1, T2>::HelpLNRforKeys(NodeT<T1, T2>* Temp, T1 Key_Parameter_1, T1 Key_Parameter_2, vector<T1> &keys)
{
	if (Temp != nullptr) {
		HelpLNRforKeys(Temp->left, Key_Parameter_1, Key_Parameter_2, keys);
		if (Temp->key >= Key_Parameter_1 && Temp->key <= Key_Parameter_2)
		{
			keys.push_back(Temp->key);
		}
		HelpLNRforKeys(Temp->right, Key_Parameter_1, Key_Parameter_2, keys);
	}
}

template<typename T1, typename T2>
NodeT<T1, T2>* RedBlackTree<T1, T2>::DeepCopy(NodeT<T1, T2>* Node)
{
	if (Node == nullptr) {
		return nullptr;
	}
	NodeT<T1, T2> *NewNode = new NodeT<T1, T2>(Node->key, Node->value);
	NewNode->isBlack = Node->isBlack;
	NewNode->parent = Node->parent;
	NewNode->left = DeepCopy(Node->left);
	NewNode->right = DeepCopy(Node->right);
	return NewNode;
}

template <typename T1, typename T2>
RedBlackTree<T1, T2>::RedBlackTree()
{
	this->root = nullptr;
	this->NoOfNodes = 0;
}

template<typename T1, typename T2>
RedBlackTree<T1, T2>::RedBlackTree(const RedBlackTree<T1, T2>& Obj)
{
	this->root = nullptr;
	this->NoOfNodes = 0;
	this->root = DeepCopy(Obj.root);
}

template<typename T1, typename T2>
RedBlackTree<T1, T2> RedBlackTree<T1, T2>::operator=(const RedBlackTree<T1, T2>& Obj)
{
	if(this != &Obj)
	{
		deleteTree(this->root);
		this->root = nullptr;
		this->NoOfNodes = 0;
		this->root = DeepCopy(Obj.root);
	}
	return *this;
}

template<typename T1, typename T2>
bool RedBlackTree<T1, T2>::insert(T1 Key_Parameter, T2 Value_Parameter)
{
	bool isInserted = false;
	NodeT<T1, T2> *Node = new NodeT<T1, T2>(Key_Parameter, Value_Parameter);
	Node->parent = nullptr;
	Node->left = nullptr;
	Node->right = nullptr;
	Node->isBlack = true;

	NodeT<T1, T2> *y = nullptr;
	NodeT<T1, T2> *x = this->root;

	while (x != nullptr) {
		y = x;
		if (Node->key < x->key) {
			x = x->left;
		}
		else if (Node->key > x->key)
		{
			x = x->right;
		}
		else
		{
			cout << "Error: Tree already contains " << Key_Parameter << endl;
			return isInserted;
		}
	}
	isInserted = true;
	this->NoOfNodes++;
	Node->parent = y;
	if (y == nullptr)
	{
		root = Node;
	}
	else if (Node->key < y->key)
	{
		y->left = Node;
	}
	else
	{
		y->right = Node;
	}

	if (Node->parent == nullptr) {
		Node->isBlack = false;
		return isInserted;
	}

	if (Node->parent->parent == nullptr) {
		return isInserted;
	}

	InsertFix(Node);
	return isInserted;
}

template<typename T1, typename T2>
bool RedBlackTree<T1, T2>::remove(T1 Key_Parameter)
{
	return DeleteNodeHelper(this->root, Key_Parameter);
}

template<typename T1, typename T2>
bool RedBlackTree<T1, T2>::search(T1 Key_Parameter)
{
	return SearchTreeHelper(this->root, Key_Parameter);
}

template<typename T1, typename T2>
vector<T2> RedBlackTree<T1, T2>::search(T1 Key_Parameter_1, T1 Key_Parameter_2)
{
	vector<T2> values;
	NodeT<T1, T2> *Temp = root;
	bool isKeys = false;
	HelpLNRforValues(Temp, Key_Parameter_1, Key_Parameter_2, values);
	return values;
}

template<typename T1, typename T2>
vector<T2> RedBlackTree<T1, T2>::values()
{
	vector<T2> values;
	NodeT<T1, T2> *Temp = root;
	bool isKeys = false;
	HelpLNRforValues(Temp, MinimumNode(Temp)->key, MaximumNode(Temp)->key, values);
	return values;
}

template<typename T1, typename T2>
vector<T1> RedBlackTree<T1, T2>::keys()
{
	vector<T1> keys;
	NodeT<T1, T2> *Temp = root;
	bool isKeys = true;
	HelpLNRforKeys(Temp, MinimumNode(Temp)->key, MaximumNode(Temp)->key, keys);
	return keys;
}

template<typename T1, typename T2>
int RedBlackTree<T1, T2>::size() const
{
	return this->NoOfNodes;
}

template<typename T1, typename T2>
NodeT<T1, T2>* RedBlackTree<T1, T2>::getRoot() const
{
	return root;
}

template<typename T1, typename T2>
void RedBlackTree<T1, T2>::print()
{
	if (root) {
		PrintHelper(this->root, "", true);
	}
}

template <typename T1, typename T2>
RedBlackTree<T1, T2>::~RedBlackTree()
{
	deleteTree(this->root);
	this->root = nullptr;
	this->NoOfNodes = 0;
}
