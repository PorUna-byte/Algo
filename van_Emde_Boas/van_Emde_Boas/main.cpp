//
//  main.cpp
//  van_Emde_Boas
//
//  Created by PorUnaCabeza on 2022/2/1.
//  Copyright © 2022 PorUnaCabeza. All rights reserved.
//

#include "van_Emde_Boas.hpp"

int main(int argc, const char * argv[]) {
    VEB* van_emde=new VEB(16);
    van_emde->insert(2);
    van_emde->insert(3);
    van_emde->insert(4);
    van_emde->insert(5);
    van_emde->insert(7);
    van_emde->insert(14);
    van_emde->insert(15);
    cout<<van_emde->is_Member(7)<<endl;
    cout<<van_emde->is_Member(8)<<endl;
    cout<<van_emde->is_Member(6)<<endl;
    cout<<van_emde->is_Member(4)<<endl;
    cout<<van_emde->is_Member(15)<<endl;
    cout<<van_emde->is_Member(1)<<endl;
    van_emde->delete_(7);
    cout<<van_emde->is_Member(7)<<endl;
    van_emde->delete_(15);
    cout<<van_emde->is_Member(15)<<endl;
    cout<<van_emde->predecessor(14)<<endl;
    cout<<van_emde->successor(14)<<endl;
    cout<<van_emde->successor(3)<<endl;
    return 0;
}
