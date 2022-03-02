//
//  Push_relabel_front.cpp
//  Push_relabel_front
//
//  Created by PorUnaCabeza on 2022/2/14.
//  Copyright © 2022 PorUnaCabeza. All rights reserved.
//

#include "Push_relabel_front.hpp"
uint32_t MGraph::Locate(const string &name){   //given name of a vertex, find the corresponding id.
    for(uint32_t i=0;i<Vnum;i++)
        if(name==vexs[i].name)
            return vexs[i].id;
    return UINT32_MAX;
}
void MGraph::Init_preflow(){
    for(uint32_t i=0;i<Vnum;i++)
        vexs[i].height=vexs[i].excess=0;
    uint32_t s=Locate(source);
    vexs[s].height=Vnum;
    for(int j=0;j<Vnum;j++)
    {
        if(edges_cap[s][j]>0)
        {
            edges_flow[s][j]=edges_cap[s][j];
            edges_resi[s][j]=0;
            edges_resi[j][s]=edges_cap[s][j];
            vexs[j].excess=edges_cap[s][j];
            vexs[s].excess=vexs[s].excess-edges_cap[s][j];
        }
    }
}
void MGraph::Relabel(Vertex *u){  //relabel the height of vertex u
    uint32_t h=UINT32_MAX;
    for(uint32_t v=0;v<u->neinum;v++)  //find the lowest height from the neighbors in the residual network
    {
        if(edges_resi[u->id][u->neighbor[v]]>0&&vexs[u->neighbor[v]].height<h)
            h=vexs[u->neighbor[v]].height;
    }
    u->height=h+1;
}
void MGraph::Push(uint32_t u,uint32_t v){   //Push operation,push as much flow as possible from u to v.
    long int deta=vexs[u].excess;
    if(edges_resi[u][v]<deta)
        deta=edges_resi[u][v];
    if(edges_cap[u][v]>0) //the edge in the residual network also exist in the original network
    {
        edges_flow[u][v]+=deta;
        edges_resi[u][v]-=deta;
        edges_resi[v][u]+=deta;
    }
    else//inverse edge
    {
        edges_resi[v][u]+=deta;
        edges_flow[v][u]-=deta;
        edges_resi[u][v]-=deta;
    }
    vexs[u].excess-=deta;
    vexs[v].excess+=deta;
}
void MGraph::Discharge(Vertex *u){    //Discharge operation，push out all excess flow，needs to call push() and relabel() many times.
    while(u->excess>0)
    {
        uint32_t v=u->current;
        if(v>=u->neinum)
        {
            Relabel(u);
            u->current=0;
        }
        else if(edges_resi[u->id][u->neighbor[v]]>0&&u->height==vexs[u->neighbor[v]].height+1)
        {
            Push(u->id,u->neighbor[v]);
        }
        else
            u->current++;
    }
}
MGraph::MGraph(ifstream& infile) //Time complexity:O(max(Vnum^2,Vnum*Enum)),Space complexity:O(Vnum^2)
{
    infile>>Vnum>>Enum;
    infile>>source>>sink;
    for(uint32_t i=0;i<Vnum;i++)
    {
        infile>>vexs[i].name;
        vexs[i].current=vexs[i].neinum=0;
        vexs[i].id=i;
    }
    for(uint32_t i=0;i<Vnum;i++){
        for(uint32_t j=0;j<Vnum;j++)
            edges_resi[i][j]=edges_flow[i][j]=edges_cap[i][j]=0;
    }
    for(uint32_t i=0;i<Enum;i++){
        string name1,name2;
        uint32_t cap=0;
        uint32_t m,n;
        infile>>name1>>cap>>name2;
        m=Locate(name1);n=Locate(name2);
        vexs[m].neighbor[vexs[m].neinum++]=n;
        vexs[n].neighbor[vexs[n].neinum++]=m;
        edges_resi[m][n]=edges_cap[m][n]=cap;
    }
    for(uint32_t i=2;i<Vnum-1;i++)
    {
        vexs[i].next=&vexs[i+1];
        vexs[i].pre=&vexs[i-1];
    }
    vexs[1].next=&vexs[2];
    vexs[1].pre=nullptr;
    vexs[Vnum-2].next=nullptr;
    link=&vexs[1];
}
void MGraph::Relabel_to_front(){
    //perform discharge operation for all vertices,if a vertex has been relabeled by discharge operation, then move it to the head of the link.
    Init_preflow();
    Vertex *u=link;
    while(u!=nullptr)
    {
        uint32_t old_height=vexs[u->id].height;
        Discharge(u);
        if(vexs[u->id].height>old_height)
        {
            if(u!=link){
                if(u->pre!=nullptr)
                    u->pre->next=u->next;
                if(u->next!=nullptr)
                    u->next->pre=u->pre;
                link->pre=u;
                u->next=link;
                u->pre=nullptr;
                link=u;
            }
        }
        u=u->next;
    }
}
long MGraph::max_flow(){
    Relabel_to_front();
    return -vexs[Locate(source)].excess;
}
