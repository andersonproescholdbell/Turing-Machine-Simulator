#include <iostream>
#include "Turing.h"
using namespace std;

int main(int argc, char* argv[]) {
  // create Turing Machine here
  Turing tm = Turing();

  // example from week 8 to find if there are a majority of 1s in a string
  tm.addState(0, true, false);
  tm.addState(1, false, false);
  tm.addState(2, false, false);
  tm.addState(3, false, false);
  tm.addState(4, false, false);
  tm.addState(5, false, false);
  tm.addState(6, false, false);
  tm.addState(7, false, false);
  tm.addState(8, false, true);
  tm.addTransition(0, 1, 's', 's', 'R');
  tm.addTransition(1, 1, 'x', 'x', 'R');
  tm.addTransition(1, 1, '1', '1', 'R');
  tm.addTransition(1, 2, '0', 'x', 'L');
  tm.addTransition(1, 5, 'e', 'e', 'L'); //
  tm.addTransition(2, 2, '0', '0', 'L');
  tm.addTransition(2, 2, 'x', 'x', 'L');
  tm.addTransition(2, 2, '1', '1', 'L');
  tm.addTransition(2, 3, 's', 's', 'R');
  tm.addTransition(3, 3, 'x', 'x', 'R');
  tm.addTransition(3, 3, '0', '0', 'R');
  tm.addTransition(3, 4, '1', 'x', 'L');
  tm.addTransition(3, 5, 'e', 'e', 'L'); //
  tm.addTransition(4, 4, 'x', 'x', 'L');
  tm.addTransition(4, 4, '0', '0', 'L');
  tm.addTransition(4, 4, '1', '1', 'L');
  tm.addTransition(4, 1, 's', 's', 'R');
  tm.addTransition(5, 5, 'x', 'x', 'L');
  tm.addTransition(5, 5, '0', '0', 'L');
  tm.addTransition(5, 5, '1', '1', 'L');
  tm.addTransition(5, 6, 's', 's', 'R');
  tm.addTransition(6, 6, 'x', 'x', 'R');
  tm.addTransition(6, 7, '0', '0', 'H');
  tm.addTransition(6, 7, 'e', 'e', 'H');
  tm.addTransition(6, 8, '1', '1', 'H');

  // delay
  cout << "Give a delay in ms: ";
  int delay;
  cin >> delay;
  tm.setDelay(delay);
  
  // give Turing string here
  cout << "Give a string for the Turing Machine to process: ";
  string s;
  cin >> s;

  tm.setTape(s);
  tm.start();
    
  if (tm.end()) {
    cout << "The Turing Machine ended in an ACCEPT state";
  } else {
    cout << "The Turing Machine ended in a REJECT state";
  }
  cout << " on input " << s << endl;

  return 0;
}
