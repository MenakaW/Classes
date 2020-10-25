#include "media.h"

using namespace std;
class Movies:public Media{
 public:
  Movies();
  void setDirector(char*);
  void setDuration(float);
  void setRating(float);
  char* getDirector();
  float* getDuration();
  float* getRating();
  ~Movies();
 private:
  char* director;
  float* duration;
  float* rating;
};
