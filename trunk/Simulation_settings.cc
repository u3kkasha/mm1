#ifndef SIMULATION_SETTINGS_H
#define SIMULATION_SETTINGS_H

class Simulation_settings {
public:
    int get_number_of_queues() { return number_of_queues; }
    void set_number_of_queues(int val) { number_of_queues = val; }
    int get_number_of_servers() { return number_of_servers; }
    void set_number_of_servers(int val) { number_of_servers = val; }
    double get_mean_inter_arrival_time() { return mean_inter_arrival_time; }
    void set_mean_inter_arrival_time(double val) { mean_inter_arrival_time = val; }
    double get_mean_service_time() { return mean_service_time; }
    void set_mean_service_time(double val) { mean_service_time = val; }
    int get_termination_time() { return termination_time; }
    void set_termination_time(int val) { termination_time = val; }

protected:
private:
    int number_of_queues;
    int number_of_servers;
    double mean_inter_arrival_time;
    double mean_service_time;
    int termination_time;
};

#endif // SIMULATION_SETTINGS_H
