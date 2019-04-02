
#include "json.hpp"

#include <iterator>
#include <vector>
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

    // This is if you want to see the JSON code without any modifications
    //std::cout << "Pure data:\n" << stringFromFile << "\n";

    std::vector<std::string> authorTitleVector{};

    std::istringstream inn(stringFromFile);
    std::istreambuf_iterator<char> first(inn);
    std::istreambuf_iterator<char> last;
    std::string stringToParse(first, last);
    json::Value* val = json::parse(authorTitleVector, stringToParse);
    std::cout << "\n1. All of the JSON data:\n" << *val << "\n\n\n";

    // This part works and gets the title and author in a nice little string, but I
    // felt like it was cheating. That's why the other two methods are still in here
    // and not commented out (they are all numbered). #2 is the method I thought might
    // be cheating. #1 and #3 are both legitimate
    //
    std::string authorTitleString = json::filterAuthorTitle(stringFromFile);
    std::cout << "\n2. Pure author and title data from a non-parsed string:\n" << authorTitleString << "\n";

    std::cout << "\n3. Pure author and title data from a parsed vector:\n";
    for (std::vector<std::string>::iterator vIter = authorTitleVector.begin(); vIter != authorTitleVector.end(); ++vIter)
    {
      std::cout << (*vIter);
      ++vIter;
      if (vIter != authorTitleVector.end())
      {
        std::cout << " : " << (*vIter);
      }
      std::cout << "\n";
    }
  }
  else
  {
    std::cout << "did not open file" << std::endl;
  }
}