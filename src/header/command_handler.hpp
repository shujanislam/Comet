#ifndef COMMAND_HANDLER_HPP
#define COMMAND_HANDLER_HPP

#include<iostream>
#include<string>
#include<filesystem>
#include<fstream>

using namespace std;
namespace fs = filesystem;

void initializeRepo(string repoPath, string repoName) {
  string repoDir = repoPath + repoName;
  
  if(!fs::exists(repoDir)){
    fs::create_directories(repoDir);
    cout<<"Repository Initialized"<<endl;
  }

  cout<<"Already Initialized"<<endl;
}

void commitRepo(const string& repoPath, const string& sourceFile) {
    string destPath = repoPath;
    if (!destPath.empty() && destPath.back() != '/' && destPath.back() != '\\') {
        destPath += '/';
    }
    
    fs::path sourcePath(sourceFile);
    string filename = sourcePath.filename().string();
    
    destPath += filename;
    
    if (!fs::exists(sourceFile)) {
        cerr << "Source file does not exist: " << sourceFile << endl;
        return;
    }

    fs::path dest(destPath);
    fs::path destDir = dest.parent_path();
    if (!fs::exists(destDir)) {
        if (!fs::create_directories(destDir)) {
            cerr << "Failed to create destination directory: " << destDir << endl;
            return;
        }
    }
    ifstream src(sourceFile, ios::binary);
    if (!src) {
        cerr << "Failed to open source file: " << sourceFile << endl;
        return;
    }
    ofstream destFile(destPath, ios::binary);
    if (!destFile) {
        cerr << "Failed to create/open destination file: " << destPath << endl;
        return;
    }
    destFile << src.rdbuf();
    cout << "Committed " << sourceFile << " to " << destPath << endl;
}

void pushRepo() {
    cout << "Pushed to the remote repository successfully" << endl;
}

void dispatchCommand(int argc, char* argv[]){
  string arg = argv[1];

  if(arg == "-i"){
    string repoName = argv[2];

    initializeRepo("/home/shujan/Programming/comet_repos/", repoName);
  }
  else if(arg == "-c"){
    string repoName = argv[2];
    string sourcefile = argv[3];
    string repoPath = "/home/shujan/Programming/comet_repos/" + repoName;

    commitRepo(repoPath, sourcefile);
  }
  else if(arg == "-p"){
    pushRepo();
  }

}

#endif
