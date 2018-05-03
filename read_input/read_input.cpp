//
// Created by kavya on 4/22/2018.
//

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
using namespace std;

void read_from_input(int choice_of_file, int choice_of_distribution, float array[], int n, int k, string timestamp) {

    int i = 0;
    ifstream inFile;
    string line, num;
    string file = "C:\\Users\\kavya\\CLionProjects\\input_data\\File";

    if(choice_of_distribution == 1)
        file.append(choice_of_file+"_Uniform_"+timestamp+".txt");
    else
        file.append(choice_of_file+"_Normal_"+timestamp+".txt");

    // for input including k, n and array:
    inFile.open(file);

    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

    if(choice_of_file == 1){
        while( getline(inFile, line) )
        {
            if(i == 0)
                num = line;
            break;
        }
        std::istringstream buf(num);
        std::istream_iterator<std::string> beg(buf), end;
        std::vector<std::string> tokens(beg, end);
        k = stoi(tokens[0]);
        n = stoi(tokens[1]);
    }
    else{
        while( getline(inFile, line) )
        {
            if(i == 0)
                n = stoi(line);
            break;
        }
    }
    i = 1;
    while( getline(inFile, line) ) {
        array[i-1] = stof(line);
        i += 1;
    }
    cout << "\nk:"<<k<<"\n";
    cout << "\nn:"<<n<<"\n";
}
