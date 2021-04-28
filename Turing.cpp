#include <iostream>
#include <vector>
#include <map>
#include "Turing.h"
#include <unistd.h>
using namespace std;

Turing::Turing() {
  currentState = 0;
  tapeIndex = 0;
  delay = 0;
  tape.push_back('s'); // start
  tape.push_back('e'); // end
}

Turing::~Turing() {

}

void Turing::addState(int num, bool start, bool accepting) {
  if (start) {
    currentState = num;
  }
  states.insert(pair<int, bool>(num, accepting));
}

void Turing::addTransition(int start, int end, char on, char write, char move) {
  tuple<char, char, int> t = tuple<char, char, int>(write, move, end);
  if (transitions.find(start) == transitions.end()) {
    map<char, tuple<char, char, int>> m;
    m.insert(pair<char, tuple<char, char, int>>(on, t));
    transitions.insert(pair<int, map<char, tuple<char, char, int>>>(start, m));
  } else {
    transitions.find(start)->second.insert(pair<char, tuple<char, char, int>>(on, t));
  }
}

void Turing::setTape(string s) {
  for (int i = 0; i < s.length(); i++) {
    tape.insert(tape.begin()+1+i, s[i]);
  }
}

char Turing::transition(char c) {
  tuple<char, char, int> t = transitions.find(currentState)->second.find(c)->second;

  usleep(delay);
  write(get<0>(t));
  currentState = get<2>(t);

  // print the tape
  for (int i = 0; i < tape.size(); i++) {
    if (i == tapeIndex) {
      cout << "[" << tape[i] << "]";
    } else {
      cout << tape[i];
    }
  }
  cout << endl;
  
  char move = get<1>(t);
  if (move == 'L') {
    moveLeft();
  } else if (move == 'R') {
    moveRight();
  } else if (move == 'H') {
    return char(0);
  }

  return tape[tapeIndex];
}

void Turing::start() {
  char c = transition('s');
  while (c != char(0)) {
    c = transition(c);
  }
}

bool Turing::end() {
  return states.find(currentState)->second;
}

void Turing::setDelay(int d) {
  delay = d * 1000;
}

void Turing::moveLeft() {
  tapeIndex--;
}

void Turing::moveRight() {
  tapeIndex++;
}

void Turing::write(char c) {
  tape[tapeIndex] = c;
}
