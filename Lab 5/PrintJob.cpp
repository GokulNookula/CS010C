#include <iostream>
#include <cstdlib>
#include "PrintJob.h"

using namespace std;

// This is the constructor for the PrintJob class
// It takes three integer arguments: setP, setJ, and numP
// These arguments are used to initialize the member variables priority, jobNumber, and numPages
PrintJob::PrintJob(int setP, int setJ, int numP): priority(setP), jobNumber(setJ), numPages(numP) {}

// This is a getter function for the priority member variable
// It returns an integer value representing the priority of the print job
int PrintJob::getPriority()
{
return priority;
}

// This is a getter function for the jobNumber member variable
// It returns an integer value representing the job number of the print job
int PrintJob::getJobNumber()
{
return jobNumber;
}

// This is a getter function for the numPages member variable
// It returns an integer value representing the number of pages in the print job
int PrintJob::getPages()
{
return numPages;
}
