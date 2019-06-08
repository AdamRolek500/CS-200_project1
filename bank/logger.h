
/**
    logger.h
    Purpose: Create concurrent log files that are dated and matained in a file structure
*/

#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <unistd.h>
#include <iostream>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fstream>
#include <stdio.h>      /* puts */
#include <time.h>

using namespace std;

class Logger
{
public:
    /** Constructors */
    Logger();
    Logger(string fileName);
    /** Utilities */
    void log(string message);

private:
    string fileName; // Name of the log file
};

#endif // LOGGER_H
