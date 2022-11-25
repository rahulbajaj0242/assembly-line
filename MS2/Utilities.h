// Name: Rahul Bajaj
// Seneca Student ID: 107707218
// Seneca email: rbajaj12@myseneca.ca
// Date of completion: Nov 16, 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.


#ifndef UTILITIES_H
#define UTILITIES_H
#include <string>

namespace sdds {

  class Utilities {
    std::size_t m_widthField{1};
    static char m_delimiter;

  public:
    void setFieldWidth(size_t newWidth);
    std::string trim(std::string &str);
    size_t getFieldWidth() const;
    std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
    static void setDelimiter(char newDelimiter);
    static char getDelimiter();
  };
  
}

#endif