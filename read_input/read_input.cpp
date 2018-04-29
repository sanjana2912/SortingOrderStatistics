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
// Driver program
int main() {

    int n = 0, i = 0;
    string line;
    ifstream inFile;

    // reading input file to get k, n, array[]:
    int k = 0;
    string num;

    // for input including k, n and array:
    inFile.open("C:\\Users\\kavya\\CLionProjects\\input_data\\Book1.csv");

    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }

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
    float array[n];
    i = 1;
    while( getline(inFile, line) ) {
        array[i-1] = stof(line);
        i += 1;
    }
    cout << "\nk:"<<k<<"\n";
    cout << "\nn:"<<n<<"\n";

 /* Uncomment for
  * // reading input file to get n, array[]:

    inFile.open("C:\\Users\\kavya\\CLionProjects\\input_data\\Book2.csv");
    if (!inFile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    string line2;
    i = 0;
    while( getline(inFile, line) )
    {
        if(i == 0)
            n = stoi(line);
        break;
    }
    float array[n];
    i = 1;
    while(getline(inFile, line)) {
        array[i-1] = stof(line);
        i += 1;
    }
    cout << "\n n:"<<n<<"\n";

    inFile.close();

*/

    // print array
    for(int j = 0; j < n ; j++) {
        cout <<"\narray["<<j<<"] : "<<array[j];
    }
    return 0;

}