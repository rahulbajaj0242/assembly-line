// Name: Rahul Bajaj
// Seneca Student ID: 107707218
// Seneca email: rbajaj12@myseneca.ca
// Date of completion: Nov 16, 2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include "Utilities.h"
#include <string.h>
#include "sstream"

using namespace std;

namespace sdds {

  char Utilities::m_delimiter = ' ';

  std::string Utilities::trim(std::string &str){
    int start = str.find_first_not_of(' ');
    int end = str.find_last_not_of(' ');
    return str.substr(start, end-start+1);
  }

  void Utilities::setFieldWidth(size_t newWidth) {
    m_widthField = newWidth;
  }

  size_t Utilities::getFieldWidth() const {
    return m_widthField;
  }

  std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more) {
    if(more) {
      string token;
      string stringAtPos = str.substr(next_pos);
      stringstream s(stringAtPos);
      if(stringAtPos[0] == m_delimiter) {
        more = false;
        throw "Delimiter Found!";
      }

      auto delFound = stringAtPos.find(m_delimiter);

      if(delFound == string::npos) {
        getline(s, token, '\n');
        token = trim(token);
        if(m_widthField < token.size()) m_widthField= token.size();
        more = false;
        return token;
      }
      else if(getline(s, token, m_delimiter)) {
        size_t currPos = str.find(token);
        token = trim(token);
        next_pos = str.find(m_delimiter, currPos);
        more = true;
        if(next_pos == string::npos) {
          more= false;
        }
        else {
          next_pos++;
        }
        if(m_widthField < token.size()) m_widthField= token.size();
        return token;
      }
      more = false;
    }
    return "NULL";
  }

  void Utilities::setDelimiter(char newDelimiter) {
    m_delimiter = newDelimiter;
  }

  char Utilities::getDelimiter() {
    return m_delimiter;
  }

}