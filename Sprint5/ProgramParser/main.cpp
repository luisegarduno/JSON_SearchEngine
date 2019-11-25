#include <iostream>
#include <chrono>
#include "parser.h"

using namespace std;

using std::chrono::high_resolution_clock;

class Timer{
    private:
        using clock_t = high_resolution_clock;
        using milli_t = std::chrono::duration<int,std::milli>;

        std::chrono::time_point<clock_t> m_beg;

    public:
        Timer() : m_beg(clock_t::now()){}
        void reset(){
            m_beg = clock_t::now();
        }

        int elapsed() const{
            return std::chrono::duration_cast<milli_t>(clock_t::now() - m_beg).count();
        }
};

class missingFilesException{
    public:
        const char * what() {
            return "Missing/invalid number of arguments";
        }
};

int main(int argc, char *argv[]){
    try {
        if(argc != 3)                           // if argument counter != 3,
            throw missingFilesException{};      // throw custom exception

        else {
            Timer theTime;
            Parser newParse = Parser(argv);

            printf("Nodes: %d\n", newParse.getTotNumNodes());
            printf("Files containing '%s': %d\n", argv[2], newParse.getTotDocsFound());
            printf("Times found: %d\n", newParse.getTotNumOfAppearances());
            //printf("time: %d ms \n", theTime.elapsed());

        }
     }

    catch (missingFilesException& e) {              // catches custom exception message
        cout << e.what() << endl;
    }

    return 0;
}
