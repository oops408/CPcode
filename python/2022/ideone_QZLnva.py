# your code goes here
list_of_input = ['asdf', 'fdas', 'asds', 'dfm', 'dfaa', 'aaaa']

for line in list_of_input:
    freq = {}
    for char in line:
        if char in freq:
            freq[char] += 1
        else:
            freq[char] = 1
    for char, count in freq.items():
        if count == 2:
            print(line)
            break
