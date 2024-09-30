#include <iostream>
#include <vector>
#include <cstring>
#include<algorithm>
using namespace std;

bool promptYesNo(string yes_or_not){
  bool YesNo = false;
  string value;
  do{
    cout << "another business?: " <<endl;
    cin >> value;
   //  conver to lowercase
    for (int i= 0; i <value.length(); i ++) value[i] = tolower(value[i]);
    if(value == "yes") value = "y";
    if(value == "no") value = "n";
    if(value == "y") YesNo = true;
    if(value == "n") YesNo = false;
  } while (value != "y" && value != "n");
  return YesNo;
}

int main(){
  vector<string*> businesses;
  cout << "Welcome to the Business Sorting Program!" << endl;
  do {
    string* pBusiness_on_stack = new string;
    cout << "Please enter the name of a business: ";
    getline(cin >> ws, *pBusiness_on_stack);;
    businesses.push_back(pBusiness_on_stack);
    cout << "Your business is: " << *pBusiness_on_stack << endl;
    bool status = promptYesNo("Do you want to enter another business?");
    if (!status) {
        break;
    }
    } while (true);

  sort(businesses.begin(), businesses.end(), [](const string* a, const string* b) {
    return *a < *b;
  });

  cout << "Your businesses are: " << endl;
  for (auto& business : businesses) {
    cout << *business << endl;
      delete business; // Deallocate each string
  }
  cout << "Thank you for using the Business Sorting Program!" << endl;
  return 0;
}