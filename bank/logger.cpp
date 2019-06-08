#include "logger.h"

Logger::Logger() {
    // Do Nothing
}

Logger::Logger(string fileName) {
    // Save this filename and append the current date
    this->fileName = fileName;
    time_t rawtime;
    struct tm *timeinfo;
    char buffer[80];
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer, 80, "_%m_%d_%Y.txt", timeinfo);
    this->fileName += buffer;

    // Creating a directory
    if (mkdir("logs") == -1)
        cerr << "Error in logger: " << strerror(errno) << endl;
    else
        cout << "Logs directory created" << endl;

    // open a file in write mode.
    // TODO: TEST THIS ON WINDOWS
    ofstream outfile;
    outfile.open("logs/" + this->fileName); // File path may be platform specific
    outfile << "Logfile Created" << endl;
    outfile.close(); 
}

void Logger::log(string message) {
    ofstream outfile;
    outfile.open("logs/" + this->fileName, ios_base::app);
    outfile << message << endl;
    outfile.close(); 
}
