#include "BinSearchTree.hpp"
#include "TreeNode.hpp"
#include <iostream>
//#include "TreeNode.hpp"
/*
  Author: Hanan Sedaghat Pisheh
  Course: CS 315
  Assignment: Lab 4 Part B
*/
using namespace std;

TreeNode *BinSearchTree::local_insert( TreeNode *root, int v ) {
  if( root == nullptr )
    return new TreeNode( v );
  if( root->value() < v )
    root->rightSubtree( local_insert( root->rightSubtree(), v ) );
  else
    root->leftSubtree( local_insert( root->leftSubtree(), v ) );


  return root;
}

void BinSearchTree::insert(int v) {
    if( ! find(v) )
  root = local_insert( root, v );
}

bool BinSearchTree::find( int v ){
  return find( root , v);
    }

bool BinSearchTree::find(TreeNode * root , int v ){
  
  if(root==nullptr)
    return false;
  if(root->value()==v)
      return true;
  if( root->value() < v ){
    return find(root->rightSubtree(), v);}
  if( root->value() > v ){
    return find(root->leftSubtree(),v);}
}
bool BinSearchTree::iterFind( int v ){
  //   if(root==nullptr) return false;
TreeNode* tree= root;
    while(tree!=nullptr){
    if(tree->value()==v)
      return true;
    if(tree->value()<v)
      tree=tree->rightSubtree();
    else if(tree->value() > v)
    tree=tree->leftSubtree();    
    } 
  return false;
  }

int BinSearchTree::size(TreeNode* root){
  if(root==nullptr)
    return 0;
  
  return 1+size(root->rightSubtree())+size(root->leftSubtree());


}

int BinSearchTree::size(){
  return size(root);}
     
void BinSearchTree::inorderDump(TreeNode *root){
  if( root == nullptr)
    return;
  inorderDump(root->leftSubtree());
  cout<<root->value()<<endl;
  inorderDump(root->rightSubtree());
  //cout<<root->value()<<endl;;
}
void BinSearchTree::inorderDump(){
  /*   
  int val= root->value();
  if( root->rightSubtree() != nullptr || root->rightSubtree()->value() < val )
    { val= root->rightSubtree()->value();
      return inorderDump();}
  if ((root->rightSubtree()==nullptr) || ( root->rightSubtree()->value() > val ))
    cout<<root->rightSubtree()->value()<<endl;
  if((root->leftSubtree() != nullptr  )||( root->leftSubtree()->value() > val )){
    cout<<root->leftSubtree()->value()<<endl;
    val= root->leftSubtree()->value();
    return inorderDump();}
    if(root->leftSubtree()==nullptr)
      cout<<"end"<<endl;
      }
 
  */
  return inorderDump(root);
}
int BinSearchTree::maxDepth(){
  return maxDepth(root);
}
int BinSearchTree::maxDepth(TreeNode *root){
  if (root==nullptr) return 0;
  
  int l =  maxDepth(root->leftSubtree());
  
  int r= maxDepth(root->rightSubtree());
  return (l > r) ? l+ 1 : r + 1;

}

