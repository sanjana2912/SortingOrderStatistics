#include <iostream>

using namespace std;

int main() {
     //
}

void input_file_menu(){
    int ch;
    cout << "\n Do you want to:\n\t 1. Generate input file\n\t 2. Provide a file from local drive";
    cout << "\n Enter your choice : ";
    cin >> ch;
    if (ch == 1)
        generate_input_menu();
    else if (ch == 2)
        provide_file_menu();
    else {
        cout << "\n Invalid input. Input must be 1 or 2. Try again!";
        input_file_menu();
    }
}

void generate_input_menu(){
    // file for kth smallest or sorting
    int ch;
    cout << "\n Do you want uniform or normal data? \n\t 1. Uniform data \n\t 2. Normal data";
    cout << "\n Enter your choice : ";
    cin >> ch;
    if(ch == 1) {
        generate_uniform_input_file();
        program_menu();
    }
    else if(ch == 2) {
        generate_normal_input_file();
        program_menu();
    }
    else {
        cout << "\n Invalid input. Input must be 1 or 2. Try again!";
        generate_input_menu();
    }
}

void program_menu() {
    int ch;
    cout << "\n Choose the program you want to run:\n\t 1. Find kth smallest in an array \n\t 2. Find the top k elements in an array "
            <<"\n\t 3. Heap Sort\n\t 4. Quick Sort - Classical\n\t 5. Quick Sort - Randomized\n\t 6. Quick Sort - Heuristic of 3 Medians"
              <<"\n\t 7. Quick Sort with insertion sort\n\t 8. C++ in_built sort function";
    cout << "\n Enter your choice : ";
    cin >> ch;
    // read from input file
    String file;
    cout<< "\nFilename:";
    cin>>file
    read_input_from_file(file);
    // call kth smallest
    int n, k, N;
    float array;
    // get the number of runs:
    cout << "\n How many times do you want to run this program?";
    cin >> N;
    switch(ch){
        case 1:
            // call subroutine which runs N times
            //kthSmallest::calcKthSmallest(array, 0, n-1, k);
            break;
        case 2:
            top_k_smallest_elements(array, n, k);
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            break;
    }
}
