#include <iostream>
#include <set>

using namespace std;

int main(){
    int A, B;
    
    
    if (!(cin >> A)) return 0;
    multiset<int> alice;
    for(int i = 0; i < A; i++){
        int energy;
        cin >> energy;
        alice.insert(energy);
    }

    
    cin >> B;
    multiset<int> bob;
    for(int i = 0; i < B; i++){
        int energy;
        cin >> energy;
        bob.insert(energy);
    }

    
    while(!alice.empty() && !bob.empty()){
        
        auto itA = alice.end(); 
        itA--; 
        auto itB = bob.end(); 
        itB--; 

        int valA = *itA;
        int valB = *itB;

        
        alice.erase(itA);
        bob.erase(itB);

        
        if(valA > valB){
            alice.insert(valA - valB);
        } else if (valB > valA){
            bob.insert(valB - valA);
        }

    }

    
    if(alice.empty() && bob.empty()){
        cout << "Tie" << endl;
        cout << 0 << endl;
    } else if (bob.empty()){
        cout << "Alice wins" << endl;
        cout << alice.size() << endl;
    } else {
        cout << "Bob wins" << endl;
        cout << bob.size() << endl;
    }
    
    return 0;
}