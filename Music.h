#include <iostream>
#include "media.h"

using namespace std;
class Music:public Media{
public:
  Music();
  void setArtist(char*);
  void setDuration(float);
  void setPublisher(char*);
  char* getArtist();
  float* getDuration();
  char* getPublisher();
  ~Music();
private:
  char* artist;
  float* duration;
  char* publisher;
};
