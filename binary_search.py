def binary_search(nums, k):
    low = 0
    high = len(nums) - 1;
    while low <= high:
        mid = int((low + high) / 2)
        if nums[mid] == k:
            return mid
        elif nums[mid] < k:
            low = mid + 1
        else:
            high = mid - 1
    return False

nums = list(map(int, input("Enter space seperated list of numbers: ").split(" ")))
k = int(input("Enter the number you want to search: "))
nums = list(sorted(nums))

index = binary_search(nums, k)

if index is not False:
    print(f"The number {k} is present at index {index} in the sorted list.")
else:
    print(f"The number {k} is not present in the list")