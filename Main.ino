#include "Charliplexing.h"
#include <Entropy.h>

int del = 80; // change delay between ant moves

int antLoc[]{7,4};//it will be randomseeded late
int antLocold[]{7,4};  //for a fading effect

int antDirection;           //starting direction (also random)



int  rows = 14;        //display size
int  columns = 9;

boolean state[14][9];

void setup() {
  LedSign::Init(GRAYSCALE);           
  for(int j = 0; j < rows; j++){
    for(int i = 0; i < columns; i++){
      state[j][i] = false;
    }
  }
  Entropy.initialize();
  antLoc[0] = Entropy.random(1,13);
  antLoc[1] = Entropy.random(1,8);
  antDirection = Entropy.random(1,4);
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
    LedSign::Set(antLoc[0],antLoc[1],3);
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
    LedSign::Set(antLoc[0],antLoc[1],3);
  }
  if(state[antLocold[0]][antLocold[1]] == 0){
    LedSign::Set(antLocold[0],antLocold[1],0);
  }else if(state[antLocold[0]][antLocold[1]] == 1){
    LedSign::Set(antLocold[0],antLocold[1],7);
  }

  antLocold[0] = antLoc[0];
  antLocold[1] = antLoc[1];
  delay(del);
}





