//
//  Object.hpp
//  RSA Decryption
//
//  Created by Caitlyn Zhang on 10/22/19.
//  Copyright © 2019 Caitlyn Zhang. All rights reserved.
//

#ifndef Object_h
#define Object_h

class Object {
private:
    char c;
    int a;
    
public:
    Object();
    Object(char, int);
    int getInt();
    char getChar();
};

#endif /* Object_hpp */
