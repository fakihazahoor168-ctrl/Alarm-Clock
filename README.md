Smart Alarm Management System

Overview

The Smart Alarm Management System is a console-based C++ application that allows users to set, view, edit, delete, snooze, and trigger multiple alarms efficiently. It uses Linked Lists, Queues, and Arrays for dynamic and efficient alarm management, while file handling ensures alarms are saved persistently. Notifications are triggered at scheduled times.

Features

Multiple Alarms: Create and manage multiple alarms with labels and repeat options.

View Alarms: Display all upcoming alarms sorted by time.

Edit/Delete Alarms: Modify or remove existing alarms easily.

Snooze Functionality: Delay alarms by a set interval (e.g., 5 or 10 minutes).

Persistent Storage: Alarms are saved in a file (CSV/TXT) and loaded on startup.

Time-Based Triggering: Automatic notifications when alarm time matches system time.

Data Structures
Feature	Data Structure	Purpose
Set Alarms	Linked List	Dynamic addition/deletion of alarms
View/Trigger Alarms	Queue / Priority Queue	Maintain time-based order
Edit/Delete	Linked List	Easy search and update by ID/label
Snooze	Array / Linked List	Reschedule alarms and track snooze count
Permanent Storage	File Handling (CSV/TXT)	Persist alarms between sessions
