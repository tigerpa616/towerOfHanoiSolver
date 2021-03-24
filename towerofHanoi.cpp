#include <iostream>
#include <vector>
#include <string>

struct State {
  std::string peg1;
  std::string peg2;
  std::string peg3;
  int g;
  int h;
  int f;
  bool goal;
};

std::vector<State> border;