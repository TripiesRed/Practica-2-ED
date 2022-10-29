
#include <iostream>
#include "maxstack.h"

using namespace std;

ostream & operator<<(ostream& flujo, const element& n){
    flujo << n.value << "," << n.max;
    return flujo;
}

int main(int argc, char *argv[]){

    // // Run the current exercise
     MaxStack stack;

     for(int i = 1; i < argc; i++){
         if (argv[i][0] == '.'){
             cout << stack.top() << endl;
             stack.pop();
         } else {
             stack.push(atoi(argv[i]));
         }
     }
     return 0;
}
