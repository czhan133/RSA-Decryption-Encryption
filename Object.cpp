//
//  Object.cpp
//  RSA Decryption
//
//  Created by Caitlyn Zhang on 10/22/19.
//  Copyright © 2019 Caitlyn Zhang. All rights reserved.
//

#include "Object.h"

Object::Object() {
    this->c = ' ';
    this->a = 28;
}

Object::Object(char c, int a) {
    this->c = c;
    this->a = a;
}

int Object::getInt() {
    return this->a;
}

char Object::getChar() {
    return this->c;
}
