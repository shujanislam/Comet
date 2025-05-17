#ifndef ARGPARSER_HPP
#define ARGPARSER_HPP

#include <iostream>
#include<vector>

using namespace std;

vector<string> validArgs = { "-i", "-c", "-p" };

inline bool checkArgs(int argc, char* argv[]) {
  if(argc < 3){
    cout<<"Error: Invalid or incomplete argument"<<endl;
    cout<<"Usage: ./comet [COMMAND] [FLAG](optional) [FILENAME]/[FOLDERNAME]"<<endl;
    
    return false;
  }
 
  string args = argv[1];
  
  bool found = false;

  for(auto i : validArgs){
    if(args == i){
      found = true;
      break;
    }
  }

  if(!found){
    cout<<"Error: Invalid arguement"<<endl;
    cout<<"Possbile arguments: ";

    for(auto i : validArgs){
      cout<<i<<" ";
    }
    cout<<endl;
  }

  return true;

}

#endif
