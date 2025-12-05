def activity_selection(intervals):
    # SORT BY END TIME
    intervals.sort(key=lambda x: x[1])
    selected = []
    last_end_time = float('-inf')
    for interval in intervals:
        start, end = interval
        if start >= last_end_time:
            selected.append(interval)
            last_end_time = end
    return selected

intervals1 = [(1, 4), (3, 5), (0, 6), (5, 7), (8, 9), (5, 9), (3, 8)]
selected_intervals1 = activity_selection(intervals1)
print("Selected intervals:", selected_intervals1)
print("Maximum number of non-overlapping intervals:", len(selected_intervals1))

intervals2 = [(1, 2), (3, 4), (0, 6), (5, 7), (8, 9)]
selected_intervals2 = activity_selection(intervals2)
print("Selected intervals:", selected_intervals2)
print("Maximum number of non-overlapping intervals:", len(selected_intervals2))
