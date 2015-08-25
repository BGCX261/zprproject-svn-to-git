
#if !defined(_TREE_H)
#define _TREE_H

namespace AlgorithmControler{
class AlgorithmControler;
}

#include "../ToolsAndTypes/Types.hpp"
#include <memory>
#include "AlgorithmProxy.hpp"

namespace AlgorithmControler{
class Tree;

class TreeNode : public AlgorithmProxy
{
public:
	TreeNode(void);
	~TreeNode(void);
	void addNode(TreeNodePtr node);
	void runNode();
	void prepareToRun();

friend class Tree;
private:
	int balance;
	TreeNode* parent;
	TreeNodePtr lChild;
	TreeNodePtr rChild;
};

class Tree
{
public:
	Tree(void){};
	Tree(TreeNode *root){};
	void addNode(TreeNodePtr node);
	void delNode(TreeNodePtr node){};
	void runTree();
	TreeNode* getParent(TreeNode *node){};
	
	~Tree(){};
private:

	//std::list<TreeNodePtr> nodeList;
	TreeNodePtr root;
};




}

#endif
