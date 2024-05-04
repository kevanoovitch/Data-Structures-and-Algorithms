#include <iostream>
#include "BST.hpp"

int main()
{

    try
    {
        BST<int> MyBST;

        
        
        MyBST.insert(8);
        MyBST.insert(4);
        MyBST.insert(2);
        MyBST.insert(1);
        MyBST.insert(3);
        MyBST.insert(6);
        MyBST.insert(7);
        MyBST.insert(5);
        
        MyBST.remove(7);

        std::cout << MyBST.inOrderTraversal() << " Expected 1, 2, 3, 4" << std::endl;
        std::cout << MyBST.preOrderTraversal() << " Expeced 4, 3, 2, 1" << std::endl;
        std::cout << MyBST.postOrderTraversal() << " Expected 1, 2, 3, 4" << std::endl;

        std::cout << MyBST.toGraphviz();  //copy paste this cout to "https://dreampuf.github.io/GraphvizOnline/"
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    

}

