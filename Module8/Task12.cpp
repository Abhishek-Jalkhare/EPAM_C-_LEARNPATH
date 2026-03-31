//
// Created by AbhishekJalkhare on 27-03-2026.
//
#include <iostream>
#include <set>
#include <vector>

bool scheduleEvent(std::set<int>& scheduledEvents, int startTime) {
    auto insertResult = scheduledEvents.insert(startTime);
    if (insertResult.second) {
        std::cout << "Successfully scheduled event at " << startTime << " minutes." << std::endl;
        return true;
    } else {
        std::cout << "Conflict! Time slot " << startTime << " minutes is already taken." << std::endl;
        return false;
    }
}

void displayScheduledEvents(const std::set<int>& events) {
    std::cout << "\n--- Scheduled Events ---" << std::endl;
    if (events.empty()) {
        std::cout << "No events scheduled." << std::endl;
    } else {
        for (int time : events) {
            std::cout << " - " << time << " minutes" << std::endl;
        }
    }
    std::cout << "--------------------------------\n" << std::endl;
}

int main() {
    std::set<int> myCalendar;

    std::cout << "Attempting to schedule events for the first time:\n";
    scheduleEvent(myCalendar, 900);
    scheduleEvent(myCalendar, 1030);
    scheduleEvent(myCalendar, 1300);
    scheduleEvent(myCalendar, 1400);
    displayScheduledEvents(myCalendar);

    std::cout << "Attempting to schedule a conflicting event:\n";
    scheduleEvent(myCalendar, 1030);
    displayScheduledEvents(myCalendar);

    std::cout << "Attempting to schedule another unique event:\n";
    scheduleEvent(myCalendar, 1200);
    displayScheduledEvents(myCalendar);

    std::cout << "Attempting to schedule a batch of events (some new, some duplicates):\n";
    std::vector<int> newEventTimes = {800, 1400, 1600, 900, 1800};
    for (int time : newEventTimes) {
        scheduleEvent(myCalendar, time);
    }
    displayScheduledEvents(myCalendar);

    return 0;
}