#include <iostream>
#include <vector>


int main(){
    int n, sarah_pos, instructions;
    std::cin >> n >> sarah_pos >> instructions;

    
    std::string chests;
    std::cin >> chests;


    int current_pos = sarah_pos;
    int max_pos = sarah_pos;
    int min_pos = sarah_pos;


    for (int k = 0; k < instructions; k++){
        char character;
        int steps;
        std::cin >> character >> steps;

        if (character == 'R'){  
            sarah_pos += steps;
        }
        else{
            sarah_pos -= steps;
        }

        min_pos = std::min(min_pos, sarah_pos);
        max_pos = std::max(max_pos, sarah_pos);
    }


    int treasure_count = 0;
    for (int pos = min_pos; pos <= max_pos; ++pos) {
        if (chests[pos - 1] == 'T') {
            treasure_count++;        
         }  
        
    }

    std::cout << treasure_count << std::endl;
    return 0;

}