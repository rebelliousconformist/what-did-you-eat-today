#include "RecepieTree.h"
#include "locale"

RecepieTree::RecepieTree()
{
    rootNode = new Recepie("root");
}

inline bool strGreater(std::string &a, std::string &b){
    std::locale loc("");
    auto const& coll = std::use_facet<std::collate<char>>(loc);
    return coll.compare(a.data(),a.data()+a.size(),b.data(),b.data()+b.size()) > 0;
}

Recepie* RecepieTree::insertRecepie(Recepie* node, std::string name)
{
    if (node == nullptr){
        node =  new Recepie(name);
        return node;
    }

    if (node->recepieName.compare(name) < 0){
        node->leftNode = insertRecepie(node->leftNode,name);
    }
    else if (node->recepieName.compare(name) > 0){
        node->rightNode = insertRecepie(node->rightNode,name);
    }  
    else{
        return node; //if same node do not insert
    }
    
    return node;
}


Recepie* RecepieTree::insertRecepie(Recepie* currentNode,Recepie* incomingNode)
{
    //if the currentNode is nullptr set the incoming node as the current nodeß
    if (currentNode == nullptr){
        return incomingNode;
    }

    if (currentNode->recepieName.compare(incomingNode->recepieName) < 0){
        currentNode->leftNode = insertRecepie(currentNode->leftNode,incomingNode);
    }
    else if (currentNode->recepieName.compare(incomingNode->recepieName) > 0){
        currentNode->rightNode = insertRecepie(currentNode->rightNode,incomingNode);
    }  
    else{
        return currentNode; //if same node do not insert
    }
    
    return currentNode;
}

bool RecepieTree::searchRecepie(Recepie* node,const std::string& name)
{

    if (node == nullptr){
        return false;
    }
    std::cout << "node recepie: " << node->recepieName << "\t searchRecepie: " << name << std::endl;

    //check string
    if (node->recepieName.compare(name) == 0){
        return true;
    }
    //move to left node
    if(searchRecepie(node->leftNode,name)) return true;
    return searchRecepie(node->rightNode,name);         //move to right node
        
}

void RecepieTree::inOrderTraversal(Recepie* node){
    if(node == nullptr){
        return;
    }
    inOrderTraversal(node->leftNode);
    std::cout << node->recepieName << std::endl;
    inOrderTraversal(node->rightNode);
}

void RecepieTree::insertBulkRecepies(std::vector<std::string> recepieList){

    for (auto &&i : recepieList)
    {
        rootNode = insertRecepie(rootNode,i);
    }    
}

void RecepieTree::insertBulkRecepies(const std::vector<Recepie*>& recepieList){

    for (auto &&i : recepieList)
    {
        this->rootNode = insertRecepie(this->rootNode,i);
    }
    
}

Recepie* RecepieTree::getRoot(){
    return this->rootNode;
}


int RecepieTree::searchRecepie()
{
    return 0;
}

RecepieTree::~RecepieTree()
{
    //delete recursively the entire tree
}