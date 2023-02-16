#include "sortic.h"

string colored(string text){
    // It works on Linux, I don't know(and don't want to know), what about windows
    return "\033[3;46;30m" + text + "\033[0m\t\t";
}

void printArray(const vector<int> arr, ofstream &inputToFile){
    for(long long i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
        inputToFile << arr[i] << " ";
    }
    inputToFile << endl;
    cout << endl;
}

void printStep(const vector<int> &a, const vector<int> &b, string functionName, ofstream &outputToFile){
    if (functionName == "rra") functionName = colored(functionName);
    cout << functionName << endl;
    outputToFile << functionName << endl;
    cout << "Vector A: ";
    outputToFile << "Vector A: ";
    if (a.size() > 0)
        printArray(a, outputToFile);
    else{
        cout << "empty\n";
        outputToFile << "empty\n";
    } 
    cout << "Vector B: ";
    outputToFile << "Vector B: ";
    if (b.size() > 0)
        printArray(b, outputToFile);
    else{
        cout << "empty\n";
        outputToFile << "empty\n";
    }
    outputToFile << endl;
    cout << endl;
}

void fileBasedArrayFill(vector<int> &a){
    string line;
    cout << "Enter name of the file to read from: ";
    // Make getline works inside switch-case
    cin.clear();
    cin.ignore();
    getline(cin, line);
    ifstream inputFromFile;
    inputFromFile.open(line);
    readFromFile(inputFromFile, a);
}


void multiLineArrayFill(ofstream &outputToFile, vector<int> &a){
    cout << "Enter numbers of array. ! - finish input\n";
    string line;
    cin >> line;
    outputToFile << line << endl;
    while(line != "!"){
        a.push_back(itc_toInt(line));
        cin >> line;
        outputToFile << line << endl;
    }
}
void inlineBasedArrayFill(string inp, vector<int> &a){
    split(inp, " ", a);

}
void split(string str, string token, vector<int> &a){
    while (str.size()){
        int index = str.find(token);
        if (index != string::npos){
            a.push_back(itc_toInt(str.substr(0, index)));
            str = str.substr(index + token.size());
        }else{
            a.push_back(itc_toInt(str));
            str = "";
        }
    }
}


int main(int argc, char** argv){
    //string inp;
    //getline(cin, inp);
    int numberOfIterations = 0;
    map<string, int> cliMapping = {{"mline", 0}, {"inline", 1}, {"file", 2}, {"argv", 3}};
    ofstream outputToFile("./result.txt");
    bool WantToRead = false;
    string userSelect;
    vector<int> a, b;
    string inp;
    cout << "Select load task method:\nmline - numbers on different lines of stdin\ninline - one line from stdin\nfile - load task from file\nargv - get task from argc\n>";
    cin >> userSelect;
    switch (cliMapping[userSelect]){
        case 0:
            multiLineArrayFill(outputToFile, a);
            break;
        case 1:{
                // Make getline works inside switch-case
                std::cin.clear();
                //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin.ignore();
                getline(cin, inp);
                inlineBasedArrayFill(inp, a);
            }
            break;
        case 2:
            fileBasedArrayFill(a);
            break;
        case 3:
            inlineBasedArrayFill(argv[1], a);
            break;
        default:
            cout << "Invalid command\n";
            return 1;
    }
    cout << "Initial array: ";
    outputToFile << "Initial array: ";
    printArray(a, outputToFile);
    outputToFile << endl;
    cout << endl;
    sorter(a, b, outputToFile, numberOfIterations);
}
