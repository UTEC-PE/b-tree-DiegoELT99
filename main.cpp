#include <iostream>

#include "btree.h"

using namespace std;

int main(int argc, char *argv[]) 
{
	BTree<unsigned int> t(6);

	t.insert(10); 
    t.insert(20); 
    t.insert(5); 
    t.insert(6); 
    t.insert(12); 
    t.insert(30); 
    t.insert(7); 
    t.insert(17); 

    t.goThroughSubTree();
	

    system("pause");
    return EXIT_SUCCESS;
}
