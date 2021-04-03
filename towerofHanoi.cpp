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

//this vector is need to be able to check what the next state will be
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

// literally just prints the values from the State struct and checks if the goal state has been reached
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

// literally just prints the values from the border and checks if the goal state has been reached
void displayBorder()
{
    // checks to see if the Goal State is in the border
    for(int k = 0; k < border.size(); k++)
    {
        if(border[k].goal)
        {
            std::cout << "Goal State in Border" << std::endl;
        }

        std::cout << border[k].peg1 << " ";
        std::cout << border[k].peg2 << " ";
        std::cout << border[k].peg3 << " ";

        std::cout << "g = " << border[k].g;
        std::cout << " h = " << border[k].h;
        std::cout << " f = " << border[k].f << std::endl << std::endl;
    }
}

// checks to see if the node in the border matches what it is suppose to be
bool inBorder(std::string p1, std::string p2, std::string p3)
{
    for(int i = 0; i < border.size(); i++)
    {
        if(border[i].peg1 == p1 && border[i].peg2 == p2 && border[i].peg3 == p3)
        {
            return true;
        }
    }
    return false;
}

// function to erase whatever is in the border to prepare for the next value in the border
void findAndRemove(std::string p1, std::string p2, std::string p3)
{
    for(int i = 0; i < border.size(); i++)
    {
        if(border[i].peg1 == p1 && border[i].peg2 == p2 && border[i].peg3 == p3)
        {
            border.erase(border.begin()+i);
        }
    }
}

State bestofBorder(State best)
{
    
}