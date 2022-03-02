//
//  main.cpp
//  Push_relabel_front
//
//  Created by PorUnaCabeza on 2022/2/14.
//  Copyright © 2022 PorUnaCabeza. All rights reserved.
//

#include "Push_relabel_front.hpp"

int main(int argc, const char * argv[]) {
    ifstream infile;
    infile.open("mapin");
    if(!infile.is_open())
    {
        cout<<"read error"<<endl;
        return 0;
    }
    MGraph G(infile);
    cout<<G.max_flow()<<endl;
    return 0;
}
