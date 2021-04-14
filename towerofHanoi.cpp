#include <vector>
#include <string>
#include <iostream>

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

void generate(State& current)
{
   findAndRemove(current.peg1, current.peg2, current.peg3);
  //   if it is already in the frointer, display "Regenerated"
  //      and then display "Updated f" if f is better
  //          and also replace the old version in the frontier.
  // Otherwise, add the state to the end of frontier
  for(int i = 0; i < border.size(); i++) {
    if(frontier[i].peg1 == current.peg1 && frontier[i].peg2 == current.peg2 && frontier[i].peg3 == current.peg3) {
      cout << "Regenerated State" << endl;
      if(frontier[i].f < current.f) {
        cout << "Updated f" << endl;
        current.f = frontier[i].f;
        return;
      }
    }
  }
  State addToFrontier;
  addToFrontier.goal = false;
  // if-then-rules to generate new safe states from current
  if(current.peg1 == "TMB" && current.peg2 == "0" && current.peg3 == "0") {
    current.g = 0;
    current.h = hValue("TMB", "0", "0");
    current.f = current.h + current.g;
    addToFrontier.peg1 = "MB";
    addToFrontier.peg2 = "T";
    addToFrontier.peg3 = "0";
    addToFrontier.g = 1;
                    // T   M   B Cost
    addToFrontier.h = hValue("MB", "T", "0");
    addToFrontier.f = addToFrontier.g + addToFrontier.h;
    if(!inFrontier(addToFrontier.peg1, addToFrontier.peg2, addToFrontier.peg3)) {
      frontier.push_back(addToFrontier);
    }
    addToFrontier.peg1 = "MB";
    addToFrontier.peg2 = "0";
    addToFrontier.peg3 = "T";
    addToFrontier.g = 1;
                    // T   M   B Cost
    addToFrontier.h = hValue("MB", "0", "T");
    addToFrontier.f = addToFrontier.g + addToFrontier.h;
    if(!inFrontier(addToFrontier.peg1, addToFrontier.peg2, addToFrontier.peg3)) {
      frontier.push_back(addToFrontier);
    }
    findNRemove("TMB", "0", "0");
    return;
  }
  else if(current.peg1 == "MB" && current.peg2 == "0" && current.peg3 == "T") {
    current.g = 1;
    current.h = hValue("MB", "0", "T");
    current.f = current.g + current.h;
    addToFrontier.peg1 = "B";
    addToFrontier.peg2 = "M";
    addToFrontier.peg3 = "T";
    addToFrontier.g = 2;
                    // T   M   B Cost
    addToFrontier.h = hValue("B", "M", "T");
    addToFrontier.f = addToFrontier.g + addToFrontier.h;
    if(!inFrontier(addToFrontier.peg1, addToFrontier.peg2, addToFrontier.peg3)) {
      frontier.push_back(addToFrontier);
    }
    findNRemove("MB", "0", "T");
    return;
  }
  else if(current.peg1 == "B" && current.peg2 == "M" && current.peg3 == "T") {
    current.g = 2;
    current.h = hValue("B", "M", "T");
    current.f = 6;
    addToFrontier.peg1 = "B";
    addToFrontier.peg2 = "TM";
    addToFrontier.peg3 = "0";
    addToFrontier.g = 3;
                    // T   M   B Cost
    addToFrontier.h = hValue("B", "TM", "0");
    addToFrontier.f = addToFrontier.g + addToFrontier.h;
    if(!inFrontier(addToFrontier.peg1, addToFrontier.peg2, addToFrontier.peg3)) {
      frontier.push_back(addToFrontier);
    }
    findNRemove("B", "M", "T");
    return;
  }
  else if(current.peg1 == "B" && current.peg2 == "TM" && current.peg3 == "0") {
    current.g = 3;
    current.h = hValue("B", "TM", "0");
    current.f = current.g + current.f;
    addToFrontier.peg1 = "0";
    addToFrontier.peg2 = "TM";
    addToFrontier.peg3 = "B";
    addToFrontier.g = 4;
                    // T   M   B Cost
    addToFrontier.h = hValue("0", "TM", "B");
    addToFrontier.f = addToFrontier.g + addToFrontier.h;
    if(!inFrontier(addToFrontier.peg1, addToFrontier.peg2, addToFrontier.peg3)) {
      frontier.push_back(addToFrontier);
    }
    addToFrontier.peg1 = "TB";
    addToFrontier.peg2 = "M";
    addToFrontier.peg3 = "0";
    addToFrontier.g = 4;
                    // T   M   B Cost
    addToFrontier.h = hValue("TB", "M", "0");
    addToFrontier.f = addToFrontier.g + addToFrontier.h;
    if(!inFrontier(addToFrontier.peg1, addToFrontier.peg2, addToFrontier.peg3)) {
      frontier.push_back(addToFrontier);
    }
    findNRemove("B", "TM", "0");
    return;
  }
  else if(current.peg1 == "0" && current.peg2 == "TM" && current.peg3 == "B") {
    current.g = 4;
    current.h = hValue("0", "TM", "B");
    current.f = current.g + current.h;
    addToFrontier.peg1 = "T";
    addToFrontier.peg2 = "M";
    addToFrontier.peg3 = "B";
    addToFrontier.g = 5;
                    // T   M   B Cost
    addToFrontier.h = hValue("T", "M", "B");
    addToFrontier.f = addToFrontier.g + addToFrontier.h;
    if(!inFrontier(addToFrontier.peg1, addToFrontier.peg2, addToFrontier.peg3)) {
      frontier.push_back(addToFrontier);
    }
    addToFrontier.peg1 = "0";
    addToFrontier.peg2 = "M";
    addToFrontier.peg3 = "TB";
    addToFrontier.g = 5;
                    // T   M   B Cost
    addToFrontier.h = hValue("0", "M", "TB");
    addToFrontier.f = addToFrontier.g + addToFrontier.h;
    if(!inFrontier(addToFrontier.peg1, addToFrontier.peg2, addToFrontier.peg3)) {
      frontier.push_back(addToFrontier);
    }
    findNRemove("0", "TM", "B");
    return;
  }
  else if(current.peg1 == "T" && current.peg2 == "M" && current.peg3 == "B") {
    current.g = 5;
    current.h = hValue("T", "M", "B");
    current.f = current.h + current.g;
    addToFrontier.peg1 = "T";
    addToFrontier.peg2 = "0";
    addToFrontier.peg3 = "MB";
    addToFrontier.g = 6;
                    // T   M   B Cost
    addToFrontier.h = hValue("T", "0", "MB");
    addToFrontier.f = addToFrontier.g + addToFrontier.h;
    if(!inFrontier(addToFrontier.peg1, addToFrontier.peg2, addToFrontier.peg3)) {
      frontier.push_back(addToFrontier);
    }
    findNRemove("T", "M", "B");
    return;
  }
  else if(current.peg1 == "T" && current.peg2 == "0" && current.peg3 == "MB") {
    current.g = 6;
    current.h = hValue("T", "0", "MB");
    current.f = current.h + current.g;
    addToFrontier.peg1 = "0";
    addToFrontier.peg2 = "0";
    addToFrontier.peg3 = "TMB";
    addToFrontier.goal = true;
    addToFrontier.g = 7;
                    // T   M   B Cost
    addToFrontier.h = hValue("0", "0", "TMB");
    addToFrontier.f = addToFrontier.g + addToFrontier.h;
    if(!inFrontier(addToFrontier.peg1, addToFrontier.peg2, addToFrontier.peg3)) {
      frontier.push_back(addToFrontier);
    }
    findNRemove("T", "0", "MB");
    return;
  }
  else if(current.peg1 == "0" && current.peg2 == "0" && current.peg3 == "TMB") {
    current.g = 7;
    current.h = hValue("0", "0", "TMB");
    current.f = current.h + current.g;
    findNRemove("0", "0", "TMB");
    return;
  }
  // ----------------------------------------------------------------------------------------
  else if(current.peg1 == "0" && current.peg2 == "M" && current.peg3 == "TB") {
    current.g = 6;
    current.h = hValue("0", "M", "TB");
    current.f = current.g + current.h;
    addToFrontier.peg1 = "M";
    addToFrontier.peg2 = "0";
    addToFrontier.peg3 = "TB";
    addToFrontier.g = 7;
                    // T   M   B Cost
    addToFrontier.h = hValue("M", "0", "TB");
    addToFrontier.f = addToFrontier.g + addToFrontier.h;
    if(!inFrontier(addToFrontier.peg1, addToFrontier.peg2, addToFrontier.peg3)) {
      frontier.push_back(addToFrontier);
    }
    findNRemove("0", "M", "TB");
    return;
  }
  else if(current.peg1 == "M" && current.peg2 == "0" && current.peg3 == "TB") {
    current.g = 7;
    current.h = hValue("M", "0", "TB");
    current.f = current.g + current.h;
    addToFrontier.peg1 = "M";
    addToFrontier.peg2 = "0";
    addToFrontier.peg3 = "TB";
    addToFrontier.g = 8;
                    // T   M   B Cost
    addToFrontier.h = hValue("M", "0", "TB");
    addToFrontier.f = addToFrontier.g + addToFrontier.h;
    if(!inFrontier(addToFrontier.peg1, addToFrontier.peg2, addToFrontier.peg3)) {
      frontier.push_back(addToFrontier);
    }
    findNRemove("M", "0", "TB");
    return;
  }
  else if(current.peg1 == "MB" && current.peg2 == "T" && current.peg3 == "0") {
    current.g = 1;
    current.h = hValue("MB", "T", "0");
    current.f = current.g + current.h;
    addToFrontier.peg1 = "B";
    addToFrontier.peg2 = "T";
    addToFrontier.peg3 = "M";
    addToFrontier.g = 8;
                    // T   M   B Cost
    addToFrontier.h = hValue("M", "0", "TB");
    addToFrontier.f = addToFrontier.g + addToFrontier.h;
    if(!inFrontier(addToFrontier.peg1, addToFrontier.peg2, addToFrontier.peg3)) {
      frontier.push_back(addToFrontier);
    }
    findNRemove("M", "0", "TB");
    return;
    }
    
}

// function to find the best state in the border state
State bestofBorder(State best)
{
    //if the border is not empty; by default the current state should be the best
    if(border.size()) {
    best.peg1 = border[0].peg1;
    best.peg2 = border[0].peg2;
    best.peg3 = border[0].peg3;
    best.f = border[0].f;
    best.g = border[0].g;
    best.h = border[0].h;
  }
    //find the best f state in the border, remove it, and return it
    for(int i = 0; i < border.size(); i++) {
    if(border[i].goal) {
      std::cout << "[Goal In Frontier]: Setting Current State To Goal!" << std::endl;
      best.peg1 = border[0].peg1;
      best.peg2 = border[0].peg2;
      best.peg3 = border[0].peg3;
      best.f = border[i].f;
      best.g = border[i].g;
      best.h = border[i].h;
      best.goal = border[i].goal;
      return best;
    }
    if(border[i].h < best.h) {
      std::cout << "Found Best" << std::endl;
      best.peg1 = border[0].peg1;
      best.peg2 = border[0].peg2;
      best.peg3 = border[0].peg3;
      best.f = border[i].f;
      best.g = border[i].g;
      best.h = border[i].h;
      best.goal = border[i].goal;
    }
  }
  return best;
}

int main()
{
    int i = 0;
    
    // T and B is not on center nor end
    State current = {"TMB", "0", "0", 0, hValue("TMB", "0", "0"), 3, false}; //T and B is not on center nor end.
  do {
      if(current.goal) {
        std::cout << "Goal Reached!" << std::endl;
        break;
      }
      std::cout << ">>>Expand:" << current.peg1 << " " << current.peg2 << " " << current.peg3 << std::endl;
      generate(current);
      std::cout << "Frontier is:" << std::endl;
      displayBorder();
      current = bestofBorder(current);
      i++;
    }while (!current.goal);// end while
  return 0;
}