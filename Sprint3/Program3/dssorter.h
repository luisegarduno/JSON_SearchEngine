#ifndef DSSORTER_H
#define DSSORTER_H

#include <stdlib.h>
#include <vector>
#include <chrono>
#include "sorter.h"

class Timer{
    private:
        // Type aliases to make accessing nested type easier
        using clock_t = std::chrono::high_resolution_clock;
        using second_t = std::chrono::duration<double, std::ratio<1> >;

        std::chrono::time_point<clock_t> m_beg;

    public:
        Timer() : m_beg(clock_t::now()){}
        void reset(){
            m_beg = clock_t::now();
        }

        double elapsed() const{
            return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
        }
};

class DSSorter{
    private:
        using clock_t = std::chrono::high_resolution_clock;
        using second_t = std::chrono::duration<double, std::ratio<1>>;

    public:
        DSSorter(){}
        void test1(){
                std::vector<int> data;

                for(int i = 0; i < 10; i++){
                    data.push_back(i);
                }

                Sorter<int>* experiment[5];
                experiment[0] = new MysterySorterA<int>;
                experiment[1] = new MysterySorterB<int>;
                experiment[2] = new MysterySorterC<int>;
                experiment[3] = new MysterySorterD<int>;
                experiment[4] = new MysterySorterE<int>;

                Timer t;
                double n = 0;


                for(int j = 0; j < 5; j++){
                    experiment[j]->setData(data);
                    t.reset();
                    experiment[j]->sort();
                    std::cout << "Time taken: " << t.elapsed() << " seconds\n" << std::endl;
                }



        }
};




#endif // DSSORTER_H
