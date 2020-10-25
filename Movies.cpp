#include <iostream>
#include "Movies.h"
#include <cstring>

using namespace std;

Movies::Movies(){

}

//remove everything that is stored in heap
Movies::~Movies(){
  delete []director;
  delete rating;
  delete duration;
}

//set director equal to newdirector using string copy
void Movies::setDirector(char* newDirector){
  director = new char[80];
  strcpy(director,newDirector);
}

//set the duration equal to the newduration
void Movies::setDuration(float newDuration){
  duration = new float;
  *duration = newDuration;
}

//make rating equal to newrating
void Movies::setRating(float newRating){
  rating = new float;
  *rating = newRating;
}

//return director
char* Movies::getDirector(){
  return director;
}

//return duration
float* Movies::getDuration(){
  return duration;
}

//return rating
float* Movies::getRating(){
  return rating;
}
