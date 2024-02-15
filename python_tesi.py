def count_towers(n):
    # Initialize a list to store the number of towers for each height
    towers = [0] * (n + 1)

    # Base cases
    towers[0] = 1
    towers[1] = 1

    # Fill the towers list using dynamic programming
    for i in range(2, n + 1):
        # A tower of height i can be built by either adding a single block
        # to the top of a tower of height i-1, or by placing two blocks
        # side-by-side on top of a tower of height i-2.
        towers[i] = towers[i - 1] + towers[i - 2]

    return towers[n]


print(count_towers(3))
