#ifndef TURING_H
#define TURING_H

#include <vector>
#include <map>
using namespace std;

class Turing {
 public:
  Turing();
  ~Turing();
  void addState(int num, bool start, bool accepting);
  void addTransition(int start, int end, char on, char write, char move);
  void setTape(string s);
  char transition(char c);
  void start();
  bool end();
  void setDelay(int d);
 private:
  int currentState;
  int tapeIndex;
  int delay;
  vector<char> tape;
  map<int, bool> states;
  map<int, map<char, tuple<char, char, int>>> transitions;
  void moveLeft();
  void moveRight();
  void write(char c);
};

#endif
