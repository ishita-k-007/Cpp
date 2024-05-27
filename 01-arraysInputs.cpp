#include <iostream>
#include <tuple>
#include <map>
#include <string>

struct LenArr
{
public:
    std::tuple<std::string, int> len_arr;

    // extract_arr_length
    // int get_arr_length(std::tuple<std::string, int> arr_length_tuple)
    int get_arr_length()
    {
        int arr_length = std::get<1>(len_arr);
        return arr_length;
    };

    // prints the entire object
    void prints_length_arr() {



    };

};

struct BuiltArr
{
public:
    std::tuple<std::string, int *> built_arr;
    int *arr1;

    // extract arr elements
    void get_arr_elements(std::tuple<std::string, int *> arr_elements_tuple, int sizeNum)
    {

        int *arr_address = std::get<1>(arr_elements_tuple);
        for (int i = 0; i < sizeNum; i++)
        {
            std::cout << *(arr_address);
            arr_address += sizeof(int);
        }
        return;
    };
};

struct ArrResponse
{
public:
    std::tuple<struct LenArr, struct BuiltArr> resultDict;
    int size_resultant_response;

    // size of resultance_response
    int get_response_size(std::tuple<struct LenArr, struct BuiltArr> resultDict)
    {
        int size_resultant_response = std::tuple_size<decltype(resultDict)>::value;
        return size_resultant_response;
    };

    void print_response_size(char *typeResponse, int numSize)
    {
        std::cout << "The size of " << typeResponse << " response is: " << numSize;
    }

    // tuple values: len array - element 0
    int get_len_arr(std::tuple<std::string, int> len_arr)
    {
        int size_arr = std::get<1>(len_arr);
        return size_arr;
    };

    // // tuple values: array itself - element 1
    // int *get_arr_elements(BuiltArr built_arr)
    // {
    //     int *arr1 = std::get<1>(built_arr);
    //     return arr1;
    // }

    // print the array given its size and array object itself
    // void print_result_array(int *arrN, int lenArrN)
    // {

    //     std::cout << "Array elements printed: " << lenArrN << std::endl;
    //     for (int i = 0; i < lenArrN; i++)
    //     {
    //         std::cout << arrN[i] << " ";
    //     };
    //     std::cout << "\n"
    //               << std::endl;
    //     return;
    // };
};

ArrResponse buildArray()
{

    // user input array size
    int arrSize;
    std::cout << "Number of elements you want to enter into the array: " << std::endl;
    std::cin >> arrSize;
    std::cout << arrSize << std::endl;

    // user input array elements
    int arrN[arrSize];
    std::cout << "Enter the elements each in a different line: " << std::endl;
    for (int i = 0; i < arrSize; i++)
    {
        std::cin >> arrN[i];
    };

    // length tuple in map
    LenArr lenArr;
    std::tuple<std::string, int> trial_len;
    trial_len = std::make_pair("length_of_resultant_array", arrSize);
    std::tie(lenArr.len_arr) = trial_len;

    // resultant arr tuple in map
    BuiltArr builtArr;
    std::tuple<std::string, int *> trial_arr;
    trial_arr = std::make_pair("resultant_array", &arrN[0]);
    std::tie(builtArr.built_arr) = trial_arr;

    // resultant response with length and array in response map
    ArrResponse resultResponse;
    std::tuple<struct LenArr, struct BuiltArr> trial_res;
    trial_res = std::make_pair(lenArr, builtArr);
    std::tie(resultResponse.resultDict) = trial_res;

    return resultResponse;
};

void printArray(int *arrN, int lenArrN = 0)
{

    std::cout << "Array elements printed: " << lenArrN << std::endl;
    for (int i = 0; i < lenArrN; i++)
    {
        std::cout << arrN[i] << " ";
    };
    std::cout << "\n"
              << std::endl;
    return;
};

int main()
{

    // by definition -->
    int arr1[5] = {1, -2, 3, 4, 5};
    std::cout << "Arr1: fully filled array --> " << std::endl;

    printArray(arr1, 5);

    // null array intialised
    int arr2[5] = {};
    std::cout << "Arr2: null array --> " << std::endl;

    printArray(arr2, 5);

    // user input elements for an array of known expected length
    ArrResponse result_response = buildArray();
    std::tuple<struct LenArr, struct BuiltArr> result_res;
    std::tie(result_res) = result_response.resultDict;

    int size_num = result_response.get_response_size(result_res);
    std::cout << size_num;

    struct LenArr arr_len;
    std::tie(arr_len) = std::get<0>(result_response.resultDict);

    struct BuiltArr arr_built;
    std::tie(arr_built) = std::get<1>(result_response.resultDict);

    int len_arr_size = arr_len.get_arr_length();
    std::cout<<"The length of array is: ", len_arr_size;





    // int arr_size;
    // std::tie(arr_size) = ;

    // std::cout<<"Len-arr"<<std::get<0>(arr_len);
    // std::cout<<"Built-arr"<<arr_built;

    // result_res = std::make_pair(result_response.resultDict[0], builtArr);
    // resultant response with length and array in response map
    // printArrResponse(result_response, size_resultant_response);
    return 0;
}