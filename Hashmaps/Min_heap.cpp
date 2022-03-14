#include <iostream>
using namespace std;

#include"PriorityQueues.h"

int main() {
    PriorityQueue pq;
    int choice;
    cin >> choice;

    while (choice != -1) {
        switch (choice) {
             case 1:  // isEmpty
                cout << (pq.isEmpty() ? "true\n" : "false\n");
                break;

             case 2:  // size
                cout << pq.getSize() << "\n";
                break;

             case 3:  // getMin
                cout << pq.getMin() << "\n";
                break;

            case 4:  // insert
                int element;
                cin >> element;
                pq.insert(element);
                break;

            case 5:  // removeMin
                cout << pq.removeMin() << "\n";
                break;


            default:
                return 0;

        }

        cin >> choice;
    }
}
