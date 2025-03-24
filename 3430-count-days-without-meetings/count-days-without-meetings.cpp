class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
     sort(meetings.begin(), meetings.end());

    int busy_days = 0;
    int prev_end = 0; // Tracks the end of the last merged interval

    // Step 2: Merge overlapping intervals and count busy days
    for (auto& meeting : meetings) {
        int start = meeting[0], end = meeting[1];

        if (start > prev_end) {
            // No overlap, add new busy days
            busy_days += (end - start + 1);
        } else if (end > prev_end) {
            // Partial overlap, extend busy days
            busy_days += (end - prev_end);
        }

        prev_end = max(prev_end, end); // Update last meeting end
    }

    // Step 3: Compute free days
    return days - busy_days;
    }
};