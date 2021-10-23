#ifndef LOG_H
#define LOG_H
#include <list>
#include <utility>
typedef std::pair<int, int> datum;

class Log {
public:
    void add_datum(datum d) { data.push_back(d); }
    datum get_most_recent_datum() { return data.front(); }
    std::list<datum> get_full_log() { return data; }
    void draw_vertical_graph()
    { /* don't know how to do it */
    }
private:
    std::list<datum> data;
};

#endif // LOG_H
