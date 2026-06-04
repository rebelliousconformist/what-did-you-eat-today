#ifndef RECEPIETREE_H
#define RECEPIETREE_H

#pragma once
#include "Recepie.h"
#include <string>
#include <iostream>

class RecepieTree
{
public:
    Recepie *rootNode = nullptr;
    RecepieTree();
    Recepie* insertRecepie(Recepie*, std::string);
    Recepie* insertRecepie(Recepie* currentNode,Recepie* incomingNode);
    void inOrderTraversal(Recepie* node);
    void insertBulkRecepies(std::vector<std::string> recepieList);
    void insertBulkRecepies(const std::vector<Recepie*>& recepieList);
    bool searchRecepie(Recepie* node,const std::string& name);
    int searchRecepie();
    Recepie* getRoot();
    ~RecepieTree();

private:

};

#endif