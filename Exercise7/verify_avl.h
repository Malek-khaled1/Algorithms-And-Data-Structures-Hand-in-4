#pragma once
#include "avl_tree.h"

template<typename Comparable>
bool verify_avl(AvlTree<Comparable>::AvlNode* node, int &height){


    if (node == nullptr)
    {
        height = -1;
        return true;
    }
    
    
    int left_height;
    int right_height;

    bool leftValid = verify_avl(node->left, left_height);
    bool rightValid = verify_avl(node->right, right_height);

    bool balanced = abs(left_height - right_height) <= 1;
    height = max(left_height, right_height) + 1;

    if (node->height != height)
    {
        return false;
    }
    

    return leftValid && rightValid && balanced;

}