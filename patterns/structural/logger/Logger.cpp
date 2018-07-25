#include "Logger.h"
#include "LoggerImpl.h"

using std::string;

#ifdef MT
typedef MT_LoggerImpl TLoggerImpl;
#else
typedef ST_LoggerImpl TLoggerImpl;
#endif

Logger::Logger(LoggerImpl *p) : pimpl(p) {}
Logger::~Logger() { delete pimpl; }

CliLogger::CliLogger() : Logger(new TLoggerImpl) {}
FileLogger::FileLogger(const string &file_name) : Logger(new TLoggerImpl), file(file_name) {}
SocketLogger::SocketLogger(
    const string &remote_host,
    int remote_port) :
    Logger(new TLoggerImpl), host(remote_host), port(remote_port) {}

CliLogger::CliLogger(LoggerImpl *p) : Logger(p) {}
FileLogger::FileLogger(LoggerImpl *p, const string &file_name) : Logger(p), file(file_name) {}
SocketLogger::SocketLogger(
    LoggerImpl *p,
    const string &remote_host,
    int remote_port) :
    Logger(p), host(remote_host), port(remote_port) {}

void CliLogger::log(const string &str) { pimpl->cli_log(str); }
void FileLogger::log(const string &str) { pimpl->file_log(file, str); }
void SocketLogger::log(const string &str) { pimpl->socket_log(host, port, str); }
