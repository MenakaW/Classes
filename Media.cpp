#include <iostream>
#include "media.h"
#include <string.h>
#include <cstring>

using namespace std;

Media::Media(){
}

//title is a common field, so this is a method to alter it
void Media::setTitle(char* newTitle){
  strcpy(title,newTitle);
}

//year is a shared field, so this is a method to alter it
void Media::setYear(int newYear){

  *year = newYear;
}

//return title
char* Media::getTitle(){
  return title;
}

//return year
int* Media::getYear(){
  return year;
}

//1 is video game, 2 is music, 3 is movie
void Media::setType(int set){
  type = set;
}

//return type
int Media::getType(){
  return type;
}


