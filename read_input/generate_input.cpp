//
// Created by kavya on 4/29/2018.
//
#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <fstream>
using namespace std;

void generate_input(int n, int k, int choice_of_file, int choice_of_distribution) {
	/* 	n -> number of elements in the array
	 * choice_of_file = 1 -> input file with k
	 * choice_of_file = 2 -> input file without k
	 * choice_of_distribution = 1 -> uniform distribution
	 * choice_of_distribution = 2 -> normal distribution
	 */
	if((choice_of_file == 1 or choice_of_file == 2) and (choice_of_distribution == 1 or choice_of_distribution == 2))
	{
		switch(choice_of_file) {
			case 1:
				if (choice_of_distribution == 1)
					generate_file1_uniform(n, k);
				else
					generate_file1_normal(n, k);
				break;
			case 2:
				if (choice_of_distribution == 2)
					generate_file2_uniform(n);
				else
					generate_file2_normal(n);
				break;
		}
	}
	else
		cout<<"Invalid input! choice_of_file and choice_of_distribution must be either 1 or 2 !";
}

void generate_file1_uniform(int n, int k){

	ofstream file1;  // Create Object of Ofstream
	file1.open("C:\\Users\\kavya\\CLionProjects\\input_data\\File1_Uniform.txt"); // Opening a File or creating if not present
	file1 << n <<" "<< k; // Writing data to file
	cout<<"Data has been written to file";

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine e(seed);
	std::uniform_real_distribution<float> distr(0,n);  // range: [0,5]  -- both 1 and 5 are included // default param: [0, INT_MAX]
	cout << " int_distribution: " << endl;
    for (int i=0; i<n; i++) {
		file1 << "\n" << distr(e) ;
    }
    cout << "\nUniform Data has been written to file with n, k and n elements!";
    file1.close();
}

void generate_file2_uniform(int n) {
    ofstream file2;  // Create Object of Ofstream
    file2.open("C:\\Users\\kavya\\CLionProjects\\input_data\\File2_Uniform.txt"); // Opening a File or creating if not present
    file2 << n; // Writing data to file

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::uniform_real_distribution<float> distr(0, n);  // range: [0,5]  -- both 1 and 5 are included // default param: [0, INT_MAX]
    for (int i = 0; i < n; i++) {
        file2 << "\n" << distr(e);
    }
    cout << "\nUniform Data has been written to file2 with n and n elements!";
    file2.close();
}

void generate_file1_normal(int n, int k){

    ofstream file1;  // Create Object of Ofstream
    file1.open("C:\\Users\\kavya\\CLionProjects\\input_data\\File1_Normal.txt"); // Opening a File or creating if not present
    file1 << n <<" "<< k; // Writing data to file

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::normal_distribution<float> distrN(10.0, 3.0);  // mean and standard deviation
    for (int i=0; i<n; i++) {
        float num = distrN(e); // convert double to int
        file1<<"\n"<< num;
    }
    cout << "\nNormal Data has been written to file with n, k and n elements!";
    file1.close();
}

void generate_file2_normal(int n) {
    ofstream file2;  // Create Object of Ofstream
    file2.open("C:\\Users\\kavya\\CLionProjects\\input_data\\File2_Normal.txt"); // Opening a File or creating if not present
    file2 << n; // Writing data to file

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::normal_distribution<float> distrN(10.0, 3.0);  // mean and standard deviation
    for (int i=0; i<n; i++) {
        float num = distrN(e); // convert double to int
        file2<<"\n"<< num;
    }
    cout << "\nNormal Data has been written to file2 with n and n elements!";
    file2.close();
}

