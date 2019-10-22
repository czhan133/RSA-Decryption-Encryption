//
//  main.cpp
//  RSA Decryption
//
//  Created by Caitlyn Zhang on 10/22/19.
//  Copyright © 2019 Caitlyn Zhang. All rights reserved.
//

#include "Object.h"

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
int moduloFunc(int, int, int);
vector<int> RSADecryption(vector<int>, int, int);

//we will read in a vector of C, and will output a vector of M

//THERE'S SOMETHING WRONG IN THIS CODE
vector<int> RSADecryption(vector<int> C, int e, int n) {
    vector<int> M;
    int b = 1; //phi(n) * b + 1
    int p = 2;
    int m;
    
    //finding the factors of n
    while ((n % p) != 0) {
        p++;
    }
    
    int q = n / p;
    
    //find phi(n)
    int phi = (p - 1) * (q - 1);
    
    //find d
    while ((phi * b + 1) % e != 0) {
        b++;
    }
    
    int d = (phi * b + 1) / e;
    
    //turn all elements in C to M
    for (int i = 0; i < C.size(); i++) {
        
        m = moduloFunc(C.at(i), d, n);
        
        M.push_back(m);
    }
    
    return M;
}

int moduloFunc(int c, int d, const int n) {
    int remain = 1;
    
    bool modulo = false;
    
    while (!modulo) {
        if (d == 1) {
            c = c * remain;
            modulo = true;
        } else if (c == 1) {
            c = remain;
            modulo = true;
        } else if (c > n) {
            c = c % n;
        } else {
            if (d % 2 != 0) {
                remain = remain * c;
            }
            
            c = c * c;
            
            d = d / 2;
        }
    }
    
    return c % n;
}


// in Main, we will use vector output of M and compare with a vector of characters
// need to create a specific object such that the vector of characters can hold both the characters
// and the given M they have.
int main() {
    //creating a vector of a2, b3, c4,..., " "28
    vector<Object> o;
    int ascii = 97;
    
    for (int i = 2; i < 28; i++) {
        Object *newObj = new Object(ascii, i);
        ascii++;
        
        o.push_back(*newObj);
    }
    
    Object *space = new Object();
    o.push_back(*space);
    
    vector<int> code = {51, 12, 51, 39, 31, 21,
                        14, 10, 20, 17, 7, 25,
                        14, 26, 33, 52, 15, 7,
                        27, 51, 7, 49, 8, 15,
                        51, 7, 8, 25, 7, 25,
                        10, 49, 18, 52, 51, 7,
                        8, 25, 7, 18, 26, 25,
                        25, 10, 27, 52, 51, 7,
                        27, 33, 21, 7, 20, 26,
                        21, 7, 25, 10, 49, 18,
                        52, 51, 39};
    
    vector<int> decode = RSADecryption(code, 23, 55);
    
    for (int i = 0; i < decode.size(); i++) {
        
        for (int j = 0; j < o.size(); j++) {
            if (decode.at(i) == o.at(j).getInt()) {
                cout << o.at(j).getChar();
            }
        }
    }
    
    cout << endl;
    
    return 0;
}
