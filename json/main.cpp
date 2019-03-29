
#include "json.hpp"

#include <iterator>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
  std::ifstream infile;
  infile.open("cpp.json");
  if (infile)
  {
    std::string stringFromFile = "";
    getline(infile, stringFromFile);

    //std::cout << "Pure data:\n" << stringFromFile << "\n";

    std::istringstream inn(stringFromFile);
    std::istreambuf_iterator<char> first(inn);
    std::istreambuf_iterator<char> last;
    std::string stringToParse(first, last);
    json::Value* val = json::parse(stringToParse);
    std::cout << "\nAll of the JSON data:\n" << *val << "\n\n\n";

    // This part works and gets the title and author in a nice little string, but I
    // felt like it was cheating so it's commented out
    //
    //std::string authorTitleString = json::getAuthorTitle(stringFromFile);
    //std::cout << "\nPure author and title data:\n" << authorTitleString << "\n";
  }
  else
  {
    std::cout << "did not open file" << std::endl;
  }
}