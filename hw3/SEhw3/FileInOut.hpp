//
//  FileInOut.hpp
//  SEhw3
//
//  Created by 이다솜 on 2022/06/02.
//

#ifndef FileInOut_hpp
#define FileInOut_hpp

#include <stdio.h>
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
#include <iostream>
#include <string>
using namespace std;

//class: InOut
//
class FileInOut{
private:
    FILE* in_fp, *out_fp;
public:
    FileInOut(){
        this -> in_fp = fopen(INPUT_FILE_NAME, "r+");
        this -> out_fp = fopen(OUTPUT_FILE_NAME, "w+");
    }
    void doTask();
    //case 1
    void join();
    //case 4
    int searchProduct(string name);
    void showPurchase();
    void scoreProduct(int score);
    void buyProduct(int productId);
    //case 6
    void program_exit();
    
};




#endif /* FileInOut_hpp */
