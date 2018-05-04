//
// Created by kavya on 5/3/2018.
//
#include "GenerateInput.h"
#include "TopKSmallest.h"
#include "ReadInput.h"
#include "Menu.h"

void Menu::input_file_menu(){
    int ch;
    cout << "\n Do you want to:\n\t 1. Generate input file\n\t 2. Provide a file from local drive";
    cout << "\n Enter your choice : ";
    cin >> ch;
    if (ch == 1)
        generate_input_menu();
    else if (ch == 2)
    {
        //provide_file_menu();
    }
    else {
        cout << "\n Invalid input. Input must be 1 or 2. Try again!";
        input_file_menu();
    }
}

void Menu::generate_input_menu(){
    // file for kth smallest or sorting
    int ch, n;
    cout << "\n Do you want uniform or normal data? \n\t 1. Uniform data \n\t 2. Normal data";
    cout << "\n Enter your choice : ";
    cin >> ch;
    cout << "\n Enter the number of elements:";
    cin >> n;
    if(ch == 1) {
        program_menu(1, n);
    }
    else if(ch == 2) {
        program_menu(2, n);
    }
    else {
        cout << "\n Invalid input. Input must be 1 or 2. Try again!";
        generate_input_menu();
    }
}

void Menu::program_menu(int choice_of_distribution, int n) {
    int ch, choice_of_file, k = 0;//, N;
    float array[n];
    string filename, timestamp = "";

    cout
            << "\n Choose the program you want to run:\n\t 1. Find kth smallest in an array \n\t 2. Find the top k elements in an array "
            << "\n\t 3. Heap Sort\n\t 4. Quick Sort - Classical\n\t 5. Quick Sort - Randomized\n\t 6. Quick Sort - Heuristic of 3 Medians"
            << "\n\t 7. Quick Sort with insertion sort\n\t 8. C++ built-in sort function";
    cout << "\n Enter your choice : ";
    cin >> ch;

    if (ch == 1 or ch == 2) {
        choice_of_file = 1;
        cout << "\n Enter the value of k : ";
        cin >> k;
    } else {
        choice_of_file = 2;
    }
    //cout << "\n Enter the number of times you want to run the program : ";
    //cin >> N;
   // if(N<=10){
   //     for (int i = 0; i < N; i++) {
            // generate input file:
            cout<<"\n Generating Input...";
            timestamp = GenerateInput::generate_input(n, k, choice_of_file, choice_of_distribution);

            cout<<"\ntimestamp : "<< timestamp;
            // read from input file:
            cout<<"\n Reading from Input file...";
            ReadInput::read_from_input(choice_of_file, choice_of_distribution, array, n, k, timestamp);

            switch (ch) {
                case 1:
                    //TopKSmallest::calcKthSmallest(array, 0, n - 1, k);
                    break;
                case 2:
                    cout<<"\nIn top k smallest loop...";
                    TopKSmallest::top_k_smallest_elements(array, n, k);
                    cout<<"\nFinished...!!";
                    break;
                case 3:
                    // call heap sort
                    break;
                case 4:
                    // call quick sort - classical
                    break;
                case 5:
                    // call quick sort - randomized
                    break;
                case 6:
                    // call quick sort - heuristics of 3 medians
                    break;
                case 7:
                    // call quick sort - insertion sort
                    break;
                case 8:
                    // call c++ built-in sort function
                    break;
                default:
                    // call quick sort - heuristics of 3 medians
                    break;
            }
        //}
   /* }
    else{
        cout << "N is too large, run a batch file!";
    }*/

}
