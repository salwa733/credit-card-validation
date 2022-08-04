#include <iostream>
using namespace std;
#include <vector>
class validate {
public:
    int checksum;
    int even_odd;
    int total = 0;
public:
    // the last digit in the credit card is our checksum
    int check_sum(vector<int> arr) {
        checksum = arr[arr.size() - 1];
        return checksum;
    };
    //check numbers of credit card digits (odd or even)
    int evenOdd(vector<int> arr) {
        if ((arr.size() % 2) == 0)
            even_odd = 1;  // even no
        else
            even_odd = -1;  // odd no
        return even_odd;
    };

    //using lun algorithm
    int duplicate(vector<int> arr) {
        validate x;
        int size = arr.size() - 1;
        int* newArr1 = new int[size];
        // if the digits are even we will dublicate odd numbers and set even numbers
        if (even_odd == 1) {
            for (int i = 0; i < size; i++) {
                // the odds that will be dublicated 
                //the index 0 is the first number so it consider as an odd no. etc.
                if (i % 2 == 0) {
                    newArr1[i] = arr[i] * 2;
                    //if dublicated numbers >= 10 we add the two digits and set the result
                    if ((newArr1[i] / 10 == 1) && (newArr1[i] % 10 >= 0))
                        newArr1[i] = 1 + newArr1[i] % 10;
                }
                //set even numbers
                else newArr1[i] = arr[i];
            }
        }
        // if the digits are odd we will dublicate even numbers and set odd numbers
        else if (even_odd == -1) {
            for (int i = 0; i < size; i++) {
                // the odds that will be dublicated 
               //the index 1 is the second number so it consider as an even no. etc.
                if (i % 2 != 0) {
                    newArr1[i] = arr[i] * 2;
                    //if dublicated numbers >= 10 we add the two digits and set the result
                    if ((newArr1[i] / 10 == 1) && (newArr1[i] % 10 >= 0))
                        newArr1[i] = 1 + newArr1[i] % 10;
                }
                //set odd numbers
                else newArr1[i] = arr[i];
            }

        }
        //there are no digits
        else cout << "please enter the credit card again";
        //the sum of digits
        for (int i = 0; i < size; i++)
            total += newArr1[i];
        return total;
    };

    string get_validate() {
        //if (checksum + total) %10 = 0
        if (checksum  == 10 - (total % 10))
            return "The credit card is validate";
        else
            return "The credit card is not validate";
    };
};
int main() {
    validate op;
    int n;
    cout << "Enter your credit card number of digits ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter your credit card number ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int check = op.check_sum(arr);
    int even_odd = op.evenOdd(arr);
    int duble = op.duplicate(arr);
    string s = op.get_validate();
    cout << "the checksum is" << check << endl;
    cout <<"even_odd" << even_odd << endl;
    cout << "total" << duble << endl;
    cout << "validation" << s << endl;



    return 0;
}