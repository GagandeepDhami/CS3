// Gagandeep Dhami
// Professor Bhati
// Lab 04: Roster without Conflicts
// Aug 22 2024

// vector and list algorithms
// Wayne Cheng
// 1/21/2018

// vector and list algorithms
// Wayne Cheng
// 1/21/2018
#include <fstream>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>
using namespace std;
/*
using std::ifstream;
using std::string; using std::getline;
using std::list; using std::vector;
using std::cout; using std::endl;
using std::move;
*/
// reading a list from a fileName
void readRoster(list<string>& roster, string fileName);
// printing a list out
void printRoster(const list<string>& roster);

void dropCS4Students(list<string>& masterRoster, list<string>& dropouts) {
  for (const auto& str : dropouts) {
    for (auto it = masterRoster.begin(); it != masterRoster.end(); ++it) {
      if (*it == str) {
        masterRoster.erase(it);
        break;
      }
    }
  }
}

int main(int argc, char* argv[])
{
  if (argc <= 1)
  {
    cout << "usage: " << argv[0]
      << " list of courses, dropouts last" << endl;
    exit(1);
  }
  // vector of courses of students
  vector <list<string>> courseStudents;
  for(int i=1; i < argc-2; ++i)
  {
    list<string> roster;
    readRoster(roster, argv[i]);
    cout << "\n\n" << argv[i] << "\n";
    printRoster(roster);
    courseStudents.push_back(move(roster));
  }
  // reading in dropouts
  list<string> dropouts;
  readRoster(dropouts, argv[argc-2]);
  cout << "\n\n dropouts \n";
  printRoster(dropouts);

  list<string> allStudents; // master list of students
  for(auto& lst : courseStudents)
    allStudents.splice(allStudents.end(),lst);
  cout << "\n\n all students unsorted \n";
  printRoster(allStudents);

  allStudents.sort(); // sorting master list
  cout << "\n\n all students sorted \n";
  printRoster(allStudents);

  allStudents.unique(); // eliminating duplicates
  cout << "\n\n all students, duplicates removed \n";
  printRoster(allStudents);

  dropCS4Students(allStudents, dropouts); // removing individual dropouts
  cout << "\n\n all students, dropouts removed \n";
  printRoster(allStudents);

  return 0;
}
void readRoster(list<string>& roster, string fileName)
{
  ifstream course(fileName);
  string first, last;
  while(course >> first >> last)
    roster.push_back(first + ' ' + last);
  course.close();

  return;
}
// printing a list out
void printRoster(const list<string>& roster)
{
  for(const auto& str : roster)
    cout << str << endl;

  return;
}