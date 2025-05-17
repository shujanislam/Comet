#ifndef FILE_UTILS_HPP
#define FILE_UTILS_HPP

#include<fstream>
#include<string>

using namespace std;

bool checkSourceFile(char* argv[]){

  string argc = argv[1];

  if(argc != "-i"){
    string filename = argv[3];

    ifstream sourcefile(filename);

    if(!sourcefile.is_open()){
      cout<<"Error: Source file doesn't exists."<<endl;
      return false;
    }

    return sourcefile.is_open();
  }
  else{
    return true;
  }
}

#endif
