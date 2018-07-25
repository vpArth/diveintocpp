#include <iostream>
#include "LoggerImpl.h"

using std::string;
using std::cout;
using std::endl;

void ST_LoggerImpl::cli_log(const string &str) {
  cout << "SThr[cli]: " << str << endl;
}

void ST_LoggerImpl::file_log(const string &file, const string &str) {
  cout << "SThr[" << file << "]: " << str << endl;
}

void ST_LoggerImpl::socket_log(
    const string &host, int port, const string &str) {
  cout
      << "SThr[" << host << ":" << port << "]: " << str << endl;
};

void MT_LoggerImpl::cli_log(const string &str) {
  cout << "MThr[cli]: " << str << endl;
}

void MT_LoggerImpl::file_log(const string &file, const string &str) {
  cout << "MThr[" << file << "]: " << str << endl;
}

void MT_LoggerImpl::socket_log(
    const string &host, int port, const string &str) {
  cout << "MThr[" << host << ":" << port << "]: " << str << endl;
}
