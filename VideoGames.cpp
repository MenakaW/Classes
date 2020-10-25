#include <iostream>
#include "VideoGames.h"
#include <cstring>

using namespace std;

VideoGames::VideoGames(){
}

//delete all the variables in heap
VideoGames::~VideoGames(){
  delete []publisher;
  delete rating;
}

//set raing equal to the newrating
void VideoGames::setRating(float newRating){
  rating = new float;
  *rating = newRating;
}

//return rating
float* VideoGames::getRating(){
  return rating;
}

//set publisher equal to the new publisher
void VideoGames::setPublisher(char* newPublisher){
  publisher = new char[80];
  strcpy(publisher,newPublisher);
}

//return the publisher
char* VideoGames::getPublisher(){
  return publisher;
}
