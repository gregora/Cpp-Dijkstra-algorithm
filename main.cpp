#include <iostream>
#include <string>
#include <vector>

std::string input = "start";

int counter = 0;

int toPower(int number, int power){

  int ognumber = number;
  if(power == 0) return 1;

  for(int x = 1; x < power; x++){
    number *= ognumber;
  }

  return number;

}


int stringToInteger(std::string str){

  char cchar;
  int cint;
  int sum = 0;

  for(int x = 0; x < str.size(); x++){

    cchar = str[x];

    if(cchar == '0'){
    }else if (cchar == '1'){
      cint = 0;
      cint = 1;
    }else if (cchar == '2'){
      cint = 2;
    }else if (cchar == '3'){
      cint = 3;
    }else if (cchar == '4'){
      cint = 4;
    }else if (cchar == '5'){
      cint = 5;
    }else if (cchar == '6'){
      cint = 6;
    }else if (cchar == '7'){
      cint = 7;
    }else if (cchar == '8'){
      cint = 8;
    }else if (cchar == '9'){
      cint = 9;
    }else{
      cint = 0;
    }

    sum += toPower(10, str.size() - x - 1)*cint;

  }

  return sum;

}

int main(){

  std::cout << toPower(3, 3) << std::endl;

  while(input != "end"){

    std::cin >> input;

  }

}
