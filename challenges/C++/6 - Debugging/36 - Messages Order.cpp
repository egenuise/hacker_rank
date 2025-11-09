#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Class Message
class Message {
private:
    // String to store the message text
    string text;
    // Integer to store the order/sequence of the message
    int id;
public:
    // Default constructor for Message: initializes text to empty and id to 0
    Message() : text(""), id(0) {}
    
    // Parameterized constructor to initialize both text and order id
    Message(const string & txt, int order) : text(txt), id(order) {}
    
    // Getter method to return the text of the message
    const string get_text() const {
        return text;
    }
    
    // Overload the < operator to allow sorting of messages.
    // Messages will be compared based on their order id, preserving the original send order.
    bool operator<(const Message &other) const {
        return id < other.id; // If this message's id is less than other's id, then it should come first.
    }
};

// Class MessageFactory for creating messages with an internal counter
class MessageFactory {
private:
    // Counter to differentiate messages by their creation order
    int counter;
public:
    // Default constructor: initialize counter to 0
    MessageFactory() : counter(0) {}
    
    // Method to create a Message object with the given text
    Message create_message(const string &text) {
        // Create a Message using the provided text and the current counter
        Message msg(text, counter);
        // Increment counter for next message creation
        counter++;
        // Return the newly created message
        return msg;
    }
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
    // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());         
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int main() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
}
