#include<bits/stdc++.h>

using namespace std;

struct Workshop {
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops {
    int n;
    vector<Workshop> workshops;
};

Available_Workshops* initialize(int start_time[], int duration[], int n) {
    Available_Workshops* ptr = new Available_Workshops;
    ptr->n = n;
    for (int i = 0; i < n; i++) {
        Workshop w;
        w.start_time = start_time[i];
        w.duration = duration[i];
        w.end_time = start_time[i] + duration[i];
        ptr->workshops.push_back(w);
    }
    return ptr;
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
    sort(ptr->workshops.begin(), ptr->workshops.end(),
         [](Workshop& a, Workshop& b) { return a.end_time < b.end_time; });

    int count = 0, last_end = 0;
    for (auto& w : ptr->workshops) {
        if (w.start_time >= last_end) {
            count++;
            last_end = w.end_time;
        }
    }
    return count;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
