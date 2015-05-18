#include "Student.h"
#include <sqlite3.h>
#include <string>
//#include <iostream>

long Student::nextID = 0;
//sqlite3_open("database.sl3", &Student::connection);

/*
int error = sqlite3_open("database.sl3", &Student::connection);
if (error) {
  std::cerr << "Database could not be opened." << std::endl;
  return 0;
}
//*/

const long Student::errorID = -1;
const std::string Student::errorLastName = "VOID";
const std::string Student::errorFirstName = "VOID";

Student::Student() {
  this->id = errorID;
  this->lastName = errorLastName;
  this->firstName = errorFirstName;
}

Student::Student(std::string lastName, std::string firstName) {
  if (!exists(lastName, firstName)) {
    this->id = getNextID();
    this->lastName = lastName;
    this->firstName = firstName;
    save();
  } else {
    this->id = errorID;
    this->lastName = errorLastName;
    this->firstName = errorFirstName;
  }
}

bool Student::exists(std::string lastName, std::string firstName) {
  return true;
  // connect to database and check
  /*
  int main() {
    sqlite3 *connection;
    sqlite3_stmt *result;
    int error = 0;
    const char *errorMessage; //isn't used?
    const char *tail;

    error = sqlite3_open("test.sl3", &connection);
    if (error) {
      //printf("Database could not be opened.");
      std::cout << "Database could not be opened." << std::endl;
      return 0;
    }

    sqlite3_close(connection);

    return 0;
  }
  */
}

bool Student::save() {
  return true;
}
