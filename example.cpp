#include "dijkstra.h"
#include <iostream>


int main(){

  //initiate input strings
  std::string inp1, inp2, inp3;

  std::vector <int> inputedges; // {vertex1, vertex2, v1 -> v2 distance, vertex3, vertex4, v3 -> v4 distance} - vertex2 is connected with vertex 1 with distance v1 -> v2 ...

  //get vertices number and create solved array
  int vertices;
  std::cout << "How many vertices are in your graph? ";
  std::cin >> inp1;
  vertices = std::stoi(inp1);


  std::cout << "From which vertex do you want to start, and to which vertex do you want to come (0 [zero] is not valid)? ";
  std::cin >> inp1 >> inp2; // vertex1 id, vertex2 id

  int startv;
  int endv;
  startv = std::stoi(inp1); //starting vertex id
  endv = std::stoi(inp2); //ending vertex id

  while (true){

    std::cin >> inp1 >> inp2 >> inp3;

    if(inp1 != "end" && inp2 != "end" && inp3 != "end"){

      inputedges.push_back(std::stoi(inp1)); //vertex1
      inputedges.push_back(std::stoi(inp2)); //vertex2
      inputedges.push_back(std::stoi(inp3)); //distance

    }else{
      break;
    }

  }

  std::cout << dijkstra(inputedges, vertices, startv, endv) << std::endl;

}
