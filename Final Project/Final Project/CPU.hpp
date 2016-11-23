//
//  CPU.hpp
//  Final Project
//
//  Created by Steven Mumford on 11/16/16.
//  Copyright © 2016 Steven Mumford. All rights reserved.
//

#ifndef CPU_hpp
#define CPU_hpp

#include "User.hpp"

class CPU : public User
{
private:
    string name;
    int money;
    
public:
    CPU();
    CPU(int);
    
    int blackJackBet(); //
    int texasBet();     // SAME? Only need one bet function?
    
};

#endif /* CPU_hpp */
