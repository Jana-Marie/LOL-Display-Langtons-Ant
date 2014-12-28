#include "Charliplexing.h"

int del = 80; // change delay between ant moves

//int antLoc[]{7,4};                      //Starting point (is set to random right now
int antLoc[]{random(2,12),random(1,8)};

int antDirection = random(1,4);           //starting direction (also random)



int  rows = 14;        //display size
int  columns = 9;

boolean state[14][9];

void setup() {
  LedSign::Init();           
  for(int j = 0; j < rows; j++){
    for(int i = 0; i < columns; i++){
      state[j][i] = false;
    }
  }
}

void loop(){
  updateScene();
}

void turnLeft(){
  if (antDirection > 1){
    antDirection--;
  } 
  else{
    antDirection = 4;
  }
}

void turnRight(){
  if (antDirection < 4){
    antDirection++;
  } 
  else {
    antDirection = 1;
  }
}

void moveForward(){
  if (antDirection == 1){
    antLoc[0]--;
  }
  if (antDirection == 2){
    antLoc[1]++;
  }
  if (antDirection == 3){
    antLoc[0]++;
  }
  if (antDirection == 4){
    antLoc[1]--;
  }
}

void updateScene(){
  moveForward();
  if (state[antLoc[0]][antLoc[1]] == 0){
    if(antLoc[0] > 13){
      antLoc[0] = 0;
    }
    if( antLoc[0] < 0){
      antLoc[0] = 13;
    }
    if(antLoc[1] > 8){
      antLoc[1] = 0;
    }
    if (antLoc[1] < 0){
      antLoc[1] = 8;
    }
    state[antLoc[0]][antLoc[1]] = true;
    turnRight();
    LedSign::Set(antLoc[0],antLoc[1],1);
  } 
  else {
    if(antLoc[0] > 13){
      antLoc[0] = 0;
    }
    if(antLoc[0] < 0){
      antLoc[0] = 13;
    }
    if(antLoc[1] > 8){
      antLoc[1] = 0;
    }
    if (antLoc[1] < 0){
      antLoc[1] = 8;
    }
    state[antLoc[0]][antLoc[1]] = false;
    turnLeft();
    LedSign::Set(antLoc[0],antLoc[1],0);
  }
  delay(del);
}





