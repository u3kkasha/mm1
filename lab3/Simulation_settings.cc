#ifndef SIMULATION_SETTINGS_H
#define SIMULATION_SETTINGS_H
#include <vector>
class Simulation_settings {
public:
  int get_number_of_queues() { return number_of_queues; }
  void set_number_of_queues(int val) {
    number_of_queues = val;
    mean_inter_arrival_time.resize(number_of_queues);
  }
  int get_number_of_servers() { return number_of_servers; }
  void set_number_of_servers(int val) {
    number_of_servers = val;
    mean_service_time.resize(number_of_servers);
  }
  double get_mean_inter_arrival_time(int index) {
    return mean_inter_arrival_time.at(index);
  }
  void set_mean_inter_arrival_time(int index, double val) {
    mean_inter_arrival_time.at(index) = val;
  }
  double get_mean_service_time(int index) {
    return mean_service_time.at(index);
  }
  void set_mean_service_time(int index, double val) {
    mean_service_time.at(index) = val;
  }
  int get_termination_time() { return termination_time; }
  void set_termination_time(int val) { termination_time = val; }

protected:
private:
  int number_of_queues;
  int number_of_servers;
  std::vector<double> mean_inter_arrival_time = std::vector<double>(2);
  std::vector<double> mean_service_time = std::vector<double>(2);
  int termination_time;
};

#endif // SIMULATION_SETTINGS_H
