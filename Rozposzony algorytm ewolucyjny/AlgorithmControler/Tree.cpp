#include "Tree.hpp"
namespace AlgorithmControler{
TreeNode::TreeNode(void)
{
	balance=0;
	parent=NULL;
}



TreeNode::~TreeNode(void)
{
}

void TreeNode::prepareToRun()
{
	
	if(lChild.get()!=NULL)
		lChild->prepareToRun();
	if(rChild.get()!=NULL)
		rChild->prepareToRun();

	Conections con;
	if(parent!=NULL)
		con.parent=parent->getEndPoint();
	if(lChild.get()!=NULL)
		con.lChild=lChild->getEndPoint();
	if(rChild.get()!=NULL)
		con.rChild=rChild->getEndPoint();

	setConections(con);	

}

void TreeNode::runNode()
{

runAlgorithm();
	if(lChild.get()!=NULL)
		lChild->runNode();
	if(rChild.get()!=NULL)
		rChild->runNode();

	

}


void TreeNode::addNode(TreeNodePtr node)
{
	if(balance>0)
	{
		balance--;
		if(lChild.get()==NULL)
		{
			lChild=node;
			node->parent=this;
		}
		else
			lChild->addNode(node);
	}
	else
	{
		balance++;
		if(rChild.get()==NULL)
		{
			rChild=node;
			node->parent=this;
		}
		else
			rChild->addNode(node);
	}
}

void Tree::addNode(TreeNodePtr node)
{
	if(root.get()==NULL)
		root=node;
	else
		root->addNode(node);
}

void Tree::runTree()
{
	root->prepareToRun();
	root->runNode();
}
}