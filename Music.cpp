#include <iostream>
#include "Music.h"
#include <cstring>

using namespace std;

Music::Music(){

}

//delete everything on the heap, basically anytime i use the new keyword
Music::~Music(){
  delete []artist;
  delete []publisher;
  delete duration;
}

//make artist equal to newartist using string copy
void Music::setArtist(char* newArtist){
  artist = new char[80];
  strcpy(artist,newArtist);
}

//set duration equal to newduration
void Music::setDuration(float newDuration){
  duration = new float;
  *duration = newDuration;
}

//set publisher equal to newpublisher
void Music::setPublisher(char* newPublisher){
  publisher = new char[80];
  strcpy(publisher,newPublisher);
}

//return publisher
char* Music::getPublisher(){
  return publisher;
}

//return artist
char* Music::getArtist(){
  return artist;
}

//return duration
float* Music::getDuration(){
  return duration;
}
