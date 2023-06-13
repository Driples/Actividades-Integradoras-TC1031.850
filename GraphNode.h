#ifndef GRAPHNODE_H
#define GRAPHNODE_H

#include <string>
#include <map>

struct GraphNode{
    std::string ip;
    std::map<std::string, int> adj; // dirección IP de destino, peso
};

#endif
