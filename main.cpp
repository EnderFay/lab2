#include "include/menu.h"
#include <iostream>

int main(){
  try {
        Menu railwaySystem;
        railwaySystem.run();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
