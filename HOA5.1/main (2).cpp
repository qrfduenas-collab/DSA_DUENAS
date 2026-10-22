#include <iostream>
#include <queue>


void display(std::queue<char> r);

int main(){


  std::queue<char> q;
  q.push('c');
  q.push('p');
  q.push('e');
  q.push('0');
  q.push('1');
  q.push('0');




  //DISPLAY
  display(q);

  //empty()
  std::cout << "is the function empty? " << q.empty();
  std::cout << "\n";
  //size()
  std::cout << "size of the queue: " << q.size();
  std::cout << "\n";
  //front
  std::cout << "function frot: " << q.front();
  std::cout << "\n";
  //back
  std::cout << "is the function empty? " << q.empty();
  std::cout << "\n";
  //pop
  q.pop();
  //display
 display(q);
  //push another element 
  q.push('r');
  q.push('a');
  q.push('l');
  q.push('p');
  q.push('h');
  q.push('x');
  //display
  display(q);

}


void display(std::queue<char> r){
  //create a copy of the queue
  std::queue<char> c = r;


  while(!c.empty()){
    std::cout<< " " << c.front();
    c.pop();


  }
  std::cout << "\n";


}