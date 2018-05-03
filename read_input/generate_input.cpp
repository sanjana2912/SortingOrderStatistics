//
// Created by kavya on 4/29/2018.
//
#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <fstream>
using namespace std;

string get_date(void);

string generate_file1_uniform(int n, int k){
	ofstream file1;  // Create Object of Ofstream
    string timestamp = get_date();
	file1.open("C:\\Users\\kavya\\CLionProjects\\input_data\\File1_Uniform_"+timestamp+".txt"); // Opening a File or creating if not present
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
    return timestamp;
}

string generate_file2_uniform(int n) {
    ofstream file2;  // Create Object of Ofstream
    string timestamp = get_date();
    file2.open("C:\\Users\\kavya\\CLionProjects\\input_data\\File2_Uniform_"+timestamp+".txt"); // Opening a File or creating if not present
    file2 << n; // Writing data to file

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::uniform_real_distribution<float> distr(0, n);  // range: [0,5]  -- both 1 and 5 are included // default param: [0, INT_MAX]
    for (int i = 0; i < n; i++) {
        file2 << "\n" << distr(e);
    }
    cout << "\nUniform Data has been written to file2 with n and n elements!";
    file2.close();
    return timestamp;
}

string generate_file1_normal(int n, int k){

    ofstream file1;  // Create Object of Ofstream
    string timestamp = get_date();
    file1.open("C:\\Users\\kavya\\CLionProjects\\input_data\\File1_Normal_"+timestamp+".txt"); // Opening a File or creating if not present
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
    return timestamp;
}

string generate_file2_normal(int n) {
    ofstream file2;  // Create Object of Ofstream
    string timestamp = get_date();
    file2.open("C:\\Users\\kavya\\CLionProjects\\input_data\\File2_Normal_"+timestamp+".txt"); // Opening a File or creating if not present
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
    return timestamp;
}

string get_date(void)
{
    time_t now;
    char the_date[20];
    the_date[0] = '\0';
    now = time(NULL);
    if (now != -1)
        strftime(the_date, 20, "%d_%m_%Y_%H_%M_%S", gmtime(&now));
    return std::string(the_date);
}

string generate_input(int n, int k, int choice_of_file, int choice_of_distribution) {
    /* 	n -> number of elements in the array
     * choice_of_file = 1 -> input file with k
     * choice_of_file = 2 -> input file without k
     * choice_of_distribution = 1 -> uniform distribution
     * choice_of_distribution = 2 -> normal distribution
     */
    string timestamp;
    if((choice_of_file == 1 or choice_of_file == 2) and (choice_of_distribution == 1 or choice_of_distribution == 2))
    {
        switch(choice_of_file) {
            case 1:
                if (choice_of_distribution == 1)
                    timestamp = generate_file1_uniform(n, k);
                else
                    timestamp = generate_file1_normal(n, k);
                break;
            case 2:
                if (choice_of_distribution == 2)
                    timestamp = generate_file2_uniform(n);
                else
                    timestamp = generate_file2_normal(n);
                break;
        }
    }
    else
        cout<<"Invalid input! choice_of_file and choice_of_distribution must be either 1 or 2 !";
}
