#include <cstring>
#include <string.h>
#pragma once
using namespace std;
class Media{

 public:
  Media();
  void setTitle(char*);
  void setYear(int);
  char* getTitle();
  int* getYear();
  void setType(int);
  int getType();
  virtual ~Media(){
    delete []title;
    delete year;
  }
 private:
  char* title = new char[80];
  int* year = new int;
  int type;
};
