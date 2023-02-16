#include "sortic.h"


void printArray(const vector<int> arr, ofstream &inputToFile){
    for(long long i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printStep(const vector<int> &a, const vector<int> &b, string functionName, ofstream &outputToFile){
    cout << functionName << endl;
    outputToFile << functionName << endl;
    cout << "Vector A: ";
    outputToFile << "Vector A: ";
    if (a.size() > 0){}
        //printArray(a, outputToFile);
    else{
        cout << "empty\n";
        outputToFile << "empty\n";
    } 
    cout << "Vector B: ";
    outputToFile << "Vector B: ";
    if (b.size() > 0) {}
        //printArray(b, outputToFile);
    else{
        cout << "empty\n";
        outputToFile << "empty\n";
    }
    outputToFile << endl;
    cout << endl;
}
void multiLineArrayFill(vector<int> &a){
    cout << "Enter numbers of array. ! - finish input\n";
    string line;
    cin >> line;
    while(line != "!"){
        a.push_back(itc_toInt(line));
        cin >> line;
    }
}

void inputCommands(vector<string> &commands){
    string line;
    cin >> line;
    while (line != "*"){
        commands.push_back(line);
        cin >> line;
    }
}

int main(){
    vector<int> a, b;
    vector<string> commands;
    multiLineArrayFill(a);
    int initArraySize = a.size();
    //cout << "Now, enter commands"
    inputCommands(commands);   
    for (int i = 0; i < commands.size(); ++i){
        string cmd = commands[i];
        if (cmd == "sa") sa(a);
        else if (cmd == "sb") sb(b);
        else if (cmd == "ss") ss(a, b);
        else if (cmd == "pa") pa(a, b);
        else if (cmd == "pb") pb(b, a);
        else if (cmd == "ra") ra(a);
        else if (cmd == "rb") rb(b);
        else if (cmd == "rr") rr(a, b);
        else if (cmd == "rra") rra(a);
        else if (cmd == "rrb") rrb(b);
        else if (cmd == "rrr") rrr(a, b);
    }
    if ((isSorted(a) && a.size() == initArraySize) || (isSorted(b) && b.size() == initArraySize)) cout << "OK"; else cout << "KO";
    /*cout << "\nArray after such commands: ";
    for(long long i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << endl; */
    return 0;

}
