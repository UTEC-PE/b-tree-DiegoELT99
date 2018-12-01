#include <iostream>

#include "btree.h"

using namespace std;

int main(int argc, char *argv[]) 
{
	BTree<unsigned int> t(6);

	t.insert(1); 
    t.insert(2); 
    t.insert(5); 
    t.insert(3); 
    t.insert(4); 
    t.insert(10); 
    t.insert(11); 
    t.insert(17); 

    t.goThroughSubTree();
	

    system("pause");
    return EXIT_SUCCESS;
}
