/* ==================================================
Binary Search Tree
Shikuan Huang

Preorder, Inorder, Postorder tree traversal
Depth First Search
Overloaded stream insertion operator
================================================== */

#include <iostream>
#include <list>
using namespace std;
using std::list;

template <typename T>
class BST
{
private:
	T value;			// value contained in node
	bool empty;			// whether node has a value
	BST<T> * left;		// left child
	BST<T> * right;		// right child
	int numberOfElements;
	
	// Called by overloaded "insert"
	bool insert(T arg, BST * parent)
	{
		if (empty)
		{
			value = arg;
			empty = false;
			return true;
		}	
		else if (arg < value)
		{
			if (left == NULL)
				left = new BST();	
			return left->insert(arg, this);
		}
		else
		{
			if (right == NULL)
				right = new BST();
			return right->insert(arg, this);	
		}
	}
	
	// Called by overloaded "remove"
	bool remove(T arg, BST * parent)
	{
		if (empty)									// Removing from an empty tree
			return false;
			
		if (value == arg)							// Found item to remove
		{				
			BST<T> ** edge = NULL;
			if (parent != NULL)
			{
				if (parent->left != NULL && parent->left->value == value)
				{
					edge = &(parent->left);	
				}
				else
				{
					edge = &(parent->right);
				}
			}
			
			BST * temp = this;
			if (left != NULL && right != NULL)		// Removing node with two children
			{
				BST<T> * nextItemParent = NULL;
				BST<T> * nextItem = findNextItem(this, nextItemParent);
				value = nextItem->value;
				return nextItem->remove(value, nextItemParent);
			}
			else if (left != NULL)					// Removing node with a left child
			{
				if (parent != NULL)
					*edge = left;
			}
			else if (right != NULL)					// Removing node with a right child
			{
				if (parent != NULL)
					*edge = right;
			}
			else
			{
				if (parent != NULL)
					*edge = NULL;
			}
			temp->left = NULL;
			temp->right = NULL;
			if (parent != NULL)
				delete temp;
			else
				empty = true;
			return true;
		}
		else if (arg < value)						// If item to remove is less than current node's value
		{	
			if (left != NULL)
				return left->remove(arg, this);
			else
				return false;
		}
		else 										// If item to remove is greater than current node's value
		{
			if (right != NULL)
				return right->remove(arg, this);
			else
				return false;
		}
	}
	
	// Returns a pointer to the next node in order in the tree
	BST<T> * findNextItem(BST<T> * me, BST<T> * & myParent) const
	{
		myParent = me;
		BST<T> * temp = me->right;
		while (temp->left != NULL)
		{
			myParent = temp;
			temp = temp->left;	
		}
		return temp;
	}
	
public:
	// Default Constructor
	BST()
	{
		left = NULL;
		right = NULL;
		value = T();
		empty = true;
		numberOfElements = 0;
	}
	
	BST(T arg)
	{
		left = NULL;
		right = NULL;
		value = arg;
		empty = false;
	    numberOfElements = 1;
	}
	
	// Copy Constructor
	BST(const BST<T> & arg)
	{
		copyHelper(&arg, this);
	}
	
	// Assignment Operator
	BST<T> & operator=(const BST<T> & arg)
	{	
		// Check for self-assignment
		if (&arg == this)
			return *this;
	
		this->~BST();
		
		copyHelper(&arg, this);
		return *this;
	}
	
	// Recursively copy the binary search tree
	void copyHelper(const BST<T> * from, BST<T> * to)
	{
		if (from->empty)
		{
			to->empty = from->empty;
			to->numberOfElements = from->numberOfElements;
			to->left = NULL;
			to->right = NULL;
			return;
		}
		
		to->value = from->value;
		to->empty = from->empty;
		to->numberOfElements = from->numberOfElements;
		
		if (from->left != NULL)
		{
			to->left = new BST();
			copyHelper(from->left, to->left);
		}
		else
			to->left = NULL;
			
		if (from->right != NULL)
		{
			to->right = new BST();
			copyHelper(from->right, to->right);
		}
		else
			to->right = NULL;
	}
	
	// Destructor
	~BST()
	{
		delete left;
		delete right;
		left = NULL;
		right = NULL;
	}
	
	// Prints the value in the BST node
	void print() const
	{
		if (!empty)
			cout << value;	
		else
			cout << "NULL";
	}

	void printPreorder() const
	{
		if (!empty)
		{
			cout << value << " ";
			if (left != NULL)
				left->printPreorder();
			if (right != NULL)
				right->printPreorder();
		}
	}
	
	void printInorder() const
	{
		if (!empty)
		{
			if (left != NULL)
				left->printInorder();
			cout << value << " ";
			if (right != NULL)
				right->printInorder();	
		}
	}
	
	void printPostorder() const
	{
		if (!empty)
		{
			if (left != NULL)
				left->printPostorder();
			if (right != NULL)
				right->printPostorder();
			cout << value << " ";	
		}
	}
	
	// Print tree in breadth first search fashion
	void printBFS(bool head = 1) const
	{
		if (empty)
			return;
		
		list<BST *> bfsQueue;
		bfsQueue.push_back(this);
		
		BST * temp;
		
		while(!bfsQueue.empty())
		{
			temp = bfsQueue.front();
			bfsQueue.pop_front();
			cout << temp->value << " ";
			if (temp->left != NULL)
				bfsQueue.push_back(temp->left);
			if (temp->right != NULL)
				bfsQueue.push_back(temp->right);
		}
	}
	
	// Insert an item into the BST
	bool insert(T arg)
	{
		bool result = insert(arg, NULL);
		if (result)		// If properly inserted
		{
			numberOfElements++;
			return result;	
		}
		return result;
	}
	
	// Remove an item from the BST
	bool remove(T arg)
	{
		bool result = remove(arg, NULL);
		if (result)
		{
			numberOfElements--;
			return result;	
		}
		return result;
	}
	
	// Returns the number of elements in the BST
	int size() const
	{
		return numberOfElements;
	}
	
	// Overloaded equality - All nodes contain the same elements in the same positions
	bool operator==(const BST<T> & arg) const
	{
		if (value != arg.value)
			return false;
		
		bool left = false;
		bool right = false;
		
		// recursively check left
		if (this->left == NULL && arg.left == NULL)
			left = true;
		else if (this->left != NULL && arg.left != NULL)
			left = *(this->left) == *(arg.left);
		else
			left = false;
		
		// recursively check right
		if (this->right == NULL && arg.right == NULL)
			right = true;
		else if (this->right != NULL && arg.right != NULL)
			right = *(this->right) == *(arg.right);
		else
			right = false;
		
		return left && right;
	}
};


// Overloaded Stream Insertion Operator
template <typename T>
ostream & operator<<(ostream& output, const BST<T> & arg)
{
	arg.printBFS();
	return output;	
}
