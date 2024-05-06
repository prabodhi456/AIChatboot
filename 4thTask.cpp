#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string preprocessInput(string input) {
    // Convert input to lowercase
    transform(input.begin(), input.end(), input.begin(), ::tolower);

    // Remove punctuation
    input.erase(remove_if(input.begin(), input.end(), ::ispunct), input.end());

    // Remove extra spaces
    input.erase(unique(input.begin(), input.end(), [](char a, char b) { return a == ' ' && b == ' '; }), input.end());

    return input;
}

string getResponse(string input) {
    if (input.find("hello") != string::npos || input.find("hi") != string::npos)
        return "Hello! How can I help you?";
    else if (input.find("how are you") != string::npos)
        return "I'm just a computer program, but thank you for asking!";
    else if (input.find("bye") != string::npos)
        return "Goodbye! Have a great day!";
    else
        return "I'm sorry, I didn't understand that.";
}

int main() {
    cout << "Chatbot: Hello! How can I help you?" << endl;

    while (true) {
        cout << "You: ";
        string input;
        getline(cin, input);

        input = preprocessInput(input);

        if (input == "quit")
            break;

        string response = getResponse(input);
        cout << "Chatbot: " << response << endl;
    }

    return 0;
}
