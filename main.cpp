#include <iostream>
#include <cstring>
#include "media.h"
#include "VideoGames.h"
#include <vector>
#include "Music.h"
#include "Movies.h"

using namespace std;

//method prototypes
void addData(vector<Media*> &vectorr);
void searchData(vector<Media*> vectorr);
void deleteData(vector<Media*> &vectorr);

int main(){
  //initialize vector
  vector<Media*> media;
  char input[80];
  while (true){
    //stay in the loop until the user inputs quit, otherwise, call the respective functions for add,search, and delete
    cout << "enter an action: add, search, delete, or quit" << endl;
    cin >> input;
    cin.get();
    if(input[0]=='a'||input[0]=='A'){
      addData(media);
    }
    else if(input[0]=='s' || input[0]=='S'){
      searchData(media);
    }
    else if(input[0]=='d' || input[0]=='D'){
      deleteData(media);
    }
    else if(input[0]=='q'||input[0]=='Q'){
      break;
    }
  }
  return 0;
  
  
}

void searchData(vector<Media*> vectorr){
  //ask the user if they want to search by year or title
  cout << "would you like to search using the title or the year?" << endl;
  char input[10];
  cin >> input;
  cin.get();
  //if year, read in the year from the user
  if(input[0]=='y'|| input[0]=='Y'){
    cout << "please enter the year" << endl;
    int year;
    cin >> year;
    cin.get();
    //cycle through the vector of media
    for(vector<Media*>::iterator it = vectorr.begin(); it!=vectorr.end(); it++){
      //if the year is the same as the inputted year
      if(*((*it)->getYear())==year){
	//print out the title and year
	char toPrint1[80];
	strcpy(toPrint1,(*it)->getTitle());
	cout << toPrint1 <<", ";
	cout << *(*it)->getYear() << ", ";
	if((*it)->getType() == 1){
	  //print out the rating and publisher if it's a videogame
	  cout << *(dynamic_cast<VideoGames*>(*it))->getRating() << " stars, ";
	  char toPrint2[80];
	  strcpy(toPrint2,(dynamic_cast<VideoGames*>(*it))->getPublisher());
	  cout << "published by " << toPrint2 << endl;
	}
	if((*it)->getType() == 2){
	  //print out the artist, duration, and publisher if it's music
	  char toPrint2[80];
	  strcpy(toPrint2,(dynamic_cast<Music*>(*it))->getArtist());
	  cout << "by " << toPrint2 << ", ";
	  cout << *(dynamic_cast<Music*>(*it))->getDuration() << " seconds long, ";
	  char toPrint3[80];
	  strcpy(toPrint3,(dynamic_cast<Music*>(*it))->getPublisher());
	  cout << "and published by "<< toPrint3 << endl;
	}
	if((*it)->getType() == 3){
	  //print out the director, duration, and rating if it's a movie
	  char toPrint2[80];
	  strcpy(toPrint2,(dynamic_cast<Movies*>(*it))->getDirector());
	  cout << "directed by " << toPrint2 << ", ";
	  cout << *(dynamic_cast<Movies*>(*it))->getDuration() << " minutes long, ";
	  cout << "and is rated "<< *(dynamic_cast<Movies*>(*it))->getRating()<< " stars" << endl;
	}
      }
    }
  }
  //if it's a title, cycle through the vector and look for the matching media
  else if(input[0]=='t' || input[0] || 'T'){
    cout << "please enter the title" << endl;
    char title[80];
    cin.get(title,80);
    cin.get();
    for(vector<Media*>::iterator it = vectorr.begin(); it!=vectorr.end();it++){
      //if a match is found, print out the data, just like above
      if(strcmp(((*it)->getTitle()),title)==0){
	char toPrint1[80];
	strcpy(toPrint1,(*it)->getTitle());
	cout << toPrint1 <<", ";
	cout << *(*it)->getYear() << ", ";
	if((*it)->getType() == 1){
	  cout << *(dynamic_cast<VideoGames*>(*it))->getRating() << " stars, ";
	  char toPrint2[80];
	  strcpy(toPrint2,(dynamic_cast<VideoGames*>(*it))->getPublisher());
	  cout << "published by " << toPrint2 << endl;
	}
	if((*it)->getType() == 2){
	  char toPrint2[80];
	  strcpy(toPrint2,(dynamic_cast<Music*>(*it))->getArtist());
	  cout << "by " << toPrint2 << ", ";
	  cout << *(dynamic_cast<Music*>(*it))->getDuration() << " seconds long, ";
	  char toPrint3[80];
	  strcpy(toPrint3,(dynamic_cast<Music*>(*it))->getPublisher());
	  cout << "and published by "<< toPrint3 << endl;
	}
	if((*it)->getType() == 3){
	  char toPrint2[80];
	  strcpy(toPrint2,(dynamic_cast<Movies*>(*it))->getDirector());
	  cout << "directed by " << toPrint2 << ", ";
	  cout << *(dynamic_cast<Movies*>(*it))->getDuration() << " minutes long, ";
	  cout << "and is rated "<< *(dynamic_cast<Movies*>(*it))->getRating()<< " stars" << endl;
	}
      }
    }
  }
  
}

void deleteData(vector<Media*> &vectorr){
  //use the search algorithm to find the matching media
  cout << "would you like to search using the title or the year?" << endl;
  char input[10];
  cin >> input;
  cin.get();
  if(input[0]=='y'|| input[0]=='Y'){
    cout << "please enter the year" << endl;
    int year;
    cin >> year;
    cin.get();
    for(vector<Media*>::iterator it = vectorr.begin(); it!=vectorr.end(); it++){
      if(*((*it)->getYear())==year){
	char toPrint1[80];
	strcpy(toPrint1,(*it)->getTitle());
	cout << toPrint1 <<", ";
	cout << *(*it)->getYear() << ", ";
	if((*it)->getType() == 1){
	  cout << *(dynamic_cast<VideoGames*>(*it))->getRating() << " stars, ";
	  char toPrint2[80];
	  strcpy(toPrint2,(dynamic_cast<VideoGames*>(*it))->getPublisher());
	  cout << "published by " << toPrint2 << endl;
	  cout << "do you want to delete the above video game? (y/n)?" << endl;
	  char yn[2];
	  cin>>yn;
	  cin.get();
	  //if the user wants to delete the media, erase it from the vectorr and call the destructor for each specific media type
	  //then break in order to not mess up the iterator
	  if(yn[0]=='y' || yn[0]=='Y'){
	    vectorr.erase(it);
	    delete(dynamic_cast<VideoGames*>(*it));
	    return;
	  }
	  else{
	    cout << "okay, not deleting" << endl;
	  }
	}
	if((*it)->getType() == 2){
	  char toPrint2[80];
	  strcpy(toPrint2,(dynamic_cast<Music*>(*it))->getArtist());
	  cout << "by " << toPrint2 << ", ";
	  cout << *(dynamic_cast<Music*>(*it))->getDuration() << " seconds long, ";
	  char toPrint3[80];
	  strcpy(toPrint3,(dynamic_cast<Music*>(*it))->getPublisher());
	  cout << "and published by "<< toPrint3 << endl;
	  cout << "do you want to delete the above song? (y/n)?" << endl;
	  char yn[2];
	  cin>>yn;
	  cin.get();
	  if(yn[0]=='y' || yn[0]=='Y'){
	    vectorr.erase(it);
	    delete(dynamic_cast<Music*>(*it));
	    return;
	  }
	  else{
	    cout << "okay, not deleting" << endl;
	  }
	}
	if((*it)->getType() == 3){
	  char toPrint2[80];
	  strcpy(toPrint2,(dynamic_cast<Movies*>(*it))->getDirector());
	  cout << "directed by " << toPrint2 << ", ";
	  cout << *(dynamic_cast<Movies*>(*it))->getDuration() << " minutes long, ";
	  cout << "and is rated "<< *(dynamic_cast<Movies*>(*it))->getRating()<< " stars" << endl;
	  cout << "do you want to delete the above movie? (y/n)?" << endl;
	  char yn[2];
	  cin>>yn;
	  cin.get();
	  if(yn[0]=='y' || yn[0]=='Y'){
	    vectorr.erase(it);
	    delete(dynamic_cast<Movies*>(*it));
	    return;
	  }
	  else{
	    cout << "okay, not deleting" << endl;
	  }
	}
      }
    }
  }
  //same as for year search
  else if(input[0]=='t' || input[0] || 'T'){
    cout << "please enter the title" << endl;
    char title[80];
    cin.get(title,80);
    cin.get();
    for(vector<Media*>::iterator it = vectorr.begin(); it!=vectorr.end();it++){
      if(strcmp(((*it)->getTitle()),title)==0){
	char toPrint1[80];
	strcpy(toPrint1,(*it)->getTitle());
	cout << toPrint1 <<", ";
	cout << *(*it)->getYear() << ", ";
	if((*it)->getType() == 1){
	  cout << *(dynamic_cast<VideoGames*>(*it))->getRating() << " stars, ";
	  char toPrint2[80];
	  strcpy(toPrint2,(dynamic_cast<VideoGames*>(*it))->getPublisher());
	  cout << "published by " << toPrint2 << endl;
	  cout << "do you want to delete the above video game? (y/n)?" << endl;
	  char yn[2];
	  cin>>yn;
	  cin.get();
	  if(yn[0]=='y' || yn[0]=='Y'){
	    vectorr.erase(it);
	    delete(dynamic_cast<VideoGames*>(*it));
	    return;
	  }
	  else{
	    cout << "okay, not deleting" << endl;
	  }
	}
	if((*it)->getType() == 2){
	  char toPrint2[80];
	  strcpy(toPrint2,(dynamic_cast<Music*>(*it))->getArtist());
	  cout << "by " << toPrint2 << ", ";
	  cout << *(dynamic_cast<Music*>(*it))->getDuration() << " seconds long, ";
	  char toPrint3[80];
	  strcpy(toPrint3,(dynamic_cast<Music*>(*it))->getPublisher());
	  cout << "and published by "<< toPrint3 << endl;
	  cout << "do you want to delete the above song? (y/n)?" << endl;
	  char yn[2];
	  cin>>yn;
	  cin.get();
	  if(yn[0]=='y' || yn[0]=='Y'){
	    vectorr.erase(it);
	    delete(dynamic_cast<Music*>(*it));
	    return;
	  }
	  else{
	    cout << "okay, not deleting" << endl;
	  }
	}
	if((*it)->getType() == 3){
	  char toPrint2[80];
	  strcpy(toPrint2,(dynamic_cast<Movies*>(*it))->getDirector());
	  cout << "directed by " << toPrint2 << ", ";
	  cout << *(dynamic_cast<Movies*>(*it))->getDuration() << " minutes long, ";
	  cout << "and is rated "<< *(dynamic_cast<Movies*>(*it))->getRating()<< " stars" << endl;
	  cout << "do you want to delete the above movie? (y/n)?" << endl;
	  char yn[2];
	  cin>>yn;
	  cin.get();
	  if(yn[0]=='y' || yn[0]=='Y'){
	    vectorr.erase(it);
	    delete(dynamic_cast<Movies*>(*it));
	    return;
	  }
	  else{
	    cout << "okay, not deleting" << endl;
	  }
	}
      }
    }
  }
}

void addData(vector<Media*> &vectorr){
  char input1[80];
  cout << "Please print out the type of media you would like to add: video games, music or movies" << endl;
  cin.get(input1,80);
  cin.get();
  //for each media type, create a new instance of that media type, then enter the fields specific to that media types, finally add it to the vector
  if(input1[1]=='i' || input1[1]=='I'){
    VideoGames* vc= new VideoGames();
    vc->setType(1);
    cout << "Please enter the title" << endl;
    char title[80];
    cin.get(title,80);
    cin.get();
    vc->setTitle(title);
    cout << "Please enter the year" << endl;
    int year;
    cin >> year;
    cin.get();
    vc->setYear(year);
    cout << "Please enter the publisher" << endl;
    char publisher[80];
    cin.get(publisher,80);
    cin.get();
    vc->setPublisher(publisher);
    cout << "Please enter the star rating" << endl;
    float rating;
    cin >> rating;
    cin.get();
    vc->setRating(rating);
    vectorr.push_back(vc);
  }
  else if(input1[1]=='u' || input1[1]=='U'){
    Music* m = new Music();
    m->setType(2);
    cout << "Please enter the title" << endl;
    char title[80];
    cin.get(title,80);
    cin.get();
    m->setTitle(title);
    cout << "Please enter the year" << endl;
    int year;
    cin >> year;
    cin.get();
    m->setYear(year);
    cout << "Please enter the artist's name" << endl;
    char artist[80];
    cin.get(artist,80);
    cin.get();
    m->setArtist(artist);
    cout << "Please enter the duration in seconds" << endl;
    float duration;
    cin >> duration;
    cin.get();
    m->setDuration(duration);
    cout << "Please enter the publisher" << endl;
    char publisher[80];
    cin.get(publisher,80);
    cin.get();
    m->setPublisher(publisher);
    vectorr.push_back(m);
  }
  else if(input1[1]=='o' || input1[1]=='O'){
    Movies* mo = new Movies();
    mo->setType(3);
    cout << "Please enter the title" << endl;
    char title[80];
    cin.get(title,80);
    cin.get();
    mo->setTitle(title);
    cout << "Please enter the year" << endl;
    int year;
    cin >> year;
    cin.get();
    mo->setYear(year);
    cout << "Please enter the director's name" << endl;
    char director[80];
    cin.get(director,80);
    cin.get();
    mo->setDirector(director);
    cout << "Please enter the duration in minutes" << endl;
    float duration;
    cin >> duration;
    cin.get();
    mo->setDuration(duration);
    cout << "Please enter the star rating" << endl;
    float rating;
    cin >> rating;
    cin.get();
    mo->setRating(rating);
    vectorr.push_back(mo);
  }
  else{
    cout << "Sorry, invalid data type" << endl;
    return;
  }
		     
}
