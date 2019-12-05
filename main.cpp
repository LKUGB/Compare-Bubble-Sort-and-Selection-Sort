//
// Created by MSI on 2019/12/4.
//

#include <iostream>
#include <vector>
#include "Data.h"
#include <fstream>
#include <sstream>
#include <ctime>
#include "SortFunctions.h"


using namespace std;

int main(){
    //define a vector for inputting the objects extracted and integrated from the data file
    vector<Data> dataV;

    //define the input and output file stream
    ifstream inFS;
    ofstream outFS;

    //open the file and extract data from the file and place them in dataV as object type
    inFS.open("../wfp_market_food_prices.csv");

    //read file one at a time
    string line;
    cout << "Reading ../wfp_market_food_prices.csv.." << endl;

    //skip the first line because the first line is the variable names
    getline(inFS, line);

    while(getline(inFS, line)){
        //turn line into input string stream
        istringstream food(line);
        string substring;

        //read countryName
        getline(food, substring, ',');
        string countryName = substring;
        //read localityName
        getline(food, substring, ',');
        string localityName = substring;
        //read marketName
        getline(food, substring, ',');
        string marketName = substring;
        //read itemName
        getline(food, substring, ',');
        string itemName = substring;
        //read currency
        getline(food, substring, ',');
        string currency = substring;
        //read marketType
        getline(food, substring, ',');
        string marketType = substring;
        //read yearRecorded
        getline(food, substring, ',');
        int yearRecorded = stoi(substring);
        //read pricePaid;
        double pricePaid = stod(substring); //conversion from a string type to a double

        //store the variables into the object of data class
        //declare Data object
        Data obj;
        obj.countryName = countryName;
        obj.localityName = localityName;
        obj.marketName = marketName;
        obj.itemName = itemName;
        obj.currency = currency;
        obj.marketType = marketType;
        obj.yearRecorded = yearRecorded;
        obj.pricePaid = pricePaid;

        //insert the data object into dataV vector
        dataV.push_back(obj);
}
    //FIXME: HOW TO SET N FOR THE SIZE OF THE DATA VECTOR

    //close the file
    inFS.close();

    //create four copies of dataV
    vector<Data> dataV_B, dataV_S, dataV_Q, dataV_M;

    //copy the objects in dataV into the four vectors
    for(int i = 0; i < dataV.size(); i++){
        dataV_B[i] = dataV[i];
        dataV_S[i] = dataV[i];
        dataV_Q[i] = dataV[i];
        dataV_M[i] = dataV[i];
    }

    //populate another vector with random integers (intV)
    int randVecSize = dataV.size(); //should be the same with the size of dataV
    vector<int> intV;
    srand(time(0)); //random seed
    for(int i = 0; i < randVecSize; i++){
        intV[i] = rand();
    }

    //create four copies of intV
    vector<int> intV_B, intV_S, intV_Q, intV_M;

    //copy the int values in dataV into the four vectors
    for(int i = 0; i < intV.size(); i++){
        intV_B[i] = intV[i];
        intV_S[i] = intV[i];
        intV_Q[i] = intV[i];
        intV_M[i] = intV[i];
    }

    //use the sorting algorithms to sort the vectors (4 random number vectors and 4 data vectors)
    SortFunctions obj;

    //record the time for the execution of bubbleSort on random int vector
    clock_t start_BubbleSort = clock();
    obj.BubbleSort(intV_B, intV_B.size());
    clock_t end_BubbleSort = clock();
    double elapsed_BubbleSort = double(end_BubbleSort - start_BubbleSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for BubbleSort on random int vector: " << elapsed_BubbleSort << endl;

    //record the time for execution of selectionSort on random int vector
    clock_t start_SelectionSort = clock();
    obj.SelectionSort(intV_S, intV_S.size());
    clock_t end_SelectionSort = clock();
    double elapsed_SelectionSort = double(end_SelectionSort - start_SelectionSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for SelectionSort on random int vector: " << elapsed_SelectionSort << endl;

    //record the time for execution of QuickSort on random int vector
    clock_t start_QuickSort = clock();
    obj.QuickSort(intV_Q, 0, intV_Q.size());
    clock_t end_QuickSort = clock();
    double elapsed_QuickSort = double(end_QuickSort - start_QuickSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for QuickSort on random int vector: " << elapsed_QuickSort << endl;

    //record the time for execution of selectionSort on random int vector
    clock_t start_MergeSort = clock();
    obj.MergeSort(intV_M, 0, intV_M.size());
    clock_t end_MergeSort = clock();
    double elapsed_MergeSort = double(end_MergeSort - start_MergeSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for MergeSort on random int vector: " << elapsed_MergeSort << endl;

    //sorting the Data vectors*************************************************************************************************************
    //record the time for the execution of bubbleSort on Data vectors (sorting the pricePaid for the commodities)
    start_BubbleSort = clock();
    obj.BubbleSort(dataV_B, dataV_B.size());
    end_BubbleSort = clock();
    elapsed_BubbleSort = double(end_BubbleSort - start_BubbleSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for BubbleSort on Data vector: " << elapsed_BubbleSort << endl;

    //record the time for execution of selectionSort on on Data vectors
    start_SelectionSort = clock();
    obj.SelectionSort(intV_S, intV_S.size());
    end_SelectionSort = clock();
    elapsed_SelectionSort = double(end_SelectionSort - start_SelectionSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for SelectionSort on Data vector: " << elapsed_SelectionSort << endl;

    //record the time for execution of QuickSort on Data vectors
    start_QuickSort = clock();
    obj.QuickSort(intV_Q, 0, intV_Q.size());
    end_QuickSort = clock();
    elapsed_QuickSort = double(end_QuickSort - start_QuickSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for QuickSort on Data vector: " << elapsed_QuickSort << endl;

    //record the time for execution of selectionSort on Data vectors
    start_MergeSort = clock();
    obj.MergeSort(intV_M, 0, intV_M.size());
    end_MergeSort = clock();
    elapsed_MergeSort = double(end_MergeSort - start_MergeSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for MergeSort on Data vector: " << elapsed_MergeSort << endl;

//************************************************************************************************************************
//resort the sorted vectors by the same set of algorithm
//resorting sorted random int vectors
    //record the time for execution of bubbleSort on resorting the sorted random int vector
    start_BubbleSort = clock();
    obj.BubbleSort(dataV_B, dataV_B.size());
    end_BubbleSort = clock();
    elapsed_BubbleSort = double(end_BubbleSort - start_BubbleSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for BubbleSort on sorted random int vectors: " << elapsed_BubbleSort << endl;

    //record the time for execution of selectionSort on resorting the sorted random int vector
    start_SelectionSort = clock();
    obj.SelectionSort(intV_S, intV_S.size());
    end_SelectionSort = clock();
    elapsed_SelectionSort = double(end_SelectionSort - start_SelectionSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for SelectionSort on sorted random int vectors: " << elapsed_SelectionSort << endl;

    //record the time for execution of QuickSort on resorting the sorted random int vector
    start_QuickSort = clock();
    obj.QuickSort(intV_Q, 0, intV_Q.size());
    end_QuickSort = clock();
    elapsed_QuickSort = double(end_QuickSort - start_QuickSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for QuickSort on sorted random int vectors: " << elapsed_QuickSort << endl;

    //record the time for execution of selectionSort on resorting the sorted random int vector
    start_MergeSort = clock();
    obj.MergeSort(intV_M, 0, intV_M.size());
    end_MergeSort = clock();
    elapsed_MergeSort = double(end_MergeSort - start_MergeSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for MergeSort on sorted random int vectors: " << elapsed_MergeSort << endl;

    //resorting sorted Data vectors******************************************************************************************
    //record the time for execution of bubbleSort on sorted Data vectors
    start_BubbleSort = clock();
    obj.BubbleSort(dataV_B, dataV_B.size());
    end_BubbleSort = clock();
    elapsed_BubbleSort = double(end_BubbleSort - start_BubbleSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for BubbleSort on sorted Data vectors: " << elapsed_BubbleSort << endl;

    //record the time for execution of selectionSort on sorted Data vectors
    start_SelectionSort = clock();
    obj.SelectionSort(intV_S, intV_S.size());
    end_SelectionSort = clock();
    elapsed_SelectionSort = double(end_SelectionSort - start_SelectionSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for SelectionSort on sorted Data vectors: " << elapsed_SelectionSort << endl;

    //record the time for execution of QuickSort on sorted Data vectors
    start_QuickSort = clock();
    obj.QuickSort(intV_Q, 0, intV_Q.size());
    end_QuickSort = clock();
    elapsed_QuickSort = double(end_QuickSort - start_QuickSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for QuickSort on sorted Data vectors: " << elapsed_QuickSort << endl;

    //record the time for execution of selectionSort on sorted Data vectors
    start_MergeSort = clock();
    obj.MergeSort(intV_M, 0, intV_M.size());
    end_MergeSort = clock();
    elapsed_MergeSort = double(end_MergeSort - start_MergeSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for MergeSort on sorted Data vectors: " << elapsed_MergeSort << endl;

    return 0;























}

