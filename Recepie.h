#ifndef RECEPIE_H
#define RECEPIE_H

#pragma once

#include <string>
#include <vector>

class Recepie
{
public:
    Recepie();
    Recepie(std::string);
    std::string recepieName;
    std::vector<std::string> ingredients;
    Recepie *leftNode;
    Recepie *rightNode;
    ~Recepie();

private:

};
#endif