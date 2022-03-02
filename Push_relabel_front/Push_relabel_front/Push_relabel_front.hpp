//
//  Push_relabel_front.hpp
//  Push_relabel_front
//
//  Created by PorUnaCabeza on 2022/2/14.
//  Copyright © 2022 PorUnaCabeza. All rights reserved.
//  Time complexity of Push_relabel_front is O(V^3).

#ifndef Push_relabel_front_hpp
#define Push_relabel_front_hpp
#include<fstream>
#include <iostream>
using namespace std;
const uint32_t maxV=20;
class MGraph;
class Vertex{
private:
    string name; //the name of the vertex
    uint32_t id; //the identifier of the vertex
    uint32_t height;//the height of the vertex
    long int excess;//the excess preflow stored in the vertex
    uint32_t neighbor[maxV];//the identifiers of the vertices that are adjacent to the vertex
    uint32_t neinum;//actual number of the vertex's neighbors
    uint32_t current;//the current neighbor being considered by discharge routine
    Vertex* next; //used to link all vertices together
    Vertex* pre;
    friend class MGraph;
};
class MGraph{
private:
    string source;
    string sink;
    Vertex vexs[maxV];
    uint32_t edges_cap[maxV][maxV];
    uint32_t edges_resi[maxV][maxV];
    uint32_t edges_flow[maxV][maxV];
    uint32_t Vnum;
    uint32_t Enum;
    Vertex* link; //link all vertices together, which can be useful in the push_relabel_front() routine.
    uint32_t Locate(const string &name);
    void Init_preflow();
    void Relabel(Vertex *u);
    void Push(uint32_t u,uint32_t v);
    void Discharge(Vertex *u);
    void Relabel_to_front();
public:
    MGraph(ifstream& infile); //Time complexity:O(max(Vnum^2,Vnum*Enum)),Space complexity:O(Vnum^2)
    long max_flow();
};
#endif /* Push_relabel_front_hpp */
