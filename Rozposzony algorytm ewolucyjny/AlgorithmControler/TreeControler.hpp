#if !defined(_TREECONTROLER_H)
#define _TREECONTROLER_H



namespace AlgorithmControler
{
 class AlgorithmControler;
	class TreeControler;
	class TreeNode;
}

#include "AlgorithmControler.hpp"


namespace AlgorithmControler
{

	
	

	class TreeRunner;
	class TreeControler:   public AlgorithmControler
	{
	public:
		TreeControler(void);
		TreeControler(int port, const Conections& conections);
		void treeRun();
		//void start();
		//void join();
		//void run();

		void addNode(TreeNodePtr node);
		void delNode(TreeNode *tree);
		void addTree(Tree * tree){};
		~TreeControler(void);

	private:
		std::auto_ptr<TreeRunner> treeRunner;
		std::auto_ptr<Tree> tree;

	};

	class TreeRunner : public ToolsAndTypes::Thread
	{
	public:
		TreeRunner(){}
		TreeRunner(TreeControler *aTreeControler) 
		{treeControler = aTreeControler;}
		void run()
		{treeControler->treeRun();}
		~TreeRunner(){}
	private:
		TreeControler * treeControler;

	};
	


	


}
#endif 