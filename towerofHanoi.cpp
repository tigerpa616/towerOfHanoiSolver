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

//  h (x)= (the total number of disks on the left and middle pegs) + 2*（number of disks that are in the right peg and smaller than any disk that is in the left or middle peg）
int hValue(std::string p1, std::string p2, std::string p3)

{
    std::vector<char> findings;
    int h = 0;
    
    //if peg 1 is not empty
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

    //if peg 2 is not empty
    if(p2 != "0")
    {
        for(int i = 0; i < p2.length(); i++)
        {
            if(p2[i] == 'T' || p2[i] == 'M' || p2[i] == 'B')
            {
                findings.push_back(p2[i]);
                h = h + 1;
            }
        }
    }

    //if peg 3 is not empty
    if(p3 != "0")
    {
        if(p3[0] == 'T')
        {
            for(int i = 0; i < findings.size(); i++)
            {
                if(p2[i] == 'M' || p2[i] == 'B')
                {
                    h = h + 2;
                }
            }
        }
        
    }

    //else if peg 3 contains the middle ring
    else if(p3[0] == 'M')
    {
        for(int i = 0; i < findings.size(); i++)
        {
            //if peg 3 also contains the bottom ring
            if(findings[i] == 'B')
            {
                h = h + 2;
            }
        }
    }

    return h;
}

void displayState(State toDisplay)
{
    std::cout << toDisplay.peg1 << " ";
    std::cout << toDisplay.peg2 << " ";
    std::cout << toDisplay.peg3 << " " << std::endl;

    std::cout << "g: " << toDisplay.g << " ";
    std::cout << "h: " << toDisplay.h << " ";
    std::cout << "f: " << toDisplay.f << " ";

    if(toDisplay.goal)
    {
        std::cout << "Goal: Achieved" << std::endl;
        return;
    }

    std::cout << "Goal: Not Achieved" << std::endl;
}