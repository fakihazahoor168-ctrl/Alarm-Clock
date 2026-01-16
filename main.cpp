#include "alarm_function.h"

int main() {
    AlarmNode* head = NULL;
    int choice;

    load_alarms_from_file(head);

    do {
        cout << "\n======= ALARM CLOCK SYSTEM =======\n";
        cout << "1. View All Alarms\n";
        cout << "2. Set New Alarm\n";
        cout << "3. Edit Alarm\n";
        cout << "4. Delete Alarm\n";
        cout << "5. Exit\n";
        cout << "6. Check and Trigger Alarms\n";
        cout << "7. View Upcoming Alarms\n";
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                display_alarms(head);
                break;
            case 2: {
                string time, repeat;
                int pos;
                cout << "Enter alarm time (e.g. 06:30 AM): ";
                cin.ignore();
                getline(cin, time);
                cout << "Enter repeat type (None/Daily): ";
                getline(cin, repeat);
                cout << "Enter position to insert: ";
                cin >> pos;
                insert_alarm(head, time, repeat, pos);
                save_alarms_to_file(head);
                break;
            }
            case 3: {
                int pos;
                string newTime, repeat;
                cout << "Enter position to edit: ";
                cin >> pos;
                cout << "Enter new alarm time: ";
                cin.ignore();
                getline(cin, newTime);
                cout << "Enter new repeat type (None/Daily): ";
                getline(cin, repeat);
                edit_alarm(head, pos, newTime, repeat);
                save_alarms_to_file(head);
                break;
            }
            case 4: {
                int pos;
                cout << "Enter position to delete: ";
                cin >> pos;
                delete_alarm(head, pos);
                save_alarms_to_file(head);
                break;
            }
            case 5:
                cout << "Exiting system. Bye!\n";
                break;
            case 6:
                check_and_trigger_alarms(head);
                break;
            case 7:
                view_upcoming_alarms(head);
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
