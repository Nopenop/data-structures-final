#ifndef READER_H
#define READER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
// Reader OBJECT
/*
TO CREATE A READER OBJECT, USE THE FOLLOWING PARAMETERS:
  std::string path; - This is the filepath the csv file you want to read

OBJECT METHODS:
  std::vector<std::string> getColumn(const std::string& key); - returns string
vector with given key name. If key does not exists, throws error
  std::vector<std::string> getRow(int index) - returns string vector generated
from row within columns matrix
  void printKeys() const; prints all key names the console
*/
class Reader {
  // take a string and create string vector
  std::vector<std::string> makeRow(std::string rowStr) {
    std::vector<std::string> curRow;
    std::string curStr;
    bool inQuotes = false;
    int i = 0;
    while (i < rowStr.size()) {
      if (inQuotes) {
        curStr += rowStr[i];
      } else if (rowStr[i] == ',') {
        curRow.push_back(curStr);
        curStr = "";
      } 
      else
        curStr += rowStr[i];
      i++;
      if(rowStr[i] == '\"') {
        inQuotes = !inQuotes;
        i++;
      }
    }
    curRow.push_back(curStr);
    return curRow;
  }

public:
  std::vector<std::string> columnNames;
  std::vector<std::string> *columns;
  // CONSTRUCTOR FOR READER OBJECT
  /*
  PARAMETERS:
    Takes filepath string as parameter to read from csv file
  RETURNS:
    Returns the Reader object
  */
  Reader(std::string path) {
    std::fstream input;
    input.open(path, std::ifstream::in);
    for (std::string line; getline(input, line);) {
      std::vector<std::string> row = makeRow(line);
      if (columnNames.empty()) {
        for (std::string columnName : row) {
          columnNames.push_back(columnName);
        }
        columns = new std::vector<std::string>[columnNames.size()];
      } else {
        for (int i = 0; i < row.size(); i++) {
          columns[i].push_back(row[i]);
        }
      }
    }
    input.close();
  }
  // PRINT KEYS FUNCTION
  /*
  OUTPUTS TO TERMINAL ALL KEY VALUES GENERATED FROM CSV FILE
  */
  void printKeys() {
    for (std::string name : columnNames) {
      std::cout << name << std::endl;
    }
  }

  // GET ROW FUNCTION
  /*
  PARAMETERS:
  Takes the int index as parameter
  RETURNS:
  returns a string vector with row's values
  */
  std::vector<std::string> getRow(int index) {
    if (index > columns[0].size())
      throw std::string("Error: Reader: getRow: index out of range");
    std::vector<std::string> row;
    for (int i = 0; i < columnNames.size(); i++) {
      row.push_back(columns[i].at(index));
    }
    return row;
  }

  // GET COLUMN FUNCTION
  /*
  PARAMETERS:
  Takes std::string key as parameter
  RETURNS:
  returns string vector column if key is in column names
  */
  std::vector<std::string> getColumn(std::string key) {
    for (int i = 0; i < columnNames.size(); i++) {
      if (columnNames[i] == key)
        return columns[i];
    }
    throw std::string("Error: Reader: getColumn: key not found");
  }
};

#endif