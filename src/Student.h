#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <iostream>
#include <sqlite3.h>
#include <string>

class Student {
  private:
    static sqlite3 *connection;

    static long nextID;
    long id;

    std::string firstName;
    std::string lastName;

  protected:
    static long getNextID() {return nextID++;}
    /**-/static void openConnection() {
      int error = sqlite3_open("database.sl3", &connection);
      if (error) {
        //needs to like crash the program or something
        std::cerr << "Database (database.sl3) could not be opened." << std::endl;
        return;// 0;
      }
    }//*/

  public:
    Student();
    //Student(somehow load another one);
    Student(std::string lastName, std::string firstName);

    void setLastName(std::string lastName);
    void setFirstName(std::string firstName);

    long getID() {return id;}
    std::string getLastName() {return lastName;}
    std::string getFirstName() {return firstName;}

    bool exists(std::string lastName, std::string firstName);
    //bool load();
    bool save();

    const static long errorID;
    const static std::string errorLastName;
    const static std::string errorFirstName;
};

/*
int error = sqlite3_open("database.sl3", &Student::connection);
if (error) {
  std::cerr << "Database could not be opened." << std::endl;
  return 0;
}
//*/

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

#endif // STUDENT_H_INCLUDED
