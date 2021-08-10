#ifndef QUEUE_H
#define QUEUE_H
#include <queue>
#include <utility>
#include "Log.cc"
#include "Job.cc"
#include "Timing_unit.cc"

class Queue
{
    public:
        void update_history_log() 
        { 
              auto current_time=Singleton::Timing_unit::get_current_time();
              auto queue_size=fifo_queue.size();
              history.add_datum(std::make_pair(current_time,queue_size));
        }
        void insert(Job j){fifo_queue.push(j); update_history_log();}
        Job remove(){
        Job j = fifo_queue.front();
        fifo_queue.pop(); update_history_log();
        return j;
        }
        bool is_empty(){return fifo_queue.empty();}
        Log get_log(){return history;}
        Job& head()
        {
            return fifo_queue.front();
        }
        Job& tail()
        {
            return fifo_queue.back();
        }

    protected:

    private:
        std::queue<Job> fifo_queue;
        Log history;
};

#endif // QUEUE_H
