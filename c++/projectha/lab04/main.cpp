
/*
  Author: Hanan sedaghat pisheh
  Course: CS 315
  Assignment: Lab 4 Part B
*/  

#include <iostream>
#include "TreeNode.hpp"
#include "BinSearchTree.hpp"
using namespace std;
int main( int argc, char *argv[] ) {
  // create a tree and then print the values of its nodes
  // from the smallest to the largest.

  BinSearchTree *tree = new BinSearchTree();

  int v;
  while( cin >> v ) {
    tree->insert( v );
  }
  
 
 //cout<<tree->iterFind(5)<<endl;
 //cout<<tree->iterFind(0)<<endl;
 //cout<<tree->iterFind(7)<<endl;
 //cout<<tree->maxDepth()<<endl;
  //  tree->insert(17);
 tree->inorderDump();
 cout<<tree->size()<<endl;
 return 0;
}
