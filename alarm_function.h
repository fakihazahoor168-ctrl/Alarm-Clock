#ifndef ALARM_FUNCTIONS_H
#define ALARM_FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <windows.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

using namespace std;

class AlarmNode {
public:
    string time;
    string repeat; // NEW FIELD
    AlarmNode* next;
    AlarmNode* prev;
    AlarmNode(string t, string r);
};

void insert_alarm(AlarmNode*& head, string newTime, string repeat, int position);
void save_alarms_to_file(AlarmNode* head);
void load_alarms_from_file(AlarmNode*& head);
void display_alarms(AlarmNode* head);
void delete_alarm(AlarmNode*& head, int position);
void edit_alarm(AlarmNode* head, int position, string newTime, string repeat);
void check_and_trigger_alarms(AlarmNode* head);
void view_upcoming_alarms(AlarmNode* head);

#endif
