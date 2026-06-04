#include <iostream>
#include <csignal>
#include <iostream>
#include <fstream>
#include <filesystem>
#include "FileLogger.h"
#include "ConsoleLogger.h"
#include "Recepie.h"
#include "RecepieTree.h"

std::atomic<bool> running(true);
void signalHandler(int s)
{
    running = false;
    printf("Stopping %d\n", s);
    exit(1);
}

enum class choices {NONE,READ,STORE};

int main(int, char **)
{
    signal(SIGINT, signalHandler);
    std::cout << "Hello, from what-did-you-eat-today!\n";

    std::vector<std::string> lister;
    lister.push_back("AppleCake");
    lister.push_back("Cider");
    lister.push_back("ApfelStrudel");
    lister.push_back("Caesar Salad");
    lister.push_back("Caesar Salad");
    lister.push_back("Nacho");
    lister.push_back("Nuts");
    lister.push_back("Nuts");
    lister.push_back("Muesli");

    std::vector<std::unique_ptr<Recepie>> recepieList;
    std::unique_ptr<Recepie> tmpRecepie;

    tmpRecepie = std::make_unique<Recepie>("nutmeg");
    tmpRecepie->ingredients.push_back("shell");
    tmpRecepie->ingredients.push_back("taaste");
    recepieList.push_back(std::move(tmpRecepie));
    
    RecepieTree recepieBook;

    recepieBook.insertBulkRecepies(lister);
    recepieBook.insertBulkRecepies(recepieList);

    Recepie* rootNode = recepieBook.getRoot();
    recepieBook.inOrderTraversal(rootNode);

    std::cout << "search result: " << recepieBook.searchRecepie(rootNode,"Rats");


}
