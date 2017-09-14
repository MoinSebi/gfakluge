#include "gfakluge.hpp"
#include <getopt.h>
#include <string>
#include <iostream>


using namespace std;
using namespace gfak;
int main(int argc, char** argv){
    string gfa_file = "";
    bool block_order = false;

    if (argc == 1){
        cerr << "gfa_diff <a> <b> " << endl;
        exit(0);
    }

    int c;
    while (true){
        static struct option long_options[] =
        {
            {"help", no_argument, 0, 'h'},
            {0,0,0,0}
        };
    
        int option_index = 0;
        c = getopt_long(argc, argv, "hbi:", long_options, &option_index);
        if (c == -1){
            break;
        }

        switch (c){
            case '?':
            case 'h':
                cerr << "gfa_sort [-b --block-order ] -i <GFA_File> >> my_sorted_gfa.gfa" << endl;
                exit(0);

            case 'b':
                block_order = true;
                break;

            default:
                abort();
        }
    }

    GFAKluge gg;
    gg.parse_gfa_file(argv[2]);
    gg.parse_gfa_file(argv[3]);

    if (block_order){
        cout << gg.block_order_string();
    }
    else{
        cout << gg;
    }
    
    return 0;
}
