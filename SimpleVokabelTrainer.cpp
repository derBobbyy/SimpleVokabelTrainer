#include <fstream>
#include <iterator>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string print_menue(){
    cout << "Vokabel trainer \n";
    cout << "Bitte treffe eine Auswahl: \n";
    cout << " \n";
    cout << "(1) Neue Vokabel Hinzufügen \n";
    cout << "(2) Vokabeltest Starten \n";

    string option;
    cin >> option;

    return option;
}

vector<string> loadTxtFile(string textFile){
    string str;
    ifstream in(textFile);
    vector<string> newVector;

    while(getline(in, str)){
        if(str.size() > 0){
            newVector.push_back(str);
        }
    }

    return newVector;
}

void save_vector_to_txt_file(string fileName, vector<string> myVector){
    ofstream output_file(fileName);
    ostream_iterator<string> output_iterator(output_file, "\n");
    copy(myVector.begin(), myVector.end(), output_iterator);
}

void ask_word(vector<string> voc_german, vector<string> voc_english){
    cout << "Vokabeltest wird gestartet... \n";
    int random = rand() % voc_german.size();
    string sel_elem = voc_german[random];
    string sel_translation = voc_english[random];
    cout << "Bitte übersetzte folgendes Wort: " + sel_elem + "\n";
    string userInput;
    cin >> userInput;
    if(userInput == sel_translation){
        cout << "richtig! \n";
    }else{
        cout << "Leider falsch \n";
    }
}

int main(){

    vector<string> voc_german = loadTxtFile("voc_german.txt");
    vector<string> voc_english = loadTxtFile("voc_english.txt");

    string selection = print_menue();
    

    if(selection == "1"){

        cout << "Welche Vokabel (Deutsch)? \n";
        string german_word;
        string english_word;
        cin >> german_word;
        cout << "Wie lautet die übersetzung? \n";
        cin >> english_word;

        // Wort hinzufügen
        voc_german.push_back(german_word);
        voc_english.push_back(english_word);
        cout << "Vokabel wurde hinzugefügt. \n";
        cout << "Hinzugefügte Vokabeln: " + to_string(voc_german.size());


        save_vector_to_txt_file("./voc_german.txt", voc_german);
        save_vector_to_txt_file("./voc_english.txt", voc_english);


    }else{
        int i;
        while(i < 10){
            ask_word(voc_german, voc_english);
            i++;
        }
    }

    return 0;
}

