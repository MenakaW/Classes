#include "media.h"

class VideoGames:public Media{

 public:
  VideoGames();
  void setRating(float);
  float* getRating();
  void setPublisher(char*);
  char* getPublisher();
  ~VideoGames();
 private:
  float* rating;
  char* publisher;
};
