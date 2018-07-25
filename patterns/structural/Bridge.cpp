#include "logger/Logger.h"
#include "logger/LoggerImpl.h"

using std::string;

int main() {
  Logger *fl = new FileLogger("/tmp/bridge.log");
  Logger *sl = new SocketLogger("localhost", 3000);
  Logger *cl = new CliLogger();

  fl->log("Bridge");
  sl->log("pattern");
  cl->log("example");

  delete fl;
  delete sl;
  delete cl;

  LoggerImpl *logWriter = new MT_LoggerImpl;
  Logger *mfl = new FileLogger(logWriter, "/dev/null");
  Logger *msl = new SocketLogger(logWriter, "8.8.8.8", 80);
  Logger *mcl = new CliLogger(logWriter);
  mfl->log("Select");
  msl->log("implementation");
  mcl->log("runtime");

  delete mcl;
  delete msl;
  delete mfl;
  delete logWriter;

  return 0;
}