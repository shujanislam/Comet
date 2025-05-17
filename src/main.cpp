#include<iostream>
#include<string>

#include "header/argparser.hpp"
#include "header/file_utils.hpp"
#include "header/command_handler.hpp"

using namespace std;

int main(int argc, char* argv[]){
  if(checkArgs(argc, argv) && checkSourceFile(argv)){
    dispatchCommand(argc, argv);
  }

  return 0;
}
