//
// Created by kavya on 5/3/2018.
//

#ifndef MENU_GENERATEINPUT_H
#define MENU_GENERATEINPUT_H
#include <string>
#include <iostream>
#include <random>
#include <chrono>
#include <string>
#include <fstream>
using namespace std;

class GenerateInput {

public:
    static string get_date(void);

    static string generate_input(int n, int k, int choice_of_file, int choice_of_distribution);

    static string generate_file1_uniform(int n, int k);

    static string generate_file2_uniform(int n);

    static string generate_file1_normal(int n, int k);

    static string generate_file2_normal(int n);

    static void write_runtime_to_file(int n, float runtime, string filename);

};


#endif //MENU_GENERATEINPUT_H
