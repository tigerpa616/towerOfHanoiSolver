

void generate(State& current)
{
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

