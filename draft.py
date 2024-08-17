import random

def generate_test_cases(num_cases=10):
    test_cases = []

    for _ in range(num_cases):
        n = random.randint(1, 2 * 10**5)  # Vary array size within constraints
        arr = [random.randint(-10**9, 10**9) for _ in range(n)]

        # Specific scenarios to cover:
        test_cases.extend([
            (arr, "random"),
            (arr + arr, "repeated"),  # Repeated sequences
            ([-x for x in arr], "negated"),  # All negatives
            (sorted(arr), "sorted_asc"), 
            (sorted(arr, reverse=True), "sorted_desc"),
            ([0] * n, "all_zeros"),
            ([10**9] * n, "all_max"),
            ([-10**9] * n, "all_min"),
            ([1, -1] * (n // 2), "alternating"),
            (arr + [10**9], "ending_max"), 
            (arr + [-10**9], "ending_min"),
        ])

    return test_cases

# Generate and print test cases
for arr, label in generate_test_cases():
    print(f"# {label}:")
    print(len(arr))
    print(*arr)  
