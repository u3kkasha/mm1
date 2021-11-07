//بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ

#include "Log.hpp"
#include "Simulation_parameters.cc"

double Log::average_load() {
  /**
      Calculates the area under the graph of y vs x, where x is the first
     element of the pair and y is the second element of the pair and then
     divides it by the total time i.e. termination_time
     @return the result of ∫y dx from 0 till termination time
     */
  long result = 0;
  auto termination_time =
      Singleton::Simulation_parameters::termination_time;

  add_datum(datum(termination_time,
                  0)); // this needs to be done for calculation purposes

  for (auto iterator = data.begin(); iterator != std::prev(data.end());
       iterator++) {
    auto [time1, value1] = *iterator;
    auto [time2, value2] = *std::next(iterator);
    auto height = value1;
    auto width = time2 - time1;
    auto rectangle_area = height * width;
    result += rectangle_area;
  }
  return static_cast<double>(result) / termination_time;
}
