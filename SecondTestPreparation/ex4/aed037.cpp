#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

struct Customer {
    string name;
    int arrival;
    int products;
    int start_time;
    int departure_time;
};

struct CheckoutQueue {
    queue<Customer> q;
    int speed;  // Ki - time per product
    int next_free_time;  // when the checkout becomes free
    vector<Customer> served;  // customers who have been served at this checkout
};

int main() {
    int C;
    cin >> C;
    
    vector<CheckoutQueue> checkouts(C);
    
    // Read checkout speeds
    for (int i = 0; i < C; i++) {
        cin >> checkouts[i].speed;
        checkouts[i].next_free_time = 0;
    }
    
    int N;
    cin >> N;
    
    vector<Customer> customers(N);
    
    // Read customers
    for (int i = 0; i < N; i++) {
        cin >> customers[i].name >> customers[i].arrival >> customers[i].products;
    }
    
    // Process each customer
    for (int i = 0; i < N; i++) {
        int arrival_time = customers[i].arrival;
        
        // First, process any customers who finish at this arrival time
        // We need to mark them as served and update next_free_time
        for (int j = 0; j < C; j++) {
            while (!checkouts[j].q.empty()) {
                Customer& front = checkouts[j].q.front();
                int service_time = 10 + front.products * checkouts[j].speed;
                int departure = front.start_time + service_time;
                
                if (departure <= arrival_time) {
                    front.departure_time = departure;
                    checkouts[j].served.push_back(front);
                    checkouts[j].q.pop();
                    checkouts[j].next_free_time = departure;
                } else {
                    break;
                }
            }
        }
        
        // Now process the arriving customer
        // Find the best checkout according to the rules
        int best_checkout = 0;
        int min_queue_size = checkouts[0].q.size();
        int min_last_products = (checkouts[0].q.empty()) ? INT_MAX : checkouts[0].q.back().products;
        
        for (int j = 1; j < C; j++) {
            int queue_size = checkouts[j].q.size();
            int last_products = (checkouts[j].q.empty()) ? INT_MAX : checkouts[j].q.back().products;
            
            if (queue_size < min_queue_size) {
                min_queue_size = queue_size;
                min_last_products = last_products;
                best_checkout = j;
            } else if (queue_size == min_queue_size) {
                if (last_products < min_last_products) {
                    min_last_products = last_products;
                    best_checkout = j;
                }
            }
        }
        
        // Add customer to the chosen checkout
        customers[i].start_time = max(arrival_time, checkouts[best_checkout].next_free_time);
        
        CheckoutQueue& chosen = checkouts[best_checkout];
        chosen.q.push(customers[i]);
        
        // If this is the first in queue, calculate when they finish
        if (chosen.q.size() == 1) {
            int service_time = 10 + customers[i].products * chosen.speed;
            customers[i].departure_time = customers[i].start_time + service_time;
            chosen.next_free_time = customers[i].departure_time;
        }
    }
    
    // Process remaining customers in queues
    for (int j = 0; j < C; j++) {
        while (!checkouts[j].q.empty()) {
            Customer front = checkouts[j].q.front();
            checkouts[j].q.pop();
            
            front.start_time = checkouts[j].next_free_time;
            int service_time = 10 + front.products * checkouts[j].speed;
            front.departure_time = front.start_time + service_time;
            checkouts[j].served.push_back(front);
            checkouts[j].next_free_time = front.departure_time;
        }
    }
    
    // Output results
    for (int i = 0; i < C; i++) {
        cout << "Checkout #" << (i + 1) << ": " << checkouts[i].served.size() << "\n";
        for (const auto& cust : checkouts[i].served) {
            cout << ". " << cust.name << " " << cust.arrival << " " 
                 << cust.start_time << " " << cust.departure_time << "\n";
        }
    }
    
    return 0;
}
