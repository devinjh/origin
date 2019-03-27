
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
    std::string s2 = "";
    getline(infile, s2);
    //std::cout << s2 << std::endl;

    std::cout << "\n---\n" << std::endl;

    std::istringstream inn(s2);
    std::istreambuf_iterator<char> first(inn);
    std::istreambuf_iterator<char> last;
    std::string s3(first, last);
    json::Value* val = json::parse(s3);
    std::cout << *val << '\n';
  }
  else
  {
    std::cout << "did not open file" << std::endl;
  }

  std::cout << "done" << std::endl;
}