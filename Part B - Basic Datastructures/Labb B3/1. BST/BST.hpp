#ifndef BST_HPP
#define BST_HPP

#include <string>
#include <stdexcept>

template <class T>
class BST {
private:
    class Node {
    public:
        T data;
        Node* left;
        Node* right;
        Node* parent; // Is not required to be used if using a recursive approach.
        // If you are using an iterative approach, it is beneficial to use a parent pointer.

        Node(int val) : data(val), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    Node* root;
    Node* insertRec(Node* node, T element);
    void inOrderTraversalHelper(Node* node, std::string& result);
    void preOrderTraversalHelper(Node* node, std::string& result);
    void postOrderTraversalHelper(Node* node, std::string& result);
    Node* removeRec(Node* node, T element);
    Node* minValueNode(Node* node);
    
public:
    BST();

    void insert(T element);

    T getMin();

    T find(T element);

    void remove(T element);

    std::string inOrderTraversal();

   

    std::string preOrderTraversal();

    std::string postOrderTraversal();

    std::string toGraphviz();
    std::string toGraphvizRec(std::string data, Node* current, int& nodeID);

   
};

template <class T>
BST<T>::BST() : root(nullptr)
{

}
template <class T>
void BST<T>::insert(T element) {

    this->root = insertRec(this->root, element);
}


template <class T>
typename BST<T>::Node* BST<T>::insertRec(Node* node, T element) {

    // Basfall: noden pekara på en tom plats, skapa en ny nod
    if (node == nullptr) {
        return new Node(element);
    }

    if (element < node->data)
    {
        //Choose left
        node->left = insertRec(node->left, element);
    }
    else if (element > node->data)
    {
        node->right = insertRec(node->right, element);
    }
    return node;
}


template <class T>
T BST<T>::getMin() {

    Node* current = this->root;

    if (current == nullptr) {
        throw std::runtime_error("Attempt to get minimum from an empty tree.");
    }



    while (current->left != nullptr)
    {
        current = current->left;
    }
    
   

    return current->data;
}

template <class T>
T BST<T>::find(T element)
{
    Node* current = this->root;
    if (current == nullptr)
    {
        throw std::runtime_error {"Find() called on empty array"};
    }
    
    while (current != nullptr)
    {
        if (element < current->data)
        {
            current = current->left;
        }else if (element > current->data) {
            current = current->right;
        }
        else {
            return current->data;  // Element found
        }
    }

    throw std::runtime_error("Element not found in the BST");
}

template <class T>
void BST<T>::remove(T element) {
    root = removeRec(root, element);
}

template <class T>
typename BST<T>::Node* BST<T>::removeRec(Node* node, T element) {
    
    // find the node in question

    if (node == nullptr)
    {
        // element not found
        return node;
    }
    if (element < node->data)
    {
        //go left
        node->left = removeRec(node->left, element);
    }
    else if (element > node->data)
    {
        // go right
        node->right = removeRec(node->right, element);
    }
    else {
        // Node with only one child or no child
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        // Node with two children: Get the inorder successor (smallest in the right subtree)
        Node* temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = removeRec(node->right, temp->data);
    }
    return node;
}

template <class T>
typename BST<T>::Node* BST<T>::minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr) {
        current = current->left; // Move to the leftmost node
    }
    return current;
}

template <class T>
std::string BST<T>::inOrderTraversal() {
    // Create a string and add elements in order and separated by space.
    // i.e. a BST inserted with values 1, 2 and 3 becomes the following string
    // '1,2,3,
    std::string result;
    inOrderTraversalHelper(this->root,result);

    return result;

}

template <class T>
void BST<T>::inOrderTraversalHelper(Node* node, std::string& result) {
    if (node == nullptr) {
        return;  // Base case: if the node is null, simply return.
    }
    inOrderTraversalHelper(node->left, result);   // Visit left subtree
    result += std::to_string(node->data) + ",";  // Process current node
    inOrderTraversalHelper(node->right, result);  // Visit right subtree
}

template <class T>
std::string BST<T>::preOrderTraversal() {
    // Create a string and add elements pre order and separated by space.
    // i.e. a BST inserted with values 1, 2 and 3 becomes the following string
    // '1,2,3,'

    std::string result;
   
    preOrderTraversalHelper(this->root, result);
    return result;
}

template <class T>
void BST<T>::preOrderTraversalHelper(Node* node, std::string& result) {
 
 
    if (node == nullptr)
    {
        //The node is null just return since threre are no value here.
        return;
    }
    
    //Visit/proccess the root.
    result += std::to_string(node->data) + ",";

    //Traverse the left subtree, i.e., call Preorder(left->subtree)
    preOrderTraversalHelper(node->left, result);

    //Traverse the right subtree, i.e., call Preorder(right->subtree)
    preOrderTraversalHelper(node->right, result);

}

template <class T>
std::string BST<T>::postOrderTraversal() {
    // Create a string and add elements post order and separated by space.
    // i.e. a BST inserted with values 1, 2 and 3 becomes the following string
    // '3,2,1,'

    std::string result;

    postOrderTraversalHelper(this->root, result);
    return result;
}

template <class T>
void BST<T>::postOrderTraversalHelper(Node* node, std::string &result)
{

    if (node == nullptr)
    {
        //base case
        return;

    }

    //Traverse the left subtree, i.e., call Postorder(left->subtree)
    postOrderTraversalHelper(node->left, result);
    
   
    //Traverse the right subtree, i.e., call Postorder(right->subtree)
    postOrderTraversalHelper(node->right, result);
    //Visit the root
    result += std::to_string(node->data) + ",";
}

template <class T>
std::string BST<T>::toGraphviz()
{
    int nodeID = 0;
    std::string data = "";
    if (root != nullptr)
    {
        data += "digraph {\n";
        data += "\tRoot [shape=plaintext];\n";
        data += "\t\"Root\" -> 0 [color=black];\n";
        data = toGraphvizRec(data, this->root, nodeID);
        data += "}\n";
    }
    return data;
}

template <class T>
std::string BST<T>::toGraphvizRec(std::string data, Node* current, int& nodeID)
{
    int my_nodeID = nodeID;
    data += "\t" + std::to_string(my_nodeID) + " [label=\"" + std::to_string(current->data) + "\"];\n";
    nodeID++;
    if (current->left != nullptr)
    {
        data += "\t" + std::to_string(my_nodeID) + " -> " + std::to_string(nodeID) + " [color=blue];\n";
        data = toGraphvizRec(data, current->left, nodeID);
    }
    else
    {
        data += "\t" + std::to_string(nodeID) + " [label=nill,style=invis];\n";
        data += "\t" + std::to_string(my_nodeID) + " -> " + std::to_string(nodeID) + " [style=invis];\n";
    }
    nodeID++;
    if (current->right != nullptr)
    {
        data += "\t" + std::to_string(my_nodeID) + " -> " + std::to_string(nodeID) + " [color=red];\n";
        data = toGraphvizRec(data, current->right, nodeID);
    }
    else
    {
        data += "\t" + std::to_string(nodeID) + " [label=nill,style=invis];\n";
        data += "\t" + std::to_string(my_nodeID) + " -> " + std::to_string(nodeID) + " [style=invis];\n";
    }
    return data;
}

#endif