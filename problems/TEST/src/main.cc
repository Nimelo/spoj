#include <iostream>
#include <string>

int main(){
  std::string answer = "42";
  std::string line;

  while(std::getline(std::cin, line))
    if(line != answer)
      std::cout << line << std::endl;
    else
      break;

  return 0;
}