//  William Baldwin
//  wjb0031
//  project3_wjb0031.cpp
//  Project_3
//
//  My brother(for checking over my code).
// Got help from my brother Rob with some of the methods with vectors.
//  Created by William Baldwin on 2/29/20.
//  Copyright © 2020 William Baldwin. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


bool check_file(string);

vector<int> read_file(string);

void write_file(string, vector<int>);

vector<int> merge (vector<int>, vector<int>);

void print_vector_horizontal(vector<int>);

void print_vector_vertical(vector<int>);

void print_file(vector<int>, string);

int main(int argc, const char * argv[]) {
    
    
    ifstream inStream;
    string filename1;
    string filename2;
    string filename3;
    vector<int> numbers1;
    vector<int> numbers2;
    vector<int> numbers3;
    
    
    std::cout << "*** Welcome to William's sorting program ***\n";
    
    do {
    std::cout << "Enter the first input file name: ";
    std::cin >> filename1;
    }while (cin.fail() || !check_file(filename1));
    
    numbers1 = read_file(filename1);
    
    print_file(numbers1, filename1);
    
   
    do {
        std::cout << "\nEnter the second input file name: ";
        std::cin >> filename2;
    }while (cin.fail() || !check_file(filename2));
    
    numbers2 = read_file(filename2);

    print_file(numbers2, filename2);

    numbers3 = merge(numbers1, numbers2);

    print_vector_horizontal(numbers3);
    
    do {
   std::cout << "Enter the output file name: ";
    std::cin >> filename3;
    } while (cin.fail());
    
    write_file(filename3, numbers3);
    
    std::cout << "*** Please check the new file - " << filename3 << "***\n";
    std::cout << "*** Goodbye. ***\n";
    
    return 0;
}



bool check_file (string file) {
    ifstream stream;
    
    stream.open(file.c_str());
    if (stream.fail()) {
    std::cout << "File couldn't open, enter valid file name.\n";
    }
    stream.close();
    
    return true;
}




vector<int> read_file(string file) {
  ifstream stream;
  
    vector<int> v;
    int i;
    
    stream.open(file.c_str());
    while(stream >> i) {
        v.push_back(i);
        
    }
    
    stream.close();
    return v;
}



void write_file (string file, vector<int> v) {
  ofstream fstream(file.c_str());
    int i = 0;
  while ( i < v.size()) {
    fstream << v[i] << std::endl;
      i++;
  }
  
}



vector<int> merge (vector<int> v1, vector<int> v2) {
   
    vector<int> v3;
    int i = 0;
    int j = 0;
    
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] > v2[j]) {
          v3.push_back(v2[j]);
          j++;
        }
        else {
          v3.push_back(v1[i]);
          i++;
        }
    }
  
    
    while (i < v1.size()) {
      v3.push_back(v1[i]);
      i++;
    }
    while (j < v2.size()) {
      v3.push_back(v2[j]);
      j++;
    }
  
    return v3;
}

void print_vector_vertical(vector<int> v) {
    int i = 0;
    while (i < v.size()) {
        std::cout << v[i] << std::endl;
        i++;
    }
}


void print_vector_horizontal(vector<int> v) {
    std::cout << "\nThe sorted list of " << v.size() << " numbers is: ";
    for (int i = 0; i < v.size() - 1; i++) {
        std::cout << v[i] << ' ';
    }
    if (v.size() > 0) {
        std::cout << v[v.size() - 1] << std::endl;;
    }
}


void print_file(vector<int> v, string filename) {
    std::cout << "The list of " << v.size() << " numbers in file " << filename << " is:" << std::endl;
    print_vector_vertical(v);
}
