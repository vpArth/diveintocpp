#pragma once

#include <string>

using std::string;

class LoggerImpl {
public:
  virtual ~LoggerImpl() = default;
  virtual void cli_log(const string &str) = 0;
  virtual void file_log(
      const string &file, const string &str) = 0;
  virtual void socket_log(
      const string &host, int port, const string &str) = 0;
};

class ST_LoggerImpl : public LoggerImpl {
public:
  void cli_log(const string &str) override;
  void file_log(const string &file, const string &str) override;
  void socket_log(
      const string &host, int port, const string &str) override;
};

class MT_LoggerImpl : public LoggerImpl {
public:
  void cli_log(const string &str) override;
  void file_log(const string &file, const string &str) override;
  void socket_log(
      const string &host, int port, const string &str) override;
};
