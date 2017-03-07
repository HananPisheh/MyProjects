#include "BinSearchTree.hpp"
#include "TreeNode.hpp"
#include <iostream>
#include <queue>
/*
  Author: Hanan Sedaghat Pisheh
  Course: CS 315
  Assignment: Lab 4 Part C
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
  if(root==nullptr) return false;
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
 return inorderDump(root);
}

int BinSearchTree::maxDepth(){
  return maxDepth(root);
}

int BinSearchTree::maxDepth(TreeNode *root){
  if (root==nullptr) return 0 ;

  int l =  maxDepth(root->leftSubtree());

  int r= maxDepth(root->rightSubtree());
  return (l > r) ? l+ 1 : r + 1;

}

void BinSearchTree::levelOrderDump(TreeNode * root){
  if (root==nullptr) return;
  queue<TreeNode*>Q;
  Q.push(root);
  while(! Q.empty()){
    TreeNode *croot=Q.front();
    cout<<croot->value()<<" ";
    if(croot->leftSubtree() != nullptr) Q.push(croot->leftSubtree());
    if(croot->rightSubtree() != nullptr) Q.push(croot->rightSubtree());
    Q.pop();
  }
}

void BinSearchTree::levelOrderDump(){
   levelOrderDump( root);  
}

TreeNode* BinSearchTree:: remove( int v ,TreeNode * root){
  if(root==nullptr) return root;
  else if(v < root->value()) root->leftSubtree(remove(v,root->leftSubtree()));
  else if(v > root->value()) root->rightSubtree(remove(v,root->rightSubtree()));
  else// found it
    {
      bool left=root->leftSubtree()!=NULL;
      bool right=root->rightSubtree()!=NULL;
      //case1:no children
      if(!left && !right){
	delete root;
	root=NULL;
	return root;}
      //case2: 1 child
      else if(right && !left){
	TreeNode* tmp=root;
	root=root->rightSubtree();
	delete tmp;

	 }
      else if(!right && left){
	TreeNode* tmp=root;
	root=root->leftSubtree();
	delete tmp;
      }

      else{

	TreeNode* tmp=smallest(root->rightSubtree());
	root->value()=tmp->value();
	root->rightSubtree(remove(tmp->value(),root->rightSubtree()));
      }
 
    }

     return root;

						}
bool BinSearchTree:: remove( int v ){
  if (find(v)==1){
     remove(v , root);
     return true;}
  else
    return false;
}




TreeNode *BinSearchTree::smallest(){
  return smallest(root);
}
TreeNode *BinSearchTree:: smallest(TreeNode * root){
  //int tmp;
  //tmp=root->value();
  while(root->leftSubtree() != NULL )
    root=root->leftSubtree();
  return root;
  
  }
int BinSearchTree::kthSmallest(int k, TreeNode * root){

  if(k>size(root)) {cout<<"ERRoR for unacceptable K";
    return 0;}
  else{
  if(k > size(root->leftSubtree())){
  k=k-size(root->leftSubtree())-1;
  if(k==0) return root->value();
  return kthSmallest(k,root->rightSubtree());
  }

  
  else if(k ==size(root->leftSubtree()) || k == size(root->rightSubtree()) ){
    return root->leftSubtree()!=NULL? kthSmallest(k,root->leftSubtree()): kthSmallest(k,root->rightSubtree());
  }
  
    
  else if (k<size(root->leftSubtree())){
   return kthSmallest(k,root->leftSubtree());}
  }}

int BinSearchTree::kthSmallest( int k ){  
  return kthSmallest( k , root); }

void BinSearchTree::valuesAtLevel( int k , TreeNode* root, int n){
  if(n==k){
    cout<<root->value()<<"   ";
    return;}
  if(root->rightSubtree() !=nullptr)
    valuesAtLevel(k,root->rightSubtree(),n+1);
  if(root->leftSubtree() !=nullptr)
    valuesAtLevel(k,root->leftSubtree(),n+1);
  return;
}
void BinSearchTree::valuesAtLevel( int k ){
  int n=1;
  return valuesAtLevel(k, root, n ); 
}
void BinSearchTree::iterValuesAtLevel( int k , TreeNode* root){
  int n=1;
  if(!root) return;
  queue<TreeNode*> curr,next;
  curr.push(root);
  while(!curr.empty()){
    TreeNode *tmp=curr.front();
    curr.pop();
    if(tmp){
      if(n==k){
	cout<<tmp->value()<<" ";}
      next.push(tmp->leftSubtree());
      next.push(tmp->rightSubtree());
    }
    if(curr.empty()){
      cout<<endl;
      swap(curr,next);
      n++;
    }
  }
} 
void BinSearchTree::iterValuesAtLevel( int k ){
return iterValuesAtLevel(k, root );} 
  
int BinSearchTree::iterMaxDepth(TreeNode *root) {
    if (!root) return 0;
    queue<TreeNode*> s;
    s.push(root);
    int maxDepth = 0;
    TreeNode *prev = NULL;
    while (!s.empty()) {
      TreeNode *curr = s.back();
      if (!prev || prev->leftSubtree() == curr || prev->rightSubtree() == curr) {
	if (curr->leftSubtree())
	  s.push(curr->leftSubtree());
	else if (curr->rightSubtree())
	  s.push(curr->rightSubtree());
      }
      else if (curr->leftSubtree() == prev) {
	if (curr->rightSubtree())
	  s.push(curr->rightSubtree());
      } else {
	s.pop();
      }
      prev = curr;
      if (s.size() > maxDepth)
	maxDepth = s.size();
    }
    return maxDepth;
  }
  
int BinSearchTree::iterMaxDepth(){
  return iterMaxDepth(root);
}

bool BinSearchTree::hasRootToLeafSum( int sum , TreeNode * root){
  int subsum;
  
  if(root==NULL) return false;
    
  if ((root->rightSubtree()==nullptr) && (root->leftSubtree()==nullptr)){  

    return (sum-(root->value()) ==0);
  }
  
  else{
    int subsum=sum-(root->value());
    return (hasRootToLeafSum(subsum,root->leftSubtree()) or hasRootToLeafSum(subsum,root->rightSubtree()));

  }
  }
bool BinSearchTree::hasRootToLeafSum( int sum ){
  return hasRootToLeafSum(sum , root );
}

bool BinSearchTree::areIdentical( TreeNode* root , TreeNode* bst){
  if(size(root) != size(bst)) return false;
  else{
    if(root==NULL && bst==NULL)
      return true;
    if(root->value() == bst->value()){
      return areIdentical(root->rightSubtree(),bst->rightSubtree())&&
	areIdentical(root->leftSubtree() , bst->leftSubtree());      

    }
    }
  return false;
  }
bool BinSearchTree::areIdentical(  BinSearchTree *bst ){
  return areIdentical( root ,bst->root);
}
BinSearchTree* BinSearchTree::intersectWith(TreeNode* root , TreeNode *bst ,BinSearchTree* common){
    if(root==NULL || bst ==NULL){return NULL;}
  if(root->value() == bst->value()){
    common->insert(root->value());
    //common=local_insert( common , root->value() );
    //cout<<root->value();
    // common->inorderDump();
    intersectWith( root->rightSubtree(),bst->rightSubtree(),common);
    intersectWith( root->leftSubtree(),bst->leftSubtree(), common);
    }
    else if (root->value() < bst->value())
    intersectWith( root,bst->leftSubtree(),common);
  else
    intersectWith( root->leftSubtree(),bst,common);
  //common->insert(root->value());
  //  cout<<"AKHar";
  return common;
}

BinSearchTree* BinSearchTree::intersectWith( BinSearchTree *bst ){
  BinSearchTree* common = new BinSearchTree();
  return intersectWith( root , bst->root, common);
}

BinSearchTree * BinSearchTree::unionWith(TreeNode* root , BinSearchTree *bst ){
  
  // BinSearchTree* uni = new BinSearchTree;
  if(root==NULL)
    return bst;
  else{
    //unionWith(root,bst->value());
    unionWith(root->leftSubtree(),bst);
    bst->insert(root->value());
    unionWith(root->rightSubtree(),bst);
    return bst;
    }
}
BinSearchTree * BinSearchTree::unionWith( BinSearchTree *bst ){
  return unionWith( root , bst);}

BinSearchTree *BinSearchTree::differenceOf(TreeNode* root , TreeNode *bst, BinSearchTree* common ){
  if(root==NULL){ return common;}
  if(! find(bst,root->value())) {
      common->insert(root->value());
    // common->inorderDump();
      //cout<<root->value()<<"  ";
     }
    differenceOf( root->rightSubtree(),bst,common);
    differenceOf( root->leftSubtree(),bst, common);
    
   return common; 

  
   }
BinSearchTree *BinSearchTree::differenceOf( BinSearchTree *bst ){

  BinSearchTree* common = new BinSearchTree();
  return differenceOf( root , bst->root, common);}

BinSearchTree::~BinSearchTree()
{ removeSubtree(root); }

void BinSearchTree::removeSubtree(TreeNode* root){
  if (root !=NULL)
    {
      if( root->leftSubtree() !=NULL)
	removeSubtree(root->leftSubtree());
      if( root->rightSubtree() !=NULL)
	removeSubtree(root->rightSubtree());
      delete root;
      }
}
  
