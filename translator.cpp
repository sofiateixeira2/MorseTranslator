#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

string translateText(string line) {
    string ans;
    int i = 0;
    string tmp;

    for(i = 0; i < line.length(); i++) {
        char c = line.at(i);
        while(c != ' ') {
            tmp = tmp + c;
            if(i >= line.length()) break;
            else {
                i += 1;
                c = line.at(i);
            }
        }

        string text;

        if(tmp.compare(".-") == 0) text = "a";
        else if(tmp.compare("-...") == 0) text = "b";
        else if(tmp.compare("-.-.") == 0) text = "c";
        else if(tmp.compare("-..") == 0) text = "d";
        else if(tmp.compare(".") == 0) text = "e";
        else if(tmp.compare("..-.") == 0) text = "f";
        else if(tmp.compare("--.") == 0) text = "g";
        else if(tmp.compare("....") == 0) text = "h";
        else if(tmp.compare("..") == 0) text = "i";
        else if(tmp.compare(".---") == 0) text = "j";
        else if(tmp.compare("-.-") == 0) text = "k";
        else if(tmp.compare(".-..") == 0) text = "l";
        else if(tmp.compare("--") == 0) text = "m";
        else if(tmp.compare("-.") == 0) text = "n";
        else if(tmp.compare("---") == 0) text = "o";
        else if(tmp.compare(".--.") == 0) text = "p";
        else if(tmp.compare("--.-") == 0) text = "q";
        else if(tmp.compare(".-.") == 0) text = "r";
        else if(tmp.compare("...") == 0) text = "s";
        else if(tmp.compare("-") == 0) text = "t";
        else if(tmp.compare("..-") == 0) text = "u";
        else if(tmp.compare("...-") == 0) text = "v";
        else if(tmp.compare(".--") == 0) text = "w";
        else if(tmp.compare("-..-") == 0) text = "x";
        else if(tmp.compare("-.--") == 0) text = "y";
        else if(tmp.compare("-...") == 0) text = "z";
        else if(tmp.compare("/") == 0) text = " ";
        else text = "#";

        tmp = "";

        ans = ans + text;

    }
    
    return ans;
}

string translateMorse(string line) {
    string ans;

    for(int i = 0; i < line.length(); i++) {
        char c = tolower(line.at(i));    
        string morse;
        switch (c) {
            case 'a':
                morse = ".-";
                break;
            case 'b':
                morse = "-...";
                break;
            case 'c':
                morse = "-.-.";
                break;
            case 'd':
                morse = "-..";
                break;
            case 'e':
                morse = ".";
                break;
            case 'f':
                morse = "..-.";
                break;
            case 'g':
                morse = "--.";
                break;
            case 'h':
                morse = "....";
                break;
            case 'i':
                morse = "..";
                break;
            case 'j':
                morse = ".---";
                break;
            case 'k':
                morse = "-.-";
                break;
            case 'l':
                morse = ".-..";
                break;
            case 'm':
                morse = "--";
                break;
            case 'n':
                morse = "-.";
                break;
            case 'o':
                morse = "---";
                break;
            case 'p':
                morse = ".--.";
                break;
            case 'q':
                morse = "--.-";
                break;
            case 'r':
                morse = ".-.";
                break;
            case 's':
                morse = "...";
                break;
            case 't':
                morse = "-";
                break;
            case 'u':
                morse = "..-";
                break;
            case 'v':
                morse = "...-";
                break;
            case 'w':
                morse = ".--";
                break;
            case 'x':
                morse = "-..-";
                break;
            case 'y':
                morse = "-.--";
                break;
            case 'z':
                morse = "--..";
                break;
            case ' ':
                morse = "/";
                break;
            default:
                morse = "#";
                break;
        }
        ans = ans + morse + " ";
    }

    return ans;
}

void readStandard(int op) {

    cout << "Write the input to be translated (enter '0' to translate):\n\n";
    if(op == 2) cout << "(please enter a space ' ' after every morse code word)\n\n";
    string fullLine;

    fstream output;
    output.open("output.txt", ios::out);
    if(!output) {
        cout << "Output file not created!\n" << endl;
    } else {
        cin.ignore();
        getline(cin, fullLine);
        int cmp = fullLine.compare("0");
        while(cmp != 0) {
            if(op == 1) output << translateMorse(fullLine);
            if(op == 2) output << translateText(fullLine);
            
            getline(cin, fullLine);
            cmp = fullLine.compare("0");
        }

        cout << "Output file created sucessfully!\n" << endl;
        cout << "Check out the morse code version of your text in 'output.txt'" << endl;
        output.close();
    }
}

void readFile(int op) {
    cout << "Write the name of the file txt with the input to be translated (include the extension .txt):" << endl;
    cout << ": ";
    string fileName;
    cin >> fileName;
    system("CLS");

    fstream output;
    output.open("output.txt", ios::out);

    string line;
    ifstream input (fileName);
    if(input.is_open()) {
        cout << "\nFile opened sucessfuly!" << endl;
        cout << "Input is now going to be translated." << endl;

        if(!output) {
            cout << "\nOutput file not created!\n" << endl;
        } else {
            cout << "\nOutput file created sucessfully!\n" << endl;
        }

        cin.ignore();
        while (getline(input, line)) {
            if(op == 1) {
                output << translateMorse(line);
            } else if(op == 2) {
                output << translateText(line);
            }
        }
        input.close(); 
        output.close();

        cout << "Check out the morse code version of your text in 'output.txt'" << endl;       
    } else cout << "Unable to open file" << endl;
}


int main() {
    int op;
    BEGIN:
    system("CLS");
    cout << "!WARNING! The following program is not finished yet so it may contain some errors or bugs." << endl;
    cout << "This program (at the moment) does not work with numbers" << endl;
    cout << "(Special characters also don't work as they don't have morse code translation)\n" << endl;
    cout << "Choose your option" << endl;
    cout << "1. Translate text to morse code" << endl;
    cout << "2. Translate morse code to text" << endl;
    cout << "0. Exit" << endl;
    cout << ": ";
    cin >> op;
    system("CLS");

    if(op == 1) {
        cout << "1. Input via standard input" << endl;
        cout << "2. Input via file" << endl;
        cout << ": ";
        int inputOP;
        cin >> inputOP;
        system("CLS");
        if(inputOP == 1) readStandard(op);
        if(inputOP == 2) readFile(op);
        cout << "\nDo you want to translate something else? (y/n)" << endl;
        cout << ": ";
        char ans;
        cin >> ans;
        if(ans == 'y') goto BEGIN;
        else if (ans == 'n') return 0;
    } else if(op == 2) {
        cout << "1. Input via standard input" << endl;
        cout << "2. Input via file" << endl;
        cout << ": ";
        int inputOP;
        cin >> inputOP;
        system("CLS");
        if(inputOP == 1) readStandard(op);
        if(inputOP == 2) readFile(op);
                cout << "\nDo you want to translate something else? (y/n)" << endl;
        cout << ": ";
        char ans;
        cin >> ans;
        if(ans == 'y') goto BEGIN;
        else if (ans == 'n') return 0;
    } else if(op == 0) {
        return 0;
    } else {
        cout << "Not a valid option." << endl;
        return 0;
    }

    return 0;
}