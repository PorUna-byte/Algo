//
//  Manacher_LPS.cpp
//  Manacher_LPS
//
//  Created by PorUnaCabeza on 2021/12/16.
//  Copyright © 2021 PorUnaCabeza. All rights reserved.
//

#include "Manacher_LPS.hpp"
void LPS::search(){
    int N=2*text.length()+1;
    bool expand=false;
    while(currentPos<N)
    {
        expand=false;
        if(currentPos<=centerRightPos)
        {
            imageCur=2*centerPos-currentPos;
            /*
             case 1:
             cur-left palindrome is completely contained in center palindrome
             cur-left palindrome is NOT a prefix of center palindrome                 */
            if(lps[imageCur]<centerRightPos-currentPos)
                lps[currentPos]=lps[imageCur];
            /*
             case 2:
             cur-left palindrome is prefix of center palindrome (means completely contained also)
             center palindrome is suffix of input string
             */
            else if(lps[imageCur]==centerRightPos-currentPos&&
                    currentPos==N-1)
                lps[currentPos]=lps[imageCur];
            /*
             case 3:
             cur-left palindrome is prefix of center palindrome (and so cur-left palindrome is completely contained in center palindrome)
             center palindrome is NOT suffix of input string
             case 4:
             cur-left palindrome is NOT completely contained in center palindrome
             */
            else
            {
                lps[currentPos]=centerRightPos-currentPos;
                expand=true;
            }
        }
        else
        {
            lps[currentPos]=0;
            expand=true;
        }
        if(expand)
        {
            while(currentPos+lps[currentPos]<N-1&&currentPos-lps[currentPos]>0&&
                  ((currentPos+lps[currentPos]+1)%2==0||
                   text[(currentPos+lps[currentPos]+1)/2]==text[(currentPos-lps[currentPos]-1)/2]))
                lps[currentPos]++;
            centerPos=currentPos;
            centerRightPos=currentPos+lps[currentPos];
            if(lps[currentPos]>long_length)
            {
                long_center=currentPos;
                long_length=lps[currentPos];
            }
        }
        currentPos++;
    }
    cout<<"The longest palindrome of "<<text<<"is:"<<endl;
    cout<<text.substr((long_center-long_length)/2,long_length)<<endl;
}
