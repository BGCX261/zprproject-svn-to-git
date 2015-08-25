#include "TreeControler.hpp"
#include <sstream>

namespace AlgorithmControler{
TreeControler::TreeControler()
{}

TreeControler::TreeControler( int port, const Conections& conections)
: AlgorithmControler(port, conections)
{
	treeRunner = std::auto_ptr<TreeRunner>(new TreeRunner(this));
	tree = std::auto_ptr<Tree>( new Tree());

	TreeNodePtr root = TreeNodePtr(new TreeNode());
	std::stringstream ss;

	ss<<"localhost:"<<port;
	
	root->setEndPoint(ss.str());

	tree->addNode(root);
}



TreeControler::~TreeControler(void)
{
}



void TreeControler::addNode(TreeNodePtr  node)
{
	tree->addNode(node);
}

void TreeControler::treeRun()
{
	std::cout<<"TreeControler::treeRun()"<<std::endl;
	tree->runTree();
	
	//AlgorithmControler::run();
	
}
}