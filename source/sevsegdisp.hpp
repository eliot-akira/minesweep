#pragma once

#include <string>
#include <vector>
#include <cmath>
#include "setup.hpp"
#include "buffer.hpp"
#include "colour.hpp"

class SevSegDisp{
    public:
        SevSegDisp(int,int);

        void operator ++(){
            if(number > int(std::pow(10, noOfDigits)) - 1) return;
            else ++number;
        }

        void operator --(){
            if(number) --number;
        }

        void set(int);
        void update(std::string);


    private:
    int noOfDigits;
    int number;
} flagDisp(5, 0), timeDisp(5, 0);

SevSegDisp::SevSegDisp(int dig, int n){
    noOfDigits = dig;
    number = n;
}

void SevSegDisp::set(int n){
    number = n;
}

void SevSegDisp::update(std::string prepend){
    int homeLine = writeBuf.getCurrLine();
    int num = number;

    writeBuf << endl << reset; // << prepend;
    auto str = std::to_string(num);
    writeBuf << cyan_fg << "  Flags: " << str << " " << endl << reset;
}
