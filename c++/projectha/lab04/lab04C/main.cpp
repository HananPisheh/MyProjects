/*
  Author: Hanan sedaghat pisheh
  Course: CS 315
  Assignment: Lab 4 Part C
*/  

#include <iostream>
#include "TreeNode.hpp"
#include "BinSearchTree.hpp"
using namespace std;
int main( int argc, char *argv[] ) {
  // create a tree and then print the values of its nodes
  // from the smallest to the largest.

  BinSearchTree *tree = new BinSearchTree();
  BinSearchTree *bst = new BinSearchTree();

  int v;
  while( cin >> v ) {
    tree->insert( v );
    bst->insert(v);
  }
  /*
  cout<<"levelOrderDump():"<< endl;
   tree->levelOrderDump();

  

  cout << "Kthsmallest 5 esh: ";  
  cout<< tree->kthSmallest(5);
  cout << "Kthsmallest 1 esh: ";
  cout<<tree->kthSmallest(1);
  

  
  cout<<"valuesAtLevel(4 ):"<<endl;
  tree->valuesAtLevel( 4 );
  cout<<"valuesAtLevel(1 ):"<<endl;
  tree->valuesAtLevel( 1 );
  


  cout<<"iterValuesAtLevel  (4 ):"<<endl;
 tree->iterValuesAtLevel  ( 4 );
 cout<<"iterValuesAtLevel  (1 ):"<<endl;
 tree->iterValuesAtLevel  ( 1 );

 cout<<"iterMaxDepth:"<<endl; 
 cout<< tree->iterMaxDepth();

  
  cout<<"hasRootToLeafSum yes:  "<<tree->hasRootToLeafSum(27);
 cout<<"hasRootToLeafSum no:  "<<tree->hasRootToLeafSum(10);



 cout<<"intersectWith";
 tree->intersectWith(bst)->levelOrderDump();


  */ 
  cout<<endl<<endl;
  cout<<"unionWith : "<<endl;
  tree->unionWith(bst)->levelOrderDump();
  cout<<endl;
  bst->insert(88);
  /*
  tree->insert(999);
  cout<<"diffrence of : "<<endl;
  tree->differenceOf(bst)->levelOrderDump();
  

  cout<<"are identical???:  "<<tree->areIdentical(bst);



  cout<<"remove():"<<endl;
  cout<<"remove(8):"<<endl;
  tree->remove(8);
  tree->levelOrderDump();
  cout<<"remove(1):"<<endl;
  tree->remove(1);
  tree->levelOrderDump();
  cout<<"remove(18):"<<endl;
  tree->remove(18);
  tree->levelOrderDump();
  
  */

  return 0;
}
