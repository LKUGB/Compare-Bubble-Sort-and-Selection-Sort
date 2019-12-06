//
// Created by MSI on 2019/12/4.
//

#include <iostream>
#include <vector>
#include "Data.h"
#include <fstream>
#include <sstream>
#include <ctime>


using namespace std;
//bubbleSort implementation; source: previous project: BubbleSort
template<typename T>
void BubbleSort(vector<T> a, int n) {
    bool swapped = true;
    while(swapped){
        swapped = false;
        for(int i = 0; i < n-1; i++) {     //create for loop to check whether the array is sorted
            if (a[i+1] < a[i]) {
                swap(a[i],a[i+1]);     //if the neighbouring element is not sorted, we have to operate the swap function
                swapped = true;
            }
        }
    }
}

//selectionSort implementation; source: zybook 15.6
template<typename T>
void SelectionSort(vector<T> numbers, int numbersSize) {
    int i;
    int j;
    int indexSmallest;
    int temp;      // Temporary variable for swap

    for (i = 0; i < numbersSize - 1; ++i) {

        // Find index of smallest remaining element
        indexSmallest = i;
        for (j = i + 1; j < numbersSize; ++j) {

            if ( numbers[j] < numbers[indexSmallest] ) {
                indexSmallest = j;
            }
        }

        // Swap numbers[i] and numbers[indexSmallest]
        temp = numbers[i];
        numbers[i] = numbers[indexSmallest];
        numbers[indexSmallest] = temp;
    }
}



//quickSort implementation, source: zybook 15.8
template <typename T>
int Partition(vector<T> &numbers, int i, int k) {
    int l;
    int h = 0;
    int midpoint;
    int pivot;
    int temp;
    bool done;

    /* Pick middle element as pivot */
    midpoint = i + (k - i) / 2;
    pivot = numbers.at(midpoint);

    done = false;
    l = i;
    h = k;

    while (!done) {

        /* Increment l while numbers[l] < pivot */
        while (numbers.at(l) < pivot) {
            ++l;
        }

        /* Decrement h while pivot < numbers[h] */
        while (pivot < numbers.at(h)) {
            --h;
        }

        /* If there are zero or one elements remaining,
         all numbers are partitioned. Return h */
        if (l >= h) {
            done = true;
        }
        else {
            /* Swap numbers[l] and numbers[h],
             update l and h */
            temp = numbers.at(l);
            numbers.at(l) = numbers.at(h);
            numbers.at(h) = temp;

            ++l;
            --h;
        }
    }

    return h;
}

template<typename T>
void QuickSort(vector<T> numbers, int i, int k) {
    int j;

    /* Base case: If there are 1 or zero elements to sort,
     partition is already sorted */
    if (i >= k) {
        return;
    }

    /* Partition the data within the array. Value j returned
     from partitioning is location of last element in low partition. */
    j = Partition(numbers, i, k);

    /* Recursively sort low partition (i to j) and
     high partition (j + 1 to k) */
    QuickSort(numbers, i, j);
    QuickSort(numbers, j + 1, k);
}

//mergeSort implementation; source: zybook 15.9
template<typename T>
void Merge(vector<T> numbers, int i, int j, int k) {
    int mergedSize;                            // Size of merged partition
    int mergePos;                              // Position to insert merged number
    int leftPos;                               // Position of elements in left partition
    int rightPos;                              // Position of elements in right partition
    int* mergedNumbers = nullptr;

    mergePos = 0;
    mergedSize = k - i + 1;
    leftPos = i;                               // Initialize left partition position
    rightPos = j + 1;                          // Initialize right partition position
    mergedNumbers = new int[mergedSize];       // Dynamically allocates temporary array
    // for merged numbers

    // Add smallest element from left or right partition to merged numbers
    while (leftPos <= j && rightPos <= k) {
        if (numbers[leftPos] < numbers[rightPos]) {
            mergedNumbers[mergePos] = numbers[leftPos];
            ++leftPos;
        }
        else {
            mergedNumbers[mergePos] = numbers[rightPos];
            ++rightPos;

        }
        ++mergePos;
    }

    // If left partition is not empty, add remaining elements to merged numbers
    while (leftPos <= j) {
        mergedNumbers[mergePos] = numbers[leftPos];
        ++leftPos;
        ++mergePos;
    }

    // If right partition is not empty, add remaining elements to merged numbers
    while (rightPos <= k) {
        mergedNumbers[mergePos] = numbers[rightPos];
        ++rightPos;
        ++mergePos;
    }

    // Copy merge number back to numbers
    for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
        numbers[i + mergePos] = mergedNumbers[mergePos];
    }
    delete[] mergedNumbers;
}

template<typename T>
void MergeSort(vector<T> numbers, int i, int k) {
    int j;

    if (i < k) {
        j = (i + k) / 2;  // Find the midpoint in the partition

        // Recursively sort left and right partitions
        MergeSort(numbers, i, j);
        MergeSort(numbers, j + 1, k);

        // Merge left and right partition in sorted order
        Merge(numbers, i, j, k);
    }
}

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

    //declare the N, which is the size of the entries we want to input into the vectors
    int N;
    cout << "Please enter the number of entries you want to put into the vectors: ";
    cin >> N;

    for(int i = 0; i < N; i++){
        getline(inFS, line);
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
        cout << substring << endl;
        flush(cout);
        int yearRecorded = stoi(substring);
        //read pricePaid;
        getline(food, substring, ',');
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
    dataV_B = dataV;
    dataV_S = dataV;
    dataV_Q = dataV;
    dataV_M = dataV;

    //populate another vector with random integers (intV)
    int randVecSize = dataV.size(); //should be the same with the size of dataV
    vector<int> intV;
    srand(time(0)); //random seed
    for(int i = 0; i < randVecSize; i++){
        intV.push_back(rand());
    }

    //create four copies of intV
    vector<int> intV_B, intV_S, intV_Q, intV_M;

    //copy the int values in dataV into the four vectors
    intV_B = intV;
    intV_S = intV;
    intV_Q = intV;
    intV_M = intV;

    //record the time for the execution of bubbleSort on random int vector
    clock_t start_BubbleSort = clock();
    BubbleSort(intV_B, intV_B.size());
    clock_t end_BubbleSort = clock();
    double elapsed_BubbleSort = double(end_BubbleSort - start_BubbleSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for BubbleSort on random int vector: " << elapsed_BubbleSort << endl;

    //record the time for execution of selectionSort on random int vector
    clock_t start_SelectionSort = clock();
    SelectionSort(intV_S, intV_S.size());
    clock_t end_SelectionSort = clock();
    double elapsed_SelectionSort = double(end_SelectionSort - start_SelectionSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for SelectionSort on random int vector: " << elapsed_SelectionSort << endl;

    //record the time for execution of QuickSort on random int vector
    clock_t start_QuickSort = clock();
    QuickSort(intV_Q, 0, intV_Q.size() - 1);
    clock_t end_QuickSort = clock();
    double elapsed_QuickSort = double(end_QuickSort - start_QuickSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for QuickSort on random int vector: " << elapsed_QuickSort << endl;

    //record the time for execution of selectionSort on random int vector
    clock_t start_MergeSort = clock();
    MergeSort(intV_M, 0, intV_M.size() - 1);
    clock_t end_MergeSort = clock();
    double elapsed_MergeSort = double(end_MergeSort - start_MergeSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for MergeSort on random int vector: " << elapsed_MergeSort << endl;

    //sorting the Data vectors*************************************************************************************************************
    //record the time for the execution of bubbleSort on Data vectors (sorting the pricePaid for the commodities)
    start_BubbleSort = clock();
    BubbleSort(dataV_B, dataV_B.size());
    end_BubbleSort = clock();
    elapsed_BubbleSort = double(end_BubbleSort - start_BubbleSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for BubbleSort on Data vector: " << elapsed_BubbleSort << endl;

    //record the time for execution of selectionSort on on Data vectors
    start_SelectionSort = clock();
    SelectionSort(intV_S, intV_S.size());
    end_SelectionSort = clock();
    elapsed_SelectionSort = double(end_SelectionSort - start_SelectionSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for SelectionSort on Data vector: " << elapsed_SelectionSort << endl;

    //record the time for execution of QuickSort on Data vectors
    start_QuickSort = clock();
    QuickSort(intV_Q, 0, intV_Q.size() - 1);
    end_QuickSort = clock();
    elapsed_QuickSort = double(end_QuickSort - start_QuickSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for QuickSort on Data vector: " << elapsed_QuickSort << endl;

    //record the time for execution of selectionSort on Data vectors
    start_MergeSort = clock();
    MergeSort(intV_M, 0, intV_M.size() - 1);
    end_MergeSort = clock();
    elapsed_MergeSort = double(end_MergeSort - start_MergeSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for MergeSort on Data vector: " << elapsed_MergeSort << endl;

//************************************************************************************************************************
//resort the sorted vectors by the same set of algorithm
//resorting sorted random int vectors
    //record the time for execution of bubbleSort on resorting the sorted random int vector
    start_BubbleSort = clock();
    BubbleSort(dataV_B, dataV_B.size());
    end_BubbleSort = clock();
    elapsed_BubbleSort = double(end_BubbleSort - start_BubbleSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for BubbleSort on sorted random int vectors: " << elapsed_BubbleSort << endl;

    //record the time for execution of selectionSort on resorting the sorted random int vector
    start_SelectionSort = clock();
    SelectionSort(intV_S, intV_S.size());
    end_SelectionSort = clock();
    elapsed_SelectionSort = double(end_SelectionSort - start_SelectionSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for SelectionSort on sorted random int vectors: " << elapsed_SelectionSort << endl;

    //record the time for execution of QuickSort on resorting the sorted random int vector
    start_QuickSort = clock();
    QuickSort(intV_Q, 0, intV_Q.size() - 1);
    end_QuickSort = clock();
    elapsed_QuickSort = double(end_QuickSort - start_QuickSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for QuickSort on sorted random int vectors: " << elapsed_QuickSort << endl;

    //record the time for execution of selectionSort on resorting the sorted random int vector
    start_MergeSort = clock();
    MergeSort(intV_M, 0, intV_M.size() - 1);
    end_MergeSort = clock();
    elapsed_MergeSort = double(end_MergeSort - start_MergeSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for MergeSort on sorted random int vectors: " << elapsed_MergeSort << endl;

    //resorting sorted Data vectors******************************************************************************************
    //record the time for execution of bubbleSort on sorted Data vectors
    start_BubbleSort = clock();
    BubbleSort(dataV_B, dataV_B.size());
    end_BubbleSort = clock();
    elapsed_BubbleSort = double(end_BubbleSort - start_BubbleSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for BubbleSort on sorted Data vectors: " << elapsed_BubbleSort << endl;

    //record the time for execution of selectionSort on sorted Data vectors
    start_SelectionSort = clock();
    SelectionSort(intV_S, intV_S.size());
    end_SelectionSort = clock();
    elapsed_SelectionSort = double(end_SelectionSort - start_SelectionSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for SelectionSort on sorted Data vectors: " << elapsed_SelectionSort << endl;

    //record the time for execution of QuickSort on sorted Data vectors
    start_QuickSort = clock();
    QuickSort(intV_Q, 0, intV_Q.size() - 1);
    end_QuickSort = clock();
    elapsed_QuickSort = double(end_QuickSort - start_QuickSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for QuickSort on sorted Data vectors: " << elapsed_QuickSort << endl;

    //record the time for execution of selectionSort on sorted Data vectors
    start_MergeSort = clock();
    MergeSort(intV_M, 0, intV_M.size() - 1);
    end_MergeSort = clock();
    elapsed_MergeSort = double(end_MergeSort - start_MergeSort) / CLOCKS_PER_SEC;
    cout << "Time elapsed for MergeSort on sorted Data vectors: " << elapsed_MergeSort << endl;

    return 0;























}

