#ifndef LOG_H
#define LOG_H

#include <list>
#include <utility>

using datum = std::pair<int, int>;

class Log {

public:
  void add_datum(datum d) { data.push_back(d); }

  datum get_most_recent_datum() { return data.front(); }

  std::list<datum> get_full_log() { return data; }

  double average_load();

  Log() {
    add_datum(datum(0, 0)); // initial condition
  }

private:
  std::list<datum> data;
};

#endif // LOG_H
