// Bridge Abstraction
#pragma once

#include <string>

using std::string;

class LoggerImpl; // forward

class Logger {
public:
  explicit Logger(LoggerImpl *p);
  virtual ~Logger();
  virtual void log(const string &str) = 0;
protected:
  LoggerImpl *pimpl;
};

class CliLogger : public Logger {
public:
  CliLogger();
  explicit CliLogger(LoggerImpl *p);
  void log(const string &str) override;
};

class FileLogger : public Logger {
public:
  explicit FileLogger(const string &file_name);
  FileLogger(LoggerImpl *p, const string &file_name);
  void log(const string &str) override;
private:
  string file;
};

class SocketLogger : public Logger {
public:
  SocketLogger(const string &remote_host, int remote_port);
  SocketLogger(LoggerImpl *p, const string &remote_host, int remote_port);
  void log(const string &str) override;
private:
  string host;
  int port;
};