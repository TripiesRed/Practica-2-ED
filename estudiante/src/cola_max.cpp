#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include "maxqueue.h"

using namespace std;

ostream & operator<<(ostream& flujo, const element& n){
    flujo << n.value << "," << n.max;
    return flujo;
}

int main(int argc, char *argv[]){

    // // Run the current exercise
    MaxQueue queue;

    for(int i = 1; i < argc; i++){
        if (argv[i][0] == '.'){
             cout << queue.front() << endl;
             queue.pop();
        } else {
             queue.push(atoi(argv[i]));
        }
    }
    return 0;
}
