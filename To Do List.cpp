#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};


void displayTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks found." << endl;
        return;
    }

    cout << "Task List:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << "[" << i + 1 << "] " << (tasks[i].completed ? "[X]" : "[ ]") << " " << tasks[i].description << endl;
    }
}

int main() {
    vector<Task> tasks;

    while (true) {
        cout << "\nChoose an option:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Quit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    string description;
                    cout << "Enter task description: ";
                    cin.ignore();
                    getline(cin, description);
                    tasks.push_back(Task(description));
                    cout << "Task added successfully." << endl;
                }
                break;
            case 2:
                displayTasks(tasks);
                break;
            case 3:
                {
                    displayTasks(tasks);
                    cout << "Enter the task number to delete: ";
                    int taskNumber;
                    cin >> taskNumber;

                    if (taskNumber >= 1 && taskNumber <= static_cast<int>(tasks.size())) {
                        tasks.erase(tasks.begin() + taskNumber - 1);
                        cout << "Task deleted successfully." << endl;
                    } else {
                        cout << "Invalid task number. No task deleted." << endl;
                    }
                }
                break;
            case 4:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}

