#include "alarm_function.h"

AlarmNode::AlarmNode(string t, string r) {
    time = t;
    repeat = r;
    next = NULL;
    prev = NULL;
}

void insert_alarm(AlarmNode*& head, string newTime, string repeat, int position) {
    AlarmNode* newNode = new AlarmNode(newTime, repeat);
    if (position == 0 || head == NULL) {
        newNode->next = head;
        if (head) head->prev = newNode;
        head = newNode;
        return;
    }

    AlarmNode* temp = head;
    int count = 0;
    while (temp->next != NULL && count < position - 1) {
        temp = temp->next;
        count++;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
}

void save_alarms_to_file(AlarmNode* head) {
    ofstream outFile("alarms.txt");
    while (head != NULL) {
        outFile << head->time << "," << head->repeat << endl;
        head = head->next;
    }
    outFile.close();
}

void load_alarms_from_file(AlarmNode*& head) {
    ifstream inFile("alarms.txt");
    string line;
    int pos = 0;
    while (getline(inFile, line)) {
        size_t comma = line.find(',');
        if (comma != string::npos) {
            string time = line.substr(0, comma);
            string repeat = line.substr(comma + 1);
            insert_alarm(head, time, repeat, pos++);
        }
    }
    inFile.close();
}

void display_alarms(AlarmNode* head) {
    if (head == NULL) {
        cout << "No alarms set.\n";
        return;
    }

    cout << "\nYour Alarms:\n---------------------\n";
    int index = 0;
    while (head != NULL) {
        cout << index++ << ". " << head->time << " [" << head->repeat << "]" << endl;
        head = head->next;
    }
    cout << "---------------------\n";
}

void delete_alarm(AlarmNode*& head, int position) {
    if (head == NULL) {
        cout << "No alarms to delete.\n";
        return;
    }

    AlarmNode* temp = head;

    if (position == 0) {
        head = head->next;
        if (head) head->prev = NULL;
        delete temp;
        cout << "Alarm deleted.\n";
        return;
    }

    int count = 0;
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "Invalid position.\n";
        return;
    }

    if (temp->prev) temp->prev->next = temp->next;
    if (temp->next) temp->next->prev = temp->prev;

    delete temp;
    cout << "Alarm deleted.\n";
}

void edit_alarm(AlarmNode* head, int position, string newTime, string repeat) {
    int count = 0;
    while (head != NULL && count < position) {
        head = head->next;
        count++;
    }

    if (head == NULL) {
        cout << "Invalid position.\n";
        return;
    }

    head->time = newTime;
    head->repeat = repeat;
    cout << "Alarm updated.\n";
}

void check_and_trigger_alarms(AlarmNode* head) {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buffer[10];
    strftime(buffer, 10, "%I:%M %p", ltm);
    string currentTime = buffer;

    bool found = false;
    while (head != NULL) {
        if (head->time == currentTime) {
            cout << "\n🔔 ALARM RINGING for " << head->time << " [" << head->repeat << "] 🔔\n";
            if (!PlaySound(TEXT("alarm.wav"), NULL, SND_FILENAME | SND_ASYNC)) {
                cout << "Couldn't play alarm.wav. Beeping instead.\n";
                Beep(1000, 1000);
            }
            Sleep(5000);
            found = true;

            if (head->repeat == "None") {
                // One-time alarm: delete after ringing
                cout << "One-time alarm triggered and removed.\n";
            }
        }
        head = head->next;
    }

    if (!found) {
        cout << "No alarms at current time (" << currentTime << ").\n";
    }
}

void view_upcoming_alarms(AlarmNode* head) {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char buffer[10];
    strftime(buffer, 10, "%I:%M %p", ltm);
    string currentTime = buffer;

    cout << "\nUpcoming Alarms (after " << currentTime << "):\n------------------------\n";
    bool found = false;
    while (head != NULL) {
        if (head->time > currentTime) {
            cout << head->time << " [" << head->repeat << "]" << endl;
            found = true;
        }
        head = head->next;
    }

    if (!found) cout << "No upcoming alarms.\n";
    cout << "------------------------\n";
}
