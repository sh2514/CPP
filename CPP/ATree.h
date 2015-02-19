/* ==================================================
Arbitrary Tree
Shikuan Huang

Left child is descendant
Right child is sibling

***
DESTRUCTOR
COPY CONSTRUCTOR
ASSIGNMENT
================================================== */

#include <iostream>
using namespace std;

template <typename T>
class ATree {
private:
  T value;
  ATree<T> * left;
  ATree<T> * right;
  bool empty;
  
  ATree<T>(T initialItem) {
  	value = initialItem;
  	left = NULL;
  	right = NULL;
  	empty = false;
  }
  
  // Insert "itemToInsert" at level "argTreelevel"
  bool insert(T itemToInsert, int argTreeLevel, bool rootLevel) {
  	if (rootLevel && empty) {
  	  value = itemToInsert;
  	  empty = false;
  	  return true;
  	}
  	// When inserting too far down the tree where the levels in between does not have nodes
    else if (argTreeLevel > 1 && left == NULL) {
	  return false;
	}	
	// When we haven't reached the level to insert and there IS a descendant
	else if (argTreeLevel != 0 && left != NULL) {
	  return left->insert(itemToInsert, argTreeLevel - 1, false);
	}
	// When we haven't reached the level to insert and there IS NO descendant
	else if (argTreeLevel != 0 && left == NULL) {
	  left = new ATree<T>(itemToInsert);
	  return true;	
	}
		
	// When we have reached the level to insert
	ATree<T> * currentNode = this;

	while (currentNode->right != NULL) {
	  currentNode = currentNode->right;
	}
	
    // Insert by creating a new node
    currentNode->right = new ATree<T>(itemToInsert);
	
	return true;
  }
  
public:
  ATree<T>() {
  	left = NULL;
  	right = NULL;
  	empty = true;
  }
  
  // Insert "itemToInsert" at level "treeLevel"
  bool insert(T itemToInsert, int treeLevel = 0) {
  	if (treeLevel < 0) {
  	  return false;
  	}
  	else if (treeLevel == 0) {
      return insert(itemToInsert, treeLevel, true);
   	}
    else {
      return insert(itemToInsert, treeLevel, false);
  	}
  }
  
  // Remove "itemToInsert" from the tree if found
  bool remove(T itemToRemove) {
  	if (empty) {
  	  return false;
  	}
  	  
  	ATree<T> * previousNode = NULL;
  	ATree<T> * beginningNodeAtLevel = this;
  	do {
  	  ATree<T> * currentNodeAtLevel = beginningNodeAtLevel;
  	  do {
  	  	// When "itemToDelete" is found
  	  	if (currentNodeAtLevel->value == itemToRemove) {
  	      ATree<T> * nodeToDelete = currentNodeAtLevel;
  	  	  // "itemToDelete" is replaced by sibling
  	  	  if (currentNodeAtLevel->right != NULL) {
  	      	if (previousNode == NULL) {
  	      	  nodeToDelete = currentNodeAtLevel->right;	
  	      	  
  	      	  currentNodeAtLevel->value = currentNodeAtLevel->right->value;
  	      	  currentNodeAtLevel->empty = currentNodeAtLevel->right->empty;
		  	  currentNodeAtLevel->right = currentNodeAtLevel->right->right;
		  	  
		  	  if (currentNodeAtLevel->left != NULL) {
			    currentNodeAtLevel->left = currentNodeAtLevel->right->left;
			  }
		  	  
		  	  nodeToDelete->right = NULL;
		  	  nodeToDelete->left = NULL;
  	      	}
  	      	else {
  	      	  previousNode->right = currentNodeAtLevel->right;
  	      	  currentNodeAtLevel->right = NULL;
  	        }
		  }
		  // "itemToDelete" is replaced by descendant
		  else if (currentNodeAtLevel->left != NULL) {
		  	// When removing the root
		  	if (previousNode == NULL) {
		  	  nodeToDelete = currentNodeAtLevel->left;
		  	  
		  	  currentNodeAtLevel->value = currentNodeAtLevel->left->value;
		  	  currentNodeAtLevel->empty = currentNodeAtLevel->left->empty;
		  	  currentNodeAtLevel->right = currentNodeAtLevel->left->right;
		  	  currentNodeAtLevel->left = currentNodeAtLevel->left->left;
		  	  
		  	  nodeToDelete->right = NULL;
		  	  nodeToDelete->left = NULL;
		  	}
		  	else {
		  	  previousNode->left = currentNodeAtLevel->left;
		  	  currentNodeAtLevel->left = NULL;
		    }
		  }
		  // "itemToDelete" does not have a sibling or descendant
		  else {
		  	// When removing the root
			if (previousNode == NULL) {
				empty = true;
				return true;
			}
		  	else if (previousNode->left->value == currentNodeAtLevel->value) {
			  previousNode->left = NULL;
			}
		  	else {
		  	  previousNode->right = NULL;
		  	}
		  }
		  delete nodeToDelete;
		  return true;
  	  	}
  	  	previousNode = currentNodeAtLevel;
  	  	currentNodeAtLevel = currentNodeAtLevel->right;
  	  } while(currentNodeAtLevel != NULL);
  	  previousNode = beginningNodeAtLevel;
  	  beginningNodeAtLevel = beginningNodeAtLevel->left;
  	} while(beginningNodeAtLevel != NULL);
  }
  
  // Returns the number of nodes in the tree
  int size() const {
  	int numberOfNodes = 0;
  	const ATree<T> * beginningNodeAtLevel = this;
    do {
      const ATree<T> * currentNodeAtLevel = beginningNodeAtLevel;
      do {
        if (!(currentNodeAtLevel->empty))
        {
          numberOfNodes++;
        }
        
        currentNodeAtLevel = currentNodeAtLevel->right;
      } while(currentNodeAtLevel != NULL);
      beginningNodeAtLevel = beginningNodeAtLevel->left;
    } while(beginningNodeAtLevel != NULL);
    
    return numberOfNodes;
  }
  
  void printTree() const {
  	if (empty) {
  	  return;
    }
  	  
  	const ATree<T> * beginningNodeAtLevel = this;
  	do {
  	  // Print all nodes at current level of tree
  	  const ATree<T> * currentNodeAtLevel = beginningNodeAtLevel;
  	  do {
  	    cout << currentNodeAtLevel->value << " ";
  	    currentNodeAtLevel = currentNodeAtLevel->right;
      } while(currentNodeAtLevel != NULL);
  	  cout << endl;
  	  
  	  // Proceed to next level of tree
  	  beginningNodeAtLevel = beginningNodeAtLevel->left;
    } while(beginningNodeAtLevel != NULL);
  }
};

template<typename T>
ostream & operator<<(ostream & output, const ATree<T> & treeToPrint) {
  treeToPrint.printTree();
  return output;	
}
