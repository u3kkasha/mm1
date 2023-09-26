#if not defined (RANDOM_VARIATE_GENERATOR_GUARD)
#define RANDOM_VARIATE_GENERATOR_GUARD

#pragma once
/*
بِسْمِ اللَّهِ الرَّحْمٰنِ الرَّحِيْمِ

۞Name: Random_variate_generator
۞Type: Static Singleton
۞Purpose: Library for generating random variates.
۞Author: 215

۞Mechanism:
An LCG generator is used to generate random numbers.
All random variates are then generated by manipulating random numbers using known methods such as inverse transform etc in sha Allah.

Note:
random number: uniformly distributed value between 0 and 1 inclusive
random variate: a value that is distributed according to any other probability distribution

*/

#include <climits>
#include <ctime>
#include <cmath>

// namespace declaration
namespace Singleton {

    class Random_variate_generator
    {
        //Random number section


        private:
        //set initial seed value to current time
        inline static const int seed = time(NULL);

        static double get_random_number_pmmlcg() {
            /*
        +Purpose: Returns a random value from the range [0,1]
        +Dependencies: None
        +Author: 215
        +Parameter: void
        +Sample output
            0.729193

        +Mechanism:
        This is a Prime modulus multiplicative  LCG. These given values for multiplier, increment and modulus were taken from discrete mathematics and applications textbook.
        The program seeds the initial random_number , so that runs on different days give different values. This seeding is only done once when the function is called for the first time in sha Allah.
        The variable random_number is a static variable which means that it's value is preserved within function calls. The previous random value is used to calculate a new random value in sha Allah.
        In order to return a double datatype floating point value random_value is casted to double value and then divided by modulus's value and then returned.
        ***Casting is MANDATORY because otherwise it will be integer division hence the resulting quotient will always be zero in that case, which is not what we want.
        */
            unsigned int static random_value = seed;
            const int multiplier = 7 * 7 * 7 * 7 * 7;
            const int increment = 0;
            const int modulus = std::pow(2, 31)-1; //a prime number
            random_value = (multiplier * random_value + increment) % modulus;

            return static_cast<double > (random_value) / modulus;
        }


        public:
        // This is a function pointer reference to the random number generator function, if necessary a new random number generator function implementing another method of random number generator can be added and only this pointer has to be updated to reflect the changes.

        constexpr static const auto get_random_number = get_random_number_pmmlcg;

        // Random variate generators section

        static double get_uniform(double min, double max) {
            /*
        +Purpose: returns a uniform random variate from the range [min,max]
        +Dependencies: get_random_number();
        +Author: 215
        +Parameter: Minimum and maximum limits for random variate
        */
            return min+get_random_number()*(max-min);
        }

        static double get_exponential(double mean) {
            /*
        +Purpose: returns an exponential random variate with the chosen mean.
        Note: for exponential distribution mean=1/arrival_rate
        +Dependencies: get_random_number()
        +Author: 215
        +Parameter: A double value of the mean arrival time for this distribution
        */
            return -mean*std::log(get_random_number());

        }

    }; // end of class


}//end of namespace
#endif //end of guard band
