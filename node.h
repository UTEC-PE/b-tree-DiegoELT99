#ifndef NODE_H
#define NODE_H

#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

template <typename T> class BTree;

template <typename T>

class Node 
{
	unsigned int numberOfKeys;
    unsigned int size;
    unsigned int minimumKeys;
    vector<unsigned int> keys;
    vector<Node<T>*> childs;
    bool isLeaf;

    public: 
        Node(unsigned int size, bool isLeaf = true) : size(size), isLeaf(isLeaf) 
        {
            keys.resize(size - 1);
            childs.resize(size);
            numberOfKeys = 0;
            minimumKeys = ceil(size/2);
        }

        void goThroughSubTree()
        {
            int i;
        	for(i = 0; i < numberOfKeys; i++)
        	{
        		if (!isLeaf)
        			childs[i] -> goThroughSubTree();
        		cout << keys[i] << " ";
        	}

        	if (!isLeaf)
        		childs[i] -> goThroughSubTree();
        };

        Node<T> * search(unsigned int value)
        {
        	int i = 0;
        	while(i < numberOfKeys && value > keys[i])
        		i++;

        	if (keys[i] == value)
        		return this;
        	
        	if (isLeaf)
        	{
        		cout << "Ese valor no se encuentra en este arbol. (╥_╥)" << endl;
        		return nullptr;
        	}
        	else
        		return  childs[i] -> search(value);
        };

        void easyInsert(int value)
		{	
            int i = numberOfKeys - 1;

            if (isLeaf)
            {
                while(i >= 0 && keys[i] > value)
                {
                    keys[i+1] = keys[i];
                    i--;
                }

                keys[i+1] = value;
                numberOfKeys++;
            }

            else
            {
                while (i >= 0 && keys[i] > value)
                    i--;

                if(childs[i+1] ->  numberOfKeys == 2*minimumKeys - 1)
                {
                    division(i+1,childs[i+1]);

                    if (keys[i+1] < value)
                        i++;
                }
                childs[i+1] -> easyInsert(value);
            }

        }

        void division(int i, Node<T> * nodeToSplit)
        {
        	Node<T> * splitNode = new Node<T>(nodeToSplit -> minimumKeys, nodeToSplit -> isLeaf);
        	splitNode -> numberOfKeys = minimumKeys - 1;

        	for(int j = 0; j < minimumKeys - 1; j++)
        		splitNode -> keys[j] = nodeToSplit -> keys[j + minimumKeys];

        	if (!(nodeToSplit -> isLeaf))
        	{
        		for(int j = 0; j < minimumKeys; j++)
        			splitNode -> childs[j] = nodeToSplit -> childs [j + minimumKeys];
        	}

            nodeToSplit -> numberOfKeys = minimumKeys - 1;

            for(int j =  numberOfKeys; j >= i + 1; j--)
                keys[j+1] = keys[j];

            keys[i] = nodeToSplit -> keys[minimumKeys - 1];

            numberOfKeys++;
        }


    friend class BTree<T>; 
};

#endif