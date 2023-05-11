#ifndef __PRINTJOB_H
#define __PRINTJOB_H

#include <iostream>
#include <cstdlib>

using namespace std;

class PrintJob 
{
private:
  int priority; // the priority of the print job
  int jobNumber; // the job number of the print job
  int numPages; // the number of pages to print for this job

public:
  /*
    Constructor for creating a new PrintJob object with the given priority,
    job number, and number of pages to print.
    Parameters:
      - int priority: the priority of the print job
      - int jobNumber: the job number of the print job
      - int numPages: the number of pages to print for this job
  */
  PrintJob (int priority, int jobNumber, int numPages);

  /*
    Getter method for getting the priority of the print job.
    Return value: int representing the priority of the print job.
  */
  int getPriority();

  /*
    Getter method for getting the job number of the print job.
    Return value: int representing the job number of the print job.
  */
  int getJobNumber();

  /*
    Getter method for getting the number of pages to print for this job.
    Return value: int representing the number of pages to print for this job.
  */
  int getPages();
};
#endif
