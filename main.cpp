#include <iostream>
#include <string>
#include <vector>
#include <limits>

std::vector <int> edges; // {vertex1, vertex2, v1 -> v2 distance, vertex3, vertex4, v3 -> v4 distance} - vertex2 is connected with vertex 1 with distance v1 -> v2 ...
int vertices;
std::string inp1, inp2, inp3;

int startv;
int endv;

int MAX_INT = std::numeric_limits<int>::max();

std::vector <int> queue; // {vertexid, last id, distance}

int main(){

  //get vertices number and create solved array
  std::cout << "How many vertices are in your graph? ";
  std::cin >> inp1;
  vertices = std::stoi(inp1);
  int solved[vertices + 1][2]; // {min-distance, last vertex id}
  for(int fill = 0; fill < vertices + 1; fill++){
    solved[fill][0] = -1;
    solved[fill][1] = -1;
  }

  std::cout << "From which vertex do you want to start, and to which vertex do you want to come (0 [zero] is not valid)? ";
  std::cin >> inp1 >> inp2; // vertex1 id, vertex2 id

  startv = std::stoi(inp1); //starting vertex id
  endv = std::stoi(inp2); //ending vertex id

  while (true){

    std::cin >> inp1 >> inp2 >> inp3;

    if(inp1 != "end" && inp2 != "end" && inp3 != "end"){

      edges.push_back(std::stoi(inp1)); //vertex1
      edges.push_back(std::stoi(inp2)); //vertex2
      edges.push_back(std::stoi(inp3)); //distance

    }else{
      break;
    }

  }

  solved[startv][0] = 0;
  solved[startv][1] = 0;

  //END input, start solving

  //push first queue
  for(int x = 0; x < edges.size(); x = x + 3){
    if(edges.at(x) == startv){
      queue.push_back(edges.at(x + 1));
      queue.push_back(edges.at(x));
      queue.push_back(edges.at(x + 2));
    }
  }


  int lastId = startv;

  //start the algorithm
  while(queue.size() > 0){

    int minid;
    int minvalue = MAX_INT;
    int lastNeighbour;
    int eraseid;

    //find the smallest queue member
    for(int y = 0; y < queue.size(); y = y + 3){

      if(minvalue > queue.at(y + 2)){
        minvalue = queue.at(y + 2);
        lastNeighbour = queue.at(y + 1);
        minid = queue.at(y);
        eraseid = y;
      }

    }

    //set smallest queue member to solved
    solved[minid][0] = minvalue;
    solved[minid][1] = lastNeighbour; //probably a bug

    int curDist = queue.at(eraseid + 2);

    //remove from queue
    queue.erase(queue.begin() + eraseid);
    queue.erase(queue.begin() + eraseid);
    queue.erase(queue.begin() + eraseid);


    //add all its neighbours to the queue
    for(int z = 0; z < edges.size() - 2; z = z + 3){

      if(edges.at(z) == minid){
        //found neighbour

        int neighbourId = edges.at(z + 1);
        if(solved[neighbourId][1] == -1){
          //neighbour is not solved yet

          bool found = false;
          for(int f = 0; f < queue.size(); f = f + 3){
            //is neighbour in the queue?

            if(queue.at(f) == neighbourId){
              found = true;
              //yes it is
              if(queue.at(f + 2) > curDist + edges.at(z + 2)){
                queue.at(f + 2) = curDist + edges.at(z + 2);
                queue.at(f + 1) = minid;

              }

              break;
            }

          }

          if(!found){

            queue.push_back(neighbourId);
            queue.push_back(minid);
            queue.push_back(curDist + edges.at(z + 2));


          }

        }
      }


    }



  }

  std::cout << "---- Finished with calculations ----" << std::endl;

  //check if there even is a path
  if(solved[endv][0] == -1){
    std::cout << "There is no path" << std::endl;
  }

  //find path (back tracking)
  int currId = endv;
  std::vector<int> path;

  while(startv != currId){

    path.push_back(currId);
    currId = solved[currId][1];

  }

  path.push_back(startv);

  std::cout << "Path:";

  //output path
  for(int x = 0; x < path.size(); x++){
    std::cout << " " << path.at(path.size() - x - 1);
  }

  //output distance
  std::cout << "\nDistance: " << solved[endv][0] << std::endl;

}
