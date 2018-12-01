#ifndef BTREE_H
#define BTREE_H

#include "node.h"

template <typename T>

class BTree 
{
    private:
        Node<T>* root;
        unsigned int degree;
        unsigned int minimumDegree;
    public:
        BTree(unsigned int minimumDegree) : minimumDegree(minimumDegree), root(nullptr) {};

        Node<T> * search(int value)
        { 
            if (!root)
            {
                cout << "El arbol no tiene elementos aun. (T_T)" << endl;
            }
            else
                return root -> search(value);
        } 

        void goThroughSubTree()
        {
            if (root)
                root -> goThroughSubTree();
        }
        

        bool insert(int value)
        {
            if (!root)
            {
                root = new Node<T>(minimumDegree,true);
                root -> keys[0] = value;
                root -> numberOfKeys = 1;
            }

            else
            {
                if(root -> numberOfKeys == 2*minimumDegree-1)
                {
                    Node<T> * nodeToAdd = new Node<T>(degree, false);
                    nodeToAdd -> childs[0] = root;
                    nodeToAdd -> division(0, root);

                    int i = 0;
                    if (nodeToAdd -> keys[0] < value)
                        i++;
                    nodeToAdd -> childs[i] -> easyInsert(value);

                    root = nodeToAdd;
                }

                else
                    root -> easyInsert(value);
            }

        }

        bool remove(int k) 
        {
            // TODO
        }

        void print()
        {
            // TODO
        }

        //~BTree();
};

#endif