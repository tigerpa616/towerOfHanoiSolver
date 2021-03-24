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

//  h (x)= (the total number of disks of left and middle poles) + 2*（number of disks that in the right pole and smaller than any disk that in left or middle poles）
int hValue(std::string p1, std::string p2, std::string p3)
{
    std::vector<char> findings;
    int h = 0;
    if(p1 != "0")
    {
        for(int i = 0; i < p1.length(); i++)
        {
            if(p1[i] == 'T' || p1[i] == 'M' || p1[i] == 'B')
            {
                findings.push_back(p1[i]);
                h = h + 1;
            }
        }
    }
}