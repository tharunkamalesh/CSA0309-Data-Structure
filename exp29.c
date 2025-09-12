def find_duplicates(arr):
    seen = set()
    duplicates = set()

    for value in arr:
        if value in seen:
            duplicates.add(value)
        else:
            seen.add(value)

    return list(duplicates)

# Example usage
arr = [1, 2, 3, 4, 2, 5, 6, 3, 7, 1]
print(find_duplicates(arr))  # Output: [1, 2, 3]
