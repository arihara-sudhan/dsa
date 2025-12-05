# UNWEIGHTED (Greedy)
def greedy_set_cover(universe, sets):
    covered = set()
    selected_sets = []
    while covered != universe:
        best_set = max(sets, key=lambda s: len(s - covered))
        selected_sets.append(best_set)
        covered |= best_set
        sets.remove(best_set)
    return selected_sets

U = set([1, 2, 3, 4, 5, 6])
sets = [set([1,2,3,4]), set([3,4,5,6]), set([1,2]), set([3,4]), set([5,6])]
selected = greedy_set_cover(U, sets.copy())
print("Selected sets (unweighted):", selected)

# WEIGHTED (Greedy)
def weighted_greedy_set_cover(universe, sets, costs):
    covered = set()
    selected_sets = []
    while covered != universe:
        best_index = max(range(len(sets)), key=lambda i: len(sets[i] - covered) / costs[i])
        selected_sets.append(sets[best_index])
        covered |= sets[best_index]
        sets.pop(best_index)
        costs.pop(best_index)
    return selected_sets

U = set([1, 2, 3, 4, 5, 6])
sets = [set([1,2,3,4]), set([3,4,5,6]), set([1,2]), set([3,4]), set([5,6])]
costs = [100, 100, 10, 10, 10]
selected_weighted = weighted_greedy_set_cover(U, sets.copy(), costs.copy())
print("Selected sets (weighted):", selected_weighted)
