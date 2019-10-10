#ifndef DSSORTER_H
#define DSSORTER_H

#include <vector>
#include "sorter.h"

class DSSorter{
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

                for(int j = 0; j < 5; j++){
                    experiment[j]->setData(data);
                    experiment[j]->sort();
                }

        }
};


#endif // DSSORTER_H
